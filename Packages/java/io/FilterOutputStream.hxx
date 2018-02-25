//
//  FilterOutputStream.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FilterOutputStream_hxx
#define FilterOutputStream_hxx

#include "Array.hxx"
#include "OutputStream.hxx"


namespace java::io
{
    using java::io::OutputStream;
    
    
    class FilterOutputStream : public OutputStream
    {
    public:
        FilterOutputStream(JVM* vm, jobject instance);
        FilterOutputStream(JVM* vm, OutputStream out);
        
        void close();
        void flush();
        void write(std::int32_t b);
        void write(Array<std::uint8_t>& b);
        void write(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
    };
}

#endif /* FilterOutputStream_hxx */
