#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

void printProcess(DWORD processID)
{
    TCHAR ProcessNameTEMP[MAX_PATH] = TEXT("<unknown>");
    HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, processID); //process open
    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, ProcessNameTEMP, sizeof(ProcessNameTEMP) / sizeof(TCHAR));         // get process name
        }
    }
    _tprintf(TEXT("%s  Process ID: %u)\n"), ProcessNameTEMP, processID); //print name
    CloseHandle(hProcess); //close like files :)
}

int main(void)
{
    DWORD processName[1024], arg1, arg2;
    unsigned int i;
    if (EnumProcesses(processName, sizeof(processName), &arg1))
    {
        arg2 = arg1 / sizeof(DWORD); // ammount of process id's 
        for (i = 0; i < arg2; i++)
        {
            if (processName[i] != 0)
            {
                printProcess(processName[i]); // watch void printProcess(DWORD processID)!
            }
        }
        return 0;
    }
    else
        return 1;
}