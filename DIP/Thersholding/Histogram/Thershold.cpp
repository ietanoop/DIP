#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <Gausian Noise/Filter/Filter.cpp>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Histogram(Mat);
Mat Gray(Mat);

int main()
{
  String file="C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\Histogram\\test.bmp";


//Mat grayimage=GaussianMean(file,3,3);

Mat grayimage=GaussianMedian(file,3,3);
//Mat grayimage=Gray(imread(file));
Histogram(grayimage);

}
void Histogram(Mat img){
    int mx=0;
   int height=img.rows;
   int width=img.cols;
   int cnt[256]={0};

   for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){

        cnt[img.at<uchar>(i,j)]++;
        if(cnt[img.at<uchar>(i,j)]>mx){
            mx=cnt[img.at<uchar>(i,j)];}
    }
   }
   Mat histrogramImg(mx,256,CV_8UC1,Scalar(255));
  for(int i=0;i<256;i++){
    for(int j=cnt[i];j>=0;j--){
        histrogramImg.at<uchar>(j,i)=0;
    }
  }
Mat imgClear(height,width,CV_8UC1,Scalar(255));
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(img.at<uchar>(i,j)>122)
        imgClear.at<uchar>(i,j)=255;
        else
            imgClear.at<uchar>(i,j)=0;
    }

}
imwrite("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\Histogram\\restHistoMedian.bmp",imgClear);
namedWindow( "Show Median", CV_WINDOW_AUTOSIZE );
imshow("Show Median",imgClear);
waitKey(0);
}



