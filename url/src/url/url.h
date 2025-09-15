//
//  url.h
//  url
//
//  Created by Corey Ferguson on 9/15/25.
//

#ifndef url_h
#define url_h

#include "util.h"

struct url {
    // Typdef

    enum http_t { no, secure, unsecured };

    class portinfo {
        // Constructors
        
        portinfo();

        portinfo(const int value, const bool typed);
        
        // Member Fields

        bool _typed;
        int  _value;
    public:
        // Typdef
        
        friend url;
        
        // Member Functions

        bool typed() const;

        int  value() const;
    };

    // Constructors

    url(const std::string value);

    // Member Functions

    std::string    host() const;

    http_t         http() const;

    class portinfo port() const;

    std::string    target() const;
private:
    // Member Fields

    std::string    _host;
    http_t         _http = no;
    class portinfo _port;
    std::string    _target;
};

#endif /* url_h */
