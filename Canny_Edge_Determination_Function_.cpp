#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat orgImg, dst1;
int trackval = 1;

void track(int, void*)



{

	Mat dst2(orgImg.rows,orgImg.cols,CV_8UC1,Scalar(0));
	Mat dst3(orgImg.rows, orgImg.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < orgImg.cols - 1; i++)
	{
		for (int j = 0; j < orgImg.rows - 1; j++)
		{
			int a = dst1.at<uchar>(i + j, i) - dst1.at<uchar>(i, j);
			int b = dst1.at<uchar>(j, i) - dst1.at<uchar>(j + 1, i);

			if (a > trackval || b > trackval)

			{
				dst2.at<uchar>(j, i) = 255;

			}
			else

			{
				dst2.at<uchar>(j, i) = 0;


			}

		}

	}

	for (int i = 0; i < orgImg.cols - 1; i++)
	{
		for (int j = 0; j < orgImg.rows - 1; j++)
		{
			int a = dst1.at<uchar>(j, i + 1) - dst1.at<uchar>(j, i);
			int b = dst1.at<uchar>(j, i) - dst1.at<uchar>(j, i + 1);

			if (a > trackval || b > trackval) dst3.at<uchar>(j, i) = 255;
			else {
				dst3.at<uchar>(j, i) = 0;
			}



		}

	}

	imshow("Picture", dst1);
	imshow("Canny", dst2 + dst3);






}


int main()
{
	orgImg = imread("garden.png");
	cvtColor(orgImg, dst1, COLOR_BGR2GRAY);

	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	createTrackbar("Derivative", "Trackbar", &trackval,255,track);


	waitKey(0);
	return 0;


}

