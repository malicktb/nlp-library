# nlp-library
C++ library for text preprocessing, tokenization, and word counting. Easily integrate NLP in C++ apps.

# Features
- **Text Cleaning**: Convert text to lowercase and remove punctuation to standardize the input.
- **Word Tokenization**: Break text into individual words, providing a basis for further analysis.
- **Word Counting**: Count the occurrences of each word in the provided text.

# Usage
1. **Load Text**: Use the `loadText` function to load and clean the text from a file.
   
    ```cpp
    NLPAnalyzer analyzer;
    analyzer.loadText("sample_text.txt");
    ```

2. **Tokenize Text**: Tokenize the text into words using the `tokenize` function.

    ```cpp
    std::vector<std::string> tokens = analyzer.tokenize();
    ```

3. **Count Words**: Count the occurrences of each word in the text using the `countWords` function.

    ```cpp
    std::map<std::string, int> wordCounts = analyzer.countWords();
    ```
