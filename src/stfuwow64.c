#include <stdlib.h>

#define EXPORTABLE __declspec(dllexport)
#define NTAPI __stdcall
#define WINAPI __stdcall
typedef long NTSTATUS;
#define STATUS_SUCCESS 0

typedef int BOOL;


#if defined (_MSC_VER)
#define NAKED __declspec(naked)
#else
#define NAKED __attribute__((naked))
#endif

NAKED NTSTATUS NTAPI iTerminateProcess(void* h_process,NTSTATUS exit_status) {
     __asm__(
    "  mov %rcx,%r10 \n"
    "mov $0x2C,%eax \n"
    "syscall \n"
    "  ret	\n"
    );
}

EXPORTABLE NTSTATUS NTAPI Wow64LogInitialize(void){return STATUS_SUCCESS;}
EXPORTABLE NTSTATUS NTAPI Wow64LogMessageArgList(unsigned char Level,const char* Format,void* Args) { return STATUS_SUCCESS; }
EXPORTABLE NTSTATUS NTAPI Wow64LogSystemService(void* ServiceParameters) { return STATUS_SUCCESS; }
EXPORTABLE NTSTATUS NTAPI Wow64LogTerminate(void) { return STATUS_SUCCESS; }


BOOL WINAPI DllMain(void* hinstDLL, unsigned int fdwReason, void* lpvReserved) {
    iTerminateProcess(0, 0);
}