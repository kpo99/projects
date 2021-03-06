#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumer.h"
#include <windows.h>
#include <conio.h>
#include "mutex.h"
#include "array.h"

module_t * new_comsumer(mutex_t * mutex)
{
    LPVOID args = (LPVOID)mutex;
    HANDLE hWriteThread = CreateThread(
                             NULL,               // default security attributes
                             0,                  // default stack size
                             (LPTHREAD_START_ROUTINE) threadRead,
                              (LPVOID) args,               // no thread function arguments
                             0,                  // default creation flags
                             NULL);// receive thread identifier

return hWriteThread;
}

void free_consumer(module_t * consumer){
CloseHandle(consumer);
}



DWORD threadRead(LPVOID args) {
   mutex_t * hMutex = (mutex_t*)args;
    while(1){
   WaitForSingleObject(hMutex, INFINITE);
    if (getArray(0) > getArray(1) && getArray(1) > getArray(2) ){
        for (int i = 0; i < 3; i++){
            printf("%d ", getArray(i));
        }
        printf("\n");
        Sleep(10);
    }
    else {
        printf("Array is increasing\n");
    }
ReleaseMutex(hMutex);
    }

//printf("%d %d %d",getArray(0),getArray(1),getArray(2));

}
