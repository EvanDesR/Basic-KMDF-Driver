#pragma once
#include <ntddk.h>
constexpr auto MY_DRIVER_TAG = '1GAT';

void cleanup(PDRIVER_OBJECT DriverObject);
NTSTATUS initialization(PDRIVER_OBJECT, PUNICODE_STRING);