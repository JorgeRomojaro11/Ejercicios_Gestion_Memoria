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
    if (hMapFile == NULL) {
        _tprintf(_T("Could not create file mapping object (%d)\n"), GetLastError());
        return 1;
    }
    pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, SIZE);
    if (pBuf == NULL) {
        _tprintf(_T("Could not map view of file (%d)\n"), GetLastError());

        CloseHandle(hMapFile);
        return 1;
    }
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(
            NULL,
            _T("child.exe"), // Cambia "child.exe" al nombre real de tu ejecutable del proceso hijo
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) {
        _tprintf(_T("CreateProcess failed (%d)\n"), GetLastError());

        UnmapViewOfFile(pBuf);
        CloseHandle(hMapFile);
        return 1;
    }
    StringCchCopy((LPTSTR)pBuf, SIZE / sizeof(TCHAR), _T("Hello, child process!"));

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}


