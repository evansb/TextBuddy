#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "SortTextList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSortTextList) {
public:
	TEST_METHOD(TestSortTextListInterpret) {
		auto mock = std::make_shared<SortTextList>();
		Assert::IsTrue(mock->interpret("sort"));
		Assert::IsFalse(mock->interpret("delete"));
		Assert::IsFalse(mock->interpret("sorts"));
	}

	TEST_METHOD(TestSortTextListExecute) {
		auto mock = std::make_shared<SortTextList>();
		auto mockData = App::newSharedData("foo");
		mockData.textList.addItem("Abby James");
		mockData.textList.addItem("Hello World");
		mock->execute(mockData);
		Assert::AreEqual(mockData.textList.getAt(0), std::string("Abby James"));
		Assert::AreEqual(mockData.textList.getAt(1), std::string("Hello World"));

		mockData.textList.clearItems();

		mockData.textList.addItem("Hello World");
		mockData.textList.addItem("Abby James");
		mock->execute(mockData);
		Assert::AreEqual(mockData.textList.getAt(0), std::string("Abby James"));
		Assert::AreEqual(mockData.textList.getAt(1), std::string("Hello World"));

	}

};
