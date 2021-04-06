# -*- coding:utf-8 -*-

import cv2
import sys
import numpy as np

def seamlessCloning(image_src:str, image_dst:str):
    img_src = cv2.imread(image_src)
    img_dst = cv2.imread(image_dst)

    cv2.imshow("img_src", img_src)
    cv2.imshow("img_dst", img_dst)

    # mask
    src_mask = np.zeros(img_src.shape, img_src.dtype)
    # 多边形
    poly = np.array([ [4,80], [30,54], [151,63], [254,37], [298,90], [272,134], [43,122] ], np.int32)
    cv2.fillPoly(src_mask, [poly], (255, 255, 255))
    cv2.imshow("mask", src_mask)

    # src图贴在dst的位置
    center = (300, 100)
    # do
    output = cv2.seamlessClone(img_src, img_dst, src_mask, center, cv2.NORMAL_CLONE)

    cv2.imshow("images/opencv-seamless-cloning-example.jpg", output)
    cv2.waitKey(10000)
    cv2.destroyWindow('img')
           
def demo():
    image_src = "images/airplane.jpg"
    image_dst = "images/sky.jpg"
    seamlessCloning(image_src, image_dst)


if __name__== '__main__':
    import fire
    fire.Fire()