#include "Engine.h"

extern IApplication* EntryApplication();

#ifdef WIN32 | WIN64
	//no names since defined above, or not needed
	int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) //hInstance hPrevInstance, lpCmdLine, nCmdChow
	{
		auto EntryApp = EntryApplication();
		EntryApp->init();
		//effectively keeps window up as long as a MSG event quit has not been recieved 
		MSG msg = { 0 };
		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				EntryApp->update();
			}
		}

		return 0;
	}
#endif

#ifdef ARM64
	int main() {
	
	}
#endif