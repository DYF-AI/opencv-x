
#include <random>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

// Add salt noise to an image
void salt(cv::Mat image, int n)
{
	// C++11 random number generator
	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomRow(0, image.rows - 1);
	std::uniform_int_distribution<int> randomCol(0, image.cols - 1);

	int i, j;
	for (int k = 0; k < n; k++)
	{
		// random image coordinate
		i = randomCol(generator);
		j = randomRow(generator);
		if (image.type() == CV_8UC1)
		{ // gray-level image
			// single-channel 8-bit image
			image.at<uchar>(j, i) = 255;
		}
		else if (image.type() == CV_8UC3)
		{ // color image
			// 3-channel image
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
			// or simply:
			// image.at<cv::Vec3b>(j, i) = cv::Vec3b(255, 255, 255);
		}
	}
}

// This is an extra version of the function
// to illustrate the use of cv::Mat_
// works only for a 1-channel image
void salt2(cv::Mat image, int n)
{
	// must be a gray-level image
	CV_Assert(image.type() == CV_8UC1);
	// C++11 random number generator
	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomRow(0, image.rows - 1);
	std::uniform_int_distribution<int> randomCol(0, image.cols - 1);
	// use image with a Mat_ template
	cv::Mat_<uchar> img(image);
	//  or with references:
	//	cv::Mat_<uchar>& im2= reinterpret_cast<cv::Mat_<uchar>&>(image);

	int i, j;
	for (int k = 0; k < n; k++)
	{
		// random image coordinate
		i = randomCol(generator);
		j = randomRow(generator);
		// add salt
		img(j, i) = 255;
	}
}

int main()
{
	// open the image
	cv::Mat image = cv::imread("../images/boldt.jpg", 1);

	// call function to add noise
	salt(image, 3000);

	// display result
	// cv::namedWindow("Image");
	// cv::imshow("Image",image);

	// write on disk
	cv::imwrite("../output/saltImage_result_1.jpg", image);

	//cv::waitKey();

	// test second version
	image = cv::imread("../images/boldt.jpg", 0);

	salt2(image, 500);
	// cv::namedWindow("Image");
	// cv::imshow("Image", image);
	cv::imwrite("../output/saltImage_result_2.jpg", image);

	//cv::waitKey();

	return 0;
}
