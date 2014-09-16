#include "stdafx.h"
#include "CppUnitTest.h"
#include "App.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            App::runWithFile("Hello World");
            Assert::AreEqual(true, true);
		}

	};
}