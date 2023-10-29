#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <locale>
#include <map>

// Define your dictionary
std::unordered_map<std::string, std::string> pirateDictionary = {
    {"hello", "ahoy"},
    {"excuse me", "arrr"},
    {"sir", "matey"},
    {"boy", "matey"},
    {"man", "matey"},
    {"madame", "proud beauty"},
    {"officer", "foul blaggart"},
    {"the", "th'"},
    {"my", "me"},
    {"your", "yer"},
    {"is", "be"},
    {"are", "be"},
    {"restroom", "head"},
    {"restaurant", "galley"},
    {"hotel", "fleabag inn"},
    {"coins", "doubloons"},
    {"pirate", "buccaneer"},
    {"friend", "mate"},
    {"you", "ye"}
};

// Function to translate a word
std::string translateWord(const std::string& word) {
    std::string translatedWord = word;
    std::string trailingPunctuation;

    // Check if the last character is punctuation
    if (std::ispunct(word.back())) {
        translatedWord = word.substr(0, word.size() - 1);
        trailingPunctuation = word.substr(word.size() - 1);
    }

    bool isCapitalized = false;

    // Check if the word is capitalized
    if (std::isupper(word[0])) {
        isCapitalized = true;
    }

    // Convert the word to lowercase for dictionary lookup
    std::string lowerCaseWord = translatedWord;
    for (char &c : lowerCaseWord) {
        c = std::tolower(c);
    }

    auto it = pirateDictionary.find(lowerCaseWord);
    if (it != pirateDictionary.end()) {
        translatedWord = it->second;
    }

    // If the original word was capitalized, capitalize the translated word
    if (isCapitalized) {
        translatedWord[0] = std::toupper(translatedWord[0], std::locale());
    }

    return translatedWord + trailingPunctuation;
}

// Function to convert a sentence to pirate speech
std::string toPirateSpeech(const std::string& sentence) {
    std::stringstream result;
    std::stringstream wordStream(sentence);
    std::string word;

    while (wordStream >> word) {
        // Preserve capitalization
        bool isCapitalized = std::isupper(word[0]);
        std::string translatedWord = translateWord(word);

        if (isCapitalized) {
            translatedWord[0] = std::toupper(translatedWord[0], std::locale());
        }

        result << translatedWord << " ";
    }

    // Get the remaining non-space characters (punctuation)
    std::string remaining;
    getline(wordStream, remaining);
    result << remaining;

    return result.str();
}

// Function to convert a Roman numeral to its numeric form
int romanToDecimal(const std::string& str) {
    // Create a Roman numeral to decimal value lookup table
    std::map<char, int> romanToDecimalTable;
    romanToDecimalTable['I'] = 1;
    romanToDecimalTable['V'] = 5;
    romanToDecimalTable['X'] = 10;
    romanToDecimalTable['L'] = 50;
    romanToDecimalTable['C'] = 100;
    romanToDecimalTable['D'] = 500;
    romanToDecimalTable['M'] = 1000;

    int result = 0;
    int prevValue = 0;

    // Iterate through the input string from right to left
    for (int i = str.size() - 1; i >= 0; --i) {
        char currentChar = str[i];
        int currentValue = romanToDecimalTable[currentChar];

        // If the current value is smaller than the previous value, subtract it
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

int main() {
    std::string romanNumeral;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> romanNumeral;
    std::cin.ignore(); // Ignore the newline character

    int decimalValue = romanToDecimal(romanNumeral);
    std::cout << "The decimal equivalent is: " << decimalValue << std::endl;

    std::string input;
    std::cout << "Enter a sentence in regular English: ";
    std::getline(std::cin, input);

    std::string pirateSpeech = toPirateSpeech(input);
    std::cout << "Pirate Speech: " << pirateSpeech << std::endl;

    return 0;
}