#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "ClearItems.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestClearItems) {
public:
	/// Test if clear command is being interpreted correctly.
    TEST_METHOD(TestClearItemsInterpret) {
        auto mock = std::make_shared<ClearItems>();
        Assert::IsTrue(mock->interpret("clear"));
        Assert::IsFalse(mock->interpret("clear hummu"));
        Assert::IsFalse(mock->interpret("clea"));
    }

	/// Test if clear command is being executed correctly.
    TEST_METHOD(TestClearItemsExecute) {
        auto mock = std::make_shared<ClearItems>();
        auto mockData = App::newSharedData("foo");
        
        mockData.textList.addItem("Hello World");
        mock->execute(mockData);
        Assert::IsTrue(mockData.textList.isEmpty());

        mock->execute(mockData);
        Assert::IsTrue(mockData.textList.isEmpty());
    }

};
