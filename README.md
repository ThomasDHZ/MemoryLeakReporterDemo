# MemoryLeakReporterDemo

A lightweight C# tool for detecting and reporting memory leaks in native DLLs.

This project was created to help identify memory issues in C++ libraries used by the Vulkan Game Engine, with a focus on reliable interop and resource management.

## Key Features

- Detects memory leaks in native DLLs
- Uses P/Invoke for C#/C++ interop
- Generates clear leak reports
- Designed for use in performance-sensitive applications
- Simple and focused prototype

## Tech Stack

- **Language**: C#,C++
- **Interop**: P/Invoke
- **Framework**: .NET
- **Purpose**: Memory debugging support for native libraries

## Related Projects

Developed as a supporting tool for the [Vulkan Game Engine](https://github.com/ThomasDHZ/VulkanGameEngine) to improve stability when working with custom native DLLs.

## Getting Started

1. Clone the repository
2. Open the solution in Visual Studio
3. Build and run the demo

## Notes

This is a personal prototype/supporting tool and is not actively maintained as a standalone library. It demonstrates practical C#/native interop and memory management techniques.

## License

MIT License (or specify your preferred license)
