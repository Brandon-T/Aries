//
//  URLStreamHandlerFactory.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef URLStreamHandlerFactory_hxx
#define URLStreamHandlerFactory_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::URLStreamHandler;
    
    
    class URLStreamHandlerFactory : public Object
    {
    public:
        URLStreamHandlerFactory(JVM* vm, jobject instance);
        
        URLStreamHandler createURLStreamHandler(String protocol);
    };
}

#endif /* URLStreamHandlerFactory_hxx */
