//
//  main.cpp
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#include "url.h"

int main(int argc, const char * argv[]) {
    class url url("https://dog.ceo/api/breeds/list/all");
    
    std::cout << "host: " << url.host() << std::endl;
}
