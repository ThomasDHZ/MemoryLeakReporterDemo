# MemoryLeakReporterDemo

A lightweight C# tool for detecting and reporting memory leaks in DLLs, integrated with the VulkanGameEngine to ensure robust resource management in high-performance graphics applications.

## Project Overview
MemoryLeakReporterDemo is a specialized tool developed in June 2025 to support the `VulkanGameEngine` project. Written in C#, it uses P/Invoke for C/C++ interop to monitor and report memory leaks in dynamically loaded DLLs, enhancing the stability of Vulkan-based rendering pipelines. This prototype demonstrates advanced memory management techniques and interop skills, contributing to reliable graphics programming workflows.

## Key Features
- **Memory Leak Detection**: Built a C# tool to identify and log memory leaks in DLLs, ensuring efficient resource cleanup in VulkanGameEngine’s rendering processes.
- **C#/C++ Interop**: Leveraged P/Invoke to interface with native C/C++ DLLs, enabling seamless integration with Vulkan’s low-level operations.
- **Stability Enhancement**: Improved engine reliability by detecting memory leaks, reducing crash risks in high-performance graphics applications.
- **Prototype Efficiency**: Developed as a focused demo in one month, optimized for rapid integration and testing within the VulkanGameEngine ecosystem.

## Technical Details
- **Languages**: C/C++ 
- **Technologies**: P/Invoke, VulkanGameEngine, Visual Studio
- **Key Components**:
  - Memory leak detection module for DLLs
  - P/Invoke-based interop for native memory monitoring
  - Logging system for detailed leak reports
- **Challenges Overcome**:
  - Implemented efficient interop to monitor native memory without significant performance overhead.
  - Tailored leak detection to Vulkan-specific DLLs, ensuring compatibility with the engine’s architecture.
- **Integration**: Deployed in `VulkanGameEngine` to safeguard against memory leaks in custom DLLs and Vulkan bindings.

## Historical Context
Created as a supporting tool for `VulkanGameEngine`, this project builds on my expertise in C#/C++ interop from projects like `ListPtr<>`. It reflects a commitment to robust, high-performance software development.

## Future Considerations
- Enhance with automated memory leak resolution or integration with profiling tools like RenderDoc.
- Expand logging for comprehensive diagnostics across broader use cases.
- Develop into a standalone library for reuse in other C#/C++ projects.

## Getting Started
1. Clone the repository: `git clone https://github.com/ThomasDHZ/MemoryLeakReporterDemo`
2. Install dependencies: .NET 8.0 SDK, Visual Studio.
3. Build and run within the `VulkanGameEngine` environment or as a standalone demo.

## Contributions
This is a personal prototype project and not actively maintained. Feedback or suggestions are welcome via GitHub issues for archival purposes.
