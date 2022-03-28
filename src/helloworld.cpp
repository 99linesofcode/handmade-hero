#include <windows.h>

WNDPROC Wndproc;

LRESULT CALLBACK MainWindowCallback(
  HWND Window,
  UINT Message,
  WPARAM WParam,
  LPARAM LParam
)
{
  LRESULT Result = 0;

  switch (Message)
  {
  case WM_SIZE:
    break;
  case WM_DESTROY:
    break;
  case WM_CLOSE:
    break;
  case WM_ACTIVATE:
    break;
  default:
    Result = DefWindowProc(Window, Message, WParam, LParam);
    break;
  }

  return Result;
}

int CALLBACK WinMain(
  HINSTANCE Instance,
  HINSTANCE PrevInstance,
  PSTR CommandLine,
  INT ShowCode
)
{
  WNDCLASSA WindowClass = {};

  WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
  WindowClass.lpfnWndProc = MainWindowCallback;
  WindowClass.hInstance = Instance;
  // WindowClass.hIcon = ;
  WindowClass.lpszClassName = "HandmadeHeroWindowClass";

  if (RegisterClassA(&WindowClass)) {
    HWND WindowHandle = CreateWindowExA(
      0,
      WindowClass.lpszClassName,
      "Handmade Hero",
      WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      0,
      0,
      Instance,
      0
    );

    if (WindowHandle) {
      MSG Message;

      for (;;) {
        BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
        if (MessageResult > 0) {
          TranslateMessage(&Message);
          DispatchMessage(&Message);
        }
        else {
          break;
        }
      }
    }
    else {
      // TODO logging
    }
  }
  else {
    // TODO logging
  }

  return 0;
}
