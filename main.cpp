#include <Windows.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  // Pre-make
  auto source_code = R"EOF(#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  // Pre-make
  const string source_code = "ALL_CODE";
  if (argc > 1) {
    cout << source_code << endl;
    exit(0);
  }

  //  Hide Console
  FreeConsole();

  // Use CreateMuteA function to avoid multi-process
  HANDLE If_mute_process = CreateMutexA(NULL, FALSE, "SnipStarter");
  if (GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(If_mute_process);
    If_mute_process = NULL;
    exit(0);
  }

  /*
  Register Hot Key
  Win + Esc => Capture Screen
  Win + Delete => Exit Process
  */
  if (0 == RegisterHotKey(NULL, 3246, MOD_WIN, VK_ESCAPE)) {
    cout << "RegisterHotKey error : " << GetLastError() << endl;
  }
  if (0 == RegisterHotKey(NULL, 2874, MOD_WIN, VK_DELETE)) {
    cout << "RegisterHotKey error : " << GetLastError() << endl;
  }

  // Capture WinMsg for hotkey
  MSG msg = {0};
  while (GetMessage(&msg, NULL, 0, 0)) {
    switch (msg.message) {
    case WM_HOTKEY: {
      if (3246 == msg.wParam) {
        WinExec("D:\\ScreenCapture.exe", SW_SHOW);
      } else if (2874 == msg.wParam) {
        UnregisterHotKey(NULL, 3246);
        UnregisterHotKey(NULL, 2874);
        exit(0);
      }
      break;
    }
    default:
      break;
    }
  }
  return 0;
}
)EOF";
  if (argc > 1) {
    cout << source_code << endl;
    exit(0);
  }

  //  Hide Console
  FreeConsole();

  // Use CreateMuteA function to avoid multi-process
  HANDLE If_mute_process = CreateMutexA(NULL, FALSE, "SnipStarter");
  if (GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(If_mute_process);
    If_mute_process = NULL;
    exit(0);
  }

  /*
  Register Hot Key
  Win + Esc => Capture Screen
  Win + Delete => Exit Process
  */
  if (0 == RegisterHotKey(NULL, 3246, MOD_WIN, VK_ESCAPE)) {
    cout << "RegisterHotKey error : " << GetLastError() << endl;
  }
  if (0 == RegisterHotKey(NULL, 2874, MOD_WIN, VK_DELETE)) {
    cout << "RegisterHotKey error : " << GetLastError() << endl;
  }

  // Capture WinMsg for hotkey
  MSG msg = {0};
  while (GetMessage(&msg, NULL, 0, 0)) {
    switch (msg.message) {
    case WM_HOTKEY: {
      if (3246 == msg.wParam) {
        WinExec("D:\\ScreenCapture.exe", SW_SHOW);
      } else if (2874 == msg.wParam) {
        UnregisterHotKey(NULL, 3246);
        UnregisterHotKey(NULL, 2874);
        exit(0);
      }
      break;
    }
    default:
      break;
    }
  }
  return 0;
}