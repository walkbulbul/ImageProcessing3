#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;

Mat orgim;


int main()
{
	orgim = imread("garden.png");

	imshow("Orginal", orgim);

	cvtColor(orgim, orgim, COLOR_RGB2GRAY);

	Canny(orgim, orgim, 100, 150);

	imshow("Canny", orgim);









	
	
	
	waitKey(0);
	return 0;
}