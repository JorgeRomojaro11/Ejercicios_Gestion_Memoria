#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define SIZE 4096

int _tmain() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    hMapFile = OpenFileMapping(
            FILE_MAP_ALL_ACCESS,   // access
            FALSE,                 // do not inherit the name
            L"MySharedMemory");

    if (hMapFile == NULL) {
        _tprintf(_T("Could not open file mapping object (%d)\n"), GetLastError());
        return 1;

