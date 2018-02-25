//
//  Proxy.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Proxy_hxx
#define Proxy_hxx

#include "Array.hxx"
#include "Object.hxx"
#include "Enum.hxx"


namespace java::net
{
    using java::lang::Enum;
    using java::lang::Object;
    using java::lang::String;
    using java::net::SocketAddress;
    
    
    class Proxy : public Object
    {
    public:
        class Type : public Enum
        {
        public:
            Type(JVM* vm, jobject instance);
            
            static Type valueOf(JVM* vm, String value);
            static Array<Type> values(JVM* vm);
        };
        
        Proxy(JVM* vm, jobject instance);
        Proxy(JVM* vm, Type proxyType, SocketAddress address);
        
        SocketAddress address();
        bool equals(Object obj);
        std::int32_t hashCode();
        String toString();
        Type type();
    };
}

#endif /* Proxy_hxx */
