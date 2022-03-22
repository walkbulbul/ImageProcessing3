#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat orgImg;
Mat grayImg;
Mat hist_img;

int sequ[255];

int main()

{
	orgImg = imread("garden.png");
	cvtColor(orgImg, grayImg, COLOR_BGR2GRAY);
	Mat graphic(800, 1200, CV_8UC3, Scalar(0, 0, 0));

	equalizeHist(grayImg, hist_img);

	for (int i = 0; i < orgImg.cols; i++)

	{
		for (int j = 0; j < orgImg.rows; j++)
		{
			for (int p = 0; p < 255; p++)
			{
				if (grayImg.at<uchar>(j, i) == p) sequ[p]++;


			}

		}



	}
	for (int i = 0; i < 255; i++)
	{
		printf("%d's number: %d\n", i, sequ[1]);


	}

	for (int i = 0; i < 255; i++)

	{
		line(graphic, Point(i * 1200 / 255, 800), Point(i * 1200 / 255, 800 - sequ[i] / 30), Scalar(50, i, sequ[i]), 5, 8, 0);

	}
	imshow("Grey Picture", grayImg);
	imshow("Graphic", graphic);


	waitKey(0);
	return 0;

}
