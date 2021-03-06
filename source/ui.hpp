#ifndef __CTRX_UI_HPP__
#define __CTRX_UI_HPP__

#include <citrus/gpu.hpp>
#include <citrus/hid.hpp>
#include <citrus/types.hpp>

#include <functional>
#include <set>
#include <string>
#include <vector>

typedef struct {
    std::string id;
    std::string name;
    std::vector<std::string> details;
} SelectableElement;

void uiInit();
void uiCleanup();

void uiDrawRectangle(int x, int y, u32 width, u32 height, u8 red = 0xFF, u8 green = 0xFF, u8 blue = 0xFF, u8 alpha = 0xFF);
void uiDrawPositionBar(u32 pos, u32 nshown, u32 total, bool use_bottom = false);
std::string uiTruncateString(const std::string str, int nsize, int pos);
std::string uiFormatBytes(u64 bytes);
bool uiFileBrowser(const std::string rootDirectory, const std::string startPath, std::function<bool(bool &updateList, bool &resetCursorOnUpdate)> onLoop, std::function<void(SelectableElement* entry)> onUpdateEntry, std::function<void(std::string* currDir)> onUpdateDir, std::function<void(std::set<SelectableElement*>* marked)> onUpdateMarked, std::function<bool(std::string selectedPath, bool &updateList)> onSelect, bool useTopScreen = false);
bool uiHexViewer(const std::string path, u32 start, std::function<bool(u32 &offset, u32 &markedOffset, u32 &markedLength, bool selectMode)> onLoop, std::function<bool(u32 offset)> onUpdate, std::function<bool(u32 selectedOffset, u32 selectedLength, ctr::hid::Button selectButton, bool &updateData)> onSelect);
bool uiTextViewer(const std::string path, std::function<bool(void)> onLoop, std::function<bool(u32 offset, u32 plus)> onUpdate);
void uiDisplayMessage(ctr::gpu::Screen screen, const std::string message);
bool uiPrompt(ctr::gpu::Screen screen, const std::string message, bool question);
bool uiErrorPrompt(ctr::gpu::Screen screen, const std::string operationStr, const std::string detailStr, bool checkErrno, bool question);
std::string uiStringInput(ctr::gpu::Screen screen, std::string preset, const std::string alphabet, const std::string message, u32 resize = 1, bool allow_keyboard = false);
u32 uiNumberInput(ctr::gpu::Screen screen, u32 preset, const std::string message, bool hex = false);
std::vector<u8> uiDataInput(ctr::gpu::Screen screen, std::vector<u8> preset, const std::string message, bool allowResize = true);
void uiDisplayProgress(ctr::gpu::Screen screen, const std::string operation, const std::string details, bool quickSwap, u32 progress);

#endif