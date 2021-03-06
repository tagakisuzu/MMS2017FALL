#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	int i, j, ii, jj;
	float b, g, r;
	float current_y;//作灰階運送得到正確值current_y
	int Y = 0;//作灰階運送取其整數值Y
	int y = 0;//四捨五入判斷current_y與Y值是否要進位
	Mat image;

	image = imread("001.jpg", CV_LOAD_IMAGE_COLOR);
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
	for (i = 0, ii = 0; i<rows*2, ii<rows; i=i+2, ii++)
	{
		for (j = 0, jj=0; j<cols*2, jj<cols; j=j+ 2, jj++)
		{
			current_y = gray_image.at<unsigned char>(ii, jj);
			if (current_y >= 0 && current_y < 51) {
				d_image.at<unsigned char>(i, j) = 0;
				d_image.at<unsigned char>(i+1, j) = 0;
				d_image.at<unsigned char>(i, j+1) = 0;
				d_image.at<unsigned char>(i+1, j+1) = 0;
			}
			else if (current_y >= 51 && current_y < 101) {
				d_image.at<unsigned char>(i, j) = 255;
				d_image.at<unsigned char>(i + 1, j) = 0;
				d_image.at<unsigned char>(i, j + 1) = 0;
				d_image.at<unsigned char>(i + 1, j + 1) = 0;
			}
			else if (current_y >= 101 && current_y < 151) {
				d_image.at<unsigned char>(i, j) = 255;
				d_image.at<unsigned char>(i + 1, j) = 0;
				d_image.at<unsigned char>(i, j + 1) = 0;
				d_image.at<unsigned char>(i + 1, j + 1) = 255;
			}
			else if (current_y >= 151 && current_y < 201) {
				d_image.at<unsigned char>(i, j) = 255;
				d_image.at<unsigned char>(i + 1, j) = 0;
				d_image.at<unsigned char>(i, j + 1) = 255;
				d_image.at<unsigned char>(i + 1, j + 1) = 255;
			}
			else if (current_y >= 201 && current_y < 255) {
				d_image.at<unsigned char>(i, j) = 255;
				d_image.at<unsigned char>(i + 1, j) = 255;
				d_image.at<unsigned char>(i, j + 1) = 255;
				d_image.at<unsigned char>(i + 1, j + 1) = 255;
			}
		}

	}

	Mat d2_image = Mat(rows, cols, CV_8UC1);
	for (i = 0 ; i<rows ; i++)
	{
		for (j = 0 ; j<cols ; j++)
		{
			current_y = gray_image.at<unsigned char>(i, j);
			y = current_y / 16;
			if (i % 4 == 0 && j % 4 == 0) {
				if (y > 0) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 1) {
				if (y > 8) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 2) {
				if (y > 2) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 3) {
				if (y > 10) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 0) {
				if (y > 12) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 1) {
				if (y > 4) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 2) {
				if (y > 14) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 3) {
				if (y > 6) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 0) {
				if (y > 3) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 1) {
				if (y > 11) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 2) {
				if (y > 1) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 3) {
				if (y > 9) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 0) {
				if (y > 15) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 1) {
				if (y > 7) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 2) {
				if (y > 13) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 3) {
				if (y > 5) {
					d2_image.at<unsigned char>(i, j) = 255;
				}
				else
					d2_image.at<unsigned char>(i, j) = 0;
			}
		}

	}

	Mat d3_image = Mat(rows, cols, CV_8UC1);
	for (i = 0; i<rows; i++)
	{
		for (j = 0; j<cols; j++)
		{
			current_y = gray_image.at<unsigned char>(i, j);
			y = current_y / 16;
			if (i % 4 == 0 && j % 4 == 0) {
				if (y > 0) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 1) {
				if (y > 1) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 2) {
				if (y > 2) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 0 && j % 4 == 3) {
				if (y > 3) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 0) {
				if (y > 4) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 1) {
				if (y > 5) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 2) {
				if (y > 6) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 1 && j % 4 == 3) {
				if (y > 7) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 0) {
				if (y > 8) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 1) {
				if (y > 9) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 2) {
				if (y > 10) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 2 && j % 4 == 3) {
				if (y > 11) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 0) {
				if (y > 12) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 1) {
				if (y > 13) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 2) {
				if (y > 14) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
			else if (i % 4 == 3 && j % 4 == 3) {
				if (y > 15) {
					d3_image.at<unsigned char>(i, j) = 255;
				}
				else
					d3_image.at<unsigned char>(i, j) = 0;
			}
		}

	}
	namedWindow("Unchanged", CV_WINDOW_AUTOSIZE);
	imshow("Unchanged", image);
	namedWindow("gray_image", CV_WINDOW_AUTOSIZE);
	imshow("gray_image", gray_image);
	namedWindow("d_image", CV_WINDOW_AUTOSIZE);
	imshow("d_image", d_image);
	namedWindow("d2_image", CV_WINDOW_AUTOSIZE);
	imshow("d2_image", d2_image);
	namedWindow("d3_image", CV_WINDOW_AUTOSIZE);
	imshow("d3_image", d3_image);
	waitKey(0);
	return 0;
}
