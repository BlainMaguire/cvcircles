#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
 
using namespace std;

cv::Scalar getCircleColour(cv::Mat& image, int xCenter, int yCenter, int radius)
{
        int x, y, r2;
        // .at( y, x )
	//image.at<cv::Vec3b>(yCenter, xCenter) = color;
        r2 = radius * radius;
	int pixelCount = 0;
	double totalBlue, totalGreen, totalRed = 0;
	

	if (xCenter < image.cols && yCenter + radius < image.cols && xCenter >= 0 && yCenter + radius >=0) {
		totalBlue += image.at<cv::Vec3b>(yCenter + radius, xCenter)[0];
		totalGreen += image.at<cv::Vec3b>(yCenter + radius, xCenter)[1];
		totalRed += image.at<cv::Vec3b>(yCenter + radius, xCenter)[2];
		pixelCount++;
	}

	if (xCenter < image.cols && yCenter - radius < image.cols && xCenter >= 0 && yCenter - radius >=0) {
		totalBlue += image.at<cv::Vec3b>(yCenter - radius, xCenter)[0];
		totalGreen += image.at<cv::Vec3b>(yCenter - radius, xCenter)[1];
		totalRed += image.at<cv::Vec3b>(yCenter - radius, xCenter)[2];
		pixelCount++;
	}

	if (xCenter + radius < image.cols && yCenter < image.cols && xCenter + radius >= 0 && yCenter >=0) {
	        totalBlue += image.at<cv::Vec3b>(yCenter, xCenter + radius)[0];
	        totalGreen += image.at<cv::Vec3b>(yCenter, xCenter + radius)[1];
	        totalRed += image.at<cv::Vec3b>(yCenter, xCenter + radius)[2];
		pixelCount++;
	}

	if (xCenter - radius < image.cols && yCenter < image.cols && xCenter - radius >= 0 && yCenter >=0) {
        	totalBlue += image.at<cv::Vec3b>(yCenter, xCenter - radius)[0];
	        totalGreen += image.at<cv::Vec3b>(yCenter, xCenter - radius)[1];
        	totalRed += image.at<cv::Vec3b>(yCenter, xCenter - radius)[2];
		pixelCount++;
	}

        y = radius;
        x = 1;
        y = (int) (sqrt(r2 - 1) + 0.5);

        while (x < y) {

		if (xCenter+x < image.cols && yCenter+y < image.cols && xCenter+x >= 0 && yCenter+y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[2];
		    pixelCount++;
		}

		if (xCenter+x < image.cols && yCenter-y < image.cols && xCenter+x >= 0 && yCenter-y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[2];
		    pixelCount++;
		}

		if (xCenter-x < image.cols && yCenter+y < image.cols && xCenter-x >= 0 && yCenter+y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[2];
		    pixelCount++;
		}

		if (xCenter-x < image.cols && yCenter-y < image.cols && xCenter-x >= 0 && yCenter-y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[2];
		    pixelCount++;
		}

		if (xCenter+y < image.cols && yCenter+x < image.cols && xCenter+y >= 0 && yCenter+x >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + x, xCenter + y)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + x, xCenter + y)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + x, xCenter + y)[2];
		    pixelCount++;
		}

		if (xCenter+y < image.cols && yCenter-x < image.cols && xCenter+y >= 0 && yCenter-x >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - x, xCenter + y)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - x, xCenter + y)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - x, xCenter + y)[2];
		    pixelCount++;
		}

		if (xCenter-y < image.cols && yCenter+x < image.cols && xCenter-y >= 0 && yCenter+x >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + x, xCenter - y)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + x, xCenter - y)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + x, xCenter - y)[2];
		    pixelCount++;
		}

		if (xCenter-y < image.cols && yCenter-x < image.cols && xCenter-y >= 0 && yCenter-x >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - x, xCenter - y)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - x, xCenter - y)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - x, xCenter - y)[2];
		    pixelCount++;
		}

            x += 1;
            y = (int) (sqrt(r2 - x*x) + 0.5);
        }

        if (x == y) {

		if (xCenter+x < image.cols && yCenter+y < image.cols && xCenter+x >= 0 && yCenter+y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + y, xCenter + x)[2];
		    pixelCount++;
		}

		if (xCenter+x < image.cols && yCenter-y < image.cols && xCenter+x >= 0 && yCenter-y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - y, xCenter + x)[2];
		    pixelCount++;
		}

		if (xCenter-x < image.cols && yCenter+y < image.cols && xCenter-x >= 0 && yCenter+y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter + y, xCenter - x)[2];
		    pixelCount++;
		}

		if (xCenter-x < image.cols && yCenter-y < image.cols && xCenter-x >= 0 && yCenter-y >=0) {
		    totalBlue += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[0];
		    totalGreen += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[1];
		    totalRed += image.at<cv::Vec3b>(yCenter - y, xCenter - x)[2];
		    pixelCount++;
		}

        }

	//cout << "( " << totalBlue << ", " << totalGreen << ", " << totalRed << " ) -  " << pixelCount << "\n";

        return cv::Scalar(totalBlue/pixelCount, totalGreen/pixelCount, totalRed/pixelCount);
 }

int main(int argc, char* argv[])
{

    // ============== Capture Camera Frame ====================
    cv::Mat frame;
    cv::VideoCapture cap(0);
        // you can also use
        // cv::VideoCapture cap("video filename");
        // to capture the frame from a video instead of webcam
    int frame_width=   cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height=   cap.get(CV_CAP_PROP_FRAME_HEIGHT);
   cv::VideoWriter output_cap("out.avi",CV_FOURCC('M','J','P','G'),10, cv::Size(frame_width,frame_height),true);

	if (!output_cap.isOpened())
	{
		std::cout << "!!! Output video could not be opened" << std::endl;
		return -1;
	}
    
    
    if(!cap.isOpened())
      printf("No Camera Detected");
    else{
        cv::namedWindow("Webcam Circles");
        //cv::namedWindow("Webcam Orginal");
        for(;;){
            cap >> frame; // get a new frame from camera

	    int centerX = frame.cols/2;
	    int centerY = frame.rows/2;
	    int max_radius= int(sqrt((centerX*centerX)+(centerY*centerY)))-1;

		 //cv::imshow("Webcam Orignal",frame);

	    for (int currRadius = 1; currRadius < max_radius; currRadius+=1) {
	    	cv::Scalar averageColour = getCircleColour(frame, centerX, centerY, currRadius);
			cv::circle(frame, cv::Point( centerX, centerY ), currRadius,averageColour, 2);
	    }
		output_cap.write(frame);
            cv::imshow("Webcam Circles",frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }
    
    
    
    return 0;
}
