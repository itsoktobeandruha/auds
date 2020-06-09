#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <SetupAPI.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	HANDLE Handle;
	SP_DEVINFO_DATA DeviceInfo;
	ZeroMemory(&DeviceInfo, sizeof(SP_DEVINFO_DATA));
	DeviceInfo.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD Index = 0;
	BYTE PropertyBuffer[1024] = { 0 };
	BYTE PropertyBufferForHWID[1024] = { 0 };
	BYTE PropertyBuffer_cmp[1024] = { 0 };
	LPSTR name[30];
	DWORD pcbBuffer = 30;
	RTL_OSVERSIONINFOW info;
	int num = 0;
	GetUserNameA(name, &pcbBuffer);
	printf("User Name: %s\n", name);
	pcbBuffer = 30;
	GetComputerNameA(name, &pcbBuffer);
	printf("Name: %s\n", name);
	printf("Devices:\n");
	Handle = SetupDiGetClassDevsA(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
	while (SetupDiEnumDeviceInfo(Handle, Index, &DeviceInfo))
	{
		strcpy_s(PropertyBuffer_cmp, 1024, PropertyBuffer);
		SetupDiGetDeviceRegistryPropertyA(Handle, &DeviceInfo, SPDRP_FRIENDLYNAME, NULL, PropertyBuffer, 1024, NULL);
		if (strcmp(PropertyBuffer, PropertyBuffer_cmp))
		{
			SetupDiGetDeviceRegistryPropertyA(Handle, &DeviceInfo, SPDRP_HARDWAREID, NULL, PropertyBufferForHWID, 1024, NULL);
			printf("%d %s HWID: %s\n",num, PropertyBuffer, PropertyBufferForHWID);
			num++;
		}
		else
		{
			Index++;
			continue;
		}
	}
	printf("\n");
	system("PAUSE");
	return 0;
}