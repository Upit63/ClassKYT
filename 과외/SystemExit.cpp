#include <Windows.h>
#include <iostream>

int main()
{
	auto result = MessageBox(nullptr, L"Ok ��������", L"Bye", MB_OKCANCEL);
	if (result == 1)return 0;
	ExitWindowsEx(EWX_LOGOFF, 0);

}