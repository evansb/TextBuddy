#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "AddItem.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

ONLY_USED_AT_NAMESPACE_SCOPE class TestAddItem : public ::Microsoft::VisualStudio::CppUnitTestFramework::TestClass<TestAddItem> {

public:	
    TEST_METHOD(TestInterpret) {
        auto mock = std::make_shared<AddItem>();
        
        Assert::IsTrue(mock->interpret(std::string("add Hello World")));
        Assert::IsFalse(mock->interpret(std::string("add ")));
        Assert::IsFalse(mock->interpret(std::string("badd World")));
        Assert::IsFalse(mock->interpret(std::string("\\nadd World")));
    }
    TEST_METHOD(TestExecute) {
        auto mock = std::make_shared<AddItem>();
        auto mockData = App::newSharedData("foo");

        mock->interpret("add Hello World");
        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getAt(0), std::string("Hello World"));

        mock->interpret("add Hello Marnie");
        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getAt(1), std::string("Hello Marnie"));
    }
};
