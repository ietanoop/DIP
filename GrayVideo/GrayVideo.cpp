#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
Mat Gray(Mat);
Mat Sobel(Mat);
int main() {
    // Open a video file:
    cv::VideoCapture cap("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\GrayVideo\\sample.mp4");
    if(!cap.isOpened()) {
        std::cout << "Unable to open the video\n";
        std::exit(-1);
    }

    // Get the width/height and the FPS of the vide
    int width = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    double FPS = cap.get(CV_CAP_PROP_FPS);

    // Open a video file for writing (the MP4V codec works on OS X and Windows)
    cv::VideoWriter out("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\GrayVideo\\output.mp4", CV_FOURCC('m','p', '4', 'v'), FPS, cv::Size(width, height),false);
    if(!out.isOpened()) {
        std::cout <<"Error! Unable to open video file for output." << std::endl;
        std::exit(-1);
    }

    cv::Mat image,grayframe;

    int delta = width/3;

    while(true) {
        cap >> image;
        if(image.empty()) {
            std::cout << "Can't read frames from your video\n";
            break;
        }

        // convert it to gray
         grayframe =Sobel(Gray(image));
        // Copy the modified right panel back to the source image
        out.write(grayframe);

        // Save frame to video
        out << grayframe;

      // cv::imshow("Modified video", grayframe);

        // Stop the camera if the user presses the "ESC" key
       // if(cv::waitKey(1000.0/FPS) == 27) break;
    }

    return 0;
}
//Convert video fram into Gray
Mat Gray(Mat img1){
int height=img1.rows;
int width=img1.cols;
Mat imgR(height,width,CV_8UC1,Scalar(255));
int m,n;
m=n=0;
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
            Vec3b intensity = img1.at<Vec3b>(i, j);
    int blue = intensity.val[0];
int green = intensity.val[1];
int red = intensity.val[2];

       imgR.at<uchar>(m, n++)=(red+green+blue)/3;
    }
    m++;
    n=0;
 }
 //imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Sobel/SibleBW.jpg",imgR);
return imgR;
}
Mat Sobel(Mat img1){
int height=img1.rows;
int width=img1.cols;
Mat grayimg=Gray(img1);
Mat imgSibelR(height,width,CV_8UC1,Scalar(255));
int m,n;
m=n=0;

for(int i=1;i<height-1;i++){
    for(int j=1;j<width-1;j++){

          int r1= ((int)grayimg.at<uchar>(i-1,j-1))*(-1)+((int)grayimg.at<uchar>(i-1,j))*(0)+((int)grayimg.at<uchar>(i-1,j+1))*(1);
          int r2= ((int)grayimg.at<uchar>(i,j-1))*(-2)+((int)grayimg.at<uchar>(i,j))*(0)+((int)grayimg.at<uchar>(i,j+1))*(2);
          int r3= ((int)grayimg.at<uchar>(i+1,j-1))*(-1)+((int)grayimg.at<uchar>(i+1,j))*(0)+((int)grayimg.at<uchar>(i+1,j+1))*(1);

          int r4= ((int)grayimg.at<uchar>(i-1,j-1))*(-1)+((int)grayimg.at<uchar>(i-1,j))*(-2)+((int)grayimg.at<uchar>(i-1,j+1))*(-1);
          int r5= ((int)grayimg.at<uchar>(i,j-1))*(0)+((int)grayimg.at<uchar>(i,j))*(0)+((int)grayimg.at<uchar>(i,j+1))*(0);
          int r6= ((int)grayimg.at<uchar>(i+1,j-1))*(1)+((int)grayimg.at<uchar>(i+1,j))*(2)+((int)grayimg.at<uchar>(i+1,j+1))*(1);
          int sumx=r1+r2+r3;
          int sumy=r4+r5+r6;



       grayimg.at<uchar>(i-1, j-1)=sqrt(sumx*sumx+sumy*sumy);
    }

}
return grayimg;
}
