#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Prewitt(Mat);
Mat Gray(Mat);
int main()
{
Mat image = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Prewitt/test.bmp");
if (image.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }
Prewitt(image);
waitKey(0);
}

void Prewitt(Mat img){
int height=img.rows;
int width=img.cols;
Mat grayimg=Gray(img);
Mat imgSibelR(height,width,CV_8UC1,Scalar(255));
int m,n;
m=n=0;
for(int i=1;i<height-1;i++){
    for(int j=1;j<width-1;j++){

          int r1= ((int)grayimg.at<uchar>(i-1,j-1))*(-1)+((int)grayimg.at<uchar>(i-1,j))*(0)+((int)grayimg.at<uchar>(i-1,j+1))*(1);
          int r2= ((int)grayimg.at<uchar>(i,j-1))*(-1)+((int)grayimg.at<uchar>(i,j))*(0)+((int)grayimg.at<uchar>(i,j+1))*(1);
          int r3= ((int)grayimg.at<uchar>(i+1,j-1))*(-1)+((int)grayimg.at<uchar>(i+1,j))*(0)+((int)grayimg.at<uchar>(i+1,j+1))*(1);

          int r4= ((int)grayimg.at<uchar>(i-1,j-1))*(-1)+((int)grayimg.at<uchar>(i-1,j))*(-1)+((int)grayimg.at<uchar>(i-1,j+1))*(-1);
          int r5= ((int)grayimg.at<uchar>(i,j-1))*(0)+((int)grayimg.at<uchar>(i,j))*(0)+((int)grayimg.at<uchar>(i,j+1))*(0);
          int r6= ((int)grayimg.at<uchar>(i+1,j-1))*(1)+((int)grayimg.at<uchar>(i+1,j))*(1)+((int)grayimg.at<uchar>(i+1,j+1))*(1);
          int sumx=r1+r2+r3;
          int sumy=r4+r5+r6;

       grayimg.at<uchar>(i-1, j-1)=sqrt(sumx*sumx+sumy*sumy);
    }

}

imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Prewitt/Prewitt.bmp",grayimg);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",grayimg);
waitKey(0);
}

Mat Gray(Mat img){
int height=img.rows;
int width=img.cols;
Mat imgR(height,width,CV_8UC1,Scalar(255));
int m,n;
m=n=0;
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
            Vec3b intensity = img.at<Vec3b>(i, j);
    int blue = intensity.val[0];
int green = intensity.val[1];
int red = intensity.val[2];

       imgR.at<uchar>(m, n++)=(red+green+blue)/3;
    }
    m++;
    n=0;
 }
 imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Prewitt/PrewittBW.jpg",imgR);
return imgR;
}

