//
//  String.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef String_hxx
#define String_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::lang
{
    using java::lang::CharSequence;
    using java::lang::Iterable;
    using java::lang::Object;
    using java::lang::StringBuffer;
    using java::lang::StringBuilder;
    using java::nio::charset::Charset;
    using java::util::Locale;
    
    
    class String : public Object
    {
    public:
        String(JVM* vm, jobject instance);
        String(JVM* vm);
        String(JVM* vm, String original);
        String(JVM* vm, Array<char>& value);
        String(JVM* vm, Array<char>& value, std::int32_t offset, std::int32_t count);
        String(JVM* vm, Array<std::int32_t>& codePoints, std::int32_t offset, std::int32_t count);
        String(JVM* vm, Array<std::uint8_t>& ascii, std::int32_t hibyte, std::int32_t offset, std::int32_t count);
        String(JVM* vm, Array<std::uint8_t>& ascii, std::int32_t hibyte);
        String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length, String charsetName);
        String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length, Charset charset);
        String(JVM* vm, Array<std::uint8_t>& bytes, String charsetName);
        String(JVM* vm, Array<std::uint8_t>& bytes, Charset charset);
        String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length);
        String(JVM* vm, Array<std::uint8_t>& bytes);
        String(JVM* vm, StringBuffer buffer);
        String(JVM* vm, StringBuilder builder);
        
        char charAt(std::int32_t index);
        std::int32_t codePointAt(std::int32_t index);
        std::int32_t codePointBefore(std::int32_t index);
        std::int32_t codePointCount(std::int32_t beginIndex, std::int32_t endIndex);
        std::int32_t compareTo(String anotherString);
        std::int32_t compareToIgnoreCase(String str);
        String concat(String str);
        bool contains(CharSequence s);
        bool contentEquals(StringBuffer sb);
        bool contentEquals(CharSequence cs);
        static String copyValueOf(JVM* vm, Array<char>& data, std::int32_t offset, std::int32_t count);
        static String copyValueOf(JVM* vm, Array<char>& data);
        bool endsWith(String suffix);
        bool equals(Object anObject);
        bool equalsIgnoreCase(String anotherString);
        static String format(JVM* vm, String format, Array<Object>& args);
        static String format(JVM* vm, Locale locale, String format, Array<Object>& args);
        void getBytes(std::int32_t srcBegin, std::int32_t srcEnd, Array<std::uint8_t>& dst, std::int32_t dstBegin);
        Array<std::uint8_t> getBytes(String charsetName);
        Array<std::uint8_t> getBytes(Charset charset);
        Array<std::uint8_t> getBytes();
        void getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin);
        std::int32_t hashCode();
        std::int32_t indexOf(std::int32_t ch);
        std::int32_t indexOf(std::int32_t ch, std::int32_t fromIndex);
        std::int32_t indexOf(String str);
        std::int32_t indexOf(String str, std::int32_t fromIndex);
        String intern();
        bool isEmpty();
        static String join(JVM* vm, CharSequence delimiter, Array<CharSequence>& elements);
        static String join(JVM* vm, CharSequence delimiter, Iterable<CharSequence> elements);
        std::int32_t lastIndexOf(std::int32_t ch);
        std::int32_t lastIndexOf(std::int32_t ch, std::int32_t fromIndex);
        std::int32_t lastIndexOf(String str);
        std::int32_t lastIndexOf(String str, std::int32_t fromIndex);
        std::int32_t length();
        bool matches(String regex);
        std::int32_t offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset);
        bool regionMatches(std::int32_t toffset, String other, std::int32_t ooffset, std::int32_t len);
        bool regionMatches(bool ignoreCase, std::int32_t toffset, String other, std::int32_t ooffset, std::int32_t len);
        String replace(char oldChar, char newChar);
        String replace(CharSequence target, CharSequence replacement);
        String replaceAll(String regex, String replacement);
        String replaceFirst(String regex, String replacement);
        Array<String> split(String regex, std::int32_t limit);
        Array<String> split(String regex);
        bool startsWith(String prefix, std::int32_t toffset);
        bool startsWith(String prefix);
        CharSequence subSequence(std::int32_t beginIndex, std::int32_t endIndex);
        String substring(std::int32_t beginIndex);
        String substring(std::int32_t beginIndex, std::int32_t endIndex);
        Array<char> toCharArray();
        String toLowerCase(Locale locale);
        String toLowerCase();
        String toString();
        String toUpperCase(Locale locale);
        String toUpperCase();
        String trim();
        static String valueOf(JVM* vm, Object obj);
        static String valueOf(JVM* vm, Array<char>& data);
        static String valueOf(JVM* vm, Array<char>& data, std::int32_t offset, std::int32_t count);
        static String valueOf(JVM* vm, bool b);
        static String valueOf(JVM* vm, char c);
        static String valueOf(JVM* vm, std::int32_t i);
        static String valueOf(JVM* vm, std::int64_t l);
        static String valueOf(JVM* vm, float f);
        static String valueOf(JVM* vm, double d);
    };
}

#endif /* String_hxx */
