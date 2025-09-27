//
//  util.h
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#ifndef util_h
#define util_h

#include <iostream>
#include <sstream>

bool                     is_int(const std::string value);

bool                     is_number(const std::string value);

std::string              join(std::vector<std::string> values, std::string delimeter);

int                      parse_int(const std::string value);

double                   parse_number(const std::string value);

std::vector<std::string> split(const std::string string, const std::string delimeter);

void                     split(std::vector<std::string>& target, const std::string source, const std::string delimeter);

std::string              tolowerstr(const std::string string);

std::string              trim(const std::string string);

#endif /* util_h */
