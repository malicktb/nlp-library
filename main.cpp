#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <locale>

class NLPAnalyzer {
public:
    // Constructor
    NLPAnalyzer() {}

    // Load text from a file and clean it
    void loadText(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            std::string text;

            while (std::getline(file, line)) {
                text += line;
            }

            // Clean the text
            cleanText(text);
            file.close();
        }
    }

    // Tokenize the text into words
    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        std::istringstream iss(cleanedText);

        std::string word;
        while (iss >> word) {
            tokens.push_back(word);
        }

        return tokens;
    }

    // Count the occurrences of each word
    std::map<std::string, int> countWords() {
        std::map<std::string, int> wordCounts;
        std::vector<std::string> tokens = tokenize();

        for (const std::string& word : tokens) {
            wordCounts[word]++;
        }

        return wordCounts;
    }

private:
    std::string cleanedText;

    // Clean the text by converting to lowercase and removing punctuation
    void cleanText(std::string& text) {
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        text.erase(std::remove_if(text.begin(), text.end(), ::ispunct), text.end());
        cleanedText = text;
    }
};

int main() {
    NLPAnalyzer analyzer;

    // Load and clean the text from a file
    analyzer.loadText("sample_text.txt");

    // Count the occurrences of each word
    std::map<std::string, int> wordCounts = analyzer.countWords();

    // Display the word counts
    for (const auto& pair : wordCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
