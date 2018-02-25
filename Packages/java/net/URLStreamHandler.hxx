//
//  URLStreamHandler.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef URLStreamHandler_hxx
#define URLStreamHandler_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::InetAddress;
    using java::net::Proxy;
    using java::net::URL;
    using java::net::URLConnection;
    
    
    class URLStreamHandler : public Object
    {
    public:
        URLStreamHandler(JVM* vm, jobject instance);
        URLStreamHandler(JVM* vm);
        
    protected:
        bool equals(URL u1, URL u2);
        std::int32_t getDefaultPort();
        InetAddress getHostAddress(URL u);
        std::int32_t hashCode(URL u);
        bool hostsEqual(URL u1, URL u2);
        URLConnection openConnection(URL u);
        URLConnection openConnection(URL u, Proxy p);
        void parseURL(URL u, String spec, std::int32_t start, std::int32_t limit);
        bool sameFile(URL u1, URL u2);
        void setURL(URL u, String protocol, String host, std::int32_t port, String authority, String userInfo, String path, String query, String ref);
        void setURL(URL u, String protocol, String host, std::int32_t port, String file, String ref);
        String toExternalForm(URL u);
    };
}

#endif /* URLStreamHandler_hxx */
