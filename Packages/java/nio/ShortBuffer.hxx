//
//  ShortBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef ShortBuffer_hxx
#define ShortBuffer_hxx

#include "Array.hxx"
#include "Buffer.hxx"


namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    
    
    class ShortBuffer : public Buffer
    {
    public:
        ShortBuffer(JVM* vm, jobject instance);
        
        static ShortBuffer allocate(JVM* vm, std::int32_t capacity);
        Array<std::int16_t> array();
        std::int32_t arrayOffset();
        ShortBuffer asReadOnlyBuffer();
        ShortBuffer compact();
        std::int32_t compareTo(ShortBuffer that);
        ShortBuffer duplicate();
        bool equals(Object ob);
        std::int16_t get();
        std::int16_t get(std::int32_t index);
        ShortBuffer get(Array<std::int16_t>& dst, std::int32_t offset, std::int32_t length);
        ShortBuffer get(Array<std::int16_t>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        ShortBuffer put(std::int16_t s);
        ShortBuffer put(std::int32_t index, std::int16_t s);
        ShortBuffer put(ShortBuffer src);
        ShortBuffer put(Array<std::int16_t>& src, std::int32_t offset, std::int32_t length);
        ShortBuffer put(Array<std::int16_t>& src);
        ShortBuffer slice();
        String toString();
        static ShortBuffer wrap(JVM* vm, Array<std::int16_t>& array, std::int32_t offset, std::int32_t length);
        static ShortBuffer wrap(JVM* vm, Array<std::int16_t>& array);
    };
}

#endif /* ShortBuffer_hxx */
