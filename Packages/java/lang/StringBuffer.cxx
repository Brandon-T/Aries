//
//  StringBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "StringBuffer.hxx"

using java::lang::StringBuffer;
using java::lang::AbstractStringBuilder;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;


StringBuffer::StringBuffer(JVM* vm, jobject instance) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

StringBuffer::StringBuffer(JVM* vm) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuffer;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

StringBuffer::StringBuffer(JVM* vm, std::int32_t capacity) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuffer;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, capacity));
    }
}

StringBuffer::StringBuffer(JVM* vm, String str) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuffer;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, str.ref().get()));
    }
}

StringBuffer::StringBuffer(JVM* vm, CharSequence seq) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuffer;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/CharSequence;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, seq.ref().get()));
    }
}

StringBuffer StringBuffer::append(Object obj)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/Object;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, obj.ref().get()));
}

StringBuffer StringBuffer::append(String str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

StringBuffer StringBuffer::append(StringBuffer sb)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, sb.ref().get()));
}

StringBuffer StringBuffer::append(CharSequence s)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get()));
}

StringBuffer StringBuffer::append(CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get(), start, end));
}

StringBuffer StringBuffer::append(Array<char>& str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([C)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

StringBuffer StringBuffer::append(Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([CII)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get(), offset, len));
}

StringBuffer StringBuffer::append(bool b)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Z)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, b));
}

StringBuffer StringBuffer::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

StringBuffer StringBuffer::append(std::int32_t i)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(I)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, i));
}

StringBuffer StringBuffer::append(std::int64_t lng)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(J)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, lng));
}

StringBuffer StringBuffer::append(float f)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(F)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, f));
}

StringBuffer StringBuffer::append(double d)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(D)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, d));
}

StringBuffer StringBuffer::appendCodePoint(std::int32_t codePoint)
{
    static jmethodID appendCodePointMethod = this->vm->GetMethodID(this->cls.get(), "appendCodePoint", "(I)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendCodePointMethod, codePoint));
}

std::int32_t StringBuffer::capacity()
{
    static jmethodID capacityMethod = this->vm->GetMethodID(this->cls.get(), "capacity", "()I");
    return this->vm->CallIntMethod(this->inst.get(), capacityMethod);
}

char StringBuffer::charAt(std::int32_t index)
{
    static jmethodID charAtMethod = this->vm->GetMethodID(this->cls.get(), "charAt", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), charAtMethod, index);
}

std::int32_t StringBuffer::codePointAt(std::int32_t index)
{
    static jmethodID codePointAtMethod = this->vm->GetMethodID(this->cls.get(), "codePointAt", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointAtMethod, index);
}

std::int32_t StringBuffer::codePointBefore(std::int32_t index)
{
    static jmethodID codePointBeforeMethod = this->vm->GetMethodID(this->cls.get(), "codePointBefore", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointBeforeMethod, index);
}

std::int32_t StringBuffer::codePointCount(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID codePointCountMethod = this->vm->GetMethodID(this->cls.get(), "codePointCount", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointCountMethod, beginIndex, endIndex);
}

StringBuffer StringBuffer::remove(std::int32_t start, std::int32_t end)
{
    static jmethodID deleteMethod = this->vm->GetMethodID(this->cls.get(), "delete", "(II)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteMethod, start, end));
}

StringBuffer StringBuffer::deleteCharAt(std::int32_t index)
{
    static jmethodID deleteCharAtMethod = this->vm->GetMethodID(this->cls.get(), "deleteCharAt", "(I)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteCharAtMethod, index));
}

void StringBuffer::ensureCapacity(std::int32_t minimumCapacity)
{
    static jmethodID ensureCapacityMethod = this->vm->GetMethodID(this->cls.get(), "ensureCapacity", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), ensureCapacityMethod, minimumCapacity);
}

void StringBuffer::getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin)
{
    static jmethodID getCharsMethod = this->vm->GetMethodID(this->cls.get(), "getChars", "(II[CI)V");
    this->vm->CallVoidMethod(this->inst.get(), getCharsMethod, srcBegin, srcEnd, dst.ref().get(), dstBegin);
}

std::int32_t StringBuffer::indexOf(String str)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get());
}

std::int32_t StringBuffer::indexOf(String str, std::int32_t fromIndex)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get(), fromIndex);
}

StringBuffer StringBuffer::insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[CII)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, index, str.ref().get(), offset, len));
}

StringBuffer StringBuffer::insert(std::int32_t offset, Object obj)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, obj.ref().get()));
}

StringBuffer StringBuffer::insert(std::int32_t offset, String str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/String;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

StringBuffer StringBuffer::insert(std::int32_t offset, Array<char>& str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[C)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

StringBuffer StringBuffer::insert(std::int32_t dstOffset, CharSequence s)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get()));
}

StringBuffer StringBuffer::insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get(), start, end));
}

StringBuffer StringBuffer::insert(std::int32_t offset, bool b)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IZ)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, b));
}

StringBuffer StringBuffer::insert(std::int32_t offset, char c)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IC)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, c));
}

StringBuffer StringBuffer::insert(std::int32_t offset, std::int32_t i)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(II)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, i));
}

StringBuffer StringBuffer::insert(std::int32_t offset, std::int64_t l)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IJ)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, l));
}

StringBuffer StringBuffer::insert(std::int32_t offset, float f)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IF)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, f));
}

StringBuffer StringBuffer::insert(std::int32_t offset, double d)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ID)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, d));
}

std::int32_t StringBuffer::lastIndexOf(String str)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get());
}

std::int32_t StringBuffer::lastIndexOf(String str, std::int32_t fromIndex)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get(), fromIndex);
}

std::int32_t StringBuffer::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

std::int32_t StringBuffer::offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset)
{
    static jmethodID offsetByCodePointsMethod = this->vm->GetMethodID(this->cls.get(), "offsetByCodePoints", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), offsetByCodePointsMethod, index, codePointOffset);
}

StringBuffer StringBuffer::replace(std::int32_t start, std::int32_t end, String str)
{
    static jmethodID replaceMethod = this->vm->GetMethodID(this->cls.get(), "replace", "(IILjava/lang/String;)Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceMethod, start, end, str.ref().get()));
}

StringBuffer StringBuffer::reverse()
{
    static jmethodID reverseMethod = this->vm->GetMethodID(this->cls.get(), "reverse", "()Ljava/lang/StringBuffer;");
    return StringBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), reverseMethod));
}

void StringBuffer::setCharAt(std::int32_t index, char ch)
{
    static jmethodID setCharAtMethod = this->vm->GetMethodID(this->cls.get(), "setCharAt", "(IC)V");
    this->vm->CallVoidMethod(this->inst.get(), setCharAtMethod, index, ch);
}

void StringBuffer::setLength(std::int32_t newLength)
{
    static jmethodID setLengthMethod = this->vm->GetMethodID(this->cls.get(), "setLength", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), setLengthMethod, newLength);
}

CharSequence StringBuffer::subSequence(std::int32_t start, std::int32_t end)
{
    static jmethodID subSequenceMethod = this->vm->GetMethodID(this->cls.get(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return CharSequence(this->vm, this->vm->CallObjectMethod(this->inst.get(), subSequenceMethod, start, end));
}

String StringBuffer::substring(std::int32_t start)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(I)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, start));
}

String StringBuffer::substring(std::int32_t start, std::int32_t end)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(II)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, start, end));
}

String StringBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

void StringBuffer::trimToSize()
{
    static jmethodID trimToSizeMethod = this->vm->GetMethodID(this->cls.get(), "trimToSize", "()V");
    this->vm->CallVoidMethod(this->inst.get(), trimToSizeMethod);
}
