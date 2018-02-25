//
//  FloatBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FloatBuffer_hxx
#define FloatBuffer_hxx

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
    
    
    class FloatBuffer : public Buffer
    {
    public:
        FloatBuffer(JVM* vm, jobject instance);
        
        static FloatBuffer allocate(JVM* vm, std::int32_t capacity);
        Array<float> array();
        std::int32_t arrayOffset();
        FloatBuffer asReadOnlyBuffer();
        FloatBuffer compact();
        std::int32_t compareTo(FloatBuffer that);
        FloatBuffer duplicate();
        bool equals(Object ob);
        float get();
        float get(std::int32_t index);
        FloatBuffer get(Array<float>& dst, std::int32_t offset, std::int32_t length);
        FloatBuffer get(Array<float>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        FloatBuffer put(float f);
        FloatBuffer put(std::int32_t index, float f);
        FloatBuffer put(FloatBuffer src);
        FloatBuffer put(Array<float>& src, std::int32_t offset, std::int32_t length);
        FloatBuffer put(Array<float>& src);
        FloatBuffer slice();
        String toString();
        static FloatBuffer wrap(JVM* vm, Array<float>& array, std::int32_t offset, std::int32_t length);
        static FloatBuffer wrap(JVM* vm, Array<float>& array);
    };
}

#endif /* FloatBuffer_hxx */
