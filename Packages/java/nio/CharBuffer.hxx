//
//  CharBuffer.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharBuffer_hxx
#define CharBuffer_hxx

#include "Array.hxx"
#include "Buffer.hxx"


namespace java::nio
{
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    using java::util::stream::IntStream;
    
    
    class CharBuffer : public Buffer
    {
    public:
        CharBuffer(JVM* vm, jobject instance);
        
        static CharBuffer allocate(JVM* vm, std::int32_t capacity);
        CharBuffer append(CharSequence csq);
        CharBuffer append(CharSequence csq, std::int32_t start, std::int32_t end);
        CharBuffer append(char c);
        Array<char> array();
        std::int32_t arrayOffset();
        CharBuffer asReadOnlyBuffer();
        char charAt(std::int32_t index);
        IntStream chars();
        CharBuffer compact();
        std::int32_t compareTo(CharBuffer that);
        CharBuffer duplicate();
        bool equals(Object ob);
        char get();
        char get(std::int32_t index);
        CharBuffer get(Array<char>& dst, std::int32_t offset, std::int32_t length);
        CharBuffer get(Array<char>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        std::int32_t length();
        ByteOrder order();
        CharBuffer put(char c);
        CharBuffer put(std::int32_t index, char c);
        CharBuffer put(CharBuffer src);
        CharBuffer put(Array<char>& src, std::int32_t offset, std::int32_t length);
        CharBuffer put(Array<char>& src);
        CharBuffer put(String src, std::int32_t start, std::int32_t end);
        CharBuffer put(String src);
        std::int32_t read(CharBuffer target);
        CharBuffer slice();
        CharBuffer subSequence(std::int32_t start, std::int32_t end);
        String toString();
        static CharBuffer wrap(JVM* vm, Array<char>& array, std::int32_t offset, std::int32_t length);
        static CharBuffer wrap(JVM* vm, Array<char>& array);
        static CharBuffer wrap(JVM* vm, CharSequence csq, std::int32_t start, std::int32_t end);
        static CharBuffer wrap(JVM* vm, CharSequence csq);
    };
}

#endif /* CharBuffer_hxx */
