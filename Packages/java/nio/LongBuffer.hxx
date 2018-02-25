//
//  LongBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef LongBuffer_hxx
#define LongBuffer_hxx

#include "Array.hxx"
#include "Buffer.hxx"


namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    
    
    class LongBuffer : public Buffer
    {
    public:
        LongBuffer(JVM* vm, jobject instance);
        
        static LongBuffer allocate(JVM* vm, std::int32_t capacity);
        Array<std::int64_t> array();
        std::int32_t arrayOffset();
        LongBuffer asReadOnlyBuffer();
        LongBuffer compact();
        std::int32_t compareTo(LongBuffer that);
        LongBuffer duplicate();
        bool equals(Object ob);
        std::int64_t get();
        std::int64_t get(std::int32_t index);
        LongBuffer get(Array<std::int64_t>& dst, std::int32_t offset, std::int32_t length);
        LongBuffer get(Array<std::int64_t>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        LongBuffer put(std::int64_t l);
        LongBuffer put(std::int32_t index, std::int64_t l);
        LongBuffer put(LongBuffer src);
        LongBuffer put(Array<std::int64_t>& src, std::int32_t offset, std::int32_t length);
        LongBuffer put(Array<std::int64_t>& src);
        LongBuffer slice();
        String toString();
        static LongBuffer wrap(JVM* vm, Array<std::int64_t>& array, std::int32_t offset, std::int32_t length);
        static LongBuffer wrap(JVM* vm, Array<std::int64_t>& array);
    };
}

#endif /* LongBuffer_hxx */
