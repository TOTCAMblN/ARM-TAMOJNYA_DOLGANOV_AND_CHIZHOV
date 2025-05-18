#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) 
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ProjectScaner::MyForm form;
	Application::Run(% form);
}