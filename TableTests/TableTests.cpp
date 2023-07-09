#include "pch.h"
#include "CppUnitTest.h"
#include "../HTable/Table.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TableTests
{
	TEST_CLASS(TableTests)
	{
	public:

		TEST_METHOD(Init)
		{
			HashTable<string> table;
			table.Add("string0");
			table.Add("string1");
			table.Add("string2");
			table.Add("string3");
			table.Add("string4");
		}
		TEST_METHOD(isFound)
		{
			HashTable<string> table;
			table.Add("string0");
			table.Add("string0");
			table.Add("string2");
			table.Add("string3");
			table.Add("string4");
			Assert::IsTrue(table.Find("string4"));
			Assert::IsTrue(table.Find("string3"));
			Assert::IsTrue(table.Find("string2"));
			Assert::IsTrue(table.Find("string1"));
			Assert::IsTrue(table.Find("string0"));
		}

		TEST_METHOD(isNotFound)
		{
			HashTable<string> table;
			table.Add("string0");
			table.Add("string1");
			table.Add("string2");
			table.Add("string3");
			table.Add("string4");
			Assert::IsFalse(table.Find("str"));
		}

		TEST_METHOD(isDeleted)
		{
			HashTable<string> table;
			table.Add("string0");
			table.Add("string1");
			table.Add("string2");
			table.Add("string3");
			table.Add("string4");
			table.Remove("string0");
			Assert::IsFalse(table.Find("string0"));
		}
	};
}
