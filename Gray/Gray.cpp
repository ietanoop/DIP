#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Gray(Mat);
int main()
{
  Mat image1 = imread("C:/Users/labuser/Desktop/AnoopDIP/DIP/Gray/test.jpg");
if (image1.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }
//Mat gray_image1;
//cvtColor( image1, gray_image1, CV_BGR2GRAY );
//imwrite("C:/Users/Manoj/Desktop/AnoopDIP/graytest.jpg",gray_image1);
 Gray(image1);

  waitKey(0);
}

void Gray(Mat img1){
//namedWindow("Line",WINDOW_AUTOSIZE);
int height=img1.rows;
int width=img1.cols;

Mat imgR(height,width,CV_8UC1,Scalar(0,0));
int m,n;
m=n=0;

//Mat imgBW=img1;
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

imwrite("C:/Users/labuser/Desktop/AnoopDIP/DIP/Gray/gray.jpg",imgR);
namedWindow( "Show", CV_WINDOW_AUTOSIZE );
imshow("Show",imgR);
waitKey(0);
}

