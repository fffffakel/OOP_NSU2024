#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::vector<std::string> words;
    std::string word;


    while (std::cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        std::cout << std::endl;
        return 0;
    }

    std::set<char> common_letters(words[0].begin(), words[0].end());

    for (size_t i = 1; i < words.size(); ++i) {
        std::set<char> current_letters(words[i].begin(), words[i].end());
        std::set<char> intersection;

        std::set_intersection(common_letters.begin(), common_letters.end(),
            current_letters.begin(), current_letters.end(),
            std::inserter(intersection, intersection.begin()));

        common_letters = intersection;
    }
    for (char letter : common_letters) {
        std::cout << letter;
    }
    std::cout << std::endl;

    return 0;
}