# -*- coding:utf-8 -*-

import cv2
import numpy as np

# 1. key points
def readPoints(point_file:str):
    points = []
    with open(point_file) as file:
        for line in file:
            x,y = line.split()
            points.append((int(x), int(y)))
    return points

# 2. 绘制key points
def plotPoint(image_src:str, points):
    point_size = 1
    point_color = (0, 0, 255) # BGR
    thickness = 4 # 可以为 0 、4、8
    img_src = cv2.imread(image_src)
    print("points:", points)
    for point in points:
        cv2.circle(img_src, point, point_size, point_color, thickness)
    cv2.imshow("key points", img_src)
    cv2.waitKey(20000)

# 3. 仿射变换
# 给定一对三角形，找到仿射变换
def applyAffineTransform(src, srcTri, dstTri, size):
    warpMat = cv2.getAffineTransform(np.float32(srcTri), np.float32(dstTri))
    dst = cv2.warpAffine(src, warpMat, (size[0], size[1]), 
                         None, flags=cv2.INTER_LINEAR, borderMode=cv2.BORDER_REFLECT101)
    return dst

# 4. 检测点是否在rect里面
def rectContains(rect, point):
    if point[0] < rect[0]:
        return False
    elif point[1] < rect[1]:
        return False
    elif point[0] > rect[0] + rect[2]:
        return False
    elif point[1] > rect[1] + rect[3]:
        return False
    return True

# 5. Delaunay三角剖分算法
# 相连但不重合
def calculateDelaunayTriangles(rect, points):
    # subdiv
    subdiv = cv2.Subdiv2D(rect)
    print("subdiv: ", subdiv)

    # 将点插入subdiv
    for p in points:
        subdiv.insert(p)
    
    triangleList = subdiv.getTriangleList()

    delaunayTri = []
    pt = []

    for t in triangleList:
        pt.append((t[0], t[1]))
        pt.append((t[2], t[3]))
        pt.append((t[4], t[5]))

        pt1 = (t[0], t[1])
        pt2 = (t[2], t[3])
        pt3 = (t[4], t[5])

        # 确保检测点是否在rect里面
        if rectContains(rect, pt1) and rectContains(rect, pt2) and rectContains(rect, pt3):
            ind = []
            # 通过坐标获取面部点
            for j in range(0, 3):
                for k in range(0, len(points)):
                    if(abs(pt[j][0]-points[k][0])<1.0 and abs(pt[j][1]-points[k][1])<1.0):
                        ind.append(k)
            # 三个点组成一个三角形。 三角形数组对应于FaceMorph中的文件tri.txt
            if len(ind) == 3:
                delaunayTri.append((ind[0], ind[1], ind[2]))
        
        pt = []
        
    return delaunayTri

def warpTriangle(img1, img2, t1, t2):

    # 查找每个三角形的边界矩形
    r1 = cv2.boundingRect((np.float32([t1])))
    r2 = cv2.boundingRect((np.float32([t2])))

    # 按相应矩形的左上角偏移点
    t1Rect, t2Rect, t2RectInt = [], [], []

    for i in range(0, 3):
        t1Rect.append(((t1[i][0]-r1[0]), (t1[i][1]-r1[1])))
        t2Rect.append(((t2[i][0]-r2[0]), (t2[i][1]-r2[1])))
        t2RectInt.append(((t2[i][0]-r2[0]), (t2[i][1]-r2[1])))

    # 填充三角形获得mask
    mask = np.zeros((r2[3], r2[2], 3), dtype=np.float32)
    cv2.fillConvexPoly(mask, np.int32(t2RectInt), (1.0,1.0,1.0), 16, 0)

    img1Rect = img1[r1[1]:r1[1]+r1[3], r1[0]:r1[0]+r1[2]]

    size = (r2[2], r2[3])

    # 放射变换 t1Rect:srcTri  t2Rect:dstTri
    img2Rect = applyAffineTransform(img1Rect, t1Rect, t2Rect, size)
    img2Rect = img2Rect * mask
    img2[r2[1]:r2[1]+r2[3], r2[0]:r2[0]+r2[2]] = img2[r2[1]:r2[1]+r2[3], r2[0]:r2[0]+r2[2]] * ( (1.0, 1.0, 1.0) - mask )
    img2[r2[1]:r2[1]+r2[3], r2[0]:r2[0]+r2[2]] = img2[r2[1]:r2[1]+r2[3], r2[0]:r2[0]+r2[2]] + img2Rect 


def demo1():
    trump = "images/donald_trump.jpg"
    trump_file = "images/donald_trump.jpg.txt"
    points = readPoints(trump_file)
    plotPoint(trump, points)

def demo2():
    
    # filename1 = "images/hillary_clinton.jpg"
    filename2 = "images/donald_trump.jpg"
    filename1 = 'images/ted_cruz.jpg'

    img1 = cv2.imread(filename1)
    img2 = cv2.imread(filename2)
    img1Warped = np.copy(img2)

    # 读取面部特征点
    points1 = readPoints(filename1 + ".txt")
    points2 = readPoints(filename2 + ".txt")
     
    hull1 = []
    hull2 = []
    hullIndex = cv2.convexHull(np.array(points2), returnPoints = False)

     
    for i in range(0, len(hullIndex)):
        hull1.append(points1[int(hullIndex[i])])
        hull2.append(points2[int(hullIndex[i])])
    
    
    # 查找hull points的Delaunay三角剖分 
    sizeImg2 = img2.shape    
    rect = (0, 0, sizeImg2[1], sizeImg2[0])
     
    dt = calculateDelaunayTriangles(rect, hull2)
    
    if len(dt) == 0:
        quit()
    
    # 将仿射变换应用于Delaunay三角形 
    for i in range(0, len(dt)):
        t1 = []
        t2 = []
        
        # 获取对应于三角形的img1，img2的点 
        for j in range(0, 3):
            t1.append(hull1[dt[i][j]])
            t2.append(hull2[dt[i][j]])
        
        warpTriangle(img1, img1Warped, t1, t2)
      
    # 计算mask
    hull8U = []
    for i in range(0, len(hull2)):
        hull8U.append((hull2[i][0], hull2[i][1]))
    
    mask = np.zeros(img2.shape, dtype = img2.dtype)  
    cv2.fillConvexPoly(mask, np.int32(hull8U), (255, 255, 255))
    r = cv2.boundingRect(np.float32([hull2]))    
    center = ((r[0]+int(r[2]/2), r[1]+int(r[3]/2)))
        
    # Clone seamlessly.
    output = cv2.seamlessClone(np.uint8(img1Warped), img2, mask, center, cv2.NORMAL_CLONE)
    
    cv2.imwrite("output/output.jpg", output)
    cv2.imshow("Face Swapped", output)
    cv2.waitKey(20000)
    
    cv2.destroyAllWindows()
if __name__ == '__main__':
    import fire
    fire.Fire()