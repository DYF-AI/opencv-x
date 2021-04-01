# -*- coding:utf-8 -*-

import cv2

# 使用Alpha通道读取前景图像 
foreGroundImage = cv2.imread("images/foreGroundAsset.png", -1)

# 分割png前景图像 
b,g,r,a = cv2.split(foreGroundImage)

# 将前景RGB内容保存到单个对象中 
# opencv: b g r
foreground = cv2.merge((b,g,r))

# 将Alpha信息保存到单个Mat中 
alpha = cv2.merge((a,a,a))

# 读取背景图片
background = cv2.imread("images/backGround.jpg")

# 将uint8转换为float 
foreground = foreground.astype(float)
background = background.astype(float)
alpha = alpha.astype(float)/255

# Alpha通道混合
foreground = cv2.multiply(alpha, foreground)
background = cv2.multiply(1.0 - alpha, background)
outImage = cv2.add(foreground, background)

cv2.imwrite("output/outImgPy.png", outImage)

cv2.imshow("outImg", outImage/255)
cv2.waitKey(0)
cv2.destroyAllWindows()
