#include <iostream>
#include <fstream>
#include <msclr/marshal.h>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Windows.h>

#include "frmHomePage.h"

using namespace std;
using namespace System::Runtime::InteropServices;

bool is_file_exist(System::String^ fileName);

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
			ipModule.processImage(
				ipModule.openImage(FilePathString::filename),
				NULL, NULL, 0, this->pbPreviewWindow);
		}
		else {
			MessageBox::Show("Unable to open the selected file, Please try again!");
		}
	}
}

bool is_file_exist(System::String^ fileName)
{
	const char* filestream = (const char*)(void*)
		Marshal::StringToHGlobalAnsi(fileName);
	std::ifstream file(filestream);
	return file.good();
}

System::Void FabricDefectDitection::frmHomePage::tbThreshType_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		int args[] = { tbThreshType->Value, tbThreshValue->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			NULL, args, 2, this->pbWindow);
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::btnProcess_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->ipModule.startProcess(
		ipModule.openImage(FilePathString::filename), this->pbWindow);
}

System::Void FabricDefectDitection::frmHomePage::tbThreshValue_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		int args[] = { tbThreshType->Value, tbThreshValue->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			NULL, args, 2, this->pbWindow);
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::chkThresholding_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkThresholding->Checked) {
		int args[] = { tbThreshType->Value, tbThreshValue->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			NULL, args, 2, this->pbWindow);
		chkMorphology->Checked = false;
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpElement_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		int args[] = { tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			args, NULL, 1, this->pbWindow);
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpOperator_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		int args[] = { tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			args, NULL, 1, this->pbWindow);
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::tbMorpKernel_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		int args[] = { tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			args, NULL, 1, this->pbWindow);
		this->refresh();
	}
}

System::Void FabricDefectDitection::frmHomePage::refresh()
{
	this->label6->Text = "Element: " + tbMorpElement->Value.ToString();
	this->label7->Text = "Operator: " + tbMorpOperator->Value.ToString();
	this->label8->Text = "Keral Size: " + tbMorpKernel->Value.ToString();

	this->label9->Text = "Type: " + tbThreshType->Value.ToString();
	this->label10->Text = "Value: " + tbThreshValue->Value.ToString();
}

System::Void FabricDefectDitection::frmHomePage::bnSave_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->ipModule.saveImage();
}

System::Void FabricDefectDitection::frmHomePage::chkMorphology_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkMorphology->Checked) {
		int args[] = { tbMorpElement->Value, tbMorpKernel->Value, tbMorpOperator->Value };
		ipModule.processImage(
			ipModule.openImage(FilePathString::filename),
			args, NULL, 1, this->pbWindow);
		chkThresholding->Checked = false;
	}
}


