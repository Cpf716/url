//
//  util.h
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#ifndef util_h
#define util_h

#include <iostream>

bool                     is_int(const std::string value);

int                      parse_int(const std::string value);

std::vector<std::string> split(const std::string string, const std::string delimeter);

void                     split(std::vector<std::string>& target, const std::string source, const std::string delimeter);

bool                     starts_with(const std::string text, const std::string pattern);

std::string              tolowerstr(const std::string string);

#endif /* util_h */
