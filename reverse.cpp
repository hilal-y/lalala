#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

std::string reverseString(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>());

    std::reverse(words.begin(), words.end());

    std::ostringstream oss;
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(oss, " "));
    std::string reversedString = oss.str();
    reversedString.pop_back(); // Remove trailing space
    return reversedString;
}

int main() {
    std::string input1 = "The weather is so sunny nowadays";
    std::string input2 = "Life is so beautiful";

    std::cout << reverseString(input1) << std::endl;
    std::cout << reverseString(input2) << std::endl;

    return 0;
}
