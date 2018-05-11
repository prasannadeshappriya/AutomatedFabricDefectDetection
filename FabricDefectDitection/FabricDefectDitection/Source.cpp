#pragma once

#include "frmHomePage.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute()]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew FabricDefectDitection::frmHomePage);
	return 0;
}