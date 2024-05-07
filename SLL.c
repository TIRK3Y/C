#include <windows.h>
#include <stdio.h>

typedef int (*MYPROC)(int, int);

int main(void)
{
    HINSTANCE hinstLib;
    MYPROC ProcAdd;
    BOOL fFreeResult;

    // Load the DLL
    hinstLib = LoadLibrary("MyDll.dll");
    if (hinstLib == NULL) {
        printf("Failed to load MyDll.dll\n");
        return 1;
    }

    // Get the address of the add function
    ProcAdd = (MYPROC) GetProcAddress(hinstLib, "add");
    if (NULL == ProcAdd) {
        printf("Failed to get address of add function\n");
        return 1;
    }

    // Call the add function
    int result = ProcAdd(2, 3);
    printf("Result: %d\n", result);

    // Unload the DLL
    fFreeResult = FreeLibrary(hinstLib);
    if (!fFreeResult) {
        printf("Failed to unload MyDll.dll\n");
        return 1;
    }

    return 0;
}
