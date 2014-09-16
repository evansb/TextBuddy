#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "AddItem.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestAddItem) {
public:	
    TEST_METHOD(TestAddItemInterpret) {
        auto mock = std::make_shared<AddItem>();
        
        Assert::IsTrue(mock->interpret(std::string("add Hello World")));
        Assert::IsFalse(mock->interpret(std::string("add ")));
        Assert::IsFalse(mock->interpret(std::string("badd World")));
        Assert::IsFalse(mock->interpret(std::string("\\nadd World")));
    }

    TEST_METHOD(TestAddItemExecute) {
        auto mock = std::make_shared<AddItem>();
        auto mockData = App::newSharedData("foo");

        App::newSharedData("foo");
        mock->interpret("add Hello World");
        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getAt(0), std::string("Hello World"));

        mock->interpret("add Hello Marnie");
        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getAt(1), std::string("Hello Marnie"));
    }

};
