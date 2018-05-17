#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <msclr/marshal.h>

ref class Iprocess
{
public:
	Iprocess();

	cv::Size getCustomResolution(cv::Mat image);
	cv::Mat openImage(cv::Mat image);
	cv::Mat applyMorphology(int _morph_elem, int _morph_size, int _morph_operator, cv::Mat image);
	cv::Mat processImage(cv::Mat image, int _morphArgs[], int _thresholdArgs[], int _operation,
		System::Windows::Forms::Control^ display);
	cv::Mat openImage(System::String^ filename);
	cv::Mat applyThreshold(int _type, int _value, cv::Mat image);

	void displayFrame(cv::Mat frame, System::Windows::Forms::Control^ display);
	void startProcess(cv::Mat frame, System::Windows::Forms::Control^ display);
	void saveImage();

	//cv::Mat _image;
};

