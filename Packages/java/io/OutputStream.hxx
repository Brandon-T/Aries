//
//  OutputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef OutputStream_hxx
#define OutputStream_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::io
{
    using java::lang::Object;
    
    
    class OutputStream : public Object
    {
    public:
        OutputStream(JVM* vm, jobject instance);
        OutputStream(JVM* vm);
        
        virtual void close();
        virtual void flush();
        virtual void write(std::int32_t b);
        virtual void write(Array<std::uint8_t>& b);
        virtual void write(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
    };
}

#endif /* OutputStream_hxx */
