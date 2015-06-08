#ifndef __CTRCOMMON_UI_X_HPP__
#define __CTRCOMMON_UI_X_HPP__

#include <ctrcommon/types.hpp>
#include <ctrcommon/ui.hpp>

#include <functional>
#include <set>
#include <string>
#include <vector>

std::string uiTruncateString(const std::string str, int nsize, int pos);
std::string uiFormatBytes(u64 bytes);
bool uiFileBrowser(const std::string rootDirectory, std::function<bool(bool &updateList, bool &resetCursorOnUpdate)> onLoop, std::function<void(SelectableElement* entry)> onUpdateEntry, std::function<void(std::string* currDir)> onUpdateDir, std::function<void(std::set<SelectableElement*>* marked)> onUpdateMarked, bool useTopScreen);
bool uiErrorPrompt(Screen screen, const std::string operationStr, const std::string detailStr, bool checkErrno, bool question);
std::string uiStringInput(Screen screen, std::string preset, const std::string alphabet, const std::string message);

#endif