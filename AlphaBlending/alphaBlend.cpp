
#include <opencv2/opencv.hpp>


// 使用cv :: multiply和添加功能进行Alpha混合 
cv::Mat& blend(cv::Mat& alpha, cv::Mat& foreground, cv::Mat& background, cv::Mat& outImage)
{
    cv::Mat fore, back;
    cv::multiply(alpha, foreground, fore);
    cv::multiply(cv::Scalar::all(1.0)-alpha, background, back);
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
    // 读取前景图片
    cv::Mat foreGroundImage = cv::imread("../images/foreGroundAssetLarge.png", -1);
    cv::Mat bgra[4];
    //通道分离
    cv::split(foreGroundImage, bgra);
    
    // 将RGB内容保存到单个cv :: Mat中 
    std::vector<cv::Mat> foregroundChannels;
    foregroundChannels.push_back(bgra[0]);
    foregroundChannels.push_back(bgra[1]);
    foregroundChannels.push_back(bgra[2]);
    cv::Mat foreground = cv::Mat::zeros(foreGroundImage.size(), CV_8UC3);
    merge(foregroundChannels, foreground);
    
    // 将Alpha信息保存到单个cv :: Mat中 
    std::vector<cv::Mat> alphaChannels;
    alphaChannels.push_back(bgra[3]);
    alphaChannels.push_back(bgra[3]);
    alphaChannels.push_back(bgra[3]);
    cv::Mat alpha = cv::Mat::zeros(foreGroundImage.size(), CV_8UC3);
    merge(alphaChannels, alpha);
   
    cv::Mat background = cv::imread("../images/backGroundLarge.jpg");
    
    // 将cv :: Mat转换为float数据类型 
    foreground.convertTo(foreground, CV_32FC3);
    background.convertTo(background, CV_32FC3);
    alpha.convertTo(alpha, CV_32FC3, 1.0/255); // keeps the alpha values betwen 0 and 1

    int numOfIterations = 1; //1000;
    
    // 使用函数cv :: multiply进行Alpha混合并相加 
    cv::Mat outImage= cv::Mat::zeros(foreground.size(), foreground.type());
    double t = (double)cv::getTickCount();
    for (int i=0; i<numOfIterations; i++) {
        outImage = blend(alpha, foreground, background, outImage);
    }
    t = ((double)cv::getTickCount() - t)/cv::getTickFrequency();
    std::cout << "Time for alpha blending using cv::multiply & add function : " << t*1000/numOfIterations << " milliseconds" << std::endl;

    // 使用直接cv :: Mat访问和for循环进行Alpha混合 
    outImage = cv::Mat::zeros(foreground.size(), foreground.type());
    t = (double)cv::getTickCount();
    for (int i=0; i<numOfIterations; i++) {
        outImage = alphaBlendDirectAccess(alpha, foreground, background, outImage);
    }
    t = ((double)cv::getTickCount() - t)/cv::getTickFrequency();
    std::cout << "Time for alpha blending using alphaBlendDirectAccess : " << t*1000/numOfIterations << " milliseconds" << std::endl;

    cv::imshow("alpha blended image", outImage/255);
    cv::waitKey(0);
    
    return 0;
}
