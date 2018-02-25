//
//  ContentHandlerFactory.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef ContentHandlerFactory_hxx
#define ContentHandlerFactory_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::ContentHandler;
    
    
    class ContentHandlerFactory : public Object
    {
    public:
        ContentHandlerFactory(JVM* vm, jobject instance);
        
        ContentHandler createContentHandler(String mimetype);
    };
}

#endif /* ContentHandlerFactory_hxx */
