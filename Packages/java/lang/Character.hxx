//
//  Character.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Character_hxx
#define Character_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::lang
{
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    
    
    class Character : public Object
    {
    public:
        Character(JVM* vm, jobject instance);
        Character(JVM* vm, char value);
        
        static std::int32_t charCount(JVM* vm, std::int32_t codePoint);
        char charValue();
        static std::int32_t codePointAt(JVM* vm, CharSequence seq, std::int32_t index);
        static std::int32_t codePointAt(JVM* vm, Array<char>& a, std::int32_t index);
        static std::int32_t codePointAt(JVM* vm, Array<char>& a, std::int32_t index, std::int32_t limit);
        static std::int32_t codePointBefore(JVM* vm, CharSequence seq, std::int32_t index);
        static std::int32_t codePointBefore(JVM* vm, Array<char>& a, std::int32_t index);
        static std::int32_t codePointBefore(JVM* vm, Array<char>& a, std::int32_t index, std::int32_t start);
        static std::int32_t codePointCount(JVM* vm, CharSequence seq, std::int32_t beginIndex, std::int32_t endIndex);
        static std::int32_t codePointCount(JVM* vm, Array<char>& a, std::int32_t offset, std::int32_t count);
        static std::int32_t compare(JVM* vm, char x, char y);
        std::int32_t compareTo(Character anotherCharacter);
        static std::int32_t digit(JVM* vm, char ch, std::int32_t radix);
        static std::int32_t digit(JVM* vm, std::int32_t codePoint, std::int32_t radix);
        bool equals(Object obj);
        static char forDigit(JVM* vm, std::int32_t digit, std::int32_t radix);
        static std::uint8_t getDirectionality(JVM* vm, char ch);
        static std::uint8_t getDirectionality(JVM* vm, std::int32_t codePoint);
        static String getName(JVM* vm, std::int32_t codePoint);
        static std::int32_t getNumericValue(JVM* vm, char ch);
        static std::int32_t getNumericValue(JVM* vm, std::int32_t codePoint);
        static std::int32_t getType(JVM* vm, char ch);
        static std::int32_t getType(JVM* vm, std::int32_t codePoint);
        std::int32_t hashCode();
        static std::int32_t hashCode(JVM* vm, char value);
        static char highSurrogate(JVM* vm, std::int32_t codePoint);
        static bool isAlphabetic(JVM* vm, std::int32_t codePoint);
        static bool isBmpCodePoint(JVM* vm, std::int32_t codePoint);
        static bool isDefined(JVM* vm, char ch);
        static bool isDefined(JVM* vm, std::int32_t codePoint);
        static bool isDigit(JVM* vm, char ch);
        static bool isDigit(JVM* vm, std::int32_t codePoint);
        static bool isHighSurrogate(JVM* vm, char ch);
        static bool isISOControl(JVM* vm, char ch);
        static bool isISOControl(JVM* vm, std::int32_t codePoint);
        static bool isIdentifierIgnorable(JVM* vm, char ch);
        static bool isIdentifierIgnorable(JVM* vm, std::int32_t codePoint);
        static bool isIdeographic(JVM* vm, std::int32_t codePoint);
        static bool isJavaIdentifierPart(JVM* vm, char ch);
        static bool isJavaIdentifierPart(JVM* vm, std::int32_t codePoint);
        static bool isJavaIdentifierStart(JVM* vm, char ch);
        static bool isJavaIdentifierStart(JVM* vm, std::int32_t codePoint);
        static bool isJavaLetter(JVM* vm, char ch);
        static bool isJavaLetterOrDigit(JVM* vm, char ch);
        static bool isLetter(JVM* vm, char ch);
        static bool isLetter(JVM* vm, std::int32_t codePoint);
        static bool isLetterOrDigit(JVM* vm, char ch);
        static bool isLetterOrDigit(JVM* vm, std::int32_t codePoint);
        static bool isLowSurrogate(JVM* vm, char ch);
        static bool isLowerCase(JVM* vm, char ch);
        static bool isLowerCase(JVM* vm, std::int32_t codePoint);
        static bool isMirrored(JVM* vm, char ch);
        static bool isMirrored(JVM* vm, std::int32_t codePoint);
        static bool isSpace(JVM* vm, char ch);
        static bool isSpaceChar(JVM* vm, char ch);
        static bool isSpaceChar(JVM* vm, std::int32_t codePoint);
        static bool isSupplementaryCodePoint(JVM* vm, std::int32_t codePoint);
        static bool isSurrogate(JVM* vm, char ch);
        static bool isSurrogatePair(JVM* vm, char high, char low);
        static bool isTitleCase(JVM* vm, char ch);
        static bool isTitleCase(JVM* vm, std::int32_t codePoint);
        static bool isUnicodeIdentifierPart(JVM* vm, char ch);
        static bool isUnicodeIdentifierPart(JVM* vm, std::int32_t codePoint);
        static bool isUnicodeIdentifierStart(JVM* vm, char ch);
        static bool isUnicodeIdentifierStart(JVM* vm, std::int32_t codePoint);
        static bool isUpperCase(JVM* vm, char ch);
        static bool isUpperCase(JVM* vm, std::int32_t codePoint);
        static bool isValidCodePoint(JVM* vm, std::int32_t codePoint);
        static bool isWhitespace(JVM* vm, char ch);
        static bool isWhitespace(JVM* vm, std::int32_t codePoint);
        static char lowSurrogate(JVM* vm, std::int32_t codePoint);
        static std::int32_t offsetByCodePoints(JVM* vm, CharSequence seq, std::int32_t index, std::int32_t codePointOffset);
        static std::int32_t offsetByCodePoints(JVM* vm, Array<char>& a, std::int32_t start, std::int32_t count, std::int32_t index, std::int32_t codePointOffset);
        static char reverseBytes(JVM* vm, char ch);
        static std::int32_t toChars(JVM* vm, std::int32_t codePoint, Array<char>& dst, std::int32_t dstIndex);
        static Array<char> toChars(JVM* vm, std::int32_t codePoint);
        static std::int32_t toCodePoint(JVM* vm, char high, char low);
        static char toLowerCase(JVM* vm, char ch);
        static std::int32_t toLowerCase(JVM* vm, std::int32_t codePoint);
        String toString();
        static String toString(JVM* vm, char c);
        static char toTitleCase(JVM* vm, char ch);
        static std::int32_t toTitleCase(JVM* vm, std::int32_t codePoint);
        static char toUpperCase(JVM* vm, char ch);
        static std::int32_t toUpperCase(JVM* vm, std::int32_t codePoint);
        static Character valueOf(JVM* vm, char c);
    };
}

#endif /* Character_hxx */
