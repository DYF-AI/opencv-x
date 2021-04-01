/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 3 of the book:
OpenCV3 Computer Vision Application Programming Cookbook
Third Edition
by Robert Laganiere, Packt Publishing, 2016.

This program is free software; permission is hereby granted to use, copy, modify,
and distribute this source code, or portions thereof, for any purpose, without fee,
subject to the restriction that the copyright notice may not be removed
or altered from any source or altered source distribution.
The software is released on an as-is basis and without any warranties of any kind.
In particular, the software is not guaranteed to be fault-tolerant or free from failure.
The author disclaims all warranties with regard to this software, any use,
and any consequent failure, is purely the responsibility of the user.

Copyright (C) 2016 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    // if(argc !=2) {
    //     printf("usage: DisplayImage.out <Image_Path>\n");
    //     return -1;
    // }

    Mat image;
    //image = imread(argv[1], 1);
    image = imread("../bench1.jpg", 1);
    // H W
    std::cout << "WIDTH HEIGHT: " << image.rows << " " << image.cols << std::endl;
    // namedWindow("Display Image", WINDOW_AUTOSIZE);
    // imshow("Display Image", image);
    imwrite("opencv_image.jpg", image);
    return 0;
}
