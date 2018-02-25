//
//  AbstractStringBuilder.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef AbstractStringBuilder_hxx
#define AbstractStringBuilder_hxx

#include "Object.hxx"
#include "Array.hxx"


namespace java::lang
{
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    using java::lang::StringBuffer;
    
    
    class AbstractStringBuilder : public Object
    {
    public:
        AbstractStringBuilder(JVM* vm, jobject instance);
        
        AbstractStringBuilder append(Object obj);
        AbstractStringBuilder append(String str);
        AbstractStringBuilder append(StringBuffer sb);
        AbstractStringBuilder append(CharSequence s);
        AbstractStringBuilder append(CharSequence s, std::int32_t start, std::int32_t end);
        AbstractStringBuilder append(Array<char>& str);
        AbstractStringBuilder append(Array<char>& str, std::int32_t offset, std::int32_t len);
        AbstractStringBuilder append(bool b);
        AbstractStringBuilder append(char c);
        AbstractStringBuilder append(std::int32_t i);
        AbstractStringBuilder append(std::int64_t l);
        AbstractStringBuilder append(float f);
        AbstractStringBuilder append(double d);
        AbstractStringBuilder appendCodePoint(std::int32_t codePoint);
        std::int32_t capacity();
        char charAt(std::int32_t index);
        std::int32_t codePointAt(std::int32_t index);
        std::int32_t codePointBefore(std::int32_t index);
        std::int32_t codePointCount(std::int32_t beginIndex, std::int32_t endIndex);
        AbstractStringBuilder remove(std::int32_t start, std::int32_t end); //delete
        AbstractStringBuilder deleteCharAt(std::int32_t index);
        void ensureCapacity(std::int32_t minimumCapacity);
        void getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin);
        std::int32_t indexOf(String str);
        std::int32_t indexOf(String str, std::int32_t fromIndex);
        AbstractStringBuilder insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len);
        AbstractStringBuilder insert(std::int32_t offset, Object obj);
        AbstractStringBuilder insert(std::int32_t offset, String str);
        AbstractStringBuilder insert(std::int32_t offset, Array<char>& str);
        AbstractStringBuilder insert(std::int32_t dstOffset, CharSequence s);
        AbstractStringBuilder insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end);
        AbstractStringBuilder insert(std::int32_t offset, bool b);
        AbstractStringBuilder insert(std::int32_t offset, char c);
        AbstractStringBuilder insert(std::int32_t offset, std::int32_t i);
        AbstractStringBuilder insert(std::int32_t offset, std::int64_t l);
        AbstractStringBuilder insert(std::int32_t offset, float f);
        AbstractStringBuilder insert(std::int32_t offset, double d);
        std::int32_t lastIndexOf(String str);
        std::int32_t lastIndexOf(String str, std::int32_t fromIndex);
        std::int32_t length();
        std::int32_t offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset);
        AbstractStringBuilder replace(std::int32_t start, std::int32_t end, String str);
        AbstractStringBuilder reverse();
        void setCharAt(std::int32_t index, char ch);
        void setLength(std::int32_t newLength);
        CharSequence subSequence(std::int32_t start, std::int32_t end);
        String substring(std::int32_t start);
        String substring(std::int32_t start, std::int32_t end);
        String toString();
        void trimToSize();
    };
}

#endif /* AbstractStringBuilder_hxx */
