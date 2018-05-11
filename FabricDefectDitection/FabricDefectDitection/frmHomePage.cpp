#include <iostream>
#include <fstream>
#include <msclr/marshal.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Windows.h>

#include "frmHomePage.h"

using namespace cv;
using namespace std;
using namespace System::Runtime::InteropServices;

bool is_file_exist(System::String^ fileName);
cv::Size getCustomResolution(Mat image);
Mat _image;

ref class FilePathString {
public:
	static System::String^ filename;
};

System::Void  FabricDefectDitection::frmHomePage::btnOpen_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Filter = "jpg files (*.jpg)|*.jpg|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		FilePathString::filename = openFileDialog1->FileName;
		lblFileName->Text = FilePathString::filename;
		if (is_file_exist(FilePathString::filename)) {
			openImage();
		}
		else {
			MessageBox::Show("Unable to open the selected file, Please try again!");
		}
	}
}

System::Void FabricDefectDitection::frmHomePage::openImage()
{
	const char* filestream = (const char*)(void*)
		Marshal::StringToHGlobalAnsi(FilePathString::filename);
	Mat image;
	image = imread(filestream, IMREAD_COLOR); 

	if (image.empty())                      
	{
		MessageBox::Show("Could not open or find the image \nFile: " + FilePathString::filename);
		return;
	}
	
	try {
		resize(image, image, getCustomResolution(image));

		this->pbPreviewWindow->Width = image.size().width;
		this->pbPreviewWindow->Height = image.size().height;

		this->pbPreviewWindow->BackgroundImage = gcnew System::Drawing::Bitmap(
			image.size().width,
			image.size().height,
			image.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			(IntPtr)image.data);

		this->pbPreviewWindow->Refresh();
		Application::DoEvents();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->ToString(), "Fabric Defect Ditection",
			MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}

cv::Size getCustomResolution(Mat image) {
	int picHight = image.size().height;
	int picWidth = image.size().width;
	int newHight = 400;
	int newWidth = (picWidth * newHight) / picHight;
	if (newWidth < 280) { newWidth = 280; }
	cv::Size size(newWidth, newHight);
	return size;
}

System::Void FabricDefectDitection::frmHomePage::tbThreshType_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		this->applyThreshold(tbThreshType->Value, tbThreshValue->Value);
	}
}

System::Void FabricDefectDitection::frmHomePage::tbThreshValue_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		this->applyThreshold(tbThreshType->Value, tbThreshValue->Value);
	}
}

System::Void FabricDefectDitection::frmHomePage::chkThresholding_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		this->applyThreshold(tbThreshType->Value, tbThreshValue->Value);
		chkMorphology->Checked = false;
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpElement_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		this->applyMorphology(tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value);
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpOperator_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		this->applyMorphology(tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value);
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpKernel_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		this->applyMorphology(tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value);
	}
}

System::Void FabricDefectDitection::frmHomePage::applyThreshold(int _type, int _value) {
	try {
		int threshold_value = _value;
		int threshold_type = _type;
		int const max_value = 255;
		int const max_type = 4;
		int const max_BINARY_value = 255;

		const char* filestream = (const char*)(void*)
			Marshal::StringToHGlobalAnsi(FilePathString::filename);
		Mat image;
		image = imread(filestream, IMREAD_COLOR);

		if (image.empty())
		{
			MessageBox::Show("Could not open or find the image \nFile: " + FilePathString::filename);
			return;
		}

		cvtColor(image, image, COLOR_BGR2GRAY);

		/* 0: Binary [CV_THRESH_BINARY]
		1: Binary Inverted
		2: Threshold Truncated
		3: Threshold to Zero
		4: Threshold to Zero Inverted
		*/
		threshold(image, image, threshold_value, max_BINARY_value, threshold_type);

		cvtColor(image, image, COLOR_GRAY2RGB);
		resize(image, image, getCustomResolution(image));

		this->pbWindow->BackgroundImage = gcnew System::Drawing::Bitmap(
			image.size().width,
			image.size().height,
			image.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			(IntPtr)image.data);
		this->pbWindow->Width = image.size().width;
		this->pbWindow->Height = image.size().height;

		this->pbWindow->Refresh();
		Application::DoEvents();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Error: " + ex->ToString());
	}
}

System::Void FabricDefectDitection::frmHomePage::applyMorphology(
	int _morph_elem, int _morph_size, int _morph_operator) {
	try {
		//Element:
		//0: Rect 
		//1 : Cross 
		//2 : Ellipse
		int morph_elem = _morph_elem;

		//Kernel size:
		//(2n +1)
		int morph_size = _morph_size;

		//Operator:
		//0: Opening 
		//1: Closing 
		//2: Gradient 
		//3: Top Hat 
		//4: Black Hat
		int morph_operator = _morph_operator;

		int const max_operator = 4;
		int const max_elem = 2;
		int const max_kernel_size = 21;

		const char* filestream = (const char*)(void*)
			Marshal::StringToHGlobalAnsi(FilePathString::filename);
		Mat image;
		image = imread(filestream, IMREAD_COLOR);

		if (image.empty())
		{
			MessageBox::Show("Could not open or find the image \nFile: " + FilePathString::filename);
			return;
		}

		// Since MORPH_X : 2,3,4,5 and 6
		int operation = morph_operator + 2;

		//calculate kernel (2n+1)
		int kernel = 2 * morph_size + 1;
		Mat element = getStructuringElement(morph_elem,
			cv::Size(kernel, kernel), cv::Point(morph_size, morph_size));

		/// Apply the specified morphology operation
		morphologyEx(image, image, operation, element);

		resize(image, image, getCustomResolution(image));
		_image = image;

		this->pbWindow->BackgroundImage = gcnew System::Drawing::Bitmap(
			image.size().width,
			image.size().height,
			image.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			(IntPtr)image.data);
		this->pbWindow->Width = image.size().width;
		this->pbWindow->Height = image.size().height;

		this->pbWindow->Refresh();
		Application::DoEvents();
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Error: " + ex->ToString());
	}
}

System::Void FabricDefectDitection::frmHomePage::bnSave_Click(System::Object^  sender, System::EventArgs^  e)
{
	imwrite("G:/test.jpg", _image);
}

System::Void FabricDefectDitection::frmHomePage::chkMorphology_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		this->applyMorphology(tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value);
		chkThresholding->Checked = false;
	}
}

bool is_file_exist(System::String^ fileName)
{
	const char* filestream = (const char*)(void*)
		Marshal::StringToHGlobalAnsi(fileName);
	std::ifstream file(filestream);
	return file.good();
}
