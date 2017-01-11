#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

Mat Dilution(Mat,int,int);
Mat Erosion(Mat,int,int);
Mat boundaryDetection(Mat,int,int);

Mat Dilution(Mat img,int r,int c){
    int r1=r/2;
    int c1=c/2;
int height=img.rows;
int width=img.cols;
Mat imgD(height,width,CV_8UC1,Scalar(255));
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(img.at<char>(i,j)==0){
            for(int l=0;l<r;l++){
                for(int m=0;m<c;m++){
                    int i1=i+l-r1;int j1=j+m-c1;
                        if(i1<height&&j1<width&&i1>=0&&j1>=0)
                         imgD.at<char>(i1,j1)=0;
                }
            }
        }else{
        imgD.at<char>(i,j)=img.at<char>(i,j);
        }
    }
}
return imgD;
}
Mat Erosion(Mat img,int r,int c){
int r1=r/2;
int c1=c/2;
int height=img.rows;
int width=img.cols;
Mat imgD(height,width,CV_8UC1,Scalar(255));
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(img.at<char>(i,j)!=0){
            for(int l=0;l<r;l++){
                for(int m=0;m<c;m++){
                   int i1=i+l-r1;int j1=j+m-c1;
                        if(i1<height&&j1<width&&i1>=0&&j1>=0)
                         imgD.at<uchar>(i1,j1)=255;
                }
            }
        }else{
        imgD.at<char>(i,j)=img.at<uchar>(i,j);
        }
    }
}
return imgD;
}
Mat boundaryDetection(Mat img,int r,int c){
int r1=r/2;
int c1=c/2;
int height=img.rows;
int width=img.cols;
Mat imgBoundary(height,width,CV_8UC1,Scalar(255));
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
         int flag=0;
         if(img.at<char>(i,j)==0){
            for(int l=0;l<r;l++){
                for(int m=0;m<c;m++){
                    int i1=i+l-r1;int j1=j+m-c1;
                    if(i1<height&&j1<width&&i1>=0&&j1>=0&&(img.at<char>(i1,j1)!=0))
                    flag=1;
                }
            }
        }

        if(flag==1){
            imgBoundary.at<char>(i,j)=0;
        }
        else{
            imgBoundary.at<char>(i,j)=255;
        }
        flag=0;
    }
}
return imgBoundary;
}


