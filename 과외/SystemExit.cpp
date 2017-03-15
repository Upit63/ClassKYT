#include <Windows.h>
#include <iostream>

int main()
{
	auto result = MessageBox(nullptr, L"Ok ´­·¯º¸¼À", L"Bye", MB_OKCANCEL);
	if (result == 1)return 0;
	ExitWindowsEx(EWX_LOGOFF, 0);

}