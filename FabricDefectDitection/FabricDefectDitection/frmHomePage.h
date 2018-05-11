#pragma once

namespace FabricDefectDitection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmHomePage
	/// </summary>
	public ref class frmHomePage : public System::Windows::Forms::Form
	{
	public:
		frmHomePage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmHomePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::Label^  lblFileName;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::PictureBox^  pbPreviewWindow;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::PictureBox^  pbWindow;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::CheckBox^  chkThresholding;
	private: System::Windows::Forms::TrackBar^  tbThreshType;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TrackBar^  tbThreshValue;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::CheckBox^  chkMorphology;
	private: System::Windows::Forms::TrackBar^  tbMorpElement;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  tbMorpOperator;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TrackBar^  tbMorpKernel;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  bnSave;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->lblFileName = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pbPreviewWindow = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pbWindow = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbThreshValue = (gcnew System::Windows::Forms::TrackBar());
			this->tbThreshType = (gcnew System::Windows::Forms::TrackBar());
			this->chkThresholding = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tbMorpKernel = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbMorpOperator = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbMorpElement = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chkMorphology = (gcnew System::Windows::Forms::CheckBox());
			this->bnSave = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPreviewWindow))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWindow))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshType))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpKernel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpOperator))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpElement))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(1277, 25);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(101, 36);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Open";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &frmHomePage::btnOpen_Click);
			// 
			// lblFileName
			// 
			this->lblFileName->Location = System::Drawing::Point(21, 23);
			this->lblFileName->Name = L"lblFileName";
			this->lblFileName->Size = System::Drawing::Size(1229, 45);
			this->lblFileName->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblFileName);
			this->groupBox1->Controls->Add(this->btnOpen);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1419, 84);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"File";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pbPreviewWindow);
			this->groupBox2->Location = System::Drawing::Point(13, 242);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(603, 554);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Original Image";
			// 
			// pbPreviewWindow
			// 
			this->pbPreviewWindow->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pbPreviewWindow->Location = System::Drawing::Point(23, 30);
			this->pbPreviewWindow->Name = L"pbPreviewWindow";
			this->pbPreviewWindow->Size = System::Drawing::Size(561, 498);
			this->pbPreviewWindow->TabIndex = 0;
			this->pbPreviewWindow->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pbWindow);
			this->groupBox3->Location = System::Drawing::Point(628, 242);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(593, 554);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Preview";
			// 
			// pbWindow
			// 
			this->pbWindow->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pbWindow->Location = System::Drawing::Point(17, 30);
			this->pbWindow->Name = L"pbWindow";
			this->pbWindow->Size = System::Drawing::Size(561, 507);
			this->pbWindow->TabIndex = 0;
			this->pbWindow->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label2);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->tbThreshValue);
			this->groupBox4->Controls->Add(this->tbThreshType);
			this->groupBox4->Controls->Add(this->chkThresholding);
			this->groupBox4->Location = System::Drawing::Point(13, 109);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(509, 127);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Panel";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(194, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Value:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(198, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Type:";
			// 
			// tbThreshValue
			// 
			this->tbThreshValue->Location = System::Drawing::Point(275, 54);
			this->tbThreshValue->Maximum = 255;
			this->tbThreshValue->Name = L"tbThreshValue";
			this->tbThreshValue->Size = System::Drawing::Size(211, 56);
			this->tbThreshValue->TabIndex = 3;
			this->tbThreshValue->Value = 100;
			this->tbThreshValue->Scroll += gcnew System::EventHandler(this, &frmHomePage::tbThreshValue_Scroll);
			// 
			// tbThreshType
			// 
			this->tbThreshType->Location = System::Drawing::Point(275, 21);
			this->tbThreshType->Maximum = 4;
			this->tbThreshType->Name = L"tbThreshType";
			this->tbThreshType->Size = System::Drawing::Size(211, 56);
			this->tbThreshType->TabIndex = 3;
			this->tbThreshType->Scroll += gcnew System::EventHandler(this, &frmHomePage::tbThreshType_Scroll);
			// 
			// chkThresholding
			// 
			this->chkThresholding->AutoSize = true;
			this->chkThresholding->Location = System::Drawing::Point(33, 42);
			this->chkThresholding->Name = L"chkThresholding";
			this->chkThresholding->Size = System::Drawing::Size(113, 21);
			this->chkThresholding->TabIndex = 0;
			this->chkThresholding->Text = L"Thresholding";
			this->chkThresholding->UseVisualStyleBackColor = true;
			this->chkThresholding->CheckedChanged += gcnew System::EventHandler(this, &frmHomePage::chkThresholding_CheckedChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tbMorpKernel);
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->tbMorpOperator);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->tbMorpElement);
			this->groupBox5->Controls->Add(this->label3);
			this->groupBox5->Controls->Add(this->chkMorphology);
			this->groupBox5->Location = System::Drawing::Point(534, 109);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(897, 127);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Panel";
			// 
			// tbMorpKernel
			// 
			this->tbMorpKernel->Location = System::Drawing::Point(654, 20);
			this->tbMorpKernel->Maximum = 21;
			this->tbMorpKernel->Name = L"tbMorpKernel";
			this->tbMorpKernel->Size = System::Drawing::Size(211, 56);
			this->tbMorpKernel->TabIndex = 9;
			this->tbMorpKernel->Scroll += gcnew System::EventHandler(this, &frmHomePage::tbMorpKernel_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(547, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Kernel Size:";
			// 
			// tbMorpOperator
			// 
			this->tbMorpOperator->Location = System::Drawing::Point(282, 55);
			this->tbMorpOperator->Maximum = 4;
			this->tbMorpOperator->Name = L"tbMorpOperator";
			this->tbMorpOperator->Size = System::Drawing::Size(211, 56);
			this->tbMorpOperator->TabIndex = 7;
			this->tbMorpOperator->Scroll += gcnew System::EventHandler(this, &frmHomePage::tbMorpOperator_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(182, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Operator:";
			// 
			// tbMorpElement
			// 
			this->tbMorpElement->Location = System::Drawing::Point(282, 21);
			this->tbMorpElement->Maximum = 2;
			this->tbMorpElement->Name = L"tbMorpElement";
			this->tbMorpElement->Size = System::Drawing::Size(211, 56);
			this->tbMorpElement->TabIndex = 5;
			this->tbMorpElement->Scroll += gcnew System::EventHandler(this, &frmHomePage::tbMorpElement_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(188, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Element:";
			// 
			// chkMorphology
			// 
			this->chkMorphology->AutoSize = true;
			this->chkMorphology->Location = System::Drawing::Point(33, 42);
			this->chkMorphology->Name = L"chkMorphology";
			this->chkMorphology->Size = System::Drawing::Size(104, 21);
			this->chkMorphology->TabIndex = 0;
			this->chkMorphology->Text = L"Morphology";
			this->chkMorphology->UseVisualStyleBackColor = true;
			this->chkMorphology->CheckedChanged += gcnew System::EventHandler(this, &frmHomePage::chkMorphology_CheckedChanged);
			// 
			// bnSave
			// 
			this->bnSave->Location = System::Drawing::Point(1242, 248);
			this->bnSave->Name = L"bnSave";
			this->bnSave->Size = System::Drawing::Size(168, 35);
			this->bnSave->TabIndex = 7;
			this->bnSave->Text = L"Save";
			this->bnSave->UseVisualStyleBackColor = true;
			this->bnSave->Click += gcnew System::EventHandler(this, &frmHomePage::bnSave_Click);
			// 
			// frmHomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1447, 876);
			this->Controls->Add(this->bnSave);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmHomePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmHomePage";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPreviewWindow))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWindow))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshType))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpKernel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpOperator))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbMorpElement))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void openImage();
		System::Void applyMorphology(int _morph_elem, int _morph_size, int _morph_operator);
		System::Void applyThreshold(int _type, int _value);
		System::Void tbThreshType_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void tbThreshValue_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void chkThresholding_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void chkMorphology_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void tbMorpElement_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void tbMorpOperator_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void tbMorpKernel_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void bnSave_Click(System::Object^  sender, System::EventArgs^  e);
};
}
