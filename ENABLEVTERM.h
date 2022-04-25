#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#ifdef _WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x00004
#endif

static HANDLE stdoutHandle, stdinHandle;
static DWORD outModeInit, inModeInit;

void setup_console(void) {
  DWORD outMode = 0, inMode = 0;
  stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  stdinHandle = GetStdHandle(STD_INPUT_HANDLE);

  if (stdoutHandle == INVALID_HANDLE_VALUE ||
      stdinHandle == INVALID_HANDLE_VALUE) {
    exit(GetLastError());
  }

  if (!GetConsoleMode(stdoutHandle, &outMode) ||
      !GetConsoleMode(stdinHandle, &inMode)) {
    exit(GetLastError());
  }

  outModeInit = outMode;
  inModeInit = inMode;

  // Enable ANSI escape codes
  outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  // Set stdin as no echo and unbuffered//makes input
  // inMode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);

  if (!SetConsoleMode(stdoutHandle, outMode) ||
      !SetConsoleMode(stdinHandle, inMode)) {
    exit(GetLastError());
  }
}

#else
void setupConsole(void) {}
#endif