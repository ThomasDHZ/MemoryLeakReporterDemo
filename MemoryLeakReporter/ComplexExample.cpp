#include "ComplexExample.h"

LevelLayout VRAM_LoadLevelLayout(const char* levelLayoutPath)
{
    nlohmann::json json = nlohmann::json::parse(File_Read(levelLayoutPath).Data);

    LevelLayout levelLayout;
    levelLayout.LevelLayoutId = VkGuid(json["LevelLayoutId"].get<std::string>().c_str());
    levelLayout.LevelBounds = glm::ivec2(json["LevelBounds"][0], json["LevelBounds"][1]);
    levelLayout.TileSizeinPixels = glm::ivec2(json["TileSizeInPixels"][0], json["TileSizeInPixels"][1]);

    std::vector<uint32_t*> levelLayerList;
    for (int x = 0; x < json["LevelLayouts"].size(); x++)
    {
        std::vector<uint32_t> levelLayerMap;
        for (int y = 0; y < json["LevelLayouts"][x].size(); y++)
        {
            for (int z = 0; z < json["LevelLayouts"][x][y].size(); z++)
            {
                levelLayerMap.push_back(json["LevelLayouts"][x][y][z]);
            }
        }
        levelLayout.LevelLayerMapCount = levelLayerMap.size();
        uint32_t* levelLayerMapPtr = Memory_NewPtr(sizeof(uint32_t), levelLayerMap.size(), __FILE__, __LINE__, __func__);
        std::memcpy(levelLayerMapPtr, levelLayerMap.data(), levelLayerMap.size() * sizeof(uint32_t));
        levelLayerList.push_back(levelLayerMapPtr);
    }
    levelLayout.LevelLayerCount = levelLayerList.size();
    uint32_t** levelLayerListPtr = Memory_NewPtr(sizeof(uint32_t), levelLayerList.size(), __FILE__, __LINE__, __func__);
    std::memcpy(levelLayerListPtr, levelLayerList.data(), levelLayerList.size() * sizeof(uint32_t*));
    levelLayout.LevelLayerList = levelLayerListPtr;

    return levelLayout;
}

void VRAM_DeleteLevelLayerPtr(uint32_t** levelLayerPtr)
{
    Memory_DeletePtr(*levelLayerPtr);
}

void VRAM_DeleteLevelLayerMapPtr(uint32_t* levelLayerMapPtr)
{
    Memory_DeletePtr(levelLayerMapPtr);
}