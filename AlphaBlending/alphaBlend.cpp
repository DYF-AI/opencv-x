
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 使用cv :: multiply和添加功能进行Alpha混合 
cv::Mat& blend(cv::Mat& alpha, cv::Mat& foreground, cv::Mat& background, cv::Mat& outImage)
{
    cv::Mat fore, back;
    cv::multiply(alpha, foreground, fore);
    cv::multiply(Scalar::all(1.0)-alpha, background, back);
    cv::add(fore, back, outImage);
    
    return outImage;
}

// 使用直接指针访问进行Alpha混合 
cv::Mat& alphaBlendDirectAccess(cv::Mat& alpha, cv::Mat& foreground, cv::Mat& background, cv::Mat& outImage)
{

    int numberOfPixels = foreground.rows * foreground.cols * foreground.channels();
    
    float* fptr = reinterpret_cast<float*>(foreground.data);
    float* bptr = reinterpret_cast<float*>(background.data);
    float* aptr = reinterpret_cast<float*>(alpha.data);
    float* outImagePtr = reinterpret_cast<float*>(outImage.data);

    int i,j;
    for ( j = 0; j < numberOfPixels; ++j, outImagePtr++, fptr++, aptr++, bptr++)
    {
        *outImagePtr = (*fptr)*(*aptr) + (*bptr)*(1 - *aptr);
    }
    
    return outImage;
}


int main(int argc, char** argv)
{
    
    // Read in the png foreground asset file that contains both rgb and alpha inforcv::mation
    cv::Mat foreGroundImage = imread("../images/foreGroundAssetLarge.png", -1);
    cv::Mat bgra[4];
    split(foreGroundImage, bgra);//split png foreground
    
    // Save the foregroung RGB content into a single cv::Mat
    vector<cv::Mat> foregroundChannels;
    foregroundChannels.push_back(bgra[0]);
    foregroundChannels.push_back(bgra[1]);
    foregroundChannels.push_back(bgra[2]);
    cv::Mat foreground = cv::Mat::zeros(foreGroundImage.size(), CV_8UC3);
    merge(foregroundChannels, foreground);
    
    // Save the alpha inforcv::mation into a single cv::Mat
    vector<cv::Mat> alphaChannels;
    alphaChannels.push_back(bgra[3]);
    alphaChannels.push_back(bgra[3]);
    alphaChannels.push_back(bgra[3]);
    cv::Mat alpha = cv::Mat::zeros(foreGroundImage.size(), CV_8UC3);
    merge(alphaChannels, alpha);
   
    // Read background image
    cv::Mat background = imread("../images/backGroundLarge.jpg");
    
    // Convert cv::Mat to float data type
    foreground.convertTo(foreground, CV_32FC3);
    background.convertTo(background, CV_32FC3);
    alpha.convertTo(alpha, CV_32FC3, 1.0/255); // keeps the alpha values betwen 0 and 1

    // Number of iterations to average the performane over
    int numOfIterations = 1; //1000;
    
    // Alpha blending using functions cv::multiply and add
    cv::Mat outImage= cv::Mat::zeros(foreground.size(), foreground.type());
    double t = (double)getTickCount();
    for (int i=0; i<numOfIterations; i++) {
        outImage = blend(alpha, foreground, background, outImage);
    }
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Time for alpha blending using cv::multiply & add function : " << t*1000/numOfIterations << " milliseconds" << endl;

    // Alpha blending using direct cv::Mat access with for loop
    outImage = cv::Mat::zeros(foreground.size(), foreground.type());
    t = (double)getTickCount();
    for (int i=0; i<numOfIterations; i++) {
        outImage = alphaBlendDirectAccess(alpha, foreground, background, outImage);
    }
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Time for alpha blending using alphaBlendDirectAccess : " << t*1000/numOfIterations << " milliseconds" << endl;

    imshow("alpha blended image", outImage/255);
    waitKey(0);
    
    return 0;
}
