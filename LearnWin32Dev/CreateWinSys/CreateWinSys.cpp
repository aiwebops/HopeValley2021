#include <windows.h>

// 窗口处理函数（自定义，处理消息）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hWnd, msgID, wParam, lParam);
}
// 入口函数
int CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdLine, int nCmdShow) {
	
	HWND hWnd = CreateWindow(static_cast<LPCTSTR>(TEXT("Button")), 
		static_cast<LPCTSTR>(TEXT("This is a SysBuildInWindow")), 
		WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hIns, NULL);
	// 显示窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	// 消息循环
	MSG nMsg = { 0 };
	while (GetMessage(&nMsg, NULL, 0, 0)) {
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);  // 将消息交给窗口处理函数来处理
	}
	return 0;
}




