//
//  util.cpp
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#include "util.h"

// 1. (\+|-)?
// 2. (\+|-)?[0-9]+
bool is_int(const std::string value) {
    int i = 0;
    
    // leading positive (+) or negative (-) sign
    if (i != value.length() && (value[i] == '+' || value[i] == '-'))
        i++;
    
    if (i == value.length())
        return false;
    
    for (; i < value.length(); i++)
        if (!isdigit(value[i]))
            return false;
    
    return true;
}

int parse_int(const std::string value) {
    return is_int(value) ? stoi(value) : INT_MIN;
}

std::vector<std::string> split(const std::string string, const std::string delimeter) {
    std::vector<std::string> result;
    size_t                   start = 0;

    for (int end = 0; end <= (int)string.length() - (int)delimeter.length(); end++) {
        size_t index = 0;

        while (index < delimeter.length() && string[end + index] == delimeter[index])
            index++;

        if (index == delimeter.length()) {
            result.push_back(string.substr(start, end - start));

            start = end + index;
        }
    }

    result.push_back(string.substr(start));

    return result;
}

void split(std::vector<std::string>& target, const std::string source, const std::string delimeter) {
    size_t start = 0;

    for (int end = 0; end <= (int)source.length() - (int)delimeter.length(); end++) {
        size_t index = 0;

        while (index < delimeter.length() && source[end + index] == delimeter[index])
            index++;

        if (index == delimeter.length()) {
            target.push_back(source.substr(start, end - start));

            start = end + index;
        }
    }

    target.push_back(source.substr(start));
}

bool starts_with(const std::string text, const std::string pattern) {
    if (text.length() < pattern.length())
        return false;

    size_t index = 0;

    while (index < pattern.length() && text[index] == pattern[index])
        index++;

    return index == pattern.length();
}

std::string tolowerstr(const std::string string) {
    std::string str = string;

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}
