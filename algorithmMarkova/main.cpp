#include <iostream>
#include <map>
#include <string>

std::string replaceSubstrings(std::string input, const std::map<std::string, std::string>& rules) {
    for (auto& rule : rules) {
        std::size_t pos = 0;
        while ((pos = input.find(rule.first, pos)) != std::string::npos) {
            input.replace(pos, rule.first.length(), rule.second);
            pos += rule.second.length();
            std::cout << input << std::endl;
        }
    }
    return input;
}

int main() {
    std::map<std::string, std::string> rules = {
        {"A", "apple"},
        {"B", "bag"},
        {"S", "shop"},
        {"T", "the"},
        {"the shop", "my brother"}
    };

    std::string input = "I bought a B of As from T S.";

    std::cout << "First input: " << input << std::endl;

    std::string output = replaceSubstrings(input, rules);
    std::cout << "Resulting string: " << output << std::endl << std::endl;


    std::map<std::string, std::string> rules2 = {
        {"|0", "0||"},
        {"1", "0|"},
        {"0", ""}
    };

    std::string input2 = "101";

    std::cout << "First input: " << input2 << std::endl;

    std::string output2 = replaceSubstrings(input2, rules2);
    std::cout << "Resulting string: " << output2 << std::endl;

    return 0;
}
