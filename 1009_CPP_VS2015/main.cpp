#include "UserInterfaceForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My1009_CPP_VS2015::UserInterfaceForm form;
	Application::Run(%form);
	return 0;
}