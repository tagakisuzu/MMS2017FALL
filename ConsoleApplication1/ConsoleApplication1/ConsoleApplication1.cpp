#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	int i, j;
	float b, g, r;
	float current_y;//作灰階運送得到正確值current_y
	int Y = 0;//作灰階運送取其整數值Y
	int y = 0;//四捨五入判斷current_y與Y值是否要進位
	Mat image;

	image = imread("card.png", CV_LOAD_IMAGE_COLOR);
	int cols = image.cols;//length
	int rows = image.rows;//width
	printf("i=%d\n", cols);
	printf("j=%d\n", rows);
	Mat gray_image = Mat(rows, cols, CV_8UC1);
	for (i = 0; i<rows; i++)
	{
		for (j = 0; j<cols; j++)
		{
			b = image.at<Vec3b>(i, j)[0];//B read column
			g = image.at<Vec3b>(i, j)[1];//G
			r = image.at<Vec3b>(i, j)[2];//R
			current_y = r / 3 + g / 3 + b / 3;
			Y = r / 3 + g / 3 + b / 3;
			if (current_y - Y >= 0.5)//round it up
			{
				y = Y + 1;
			}
			else//round it down
			{
				y = Y;
			}
			gray_image.at<unsigned char>(i, j) = y;
		}

	}
	Mat d_image = Mat(rows*2, cols*2, CV_8UC1);
	for (i = 0; i<rows*2; i++)
	{
		for (j = 0; j<cols * 2; j++)
		{
			b = image.at<Vec3b>(i, j)[0];//B read column
			g = image.at<Vec3b>(i, j)[1];//G
			r = image.at<Vec3b>(i, j)[2];//R
			
			d_image.at<unsigned char>(i, j) = y;
		}

	}
	namedWindow("Unchanged", CV_WINDOW_AUTOSIZE);
	imshow("Unchanged", image);
	namedWindow("gray_image", CV_WINDOW_AUTOSIZE);
	imshow("gray_image", gray_image);
	waitKey(0);
	return 0;
}
