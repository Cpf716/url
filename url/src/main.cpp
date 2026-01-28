//
//  main.cpp
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#include "url.h"

int main(int argc, const char * argv[]) {
    class url url("https://www.google.com/search?q=Query%20string&ie=utf-8");
    
    url.params()["oe"] = std::string("utf-8");
    
    std::cout << "query: " << url.query() << std::endl;
}
