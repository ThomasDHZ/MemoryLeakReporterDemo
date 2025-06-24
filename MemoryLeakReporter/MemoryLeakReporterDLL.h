#pragma once
#include "DLL.h"
#include <mutex>

typedef unsigned char byte;

struct MemoryLeakPtr
{
    void* PtrAddress;
    size_t PtrElements;
    bool isArray;
    std::string DanglingPtrMessage;
};

#ifdef __cplusplus
extern "C" {
#endif
    DLL_EXPORT MemoryLeakPtr Memory_NewPtr(size_t memorySize, size_t elementCount, const char* file, int line, const char* func, const char* notes);
    DLL_EXPORT void Memory_DeletePtr(void* ptr);
    DLL_EXPORT void Memory_DanglingPtrMessage(MemoryLeakPtr* ptr);
#ifdef __cplusplus
}
#endif