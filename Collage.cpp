#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
Mat Resize(Mat,int,int);
void Collage(Mat[],int,int,int);
int main()
{  Mat image_array[4];
   image_array[0] = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
   image_array[1] = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
   image_array[2] = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");
   image_array[3] = imread("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/test.jpg");

 Collage(image_array,1280,720,4);

}
void Collage(Mat img_arry[],int h,int w,int no){
       Mat imgC(w,h,CV_8UC3,Scalar(0,0,0));
 int m,n,f;
  m=n=f=0;
for(int c=0;c<no;c++){
    Mat img=Resize(img_arry[c],h/2,w/2);
    for(int i=0;i<w/2;i++){ n=f+0;
        for(int j=0;j<h/2;j++){

        imgC.at<Vec3b>(m, n++)=img.at<Vec3b>(i, j);
        }
    m++;
   // n=f+0;

    }
n=0;
if(m>=w){m=0;f=w;}
}
imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Collage/collage.jpg",imgC);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",imgC);
waitKey(0);
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
