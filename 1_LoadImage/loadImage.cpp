#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if(argc !=2) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread(argv[1], 1);
    // namedWindow("Display Image", WINDOW_AUTOSIZE);
    // imshow("Display Image", image);
    imwrite("opencv_image.jpg", image);
    return 0;
}
