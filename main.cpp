#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define SIZE 4096

int _tmain() {
    HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE,
            0,
            SIZE,
            L"MySharedMemory");
