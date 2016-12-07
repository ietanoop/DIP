#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void GaussianMean(Mat,int,int);
Mat Gray(Mat);
int Mean(int[],int);
int main()
{
  Mat image = imread("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Gausian Noise\\MeanFilter\\test.bmp");
if (image.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }
Mat grayimage=Gray(image);
GaussianMean(grayimage,4,6);
waitKey(0);
}

void GaussianMean(Mat grayimg,int w_width,int w_height){
int height=grayimg.rows;
int width=grayimg.cols;
int window[w_width*w_height];
int edgeX= w_width/2;
int edgeY = w_height/2;
Mat imageMean(height,width,CV_8UC1,Scalar(255));
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
    imageMean.at<uchar>(m,n++)=Mean(window,w_height*w_width);
    }
  m++;n=edgeX;
}

imwrite("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Gausian Noise\\MeanFilter\\result.bmp",imageMean);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",imageMean);
waitKey(0);
}
int Mean(int w[],int size){
   int sum=0;
  for(int i=0;i<size;i++){
    sum= sum+w[i];

  }
  return sum/size;
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

