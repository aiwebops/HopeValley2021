#include <Windows.h>
#include <stdio.h>

using namespace std;

void C_char() {
	const char* pszText = "Hello char.";
	int len = strlen(pszText);
	printf("%s %d\n", pszText, len);
	return;
}

void W_char() {
	const wchar_t* pszText = L"Hello wchar.";
	int len = wcslen(pszText);
	wprintf(L"%s %d\n", pszText, len);
	return;
}

void T_char() {
	const TCHAR* pszText = __TEXT("Hello wchar.");
	// int len = wcslen(pszText);
#ifdef UNICODE
	wprintf(L"%s\n", pszText);
#else
	printf("%s\n", pszText);
#endif // !UNICODE	
	return;
}

void PrintUnicode() {
	const TCHAR* pszText = __TEXT("∑…—©¡¨ÃÏ…‰±Ã‘ß");
	// wprintf(L"%s\n", pszText);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int strLen = lstrlen(pszText);
	WriteConsole(hOut, pszText, strLen, NULL, NULL);
	return;
}

int main() {
	C_char();
	W_char();
	T_char();
	PrintUnicode();
	int inputChar = getchar();
	return 0;
}
