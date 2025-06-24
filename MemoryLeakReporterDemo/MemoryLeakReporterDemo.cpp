#include <iostream>
#include <ComplexExample.h>
#include "MemorySystem.h"

//This is just a quick demo of the MemoryLeakReporter system I made for my VulkanGameEngine.
//It's just a basic detector to log the allocated memory ptrs and report back at the end of the program any ptrs memory blocks that haven't been properly taken care of.
//Since I've been working with DLLs for the level editor which is in C# to make the data more easily transportable, I've needed work with the dlls in a little more of a C style. 
//Which means manually allocating memory data, then deleting the memory buffer after it's out of use.

//Right now I've gotten in the habit of creating a interface for the DLLs in the main program.
//So it's a little extra work compaired just using DLLs, but it's not that much more and makes it a lot easier to use.

void Test1()
{
	//Just showing off the reporting.
	float* floatList = memorySystem.AddPtrBuffer<float>(32, __FILE__, __LINE__, __func__);
}

void Test2()
{
	//Showing off the how to delete the ptr.
	float* floatList = memorySystem.AddPtrBuffer<float>(32, __FILE__, __LINE__, __func__);
	memorySystem.RemovePtrBuffer<float>(floatList);
}

void Test3()
{
	//Example from my game engine.
	LevelLayout levelLayout = VRAM_LoadLevelLayout("../json/TestMapLevelLayout.json");
	VRAM_DeleteLevelLayerPtr(levelLayout.LevelLayerList);
	VRAM_DeleteLevelLayerMapPtr(*levelLayout.LevelLayerList);
}

int main()
{
	Test3();
	memorySystem.ReportLeaks();
}
