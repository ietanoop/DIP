#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
void Histogram(Mat);
Mat Gray(Mat);

int main()
{
  Mat image = imread("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\Histogram\\test.bmp");
if (image.empty()) {
    cout << "Cannot open image!" << endl;
    return 1;
  }
Mat grayimage=Gray(image);
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


imwrite("C:\\Users\\Manoj\\Desktop\\AnoopDIP\\DIP\\Thersholding\\Histogram\\resultMedian.bmp",histrogramImg);
namedWindow( "Show Median", CV_WINDOW_AUTOSIZE );
imshow("Show Median",histrogramImg);
waitKey(0);
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
 imwrite("C:/Users/Manoj/Desktop/AnoopDIP/DIP/Thersholding/SibleBW.jpg",imgR);
return imgR;
}

