//��ʴ������
//��ʴ�����Ͷ�����Ը���������ԣ���ʴ�Ǽ��ٸ����������������Ӹ�������
//��ʴ��һ���˳ߴ�������Ѱ����Сֵ������õ�Ҷ�ֵ����������һ���˳ߴ�������Ѱ��һ�����ֵ������õ�Ҷ�ֵ

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>

using namespace cv;
using namespace std;

Mat srcImg, dstImg1;
int flag =1;
int coresize = 3;

void process();
void oncorevalue(int, void *);
void onselectvalue(int, void *);


void main() {

	srcImg = imread("image.png");
	namedWindow("initial", 1);
	imshow("initial", srcImg);

	namedWindow("process", 1);
	process();
	imshow("process", dstImg1);

	createTrackbar("erode/dilate", "process", &flag, 1, onselectvalue);
	//onselectvalue(flag,0);

	createTrackbar("coresize", "process", &coresize, 40, oncorevalue);
	//oncorevalue(coresize,0);
	waitKey();
}
void process() {
	Mat element = getStructuringElement(MORPH_RECT, Size(coresize * 2 + 1, coresize * 2 + 1),Point(coresize,coresize));

	if (flag == 0) {
		erode(srcImg, dstImg1, element);
		
	}
	else {
		dilate(srcImg, dstImg1, element);
	}
	imshow("process", dstImg1);

}
void oncorevalue(int, void *) {
	process();
}
void onselectvalue(int, void *) {
	process();
}