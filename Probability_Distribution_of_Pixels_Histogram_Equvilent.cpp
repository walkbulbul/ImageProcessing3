#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat orgImg;
Mat grayImg;

int sequ[255];

int main()

{
	orgImg = imread("garden.png");
	cvtColor(orgImg, grayImg, COLOR_BGR2GRAY);

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

	imshow("Grey Picture", grayImg);
	
	waitKey(0);
	return 0;

}

