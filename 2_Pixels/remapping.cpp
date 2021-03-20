
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <math.h>

// remapping an image by creating wave effects
void wave(const cv::Mat &image, cv::Mat &result)
{
	// the map functions
	cv::Mat srcX(image.rows, image.cols, CV_32F); // x-map
	cv::Mat srcY(image.rows, image.cols, CV_32F); // y-map

	// creating the mapping
	for (int i = 0; i < image.rows; i++){
		for (int j = 0; j < image.cols; j++){
			srcX.at<float>(i, j) = j;
			srcY.at<float>(i, j) = i + 3 * sin(j / 6.0);
			// horizontal flipping
			// srcX.at<float>(i,j)= image.cols-j-1;
			// srcY.at<float>(i,j)= i;
		}
	}

	// applying the mapping
	cv::remap(image,			 // source image
			  result,			 // destination image
			  srcX,				 // x map
			  srcY,				 // y map
			  cv::INTER_LINEAR); // interpolation method
}

int main()
{
	// open image
	cv::Mat image = cv::imread("../images/boldt.jpg", 0);

	// remap image
	cv::Mat result;
	wave(image, result);

	// cv::namedWindow("Remapped image");
	// cv::imshow("Remapped image", result);
	imwrite("../output/remapping_result_1.jpg", result);

	//cv::waitKey();
	return 0;
}
