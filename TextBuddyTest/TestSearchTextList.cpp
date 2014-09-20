#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "DisplayTextList.h"
#include "SearchTextList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSearchTextList) {
public:
	/// Prepare test cases
	TEST_METHOD_INITIALIZE(TestSearchTextListInterpret) {
	}
	/// Test if search command is being interpreted correctly.
	TEST_METHOD(TestSearchTextListInterpret) {
		auto mock = std::make_shared<SearchTextList>();
		Assert::IsTrue(mock->interpret("search Hello"));
		Assert::AreEqual(mock->inputCache, std::string("Hello"));
		Assert::IsFalse(mock->interpret("serach Hello"));
		Assert::IsFalse(mock->interpret("search Hello World"));
		Assert::IsFalse(mock->interpret("search"));
	}

	/// Test if search command is being executed correctly.
	TEST_METHOD(TestSearchTextListExecute) {
		// Prepare the features
		auto mock = std::make_shared<SearchTextList>();
		auto display = std::make_shared<DisplayTextList>();

		// Prepare list of two items.
		auto mockData = App::newSharedData("foo");
		mockData.textList.addItem("Hello World");
		mockData.textList.addItem("Boss Marnie");
		mockData.textList.addItem("Hello Marnie");

		// Prepare the expected search result list.
		auto mockResult = App::newSharedData("boo");
		mockResult.textList.addItem("Hello World");
		mockResult.textList.addItem("Hello Marnie");

		// Execute the command and compare the results
		mock->interpret("search Notfound");
		Assert::AreEqual(mock->execute(mockData), SearchTextList::KEYWORD_NOT_FOUND);

		mock->interpret("search Hello");
		Assert::AreEqual(mock->execute(mockData), display->execute(mockResult));
	}

};

