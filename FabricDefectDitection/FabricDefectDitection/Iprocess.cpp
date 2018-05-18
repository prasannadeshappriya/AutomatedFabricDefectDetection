#include "Iprocess.h"	

using System::Windows::Forms::MessageBox;
using System::Windows::Forms::MessageBoxButtons;
using System::Windows::Forms::MessageBoxIcon;
using System::Windows::Forms::Application;
using namespace System::Runtime::InteropServices;

Iprocess::Iprocess(){}
cv::Mat _image;

void Iprocess::startProcess(cv::Mat frame, System::Windows::Forms::Control^ display)
{
	int MIN = 0;
	int errorFlag = 1800;
	//processImage()
	//_morphArgs: 0-> _morph_elem, 1-> _morph_size, 2-> _morph_operator
	//_thresholdArgs: 0-> _type, 1-> _value
	//Operation; 0: Show, 1: Mophalogy, 2: Thresholding,
	cv::Mat resultFrame, tmpFrame, grayScaleFrame;

	tmpFrame = frame;
	int count, t_count, image_size;

	//Process 01;
	int threshArgs[] = { 0,218};
	frame = this->processImage(frame, NULL, threshArgs, 2, display);
	int morphArgs[] = { 0,3,0 };
	frame = this->processImage(frame, morphArgs, NULL, 1, display);
	morphArgs[1] = 2;
	frame = this->processImage(frame, morphArgs, NULL, 1, display);
	grayScaleFrame = cv::Mat();
	cv::cvtColor(frame, grayScaleFrame, CV_BGR2GRAY);
	t_count = 0;
	t_count = cv::countNonZero(grayScaleFrame);
	t_count = (grayScaleFrame.cols * grayScaleFrame.rows) - t_count;
	image_size = (grayScaleFrame.cols * grayScaleFrame.rows) - errorFlag;
	if (count < t_count && t_count > MIN && t_count < image_size) {
		count = t_count;
		resultFrame = frame;
	}

	//Process 02;
	frame = tmpFrame;
	morphArgs[0] = 0;
	morphArgs[2] = 1;
	morphArgs[1] = 2;
	frame = this->processImage(frame, morphArgs, NULL, 1, display);
	threshArgs[1] = 179;
	frame = this->processImage(frame, NULL, threshArgs, 2, display);
	morphArgs[0] = 1; 
	morphArgs[2] = 2; 
	morphArgs[1] = 3;
	frame = this->processImage(frame, morphArgs, NULL, 1, display);
	grayScaleFrame = cv::Mat();
	cv::cvtColor(frame, grayScaleFrame, CV_BGR2GRAY);
	t_count = cv::countNonZero(grayScaleFrame);
	t_count = (grayScaleFrame.cols * grayScaleFrame.rows) - t_count;
	image_size = (grayScaleFrame.cols * grayScaleFrame.rows) - errorFlag;
	if (count < t_count && t_count > MIN && t_count < image_size) {
		count = t_count;
		resultFrame = frame;
	}

	//Process 03;
	frame = tmpFrame;
	morphArgs[0] = 0;
	morphArgs[2] = 1;
	morphArgs[1] = 2;
	frame = this->processImage(frame, morphArgs, NULL, 1, display);

	threshArgs[1] = 202;
	frame = this->processImage(frame, NULL, threshArgs, 2, display);

	morphArgs[0] = 0;
	morphArgs[2] = 2;
	morphArgs[1] = 3;
	frame = this->processImage(frame, morphArgs, NULL, 1, display);

	threshArgs[1] = 100;
	threshArgs[0] = 1;
	frame = this->processImage(frame, NULL, threshArgs, 2, display);
	
	grayScaleFrame = cv::Mat();
	cv::cvtColor(frame, grayScaleFrame, CV_BGR2GRAY);
	t_count = 0;
	t_count = cv::countNonZero(grayScaleFrame);
	t_count = (grayScaleFrame.cols * grayScaleFrame.rows) - t_count;
	image_size = (grayScaleFrame.cols * grayScaleFrame.rows) - errorFlag;
	if (count < t_count && t_count > MIN && t_count < image_size) {
		count = t_count;
		resultFrame = frame;
	}

	this->displayFrame(resultFrame, display);
}

cv::Size Iprocess::getCustomResolution(cv::Mat image)
{
	int picHight = image.size().height;
	int picWidth = image.size().width;
	int newHight = 400;
	int newWidth = (picWidth * newHight) / picHight;
	if (newWidth < 280) { newWidth = 280; }
	cv::Size size(newWidth, newHight);
	return size;
}

cv::Mat Iprocess::openImage(cv::Mat image)
{
	try {
		resize(image, image, getCustomResolution(image));
		return image;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->ToString(), "Fabric Defect Ditection",
			MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}

void Iprocess::displayFrame(
	cv::Mat frame, System::Windows::Forms::Control^ display) {
	display->BackgroundImage = gcnew System::Drawing::Bitmap(
		frame.size().width,
		frame.size().height,
		frame.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb,
		(System::IntPtr)frame.data);
	display->Width = frame.size().width;
	display->Height = frame.size().height;

	display->Refresh();
	Application::DoEvents();
}

cv::Mat Iprocess::openImage(System::String^ filename)
{
	const char* filestream = (const char*)(void*)
		Marshal::StringToHGlobalAnsi(filename);
	cv::Mat image;
	image = imread(filestream, cv::IMREAD_COLOR);

	if (image.empty())
	{
		MessageBox::Show("Could not open or find the image \nFile: " + filename);
		return image;
	}

	return image;
}

cv::Mat Iprocess::processImage(
	cv::Mat image,
	int _morphArgs[], int _thresholdArgs[], int _operation,
	System::Windows::Forms::Control^ display) {
	//_morphArgs: 0-> _morph_elem, 1-> _morph_size, 2-> _morph_operator
	//_thresholdArgs: 0-> _type, 1-> _value
	//Operation; 0: Show, 1: Mophalogy, 2: Thresholding

	if (_operation == 0) {
		resize(image, image, getCustomResolution(image));
		this->displayFrame(image, display);
		return image;
	}

	if (_operation == 1) {
		image = this->applyMorphology(_morphArgs[0], _morphArgs[1], _morphArgs[2], image);
		this->displayFrame(image, display);
		_image = image;
		return image;
	}

	if (_operation == 2) {
		image = this->applyThreshold(_thresholdArgs[0], _thresholdArgs[1], image);
		this->displayFrame(image, display);
		_image = image;
		return image;
	}

	return image;
}

void Iprocess::saveImage()
{
	cv::imwrite("G:/test.jpg", _image);
}

cv::Mat Iprocess::applyMorphology(
	int _morph_elem, int _morph_size, int _morph_operator, cv::Mat image) {
	try {
		//Element:
		//0: Rect, 1 : Cross, 2 : Ellipse
		int morph_elem = _morph_elem;

		
		//Kernel size:
		//(2n +1)
		int morph_size = _morph_size;

		//Operator:
		//0: Opening, 1: Closing, 2: Gradient, 3: Top Hat, 4: Black Hat
		int morph_operator = _morph_operator;

		int const max_operator = 4;
		int const max_elem = 2;
		int const max_kernel_size = 21;

		// Since MORPH_X : 2,3,4,5 and 6
		int operation = morph_operator + 2;

		//calculate kernel (2n+1)
		int kernel = 2 * morph_size + 1;
		cv::Mat element = getStructuringElement(morph_elem,
			cv::Size(kernel, kernel), cv::Point(morph_size, morph_size));

		// Apply the specified morphology operation
		morphologyEx(image, image, operation, element);

		resize(image, image, getCustomResolution(image));

		//return
		return image;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Error: " + ex->ToString());
	}
}

cv::Mat Iprocess::applyThreshold(int _type, int _value, cv::Mat image) {
	try {
		int threshold_value = _value;
		int threshold_type = _type;
		int const max_value = 255;
		int const max_type = 4;
		int const max_BINARY_value = 255;

		cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

		/* 0: Binary [CV_THRESH_BINARY]
		1: Binary Inverted
		2: Threshold Truncated
		3: Threshold to Zero
		4: Threshold to Zero Inverted
		*/
		
		threshold(image, image, threshold_value, max_BINARY_value, threshold_type);

		//adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C);
		//cv::adaptiveThreshold(image, image, max_value, cv::ADAPTIVE_THRESH_GAUSSIAN_C, threshold_type, 20, 2);

		cvtColor(image, image, cv::COLOR_GRAY2RGB);
		resize(image, image, getCustomResolution(image));

		return image;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Error: " + ex->ToString());
	}
}





