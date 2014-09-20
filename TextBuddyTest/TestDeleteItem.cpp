#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "DeleteItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestDeleteItem) {
public:
	/// Test if delete command is being interpreted correctly.
    TEST_METHOD(TestDeleteItemInterpret) {
        auto mock = std::make_shared<DeleteItem>();
        Assert::IsTrue(mock->interpret("delete 0"));
        Assert::IsFalse(mock->interpret("delete one"));
        Assert::IsFalse(mock->interpret("delete -42.0"));
        Assert::IsFalse(mock->interpret("delete"));
    }

	/// Test if delete command is being executed correctly.
    TEST_METHOD(TestDeleteItemExecute) {
        auto mock = std::make_shared<DeleteItem>();
        auto mockData = App::newSharedData("foo");

        // Add one item, delete it, must be back to empty list.
        mockData.textList.addItem("Hello World");
        mock->interpret("delete 1");
        mock->execute(mockData);
        Assert::IsTrue(mockData.textList.isEmpty());

        // Add two items, delete 1, item two become item 1
        mockData.textList.addItem("Hello World");
        mockData.textList.addItem("Hello Marnie");
        mock->interpret("delete 1");
        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getSize(), (unsigned) 1);
        Assert::AreEqual(mockData.textList.getAt(0), std::string("Hello Marnie"));
        
        mockData.textList.clearItems();

        // Invalid index must not delete.
        mockData.textList.addItem("Hello World");
        bool a = mock->interpret("delete one");

        mock->execute(mockData);
        Assert::AreEqual(mockData.textList.getSize(), (unsigned) 1);
    }

};

