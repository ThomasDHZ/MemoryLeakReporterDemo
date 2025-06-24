#include "MemoryLeakReporterDLL.h"
#include <windows.h>
#include <iostream>
#include <string>

    MemoryLeakPtr Memory_NewPtr(size_t memorySize, size_t elementCount, const char* file, int line, const char* func, const char* notes)
    {
        void* memory = nullptr;
        try
        {
            memory = new byte[memorySize * elementCount];
        }
        catch (const std::bad_alloc&)
        {
            fprintf(stderr, "Allocation failed: %s\n", notes ? notes : "Unknown");
            return MemoryLeakPtr
            {
                .PtrAddress = nullptr,
                .PtrElements = 0,
                .isArray = false,
                .DanglingPtrMessage = ""
            };
        }

        return MemoryLeakPtr
        {
            .PtrAddress = memory,
            .PtrElements = elementCount,
            .isArray = elementCount > 1,
            .DanglingPtrMessage = "Ptr failed to delete at File: " + std::string(file) + " Line: " + std::to_string(line) + " Function: " + std::string(func) + " Notes: " + notes
        };
    }

    void Memory_DeletePtr(void* memoryLeakPtr)
    {
        delete[] static_cast<byte*>(memoryLeakPtr);
    }

    void Memory_DanglingPtrMessage(MemoryLeakPtr* ptr)
    {
        if (ptr)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hConsole != INVALID_HANDLE_VALUE)
            {
                CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                WORD originalAttributes = consoleInfo.wAttributes;

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << "Error: ";
                SetConsoleTextAttribute(hConsole, originalAttributes);
                std::cout << ptr->DanglingPtrMessage << std::endl;
            }
        }
    }
