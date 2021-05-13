#include <Windows.h>
#include "Student.h"

using namespace CursprojectGovorov;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyFormStudent());
}