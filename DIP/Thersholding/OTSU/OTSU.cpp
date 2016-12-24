#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <Gausian Noise/Filter/Filter.cpp>
#include <math.h>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void OTSU(Mat);
int ThersholdOTSU(Mat);
void Frequncy(Mat);
Mat Gray(Mat);
int cnt[257]={0};
int main()
{
  String file="C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\OTSU\\test.jpg";
Mat image=GaussianMean(file,3,3);

OTSU(image);
//Mat grayimage=GaussianMedian(file,3,3);
//Mat grayimage=Gray(imread(file));
//Histogram(grayimage);

}
void OTSU(Mat img){
int height=img.rows;
int width=img.cols;
int t=ThersholdOTSU(img);

Mat imgOTSU(height,width,CV_8UC1,Scalar(255));
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(img.at<uchar>(i,j)>t)
        imgOTSU.at<uchar>(i,j)=255;
        else
            imgOTSU.at<uchar>(i,j)=0;
    }

}
imwrite("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\OTSU\\OTSU.jpg",imgOTSU);
namedWindow( "Show Median", CV_WINDOW_AUTOSIZE );
imshow("Show Median",imgOTSU);
waitKey(0);
}
int ThersholdOTSU(Mat img){
int height=img.rows;
int width=img.cols;
int size=height*width;
int thershold=0;
long double WCV=9999999999;

Frequncy(img);

long double lsum[256]={0.0};
long double rsum[256]={0.0};
long double lmsum[256]={0.0};
long double rmsum[256]={0.0};
long double lvsum[256]={0.0};
long double rvsum[256]={0.0};
rsum[255]=cnt[255];
rmsum[255]=255*cnt[255];
rvsum[255]=((255-rmsum[255]/rsum[255])*(255-rmsum[255]/rsum[255]))*cnt[255];
float lvs=0.0;
float rvs=0.0;
for(int i=1;i<256;i++){
    lsum[i]=lsum[i-1]+cnt[i-1];
    lmsum[i]=lmsum[i-1]+(i-1)*cnt[i-1];
    long double lmean=(lmsum[i-1]/lsum[i-1]);
     lvs=0.0;
    for(int j=0;j<i;j++){
    lvs=lvs+((j-lmean)*(j-lmean))*cnt[j];
    }
    lvsum[i]=lvs;

}
for(int i=0;i<256;i++){
        cout <<lvsum[i]<<"\n";}
for(int i=254;i>=0;i--){
    rsum[i]=rsum[i+1]+cnt[i];
    rmsum[i]=rmsum[i+1]+i*cnt[i];
    long double rmean=((long double)rmsum[i]/rsum[i]);
     rvs=0.0;
    for(int j=i;j<=255;j++){
    rvs=rvs+(pow((j-rmean),2))*cnt[j];
    }
    rvsum[i]=rvs;

}

for(int i=0;i<256;i++){
     long double b_weight=lsum[i]/size;
     long double b_mean=lmsum[i]/lsum[i];
     long double b_variance=lvsum[i]/lsum[i];

     long double f_weight=rsum[i]/size;
     long double f_mean=rmsum[i]/rsum[i];
     long double f_variance=rvsum[i]/rsum[i];
     long double withinclassvariance=b_weight*b_variance+f_weight*f_variance;
     //cout << withinclassvariance <<"\n";
     if(WCV>withinclassvariance){
        WCV=withinclassvariance;
        thershold=i;
     }
}
cout << thershold <<"\n";
return thershold;
}
void Frequncy(Mat img){
 int mx=0;
   int height=img.rows;
   int width=img.cols;


   for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){

        cnt[img.at<uchar>(i,j)]++;
        if(cnt[img.at<uchar>(i,j)]>mx){
            mx=cnt[img.at<uchar>(i,j)];}
    }
   }
//return cnt;
}
