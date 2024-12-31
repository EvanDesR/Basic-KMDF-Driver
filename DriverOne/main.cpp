#include "Header.h"

PVOID g_myMemory;

extern "C"
NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{

	


	UNREFERENCED_PARAMETER(RegistryPath);
	KdPrint(("[+] Hello from DriverEntry\n"));
	DriverObject->DriverInit = initialization;
	// point DriverUnload to Cleanup function
	DriverObject->DriverUnload = cleanup;

	// allocate some memory
	g_myMemory = ExAllocatePool2(
		POOL_FLAG_PAGED,
		1024,
		MY_DRIVER_TAG
	);

	KdPrint(("[+] Memory allocated at 0x%08p\n", g_myMemory));

	return STATUS_SUCCESS;
}

NTSTATUS initialization(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);
	UNREFERENCED_PARAMETER(DriverObject);
	KdPrint(("Init looping \n"));

	int it = 0;
	while (it < 10)
	{
		KdPrint(("Init looping \n"));

		it++;
	}
	return STATUS_SUCCESS;
}


void cleanup(
	PDRIVER_OBJECT DriverObject
)
{
	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("[+] Hello from DriverUnload\n"));
	KdPrint(("[+] Freeing memory at 0x%08p\n", g_myMemory));

	// free the allocated memory
	ExFreePoolWithTag(
		g_myMemory,
		MY_DRIVER_TAG
	);
}