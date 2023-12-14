#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define SIZE 4096

int _tmain() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    hMapFile = OpenFileMapping(
            FILE_MAP_ALL_ACCESS,
            FALSE,
            L"MySharedMemory");

    if (hMapFile == NULL) {
        _tprintf(_T("Could not open file mapping object (%d)\n"), GetLastError());
        return 1;
    }

    pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, SIZE);
    if (pBuf == NULL) {
        _tprintf(_T("Could not map view of file (%d)\n"), GetLastError());

        CloseHandle(hMapFile);
        return 1;
    }
    _tprintf(_T("Child reads: %s\n"), pBuf);

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}

