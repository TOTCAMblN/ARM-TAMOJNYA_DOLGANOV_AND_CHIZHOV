#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>

namespace ProjectScaner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnMain;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ labelResult;

	private: System::Windows::Forms::Label^ labelBaggage;


	private: System::Windows::Forms::Label^ labelDocs;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnMain = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->labelBaggage = (gcnew System::Windows::Forms::Label());
			this->labelDocs = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnMain
			// 
			this->btnMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnMain->Location = System::Drawing::Point(10, 300);
			this->btnMain->Name = L"btnMain";
			this->btnMain->Size = System::Drawing::Size(380, 122);
			this->btnMain->TabIndex = 0;
			this->btnMain->Text = L"��������� �������";
			this->btnMain->UseVisualStyleBackColor = false;
			this->btnMain->Click += gcnew System::EventHandler(this, &MyForm::btnMain_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(380, 281);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(400, 10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(380, 281);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Font = (gcnew System::Drawing::Font(L"Roboto SemiCondensed", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelResult->Location = System::Drawing::Point(430, 392);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(84, 20);
			this->labelResult->TabIndex = 3;
			this->labelResult->Text = L"���������:";
			this->labelResult->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// labelBaggage
			// 
			this->labelBaggage->AutoSize = true;
			this->labelBaggage->Font = (gcnew System::Drawing::Font(L"Roboto SemiCondensed", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBaggage->Location = System::Drawing::Point(430, 353);
			this->labelBaggage->Name = L"labelBaggage";
			this->labelBaggage->Size = System::Drawing::Size(48, 20);
			this->labelBaggage->TabIndex = 4;
			this->labelBaggage->Text = L"����:";
			// 
			// labelDocs
			// 
			this->labelDocs->AutoSize = true;
			this->labelDocs->Font = (gcnew System::Drawing::Font(L"Roboto SemiCondensed", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDocs->Location = System::Drawing::Point(430, 317);
			this->labelDocs->Name = L"labelDocs";
			this->labelDocs->Size = System::Drawing::Size(96, 20);
			this->labelDocs->TabIndex = 5;
			this->labelDocs->Text = L"���������:";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(792, 433);
			this->Controls->Add(this->labelDocs);
			this->Controls->Add(this->labelBaggage);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnMain);
			this->Font = (gcnew System::Drawing::Font(L"Roboto SemiCondensed", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������������� �������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: void LoadImageWithoutLocking(System::Windows::Forms::PictureBox^ pictureBox,const std::string& imagePath) {
			try {
				System::String^ managedPath = gcnew System::String(imagePath.c_str());

				// ��������� ���� � ������ ������ ��� ����������
				System::IO::FileStream^ fs = gcnew System::IO::FileStream(
					managedPath,
					System::IO::FileMode::Open,
					System::IO::FileAccess::Read,
					System::IO::FileShare::Read // ��������� ������ ��������� ������ ����
				);

				// ������� ����������� �� ������
				System::Drawing::Image^ image = System::Drawing::Image::FromStream(fs);
				fs->Close(); // ��������� ����� ����� ��������

				pictureBox->Image = image;
			}
			catch (System::IO::FileNotFoundException^ ex) {
				MessageBox::Show("���� �� ������: " + ex->Message);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������: " + ex->Message);
			}
	}

	private: bool RunExeAndGetExitCode(const char* exePath, const char* workDir, DWORD& exitCode) {
		STARTUPINFO si = { sizeof(STARTUPINFO) };
		PROCESS_INFORMATION pi;

		if (!CreateProcessA(
			NULL,                   // ������ (����������� � ��������� ������)
			(LPSTR)exePath,         // ��������� ������ (��-const)
			NULL,                   // ��������� �������� �� �����������
			NULL,                   // ��������� ������ �� �����������
			FALSE,                  // �� ����������� �����������
			0,                      // ����� ��������
			NULL,                   // ��������� (��� � ��������)
			workDir,                   // ������� ����������
			(LPSTARTUPINFOA)&si,                   // STARTUPINFO
			&pi                     // PROCESS_INFORMATION
		)) {
			std::cerr << "CreateProcess failed: " << GetLastError() << std::endl;
			return false;
		}

		WaitForSingleObject(pi.hProcess, INFINITE);
		GetExitCodeProcess(pi.hProcess, &exitCode);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		return true;
	}

	private: System::Boolean checkDocs() {
		const char* exePath = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\x64\\Release\\projectBigMachine.exe";
		const char* workDir = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine";
		DWORD exitCode = 1; 

		if (RunExeAndGetExitCode(exePath,workDir, exitCode)) {
			if (exitCode == DWORD(0)) {
				labelDocs->Text = "���������: ������ ��������";
				labelDocs->BackColor = System::Drawing::Color::LightGreen;
				return true;
			}
			else {
				labelDocs->Text = "���������: �� ������ ��������";
				labelDocs->BackColor = System::Drawing::Color::Red;
				return false;
			}
		}
		else {
			labelDocs->Text = "������ ������� �������� ����������";
			labelDocs->BackColor = System::Drawing::Color::Red;
			return false;
		}
	}
	private: bool checkBaggage() {

		try {
			auto processInfo = gcnew System::Diagnostics::ProcessStartInfo();
			processInfo->FileName = "python";           // ������� ��� ���� � python.exe
			processInfo->Arguments = "test.py";         // ������
			processInfo->UseShellExecute = false;       // �� ������������ �������� Windows
			processInfo->CreateNoWindow = true;         // �� ���������� ����!
			processInfo->RedirectStandardOutput = true; // ����� ������ ����� (�����������)

			auto process = System::Diagnostics::Process::Start(processInfo);
			process->WaitForExit(); // ��� ����������

			if ((process->ExitCode == 0)) {
				labelBaggage->Text = "�������: ������ ��������";
				labelBaggage->BackColor = System::Drawing::Color::LightGreen;
			}
			else {
				labelBaggage->Text = "�������: �� ������ ��������";
				labelBaggage->BackColor = System::Drawing::Color::Red;
			}

			std::string imagePath1 = "C:\\Users\\LENOVO\\source\\repos\\ProjectScaner\\ProjectScaner\\test.png"; // ���� � ������ JPG �����
			LoadImageWithoutLocking(pictureBox1, imagePath1);

			std::string imagePath2 = "C:\\Users\\LENOVO\\source\\repos\\ProjectScaner\\ProjectScaner\\test_pred.png"; // ���� � ������ JPG �����
			LoadImageWithoutLocking(pictureBox2, imagePath2);

			return (process->ExitCode == 0);

		}
		catch (...) {
			return false;
		}
	}
	private: System::Boolean giveResult() {
		const char* exePath = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\x64\\Release\\projectBigMachine.exe";
		const char* workDir = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine";
		DWORD exitCode = 1;

		if (!RunExeAndGetExitCode(exePath, workDir, exitCode)) {
			labelDocs->Text = "������ ������� �������� ����������";
			labelDocs->BackColor = System::Drawing::Color::Red;
			labelBaggage->Text = "������ ������� �������";
			labelBaggage->BackColor = System::Drawing::Color::Red;
			return false;
		}

		if (exitCode == 0) {
			// �� ������: ��������� � ������� ��
			labelDocs->Text = "���������: ���������";
			labelDocs->BackColor = System::Drawing::Color::LightGreen;

			labelBaggage->Text = "�������: ������� �������� �� ����������";
			labelBaggage->BackColor = System::Drawing::Color::LightGreen;

			std::string imagePath1 = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner.png";;
			std::string imagePath2 = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner_pred.png";

			LoadImageWithoutLocking(pictureBox1, imagePath1);
			LoadImageWithoutLocking(pictureBox2, imagePath2);

			return true;
		}
		else if (exitCode == 1) {
			// ��������� ������, �� ������� �������� ������
			labelDocs->Text = "���������: ���������";
			labelDocs->BackColor = System::Drawing::Color::LightGreen;

			labelBaggage->Text = "�������: ���������� ������� �������";
			labelBaggage->BackColor = System::Drawing::Color::Red;

			std::string imagePath1 = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner.png";
			std::string imagePath2 = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner_pred.png";

			LoadImageWithoutLocking(pictureBox1, imagePath1);
			LoadImageWithoutLocking(pictureBox2, imagePath2);

			return false;
		}
		else if (exitCode == 2) {
			// ��������� �� ������
			labelDocs->Text = "���������: �� ������ ��������";
			labelDocs->BackColor = System::Drawing::Color::Red;

			labelBaggage->Text = "�������: �������� �� �����������";
			labelBaggage->BackColor = System::Drawing::Color::Red;

			// �� ��������� �����������
			pictureBox1->Image = nullptr;
			pictureBox2->Image = nullptr;

			return false;
		}
		else {
			labelDocs->Text = "����������� ��� ��������: " + exitCode;
			labelDocs->BackColor = System::Drawing::Color::Red;
			return false;
		}
	}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnMain_Click(System::Object^ sender, System::EventArgs^ e) {
		if (giveResult() == true) {
			labelResult->Text = "���������: ������� ��������";
			labelResult->BackColor = System::Drawing::Color::LightGreen;
		}
		else {
			labelResult->Text = "���������: ������� �� ��������";
			labelResult->BackColor = System::Drawing::Color::Red;
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
