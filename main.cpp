#include <Windows.h>

void HookVirtualMethod(void* pInstance, int index, void* pNewFunc) {
	void** pTable = *(void***)pInstance; // The vmt ptr is the first member
	void** ppFunc = pTable + index;

	DWORD oldProtection, dummyProtection;

	// Make sure we have readwrite access to the memory region
	VirtualProtect(ppFunc, sizeof(ppFunc), PAGE_EXECUTE_READWRITE, &oldProtection);

	// Overwrite the function pointer
	*ppFunc = pNewFunc;

	// Return the original mem access afterwards
	VirtualProtect(ppFunc, sizeof(ppFunc), oldProtection, &dummyProtection);
}

void* GetVirtualMethod(void* pInstance, int index) {
	void** pTable = *(void***)pInstance;

	return pTable[index];
}
