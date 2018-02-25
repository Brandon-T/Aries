//
//  String.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "String.hxx"
#include "Object.hxx"
#include "CharSequence.hxx"
#include "Iterable.hxx"
#include "Object.hxx"
#include "StringBuffer.hxx"
#include "StringBuilder.hxx"
#include "Charset.hxx"
#include "Locale.hxx"

using java::lang::String;
using java::lang::CharSequence;
using java::lang::Iterable;
using java::lang::Object;
using java::lang::StringBuffer;
using java::lang::StringBuilder;
using java::nio::charset::Charset;
using java::util::Locale;


String::String(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String::String(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

String::String(JVM* vm, String original) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, original.ref().get()));
    }
}

String::String(JVM* vm, Array<char>& value) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([C)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, value.ref().get()));
    }
}

String::String(JVM* vm, Array<char>& value, std::int32_t offset, std::int32_t count) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([CII)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, value.ref().get(), offset, count));
    }
}

String::String(JVM* vm, Array<std::int32_t>& codePoints, std::int32_t offset, std::int32_t count) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([III)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, codePoints.ref().get(), offset, count));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& ascii, std::int32_t hibyte, std::int32_t offset, std::int32_t count) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BIII)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, ascii.ref().get(), hibyte, offset, count));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& ascii, std::int32_t hibyte) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BI)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, ascii.ref().get(), hibyte));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length, String charsetName) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BIILjava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get(), offset, length, charsetName.ref().get()));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length, Charset charset) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BIILjava/nio/charset/Charset;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get(), offset, length, charset.ref().get()));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes, String charsetName) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BLjava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get(), charsetName.ref().get()));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes, Charset charset) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BLjava/nio/charset/Charset;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get(), charset.ref().get()));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes, std::int32_t offset, std::int32_t length) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BII)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get(), offset, length));
    }
}

String::String(JVM* vm, Array<std::uint8_t>& bytes) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([B)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, bytes.ref().get()));
    }
}

String::String(JVM* vm, StringBuffer buffer) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/StringBuffer;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, buffer.ref().get()));
    }
}

String::String(JVM* vm, StringBuilder builder) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/String;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/StringBuilder;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, builder.ref().get()));
    }
}

char String::charAt(std::int32_t index)
{
    static jmethodID charAtMethod = this->vm->GetMethodID(this->cls.get(), "charAt", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), charAtMethod, index);
}

std::int32_t String::codePointAt(std::int32_t index)
{
    static jmethodID codePointAtMethod = this->vm->GetMethodID(this->cls.get(), "codePointAt", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointAtMethod, index);
}

std::int32_t String::codePointBefore(std::int32_t index)
{
    static jmethodID codePointBeforeMethod = this->vm->GetMethodID(this->cls.get(), "codePointBefore", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointBeforeMethod, index);
}

std::int32_t String::codePointCount(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID codePointCountMethod = this->vm->GetMethodID(this->cls.get(), "codePointCount", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointCountMethod, beginIndex, endIndex);
}

std::int32_t String::compareTo(String anotherString)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, anotherString.ref().get());
}

std::int32_t String::compareToIgnoreCase(String str)
{
    static jmethodID compareToIgnoreCaseMethod = this->vm->GetMethodID(this->cls.get(), "compareToIgnoreCase", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToIgnoreCaseMethod, str.ref().get());
}

String String::concat(String str)
{
    static jmethodID concatMethod = this->vm->GetMethodID(this->cls.get(), "concat", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), concatMethod, str.ref().get()));
}

bool String::contains(CharSequence s)
{
    static jmethodID containsMethod = this->vm->GetMethodID(this->cls.get(), "contains", "(Ljava/lang/CharSequence;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsMethod, s.ref().get());
}

bool String::contentEquals(StringBuffer sb)
{
    static jmethodID contentEqualsMethod = this->vm->GetMethodID(this->cls.get(), "contentEquals", "(Ljava/lang/StringBuffer;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), contentEqualsMethod, sb.ref().get());
}

bool String::contentEquals(CharSequence cs)
{
    static jmethodID contentEqualsMethod = this->vm->GetMethodID(this->cls.get(), "contentEquals", "(Ljava/lang/CharSequence;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), contentEqualsMethod, cs.ref().get());
}

String String::copyValueOf(JVM* vm, Array<char>& data, std::int32_t offset, std::int32_t count)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID copyValueOfMethod = vm->GetStaticMethodID(cls.get(), "copyValueOf", "([CII)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), copyValueOfMethod, data.ref().get(), offset, count));
}

String String::copyValueOf(JVM* vm, Array<char>& data)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID copyValueOfMethod = vm->GetStaticMethodID(cls.get(), "copyValueOf", "([C)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), copyValueOfMethod, data.ref().get()));
}

bool String::endsWith(String suffix)
{
    static jmethodID endsWithMethod = this->vm->GetMethodID(this->cls.get(), "endsWith", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), endsWithMethod, suffix.ref().get());
}

bool String::equals(Object anObject)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, anObject.ref().get());
}

bool String::equalsIgnoreCase(String anotherString)
{
    static jmethodID equalsIgnoreCaseMethod = this->vm->GetMethodID(this->cls.get(), "equalsIgnoreCase", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsIgnoreCaseMethod, anotherString.ref().get());
}

String String::format(JVM* vm, String format, Array<Object>& args)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID formatMethod = vm->GetStaticMethodID(cls.get(), "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), formatMethod, format.ref().get(), args.ref().get()));
}

String String::format(JVM* vm, Locale locale, String format, Array<Object>& args)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID formatMethod = vm->GetStaticMethodID(cls.get(), "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), formatMethod, locale.ref().get(), format.ref().get(), args.ref().get()));
}

void String::getBytes(std::int32_t srcBegin, std::int32_t srcEnd, Array<std::uint8_t>& dst, std::int32_t dstBegin)
{
    static jmethodID getBytesMethod = this->vm->GetMethodID(this->cls.get(), "getBytes", "(II[BI)V");
    this->vm->CallVoidMethod(this->inst.get(), getBytesMethod, srcBegin, srcEnd, dst.ref().get(), dstBegin);
}

Array<std::uint8_t> String::getBytes(String charsetName)
{
    static jmethodID getBytesMethod = this->vm->GetMethodID(this->cls.get(), "getBytes", "(Ljava/lang/String;)[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getBytesMethod, charsetName.ref().get()));
    return Array<std::uint8_t>(this->vm, arr);
}

Array<std::uint8_t> String::getBytes(Charset charset)
{
    static jmethodID getBytesMethod = this->vm->GetMethodID(this->cls.get(), "getBytes", "(Ljava/nio/charset/Charset;)[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getBytesMethod, charset.ref().get()));
    return Array<std::uint8_t>(this->vm, arr);
}

Array<std::uint8_t> String::getBytes()
{
    static jmethodID getBytesMethod = this->vm->GetMethodID(this->cls.get(), "getBytes", "()[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getBytesMethod));
    return Array<std::uint8_t>(this->vm, arr);
}

void String::getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin)
{
    static jmethodID getCharsMethod = this->vm->GetMethodID(this->cls.get(), "getChars", "(II[CI)V");
    this->vm->CallVoidMethod(this->inst.get(), getCharsMethod, srcBegin, srcEnd, dst.ref().get(), dstBegin);
}

std::int32_t String::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

std::int32_t String::indexOf(std::int32_t ch)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, ch);
}

std::int32_t String::indexOf(std::int32_t ch, std::int32_t fromIndex)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, ch, fromIndex);
}

std::int32_t String::indexOf(String str)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get());
}

std::int32_t String::indexOf(String str, std::int32_t fromIndex)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get(), fromIndex);
}

String String::intern()
{
    static jmethodID internMethod = this->vm->GetMethodID(this->cls.get(), "intern", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), internMethod));
}

bool String::isEmpty()
{
    static jmethodID isEmptyMethod = this->vm->GetMethodID(this->cls.get(), "isEmpty", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isEmptyMethod);
}

String String::join(JVM* vm, CharSequence delimiter, Array<CharSequence>& elements)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID joinMethod = vm->GetStaticMethodID(cls.get(), "join", "(Ljava/lang/CharSequence;[Ljava/lang/CharSequence;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), joinMethod, delimiter.ref().get(), elements.ref().get()));
}

String String::join(JVM* vm, CharSequence delimiter, Iterable<CharSequence> elements)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID joinMethod = vm->GetStaticMethodID(cls.get(), "join", "(Ljava/lang/CharSequence;Ljava/lang/Iterable;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), joinMethod, delimiter.ref().get(), elements.ref().get()));
}

std::int32_t String::lastIndexOf(std::int32_t ch)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, ch);
}

std::int32_t String::lastIndexOf(std::int32_t ch, std::int32_t fromIndex)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, ch, fromIndex);
}

std::int32_t String::lastIndexOf(String str)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get());
}

std::int32_t String::lastIndexOf(String str, std::int32_t fromIndex)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get(), fromIndex);
}

std::int32_t String::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

bool String::matches(String regex)
{
    static jmethodID matchesMethod = this->vm->GetMethodID(this->cls.get(), "matches", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), matchesMethod, regex.ref().get());
}

std::int32_t String::offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset)
{
    static jmethodID offsetByCodePointsMethod = this->vm->GetMethodID(this->cls.get(), "offsetByCodePoints", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), offsetByCodePointsMethod, index, codePointOffset);
}

bool String::regionMatches(std::int32_t toffset, String other, std::int32_t ooffset, std::int32_t len)
{
    static jmethodID regionMatchesMethod = this->vm->GetMethodID(this->cls.get(), "regionMatches", "(ILjava/lang/String;II)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), regionMatchesMethod, toffset, other.ref().get(), ooffset, len);
}

bool String::regionMatches(bool ignoreCase, std::int32_t toffset, String other, std::int32_t ooffset, std::int32_t len)
{
    static jmethodID regionMatchesMethod = this->vm->GetMethodID(this->cls.get(), "regionMatches", "(ZILjava/lang/String;II)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), regionMatchesMethod, ignoreCase, toffset, other.ref().get(), ooffset, len);
}

String String::replace(char oldChar, char newChar)
{
    static jmethodID replaceMethod = this->vm->GetMethodID(this->cls.get(), "replace", "(CC)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceMethod, oldChar, newChar));
}

String String::replace(CharSequence target, CharSequence replacement)
{
    static jmethodID replaceMethod = this->vm->GetMethodID(this->cls.get(), "replace", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceMethod, target.ref().get(), replacement.ref().get()));
}

String String::replaceAll(String regex, String replacement)
{
    static jmethodID replaceAllMethod = this->vm->GetMethodID(this->cls.get(), "replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceAllMethod, regex.ref().get(), replacement.ref().get()));
}

String String::replaceFirst(String regex, String replacement)
{
    static jmethodID replaceFirstMethod = this->vm->GetMethodID(this->cls.get(), "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceFirstMethod, regex.ref().get(), replacement.ref().get()));
}

Array<String> String::split(String regex, std::int32_t limit)
{
    static jmethodID splitMethod = this->vm->GetMethodID(this->cls.get(), "split", "(Ljava/lang/String;I)[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), splitMethod, regex.ref().get(), limit));
    return Array<String>(this->vm, arr);
}

Array<String> String::split(String regex)
{
    static jmethodID splitMethod = this->vm->GetMethodID(this->cls.get(), "split", "(Ljava/lang/String;)[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), splitMethod, regex.ref().get()));
    return Array<String>(this->vm, arr);
}

bool String::startsWith(String prefix, std::int32_t toffset)
{
    static jmethodID startsWithMethod = this->vm->GetMethodID(this->cls.get(), "startsWith", "(Ljava/lang/String;I)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), startsWithMethod, prefix.ref().get(), toffset);
}

bool String::startsWith(String prefix)
{
    static jmethodID startsWithMethod = this->vm->GetMethodID(this->cls.get(), "startsWith", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), startsWithMethod, prefix.ref().get());
}

CharSequence String::subSequence(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID subSequenceMethod = this->vm->GetMethodID(this->cls.get(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return CharSequence(this->vm, this->vm->CallObjectMethod(this->inst.get(), subSequenceMethod, beginIndex, endIndex));
}

String String::substring(std::int32_t beginIndex)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(I)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, beginIndex));
}

String String::substring(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(II)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, beginIndex, endIndex));
}

Array<char> String::toCharArray()
{
    static jmethodID toCharArrayMethod = this->vm->GetMethodID(this->cls.get(), "toCharArray", "()[C");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), toCharArrayMethod));
    return Array<char>(this->vm, arr);
}

String String::toLowerCase(Locale locale)
{
    static jmethodID toLowerCaseMethod = this->vm->GetMethodID(this->cls.get(), "toLowerCase", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toLowerCaseMethod, locale.ref().get()));
}

String String::toLowerCase()
{
    static jmethodID toLowerCaseMethod = this->vm->GetMethodID(this->cls.get(), "toLowerCase", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toLowerCaseMethod));
}

String String::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

String String::toUpperCase(Locale locale)
{
    static jmethodID toUpperCaseMethod = this->vm->GetMethodID(this->cls.get(), "toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toUpperCaseMethod, locale.ref().get()));
}

String String::toUpperCase()
{
    static jmethodID toUpperCaseMethod = this->vm->GetMethodID(this->cls.get(), "toUpperCase", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toUpperCaseMethod));
}

String String::trim()
{
    static jmethodID trimMethod = this->vm->GetMethodID(this->cls.get(), "trim", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), trimMethod));
}

String String::valueOf(JVM* vm, Object obj)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, obj.ref().get()));
}

String String::valueOf(JVM* vm, Array<char>& data)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "([C)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, data.ref().get()));
}

String String::valueOf(JVM* vm, Array<char>& data, std::int32_t offset, std::int32_t count)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "([CII)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, data.ref().get(), offset, count));
}

String String::valueOf(JVM* vm, bool b)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Z)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, b));
}

String String::valueOf(JVM* vm, char c)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(C)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, c));
}

String String::valueOf(JVM* vm, std::int32_t i)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(I)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, i));
}

String String::valueOf(JVM* vm, std::int64_t l)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(J)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, l));
}

String String::valueOf(JVM* vm, float f)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(F)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, f));
}

String String::valueOf(JVM* vm, double d)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/String;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(D)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, d));
}
