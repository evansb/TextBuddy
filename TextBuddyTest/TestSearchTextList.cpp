#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "SearchTextList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSearchTextList) {
public:
	TEST_METHOD(TestSearchTextListInterpret) {
		auto mock = std::make_shared<SearchTextList>();
		Assert::IsTrue(mock->interpret("search Hello"));
	}

	TEST_METHOD(TTestSearchTextListExecute) {
		auto mock = std::make_shared<SearchTextList>();
		auto mockData = App::newSharedData("foo");
		auto mockResult = App::newSharedData("boo");
		mockData.textList.addItem("Hello World");
		mockData.textList.addItem("Boss Marnie");
		mockResult.textList.addItem("Hello World");
		mock->interpret("search Notfound");
		Assert::AreEqual(mock->execute(mockData), SearchTextList::KEYWORD_NOT_FOUND);
	}

};

