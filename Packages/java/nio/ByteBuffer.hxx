//
//  ByteBuffer.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteBuffer_hxx
#define ByteBuffer_hxx

#include "Object.hxx"
#include "Array.hxx"
#include "String.hxx"
#include "Buffer.hxx"
#include "ByteOrder.hxx"
#include "CharBuffer.hxx"
#include "DoubleBuffer.hxx"
#include "FloatBuffer.hxx"
#include "IntBuffer.hxx"
#include "LongBuffer.hxx"
#include "ShortBuffer.hxx"

namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    using java::nio::CharBuffer;
    using java::nio::DoubleBuffer;
    using java::nio::FloatBuffer;
    using java::nio::IntBuffer;
    using java::nio::LongBuffer;
    using java::nio::ShortBuffer;
    
    
    class ByteBuffer : public Buffer
    {
    public:
        ByteBuffer(JVM* vm, jobject instance);
        
        static ByteBuffer allocate(JVM* vm, std::int32_t capacity);
        static ByteBuffer allocateDirect(JVM* vm, std::int32_t capacity);
        Array<std::uint8_t> array();
        std::int32_t arrayOffset();
        CharBuffer asCharBuffer();
        DoubleBuffer asDoubleBuffer();
        FloatBuffer asFloatBuffer();
        IntBuffer asIntBuffer();
        LongBuffer asLongBuffer();
        ByteBuffer asReadOnlyBuffer();
        ShortBuffer asShortBuffer();
        ByteBuffer compact();
        std::int32_t compareTo(ByteBuffer that);
        ByteBuffer duplicate();
        bool equals(Object ob);
        std::uint8_t get();
        std::uint8_t get(std::int32_t index);
        ByteBuffer get(Array<std::uint8_t>& dst, std::int32_t offset, std::int32_t length);
        ByteBuffer get(Array<std::uint8_t>& dst);
        char getChar();
        char getChar(std::int32_t index);
        double getDouble();
        double getDouble(std::int32_t index);
        float getFloat();
        float getFloat(std::int32_t index);
        std::int32_t getInt();
        std::int32_t getInt(std::int32_t index);
        std::int64_t getLong();
        std::int64_t getLong(std::int32_t index);
        std::int16_t getShort();
        std::int16_t getShort(std::int32_t index);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        ByteBuffer order(ByteOrder bo);
        ByteBuffer put(std::uint8_t b);
        ByteBuffer put(std::int32_t index, std::uint8_t b);
        ByteBuffer put(ByteBuffer src);
        ByteBuffer put(Array<std::uint8_t>& src, std::int32_t offset, std::int32_t length);
        ByteBuffer put(Array<std::uint8_t>& src);
        ByteBuffer putChar(char value);
        ByteBuffer putChar(std::int32_t index, char value);
        ByteBuffer putDouble(double value);
        ByteBuffer putDouble(std::int32_t index, double value);
        ByteBuffer putFloat(float value);
        ByteBuffer putFloat(std::int32_t index, float value);
        ByteBuffer putInt(std::int32_t value);
        ByteBuffer putInt(std::int32_t index, std::int32_t value);
        ByteBuffer putLong(std::int64_t value);
        ByteBuffer putLong(std::int32_t index, std::int64_t value);
        ByteBuffer putShort(std::int16_t value);
        ByteBuffer putShort(std::int32_t index, std::int16_t value);
        ByteBuffer slice();
        String toString();
        static ByteBuffer wrap(JVM* vm, Array<std::uint8_t>& array, std::int32_t offset, std::int32_t length);
        static ByteBuffer wrap(JVM* vm, Array<std::uint8_t>& array);
    };
}

#endif /* ByteBuffer_hxx */
