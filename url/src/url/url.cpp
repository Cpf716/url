//
//  url.cpp
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#include "url.h"

// Constructors

url::portinfo::portinfo() {
    this->_value = INT_MIN;
    this->_typed = false;
}

url::portinfo::portinfo(const int value, const bool typed) {
    this->_value = value;
    this->_typed = typed;
}

url::url(const std::string value) {
    int start = 0;

    while (start < (int)value.length() - 1 && (value[start] != '/' || value[start + 1] != '/'))
        start++;

    if (start == value.length() - 1)
        start = 0;
    else {
        if (start) {
            std::string protocol = tolowerstr(value.substr(0, start - 1));

            if (starts_with(protocol, "http"))
                this->_http = protocol == "https" ? secure : unsecured;
        }

        start += 2;
    }

    size_t end = start;

    while (end < value.length() && value[end] != '/')
        end++;

    std::vector<std::string> host = split(value.substr(start, end - start), ":");

    if (host[0] == "localhost")
        host[0] = "127.0.0.1";

    this->_host = host[0];
    this->_port = host.size() == 1 ? portinfo(
                    this->http() == secure ?
                    443 :
                    this->http() == unsecured ?
                    80 :
                    0,
                    false
                ) : portinfo(parse_int(host[1]), true);
    this->_target = value.substr(end);
}

// Member Functions

std::string url::host() const {
    return this->_host;
}

url::http_t url::http() const {
    return this->_http;
}

url::portinfo url::port() const {
    return this->_port;
}

std::string url::target() const {
    return this->_target;
}


bool url::portinfo::typed() const {
    return this->_typed;
}

int url::portinfo::value() const {
    return this->_value;
}
