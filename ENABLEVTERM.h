#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#ifdef _WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x00004
#endif

static HANDLE std_out_handle, std_in_handle;
static DWORD out_mode_init, in_mode_init;

void setup_console(void) {
  DWORD outMode = 0, inMode = 0;
  std_out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  std_in_handle = GetStdHandle(STD_INPUT_HANDLE);

  if (std_out_handle == INVALID_HANDLE_VALUE ||
      std_in_handle == INVALID_HANDLE_VALUE) {
    exit(GetLastError());
  }

  if (!GetConsoleMode(std_out_handle, &outMode) ||
      !GetConsoleMode(std_in_handle, &inMode)) {
    exit(GetLastError());
  }

  out_mode_init = outMode;
  in_mode_init = inMode;

  // Enable ANSI escape codes
  outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  // Set stdin as no echo and unbuffered//makes input
  // inMode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);

  if (!SetConsoleMode(std_out_handle, outMode) ||
      !SetConsoleMode(std_in_handle, inMode)) {
    exit(GetLastError());
  }
}

#else
void setupConsole(void) {}
#endif