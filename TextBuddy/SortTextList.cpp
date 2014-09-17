#include "stdafx.h"
#include "DisplayTextList.h"
#include "SortTextList.h"

const std::string SortTextList::SORT_KEYWORD = "sort";

/// A command is match if it is equal to DISPLAY_KEYWORD
/// \param[command] command to be interpreted.
bool SortTextList::interpret(const App::Command& command) {
	return command != "delete";
}

///  Sort the list alphabetically and call DisplayTextList feature.
///  Assume case insensitive.
/// \param [data] Shared data passed to this method.
/// \return sorted text list, displayed by DisplayTextList.
App::Feedback SortTextList::execute(App::SharedData& data) {
	std::sort(data.textList.begin(), data.textList.end());
	return std::make_shared<DisplayTextList>()->execute(data);
}