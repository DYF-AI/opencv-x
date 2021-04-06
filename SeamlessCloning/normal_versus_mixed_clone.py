# -*- coding:utf-8 -*-

import cv2
import numpy as np

def seamless_mix_normal(image_src:str, image_dst:str):

    # 1. 读取src和dst
    img_src = cv2.imread(image_src)
    img_dst= cv2.imread(image_dst)

    # 创建mask
    mask = 255 * np.ones(img_dst.shape, img_dst.dtype)

    # 将src贴到dst的中心位置
    width, height, channels = img_src.shape
    center = (int(height/2), int(width/2))

    # 对比normal和mixed两种方式
    normal_clone = cv2.seamlessClone(img_dst, img_src, mask, center, cv2.NORMAL_CLONE)
    mixed_clone = cv2.seamlessClone(img_dst, img_src, mask, center, cv2.MIXED_CLONE)

    # 输出结果
    # cv2.imwrite("images/opencv-normal-clone-example.jpg", normal_clone)
    # cv2.imwrite("images/opencv-mixed-clone-example.jpg", mixed_clone)
    cv2.imshow("normal", normal_clone)
    cv2.imshow("mixed", mixed_clone)
    cv2.waitKey(20000)

def demo():
    image_src = "images/wood-texture.jpg"
    image_dst = "images/iloveyouticket.jpg"
    seamless_mix_normal(image_src, image_dst)

if __name__ == '__main__':
    import fire
    fire.Fire()