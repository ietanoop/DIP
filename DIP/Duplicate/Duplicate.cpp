#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Filter(Mat,Mat);
int main()
{
  Mat image1 = imread("C:/Users/Manoj/Desktop/AnoopDIP/test_dup1.jpg");
  Mat image2 = imread("C:/Users/Manoj/Desktop/AnoopDIP/test2.jpg");

  if (image1.empty() || image2.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }
Mat gray_image1;
 cvtColor( image1, gray_image1, CV_BGR2GRAY );
 Mat gray_image2;
 cvtColor( image2, gray_image2, CV_BGR2GRAY );
 Filter(gray_image1, gray_image2);
  waitKey(0);
}

void Filter(Mat img1, Mat img2){
//namedWindow("Line",WINDOW_AUTOSIZE);
int width=img1.rows;
int height=img2.cols;
Mat imgBW=img1;
for(int i=0;i<width;i++){
    for(int j=0;j<height;j++){
       imgBW.at<uchar>(i,j)=255;
    }
}
for(int i=0;i<width;i++){
    for(int j=0;j<height;j++){

     if(img1.at<uchar>(i,j)-img2.at<uchar>(i,j)>235)
    imgBW.at<uchar>(i,j)=0;
    }
}
imwrite("C:/Users/Manoj/Desktop/AnoopDIP/test_dupbw.jpg",imgBW);

imshow("Line",imgBW);
}

