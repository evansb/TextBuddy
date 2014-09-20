
#include "stdafx.h"
#include "CppUnitTest.h"

#include "App.h"
#include "DisplayTextList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestDisplayTextList) {
public:
	/// Test if search command is being interpreted correctly.
    TEST_METHOD(TestDisplayTextListInterpret) {
        auto mock = std::make_shared<DisplayTextList>();
        Assert::IsTrue(mock->interpret("display"));
        Assert::IsFalse(mock->interpret("display 2"));
    }
};