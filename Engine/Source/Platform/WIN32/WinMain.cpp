#include "Engine.h"
//Global Variables//
#pragma region GlobalVariables
	WCHAR WindowClass[MAX_NAME_STRING];
	WCHAR WindowTitle[MAX_NAME_STRING];

	INT WindowWidth;
	INT WindowHeight;

	HICON hIcon;
#pragma endregion

//Windows Operations//
#pragma region Operations
	LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam) {
		switch (message) 
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
		}

		return DefWindowProc(hWnd, message, wparam, lparam);
	}


	////no names since defined above, or not needed
	//int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR , INT) //hInstance hPrevInstance, lpCmdLine, nCmdChow
	//{
	//	IntializesVariables();
	//	CreateWindowClass();
	//	DisplayWindow();
	//	ListenForWindowEvents();

	//	return 0;
	//}
#pragma endregion
//Functions of WinMain.h Operations//
#pragma region WinMainFunctions
void IntializesVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

void CreateWindowClass() {

	/*Create a Window Class*/
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);//intializing
	wcex.style = CS_HREDRAW | CS_VREDRAW;//how the window chooses to draw
	wcex.cbClsExtra = 0;// if need extra memory at runtime at start can do this via api
	wcex.cbWndExtra = 0;//if need extra memory at runtime at start can do this via api

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);//if you want different cursor
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);//if you want different background can be overridden by graphics api

	wcex.hIcon = hIcon;//taskbar icon
	wcex.hIconSm = hIcon;//top of window icon

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr; //if a drop down is needed can create one

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = WindowProcess;//how window performs for example sizes closes etc.

	RegisterClassEx(&wcex);//register class

}

void DisplayWindow() {
	DWORD winStyle = WS_MAXIMIZE;
	if (SolutionState) {
		winStyle = WS_OVERLAPPEDWINDOW;
	}

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, winStyle, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);//create handle to window

	if (!hWnd) {//check if window has been created if for some reason window has not been made
		MessageBox(0, L"Failed To create Window", 0, 0);
		PostQuitMessage(0);
	}
	else {
		ShowWindow(hWnd, SW_SHOW);//SW_SHOW is same as nCmdShow indicating wether the window should be maximized minimized or shown normally among other things as well
	}
}
//void ListenForWindowEvents()
//{
//	//effectively keeps window up as long as a MSG event quit has not been recieved 
//	MSG msg = { 0 };
//	while (msg.message != WM_QUIT) {
//		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//}
#pragma	endregion