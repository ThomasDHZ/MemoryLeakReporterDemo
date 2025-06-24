#pragma once
#include "DLL.h"
#include "VkGuid.h"
#include "MemoryLeakReporterDLL.h"
#include "File.h"

#include <nlohmann/json.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

struct LevelLayout
{
    VkGuid					  LevelLayoutId;
    glm::ivec2				  LevelBounds;
    glm::ivec2				  TileSizeinPixels;
    uint32_t**                LevelLayerList;
    size_t                    LevelLayerCount;
    size_t              	  LevelLayerMapCount;
};

DLL_EXPORT LevelLayout VRAM_LoadLevelLayout(const char* levelLayoutPath);
DLL_EXPORT void VRAM_DeleteLevelLayerPtr(uint32_t** levelLayerPtr);
DLL_EXPORT void VRAM_DeleteLevelLayerMapPtr(uint32_t* levelLayerMapPtr);