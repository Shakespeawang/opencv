//图像的融合，分离，显示与读入

#include<stdio.h>
#include<stdlib.h>
#include<cv.h>
#include<opencv2/highgui/highgui.hpp>

#include<iostream>
using namespace cv;
using namespace std;

bool add();
bool rotimg();
bool rotimgadd();
bool separate();

int main() {
	if (separate()&add()&rotimg()&rotimgadd()) { cout << "输出成功" << endl; };
	waitKey(0);
	return 0;

}
bool separate()
{
	Mat img = imread("image.png");
	Mat logo = imread("logo.png");
	vector<Mat> channels;
	split(img,channels);
	Mat rot1 = channels[0];

	addWeighted(rot1(Rect(100, 100, logo.cols, logo.rows)),0.5,logo,0.5,0, rot1(Rect(100, 100, logo.cols, logo.rows)));
	merge(channels, img);
	
	namedWindow("separate");
	imshow("separate", img);
	return true;
}


bool rotimg()
{
	Mat img = imread("image.png", 1);
	Mat logo = imread("logo.png", 1);

	Mat rot = img(Rect(200, 250, logo.cols, logo.rows));
	Mat mask = imread("logo.png", 1);

	logo.copyTo(rot, mask);
	namedWindow("rotimg");
	imshow("rotimg", img);
	return true;
}
bool rotimgadd()
{
	Mat img = imread("image.png", 1);
	Mat logo = imread("logo.png", 1);

	Mat rot = img(Rect(200, 250, logo.cols, logo.rows));
	
	addWeighted(logo, 0.5, rot, 0.5, 0, rot);

	
	namedWindow("show");
	imshow("rotimgadd", img);
	

	return true;
}

bool add()
{
	double alp = 0.5;
	double beta;
	Mat img = imread("1.png", 1);
	Mat logo = imread("2.png", 1);

	if (!img.data) { printf("读取srcImage2错误~！ \n"); return false; }
	if (!logo.data) { printf("读取srcImage3错误~！ \n"); return false; }

	beta = 1 - alp;
	Mat dstImg;
	addWeighted(img, alp, logo, beta, 0, dstImg);
	namedWindow("show");
	imshow("show", dstImg);
	
	return true;
}

