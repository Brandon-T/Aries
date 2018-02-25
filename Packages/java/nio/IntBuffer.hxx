//
//  IntBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef IntBuffer_hxx
#define IntBuffer_hxx

#include "Object.hxx"
#include "String.hxx"
#include "Buffer.hxx"
#include "ByteOrder.hxx"


namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    
    
    class IntBuffer : public Buffer
    {
    public:
        IntBuffer(JVM* vm, jobject instance);
        
        static IntBuffer allocate(JVM* vm, std::int32_t capacity);
        Array<std::int32_t> array();
        std::int32_t arrayOffset();
        IntBuffer asReadOnlyBuffer();
        IntBuffer compact();
        std::int32_t compareTo(IntBuffer that);
        IntBuffer duplicate();
        bool equals(Object ob);
        std::int32_t get();
        std::int32_t get(std::int32_t index);
        IntBuffer get(Array<std::int32_t>& dst, std::int32_t offset, std::int32_t length);
        IntBuffer get(Array<std::int32_t>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        IntBuffer put(std::int32_t i);
        IntBuffer put(std::int32_t index, std::int32_t i);
        IntBuffer put(IntBuffer src);
        IntBuffer put(Array<std::int32_t>& src, std::int32_t offset, std::int32_t length);
        IntBuffer put(Array<std::int32_t>& src);
        IntBuffer slice();
        String toString();
        static IntBuffer wrap(JVM* vm, Array<std::int32_t>& array, std::int32_t offset, std::int32_t length);
        static IntBuffer wrap(JVM* vm, Array<std::int32_t>& array);
    };
}

#endif /* IntBuffer_hxx */
