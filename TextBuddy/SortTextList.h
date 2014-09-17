#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to sort the items in Text List alphabetically. 
class SortTextList : public App::Feature {
public:
	/// Default constructor.
	SortTextList() = default;

	/// Default destructor.
	virtual ~SortTextList() = default;

	/// A command is match if it is equal to SEARCH_KEYWORD
	/// \param[command] command to be interpreted.
	bool interpret(const App::Command& command) override;

	///  Sort the list alphabetically and call DisplayTextList feature.
	///  Assume case insensitive.
	/// \param [data] Shared data passed to this method.
	/// \return sorted text list, displayed by DisplayTextList.
	App::Feedback execute(App::SharedData& data) override;

private:
	/// \see interpret
	const static std::string SORT_KEYWORD;
};