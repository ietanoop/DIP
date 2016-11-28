#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Resize(Mat,int,int);
int main()
{
  Mat image1 = imread("C:/Users/labuser/Desktop/AnoopDIP//DIP/Resize/test.jpg");
if (image1.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }

 Resize(image1,440,360);

}

void Resize(Mat img1,int w,int h){
int height=img1.rows;
int width=img1.cols;
int w_factor=width/w;
int h_factor=height/h;
Mat imgR(height/h_factor,width/w_factor,CV_8UC3,Scalar(0,0,0));
int m,n;
m=n=0;
for(int i=0;i<height-h_factor-1;i=i+h_factor){
    for(int j=0;j<width-w_factor-1;j=j+w_factor){
      imgR.at<Vec3b>(m, n++)=img1.at<Vec3b>(i, j);
    }
    m++;
    n=0;
}

imwrite("C:/Users/labuser/Desktop/AnoopDIP/DIP/Resize/resized.jpg",imgR);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",imgR);
waitKey(0);
}

