#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Sobel(Mat);
Mat Gray(Mat);
int main()
{
  Mat image = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Gray/test.bmp");
if (image.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }

 Mat grayimg=Gray(image);
imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Gray/SibleR.bmp",grayimg);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",grayimg);
waitKey(0);
}


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

