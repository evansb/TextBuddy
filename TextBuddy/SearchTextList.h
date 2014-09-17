#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to search a word in Text List.
class SearchTextList : public App::Feature {
	friend class TestSearchTextList;
public:
	/// Default constructor.
	SearchTextList() = default;

	/// Default destructor.
	virtual ~SearchTextList() = default;

	/// A command is match if it is equal to SEARCH_KEYWORD followed
	/// with one non empty string as a keyword, separated by single space.
	/// \param [command] command to be interpreted.
	bool interpret(const App::Command& command) override;

	/// Search the occurence of the word inputCache in the text list.
	/// Return the numbered list of matching items, pretty printed
	/// as string.
	/// \param [data] Shared data passed to this method.
	/// \return Matched items displayed in numbered order.
	App::Feedback execute(App::SharedData& data) override;

private:
	/// Message displayed when keyword not found
	const static std::string KEYWORD_NOT_FOUND;
	/// \see interpret
	const static std::string SEARCH_KEYWORD;

	/// Search keyword.
	std::string inputCache;
};