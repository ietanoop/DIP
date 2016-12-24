#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
Mat Resize(Mat,int,int);
Mat addCollage(Mat,Mat, int, int);
int main(){
Mat imgCollage(720,1280,CV_8UC3,Scalar(0,0,0));

Mat img1 = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
Mat imgC=addCollage(imgCollage,img1,0,0);
Mat img2 = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
imgC=addCollage(imgCollage,img2,640,0);
Mat img3 = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
imgC=addCollage(imgCollage,img3,0,360);
Mat img4 = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
imgC=addCollage(imgCollage,img4,640,360);


imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/collage.jpg",imgC);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",imgC);
waitKey(0);
}

Mat addCollage(Mat collage,Mat img, int w, int h){
img=Resize(img,640,360);
int m,n;
m=h;
n=w;
for(int i=0;i<360;i++){
   n=w;
        for(int j=0;j<640;j++){

        collage.at<Vec3b>(m, n++)=img.at<Vec3b>(i, j);
        }
        m++;n=0;
    }
    return collage;
}
Mat Resize(Mat img1,int w,int h){
int height=img1.rows;
int width=img1.cols;
int w_factor=ceil((float)width/w);
int h_factor=ceil((float)height/h);
Mat imgR(h,w,CV_8UC3,Scalar(0,0,0));
int m,n;
m=n=0;
for(int i=0;i<height-h_factor;i=i+h_factor){
    for(int j=0;j<width-w_factor;j=j+w_factor){
      imgR.at<Vec3b>(m, n++)=img1.at<Vec3b>(i, j);
    }
    m++;
    n=0;
}


return imgR;
}
