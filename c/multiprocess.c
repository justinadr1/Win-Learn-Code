#include <windows.h>
#include <stdio.h>
#include <string.h>

void run_child(const char *role) 
{
    printf("[%s] PID %lu running\n", role, GetCurrentProcessId());
    Sleep(30000);
}

int main(int argc, char *argv[]) 
{
    // CHILD LOGIC
    if (argc > 1) 
    {
        if (strcmp(argv[1], "--type=worker") == 0) 
        {
            run_child("WORKER");
            return 0;
        }
        if (strcmp(argv[1], "--type=gpu") == 0) 
        {
            run_child("GPU");
            return 0;
        }
    }

    // MAIN LOGIC
    printf("[MAIN] PID %lu starting\n", GetCurrentProcessId());

    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);

    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    const char* roles[] = 
    {
        "--type=worker",
        "--type=worker",
        "--type=gpu"
    };

    char cmdLine[512];

    for (int i = 0; i < 3; i++) 
    {
        snprintf(cmdLine, sizeof(cmdLine), "\"%s\" %s", exePath, roles[i]);

        if (!CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) 
        {
            printf("CreateProcess failed (%lu)\n", GetLastError());
            return 1;
        }

        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }

    Sleep(30000);
    return 0;
}