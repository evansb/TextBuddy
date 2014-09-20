#include "stdafx.h"
#include "SearchTextList.h"
#include "DisplayTextList.h"

const std::string SearchTextList::SEARCH_KEYWORD = "search";
const std::string SearchTextList::KEYWORD_NOT_FOUND = "Keyword not found\n";

/// A command is match if it is equal to SEARCH_KEYWORD followed
/// with one non empty string as a keyword, separated by single space.
/// \param [command] command to be interpreted.
bool SearchTextList::interpret(const App::Command& command) {
	std::istringstream inString(command);
	std::string commandKeyword;
	std::string searchKeyword;
	std::string dummy;

	// Consume one word from the string, return false if not match.
	inString >> commandKeyword;
	bool keywordNotMatch = commandKeyword != SEARCH_KEYWORD;
	if (keywordNotMatch) {
		return false;
	}

	// Consume one word as a search keyword, if there is no more
	// word or more than one words, return false
	bool searchKeywordExists = static_cast<bool>(inString >> searchKeyword);
	bool noMoreWords = !static_cast<bool>(inString >> dummy);
	if (searchKeywordExists && noMoreWords) {
		inputCache = searchKeyword;
		return true;
	} else {
		return false;
	}
}

/// Search the occurence of the word inputCache in the text list.
/// Return the numbered list of matching items, pretty printed
/// as string.
/// \param [data] Shared data passed to this method.
/// \return Matched items displayed in numbered order.
App::Feedback SearchTextList::execute(App::SharedData& data) {	
	TextList found;
	std::for_each(
		data.textList.cbegin(),
		data.textList.cend(),
		[&] (TextList::ItemType item) {
			bool match = item.find(inputCache) != std::string::npos;
			if (match) {
				found.addItem(item);
			}
		}
	);
	if (found.isEmpty()) {
		return KEYWORD_NOT_FOUND;
	} else {
		// Store found items to a list.
		App::SharedData tempData("foo");
		tempData.textList = found;
		
		// Display the list to the user.
		auto display = std::make_shared<DisplayTextList>();
		return display->execute(tempData);
	}
}