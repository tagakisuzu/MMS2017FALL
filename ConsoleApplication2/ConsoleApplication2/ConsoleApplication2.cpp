#include "stdafx.h"
#include "math.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int compare(Mat, Mat, int, int);

int main()
{
	Mat i1 = imread("i1.pgm", CV_LOAD_IMAGE_GRAYSCALE);
	Mat i2 = imread("i2.pgm", CV_LOAD_IMAGE_GRAYSCALE);
	int r = i1.rows;
	int c = i1.cols;
	Mat i2p = Mat(r, c, CV_8U);
	int err = 0, temp = 0, a_r, a_c;

	for (int i = 0; i < r; i+16) {
		for (int j = 0; j < c; j+16) {
			if (i >= 8 && j >= 8 && i <= r - 8 && i <= c - 8) {
				for (int x = i - 8; x < i + 24; x++) {
					for (int y = j - 8; y < j + 24; y++) {
						temp = compare(i1, i2, x, y);
						if (temp < err || err == 0) {
							err = temp;
							a_r = x;
							a_r = y;
						}
					}
				}
			}
			else {
				for (int x = i - 8; x < i + 24; x++) {
					for (int y = j - 8; y < j + 24; y++) {
						if (x < 0 || y < 0) {

						}
						else {
							temp = compare(i1, i2, x, y);
							if (temp < err || err == 0) {
								err = temp;
								a_r = x;
								a_r = y;
							}
						}
					}
				}
			}
			for (int x = i; x < i+4; x++) {
				for (int y = j; y < j+4; y++) {
					i2p.at<uchar>(x, y) = i1.at<uchar>(a_r+x-i, a_c+y-j);
				}
			}
		}
	}
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", i2p);

	return 0;
}

int compare(Mat img1, Mat img2, int r, int c) {
	int er = 0;
	for (int i = r; i < r + 15;i++) {
		for (int j = c; j < c + 15; j++) {
			int ab = abs(img1.at<uchar>(i,j) - img2.at<uchar>(i, j));
			er = er + ab;
		}
	}

	return er;
}
