//
//  URL.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef URL_hxx
#define URL_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::io::InputStream;
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    using java::net::Proxy;
    using java::net::URI;
    using java::net::URLConnection;
    using java::net::URLStreamHandler;
    using java::net::URLStreamHandlerFactory;
    
    
    class URL : public Object
    {
    public:
        URL(JVM* vm, jobject instance);
        URL(JVM* vm, String protocol, String host, std::int32_t port, String file);
        URL(JVM* vm, String protocol, String host, String file);
        URL(JVM* vm, String protocol, String host, std::int32_t port, String file, URLStreamHandler handler);
        URL(JVM* vm, String file);
        URL(JVM* vm, URL context, String spec);
        URL(JVM* vm, URL context, String spec, URLStreamHandler handler);
        
        bool equals(Object obj);
        String getAuthority();
        Object getContent();
        Object getContent(Array<Class>& classes);
        std::int32_t getDefaultPort();
        String getFile();
        String getHost();
        String getPath();
        std::int32_t getPort();
        String getProtocol();
        String getQuery();
        String getRef();
        String getUserInfo();
        std::int32_t hashCode();
        URLConnection openConnection();
        URLConnection openConnection(Proxy proxy);
        InputStream openStream();
        bool sameFile(URL other);
        static void setURLStreamHandlerFactory(JVM* vm, URLStreamHandlerFactory fac);
        String toExternalForm();
        String toString();
        URI toURI();
    };
}

#endif /* URL_hxx */
