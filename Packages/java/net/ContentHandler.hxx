//
//  ContentHandler.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef ContentHandler_hxx
#define ContentHandler_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Class;
    using java::lang::Object;
    using java::net::URLConnection;
    
    
    class ContentHandler : public Object
    {
    public:
        ContentHandler(JVM* vm, jobject instance);
        ContentHandler(JVM* vm);
        
        Object getContent(URLConnection urlc);
        Object getContent(URLConnection urlc, Array<Class>& classes);
    };
}

#endif /* ContentHandler_hxx */
