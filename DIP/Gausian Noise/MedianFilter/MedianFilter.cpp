#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
Mat GaussianMedian(Mat,int,int);
Mat Gray(Mat);
int Median(int[],int);
void sortArry(int[],int);
void quicksort(int[],int,int);


Mat GaussianMedian(String filename,int w_width,int w_height){
 Mat image = imread(filename);
 Mat grayimg=Gray(image);
int height=grayimg.rows;
int width=grayimg.cols;
int window[w_width*w_height];
int edgeX= w_width/2;
int edgeY = w_height/2;
Mat imageMedian(height,width,CV_8UC1,Scalar(255));
int m,n;
m=edgeY;
n=edgeX;
int k;
for(int i=edgeY;i<height-edgeY;i++){
    for(int j=edgeX;j<width-edgeX;j++){
           k=0;
           for(int fx=0;fx<w_height;fx++){
              for(int fy=0;fy<w_width;fy++){

                 window[k++]=grayimg.at<uchar>(i+fy-edgeY,j+fx-edgeX);
              }
           }
           sortArry(window,w_height*w_width);
    imageMedian.at<uchar>(m,n++)=Median(window,w_height*w_width);
    }
  m++;n=edgeX;
}

//imwrite("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Gausian Noise\\MedianFilter\\resultMedian.bmp",imageMean);
//namedWindow( "Show Median", CV_WINDOW_AUTOSIZE );
//imshow("Show Median",imageMean);
return imageMedian;
}

int Median(int w[],int size){
  if(size%2!=0){
    return w[(size+1)/2];
  }
  else{
  return (w[(size)/2]+w[(size+1)/2])/2;
  }
}
void sortArry(int A[],int size){
quicksort(A,0,size);
}
void quicksort(int x[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
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
 imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Sobel/SibleBW.jpg",imgR);
return imgR;
}

