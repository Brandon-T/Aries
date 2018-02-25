//
//  InputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef InputStream_hxx
#define InputStream_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::io
{
    using java::lang::Object;
    
    
    class InputStream : public Object
    {
    public:
        InputStream(JVM* vm, jobject instance);
        InputStream(JVM* vm);
        
        virtual std::int32_t available();
        virtual void close();
        virtual void mark(std::int32_t readlimit);
        virtual bool markSupported();
        virtual std::int32_t read();
        virtual std::int32_t read(Array<std::uint8_t>& b);
        virtual std::int32_t read(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        virtual void reset();
        virtual std::int64_t skip(std::int64_t n);
    };
}

#endif /* InputStream_hxx */
