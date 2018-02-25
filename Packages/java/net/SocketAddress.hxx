//
//  SocketAddress.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef SocketAddress_hxx
#define SocketAddress_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    
    
    class SocketAddress : public Object
    {
    public:
        SocketAddress(JVM* vm, jobject instance);
        SocketAddress(JVM* vm);
    };
}

#endif /* SocketAddress_hxx */
