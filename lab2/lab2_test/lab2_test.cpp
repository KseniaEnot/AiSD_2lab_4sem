#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/HuffmanAlg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2test
{
	TEST_CLASS(lab2test)
	{
	public:
		bool* code;
		char* decode;

		TEST_METHOD(test_1)
		{
			char str[] = { 'N','e','w',' ','s','t','r','i','n','g','\n' };
			HuffmanAlg ForCode(str);
			int codeSize;
			int decodeSize;
			code = ForCode.Code(codeSize);
			decode = ForCode.Decode(decodeSize);
			for (size_t i = 0; i < decodeSize; i++)
			{
				Assert::AreEqual(str[i], decode[i]);
			}
		}
		TEST_METHOD(test_2)
		{
			char str[] = { 'I','f',' ','m','u','s','i','c',' ','b','e',' ','t','h','e',' ','f','o','o','d',' ','o','f',' ','l','o','v','e',',',' ','p','l','a','y',' ','o','n','.','\n' };
			HuffmanAlg ForCode(str);
			int codeSize;
			int decodeSize;
			code = ForCode.Code(codeSize);
			decode = ForCode.Decode(decodeSize);
			for (size_t i = 0; i < decodeSize; i++)
			{
				Assert::AreEqual(str[i], decode[i]);
			}
		}
		TEST_METHOD(test_3)
		{
			char str[] = { 'A',' ','g','o','o','d',' ','h','e','a','r','t','’','s',' ','w','o','r','t','h',' ','g','o','l','d','.','\n' };
			HuffmanAlg ForCode(str);
			int codeSize;
			int decodeSize;
			code = ForCode.Code(codeSize);
			decode = ForCode.Decode(decodeSize);
			for (size_t i = 0; i < decodeSize; i++)
			{
				Assert::AreEqual(str[i], decode[i]);
			}
		}
		TEST_METHOD(test_4)
		{
			char str[] = { 'O','u','r',' ','l','i','f','e',' ','i','s',' ','w','h','a','t',' ','o','u','r',' ','t','h','o','u','g','h','t','s',' ','m','a','k','e',' ','i','t','.','\n' };
			HuffmanAlg ForCode(str);
			int codeSize;
			int decodeSize;
			code = ForCode.Code(codeSize);
			decode = ForCode.Decode(decodeSize);
			for (size_t i = 0; i < decodeSize; i++)
			{
				Assert::AreEqual(str[i], decode[i]);
			}
		}
		TEST_METHOD(test_5)
		{
			char str[] = { 'L','i','f','e',' ','i','s',' ','a',' ','s','e','r','i','e','s',' ','o','f',' ','c','h','o','i','c','e','s','.','\n' };
			HuffmanAlg ForCode(str);
			int codeSize;
			int decodeSize;
			code = ForCode.Code(codeSize);
			decode = ForCode.Decode(decodeSize);
			for (size_t i = 0; i < decodeSize; i++)
			{
				Assert::AreEqual(str[i], decode[i]);
			}
		}
		TEST_METHOD(test_zeroSize)
		{
			char* str = NULL;
			int codeSize;
			int decodeSize;
			try
			{
				HuffmanAlg ForCode(str);
				code = ForCode.Code(codeSize);
				decode = ForCode.Decode(decodeSize);
			}
			catch (std::exception e)
			{
				Assert::AreEqual("null argument", e.what());
			}
		}
	};
}
