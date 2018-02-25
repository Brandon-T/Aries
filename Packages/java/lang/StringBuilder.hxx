//
//  StringBuilder.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef StringBuilder_hxx
#define StringBuilder_hxx

#include "Array.hxx"
#include "AbstractStringBuilder.hxx"


namespace java::lang
{
    using java::lang::AbstractStringBuilder;
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    using java::lang::StringBuffer;
    
    
    class StringBuilder : public AbstractStringBuilder
    {
    public:
        StringBuilder(JVM* vm, jobject instance);
        StringBuilder(JVM* vm);
        StringBuilder(JVM* vm, std::int32_t capacity);
        StringBuilder(JVM* vm, String str);
        StringBuilder(JVM* vm, CharSequence seq);
        
        StringBuilder append(Object obj);
        StringBuilder append(String str);
        StringBuilder append(StringBuffer sb);
        StringBuilder append(CharSequence s);
        StringBuilder append(CharSequence s, std::int32_t start, std::int32_t end);
        StringBuilder append(Array<char>& str);
        StringBuilder append(Array<char>& str, std::int32_t offset, std::int32_t len);
        StringBuilder append(bool b);
        StringBuilder append(char c);
        StringBuilder append(std::int32_t i);
        StringBuilder append(std::int64_t lng);
        StringBuilder append(float f);
        StringBuilder append(double d);
        StringBuilder appendCodePoint(std::int32_t codePoint);
        StringBuilder remove(std::int32_t start, std::int32_t end); //remove
        StringBuilder deleteCharAt(std::int32_t index);
        std::int32_t indexOf(String str);
        std::int32_t indexOf(String str, std::int32_t fromIndex);
        StringBuilder insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len);
        StringBuilder insert(std::int32_t offset, Object obj);
        StringBuilder insert(std::int32_t offset, String str);
        StringBuilder insert(std::int32_t offset, Array<char>& str);
        StringBuilder insert(std::int32_t dstOffset, CharSequence s);
        StringBuilder insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end);
        StringBuilder insert(std::int32_t offset, bool b);
        StringBuilder insert(std::int32_t offset, char c);
        StringBuilder insert(std::int32_t offset, std::int32_t i);
        StringBuilder insert(std::int32_t offset, std::int64_t l);
        StringBuilder insert(std::int32_t offset, float f);
        StringBuilder insert(std::int32_t offset, double d);
        std::int32_t lastIndexOf(String str);
        std::int32_t lastIndexOf(String str, std::int32_t fromIndex);
        StringBuilder replace(std::int32_t start, std::int32_t end, String str);
        StringBuilder reverse();
        String toString();
    };
}

#endif /* StringBuilder_hxx */
