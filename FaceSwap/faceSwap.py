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


def demo():
    trump = "images/donald_trump.jpg"
    trump_file = "images/donald_trump.jpg.txt"
    points = readPoints(trump_file)
    plotPoint(trump, points)

if __name__ == '__main__':
    import fire
    fire.Fire()