/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 4 of the book:
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
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#include "imageComparator.h"

int main()
{
	// Read reference image
	cv::Mat image = cv::imread("../images/waves.jpg");
	if (!image.data)
		return 0;

	// Display image
	// cv::namedWindow("Query Image");
	// cv::imshow("Query Image", image);
	cv::imwrite("../outputs/retrieve_Query_Image.jpg", image);

	ImageComparator c;
	c.setReferenceImage(image);

	// Read an image and compare it with reference
	cv::Mat input = cv::imread("../images/dog.jpg");
	cout << "waves vs dog: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/marais.jpg");
	cout << "waves vs marais: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/bear.jpg");
	cout << "waves vs bear: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/beach.jpg");
	cout << "waves vs beach: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/polar.jpg");
	cout << "waves vs polar: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/moose.jpg");
	cout << "waves vs moose: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/lake.jpg");
	cout << "waves vs lake: " << c.compare(input) << endl;

	// Read an image and compare it with reference
	input = cv::imread("../images/fundy.jpg");
	cout << "waves vs fundy: " << c.compare(input) << endl;

	//cv::waitKey();
	return 0;
}