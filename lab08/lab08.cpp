#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    size_t length;

public:
    // Constructor that creates a MyString object from a C-style string
    MyString(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Destructor that frees any heap storage allocated
    ~MyString() {
        delete[] str;
    }

    // Convert a MyString to a C-style string
    const char* toString() const {
        return str;
    }

    // Overload the assignment operator for deep copy
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this; // Self-assignment; no need to copy
        }

        delete[] str; // Deallocate existing resources

        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);

        return *this;
    }

    // Return the number of characters in the string
    size_t getLength() const {
        return length;
    }

    // Return a substring starting at index 'start' and extending 'n' characters or through the end
    MyString substr(size_t start, size_t n = static_cast<size_t>(-1)) const {
        if (start >= length) {
            return MyString("");  // Out of range
        }

        if (n == static_cast<size_t>(-1) || start + n > length) {
            n = length - start;
        }

        return MyString(str + start);
    }

    // Overload the + operator to concatenate two MyString objects
    MyString operator+(const MyString& other) const {
        MyString result(*this);
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        std::strcpy(newStr, result.str);
        std::strcat(newStr, other.str);
        result.length = newLength;
        delete[] result.str;
        result.str = newStr;
        return result;
    }

    // Overload the += operator to append a character or a string to the end
    MyString& operator+=(const MyString& other) {
        if (other.length == 0) {
            return *this; // No need to append an empty string.
        }

        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);
        delete[] str;
        length = newLength;
        str = newStr;
        return *this;
    }

    // Overload the += operator to append a character
    MyString& operator+=(char ch) {
        char chStr[2] = {ch, '\0'};
        return (*this += MyString(chStr));
    }
    char& operator[](size_t index) {
        if (index < length) {
            return str[index];
        }
        return str[length - 1];
    }

    // Overload the equality operator (==) to compare MyString objects lexicographically
    bool operator==(const MyString& other) const {
        return std::strcmp(str, other.str) == 0;
    }

    // Overload the inequality operator (!=) to compare MyString objects lexicographically
    bool operator!=(const MyString& other) const {
        return std::strcmp(str, other.str) != 0;
    }

    // Overload the less than operator (<) to compare MyString objects lexicographically
    bool operator<(const MyString& other) const {
        return std::strcmp(str, other.str) < 0;
    }

    // Overload the less than or equal to operator (<=) to compare MyString objects lexicographically
    bool operator<=(const MyString& other) const {
        return std::strcmp(str, other.str) <= 0;
    }

    // Overload the greater than operator (>) to compare MyString objects lexicographically
    bool operator>(const MyString& other) const {
        return std::strcmp(str, other.str) > 0;
    }

    // Overload the greater than or equal to operator (>=) to compare MyString objects lexicographically
    bool operator>=(const MyString& other) const {
        return std::strcmp(str, other.str) >= 0;
    }
    
};

int main() {
    MyString myStr("Hello, World!");

    // Copy constructor test
    MyString copyStr(myStr);

    // Modify the original string
    myStr[7] = 'X';

    // Output the original and copied strings
    std::cout << "Original String: " << myStr.toString() << std::endl;
    std::cout << "Copied String: " << copyStr.toString() << std::endl;

    // Assignment operator test
    MyString assignedStr("Assignment Test");
    assignedStr = myStr;

    // Modify the original string again
    myStr[0] = 'H';

    // Output the original, copied, and assigned strings
    std::cout << "Original String: " << myStr.toString() << std::endl;
    std::cout << "Copied String: " << copyStr.toString() << std::endl;
    std::cout << "Assigned String: " << assignedStr.toString() << std::endl;

    // Testing other methods
    std::cout << "Length of myStr: " << myStr.getLength() << std::endl;
    
    MyString substr = myStr.substr(7, 5);
    std::cout << "Substring of myStr: " << substr.toString() << std::endl;

    MyString appendedStr(" Appended");
    myStr += appendedStr;
    std::cout << "Modified myStr after appending: " << myStr.toString() << std::endl;

    char character = myStr[0];
    std::cout << "Character at index 0 of myStr: " << character << std::endl;

    if (myStr == copyStr) {
        std::cout << "myStr is equal to copyStr" << std::endl;
    } else {
        std::cout << "myStr is not equal to copyStr" << std::endl;
    }

    if (myStr < assignedStr) {
        std::cout << "myStr is less than assignedStr" << std::endl;
    } else {
        std::cout << "myStr is not less than assignedStr" << std::endl;
    }

    return 0;
}
