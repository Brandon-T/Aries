//
//  StringBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef StringBuffer_hxx
#define StringBuffer_hxx

#include "AbstractStringBuilder.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"


namespace java::lang
{
    using java::lang::AbstractStringBuilder;
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    
    
    class StringBuffer : public AbstractStringBuilder
    {
    public:
        StringBuffer(JVM* vm, jobject instance);
        StringBuffer(JVM* vm);
        StringBuffer(JVM* vm, std::int32_t capacity);
        StringBuffer(JVM* vm, String str);
        StringBuffer(JVM* vm, CharSequence seq);
        
        StringBuffer append(Object obj);
        StringBuffer append(String str);
        StringBuffer append(StringBuffer sb);
        StringBuffer append(CharSequence s);
        StringBuffer append(CharSequence s, std::int32_t start, std::int32_t end);
        StringBuffer append(Array<char>& str);
        StringBuffer append(Array<char>& str, std::int32_t offset, std::int32_t len);
        StringBuffer append(bool b);
        StringBuffer append(char c);
        StringBuffer append(std::int32_t i);
        StringBuffer append(std::int64_t lng);
        StringBuffer append(float f);
        StringBuffer append(double d);
        StringBuffer appendCodePoint(std::int32_t codePoint);
        std::int32_t capacity();
        char charAt(std::int32_t index);
        std::int32_t codePointAt(std::int32_t index);
        std::int32_t codePointBefore(std::int32_t index);
        std::int32_t codePointCount(std::int32_t beginIndex, std::int32_t endIndex);
        StringBuffer remove(std::int32_t start, std::int32_t end); //delete
        StringBuffer deleteCharAt(std::int32_t index);
        void ensureCapacity(std::int32_t minimumCapacity);
        void getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin);
        std::int32_t indexOf(String str);
        std::int32_t indexOf(String str, std::int32_t fromIndex);
        StringBuffer insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len);
        StringBuffer insert(std::int32_t offset, Object obj);
        StringBuffer insert(std::int32_t offset, String str);
        StringBuffer insert(std::int32_t offset, Array<char>& str);
        StringBuffer insert(std::int32_t dstOffset, CharSequence s);
        StringBuffer insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end);
        StringBuffer insert(std::int32_t offset, bool b);
        StringBuffer insert(std::int32_t offset, char c);
        StringBuffer insert(std::int32_t offset, std::int32_t i);
        StringBuffer insert(std::int32_t offset, std::int64_t l);
        StringBuffer insert(std::int32_t offset, float f);
        StringBuffer insert(std::int32_t offset, double d);
        std::int32_t lastIndexOf(String str);
        std::int32_t lastIndexOf(String str, std::int32_t fromIndex);
        std::int32_t length();
        std::int32_t offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset);
        StringBuffer replace(std::int32_t start, std::int32_t end, String str);
        StringBuffer reverse();
        void setCharAt(std::int32_t index, char ch);
        void setLength(std::int32_t newLength);
        CharSequence subSequence(std::int32_t start, std::int32_t end);
        String substring(std::int32_t start);
        String substring(std::int32_t start, std::int32_t end);
        String toString();
        void trimToSize();
    };
}

#endif /* StringBuffer_hxx */
