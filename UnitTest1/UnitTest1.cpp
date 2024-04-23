#include "pch.h"
#include "CppUnitTest.h"
#include <map>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string replaceSubstrings(std::string input, const std::map<std::string, std::string>& rules) {
	for (auto& rule : rules) {
		std::size_t pos = 0;
		while ((pos = input.find(rule.first, pos)) != std::string::npos) {
			input.replace(pos, rule.first.length(), rule.second);
			pos += rule.second.length();
		}
	}
	return input;
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestSingleRuleReplacement)
		{
			std::map<std::string, std::string> rules = {
				{"A", "apple"}
			};
			std::string input = "A is for apple.";
			std::string expected = "apple is for apple.";
			Assert::AreEqual(expected, replaceSubstrings(input, rules));
		}

		TEST_METHOD(TestMultipleRuleReplacement)
		{
			std::map<std::string, std::string> rules = {
				{"A", "apple"},
				{"B", "bag"},
				{"S", "shop"}
			};
			std::string input = "I bought a B of As from T S.";
			std::string expected = "I bought a bag of apples from T shop.";
			Assert::AreEqual(expected, replaceSubstrings(input, rules));
		}

		TEST_METHOD(TestEmptyInput)
		{
			std::map<std::string, std::string> rules = {
				{"A", "apple"}
			};
			std::string input = "";
			std::string expected = "";
			Assert::AreEqual(expected, replaceSubstrings(input, rules));
		}

		TEST_METHOD(TestNoRules)
		{
			std::map<std::string, std::string> rules = {};
			std::string input = "This is a test string.";
			std::string expected = "This is a test string.";
			Assert::AreEqual(expected, replaceSubstrings(input, rules));
		}

		TEST_METHOD(TestNoMatchingRules)
		{
			std::map<std::string, std::string> rules = {
				{"A", "apple"}
			};
			std::string input = "This is a test string.";
			std::string expected = "This is a test string.";
			Assert::AreEqual(expected, replaceSubstrings(input, rules));
		}
	};
}

