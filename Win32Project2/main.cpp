//图像的五种滤波方式
//线性滤波：方框滤波，均值滤波与高斯滤波；
//非线性滤波：中值滤波，双边滤波
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cv.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/core/core.hpp>

using namespace cv;
using namespace std;

Mat srcImg, dstImg1, dstImg2, dstImg3, dstImg4, dstImg5;
int Boxfiltervalue = 3;
int Meanfiltervalue = 3;
int Guassianvalue = 3;
int Medianvalue = 10;
int BilateralValue = 10;

void onbox(int,void *);
void onmean(int,void *);
void onguassian(int,void *);
void onmedian(int, void *);
void onbilateral(int, void *);


int main() {
	
	srcImg = imread("image.png");
	if (!srcImg.data) { printf("readerror"); return 0; }

	dstImg1 = srcImg.clone();
	dstImg2 = srcImg.clone();
	dstImg3 = srcImg.clone();

	namedWindow("initialpicture",1);
	imshow("initialpicture", srcImg);


	namedWindow("box", 1);
	createTrackbar("corevalue:", "box", &Boxfiltervalue,40,onbox);
	onbox(Boxfiltervalue, 0);

	namedWindow("mean", 1);
	createTrackbar("meanvalue", "mean", &Meanfiltervalue, 40, onmean);
	onmean(Meanfiltervalue, 0);

	namedWindow("guassian", 1);
	createTrackbar("guassianvalue", "guassian", &Guassianvalue, 40, onguassian);
	onguassian(Guassianvalue, 0);

	namedWindow("median", 1);
	createTrackbar("medianvalue", "median", &Medianvalue, 40, onmedian);
	onmedian(Medianvalue, 0);

	namedWindow("bilateral", 1);
	createTrackbar("bilateralvalue", "bilateral", &BilateralValue, 80, onbilateral);
	onbilateral(BilateralValue, 0);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));


	while (char(waitKey(1)) != 'q') {}

	return 0;

}
void onbox(int, void *) {
	boxFilter(srcImg, dstImg1, -1, Size(Boxfiltervalue + 1, Boxfiltervalue + 1));
	imshow("box", dstImg1);
}

void onmean(int, void *) {
	blur(srcImg, dstImg2, Size(Meanfiltervalue + 1, Meanfiltervalue + 1));
	imshow("mean", dstImg2);
}
void onguassian(int, void *) {
	GaussianBlur(srcImg, dstImg3, Size(Guassianvalue * 2 + 1, Guassianvalue * 2 + 1), 0, 0);
	imshow("guassian", dstImg3);
}
void onmedian(int, void *) {
	medianBlur(srcImg, dstImg4, Medianvalue*2+1);
	imshow("median", dstImg4);
}

void onbilateral(int, void *) {
	bilateralFilter(srcImg, dstImg5, BilateralValue, BilateralValue * 2, BilateralValue / 2);
	imshow("bilateral", dstImg5);
}