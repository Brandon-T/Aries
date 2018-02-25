//
//  AbstractStringBuilder.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "AbstractStringBuilder.hxx"
#include "CharSequence.hxx"
#include "String.hxx"
#include "StringBuffer.hxx"

using java::lang::AbstractStringBuilder;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::lang::StringBuffer;


AbstractStringBuilder::AbstractStringBuilder(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/AbstractStringBuilder;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

AbstractStringBuilder AbstractStringBuilder::append(Object obj)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, obj.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::append(String str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::append(StringBuffer sb)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, sb.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::append(CharSequence s)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::append(CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get(), start, end));
}

AbstractStringBuilder AbstractStringBuilder::append(Array<char>& str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([C)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::append(Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([CII)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get(), offset, len));
}

AbstractStringBuilder AbstractStringBuilder::append(bool b)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Z)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, b));
}

AbstractStringBuilder AbstractStringBuilder::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

AbstractStringBuilder AbstractStringBuilder::append(std::int32_t i)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(I)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, i));
}

AbstractStringBuilder AbstractStringBuilder::append(std::int64_t l)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(J)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, l));
}

AbstractStringBuilder AbstractStringBuilder::append(float f)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(F)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, f));
}

AbstractStringBuilder AbstractStringBuilder::append(double d)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(D)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, d));
}

AbstractStringBuilder AbstractStringBuilder::appendCodePoint(std::int32_t codePoint)
{
    static jmethodID appendCodePointMethod = this->vm->GetMethodID(this->cls.get(), "appendCodePoint", "(I)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendCodePointMethod, codePoint));
}

std::int32_t AbstractStringBuilder::capacity()
{
    static jmethodID capacityMethod = this->vm->GetMethodID(this->cls.get(), "capacity", "()I");
    return this->vm->CallIntMethod(this->inst.get(), capacityMethod);
}

char AbstractStringBuilder::charAt(std::int32_t index)
{
    static jmethodID charAtMethod = this->vm->GetMethodID(this->cls.get(), "charAt", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), charAtMethod, index);
}

std::int32_t AbstractStringBuilder::codePointAt(std::int32_t index)
{
    static jmethodID codePointAtMethod = this->vm->GetMethodID(this->cls.get(), "codePointAt", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointAtMethod, index);
}

std::int32_t AbstractStringBuilder::codePointBefore(std::int32_t index)
{
    static jmethodID codePointBeforeMethod = this->vm->GetMethodID(this->cls.get(), "codePointBefore", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointBeforeMethod, index);
}

std::int32_t AbstractStringBuilder::codePointCount(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID codePointCountMethod = this->vm->GetMethodID(this->cls.get(), "codePointCount", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), codePointCountMethod, beginIndex, endIndex);
}

AbstractStringBuilder AbstractStringBuilder::remove(std::int32_t start, std::int32_t end)
{
    static jmethodID deleteMethod = this->vm->GetMethodID(this->cls.get(), "delete", "(II)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteMethod, start, end));
}

AbstractStringBuilder AbstractStringBuilder::deleteCharAt(std::int32_t index)
{
    static jmethodID deleteCharAtMethod = this->vm->GetMethodID(this->cls.get(), "deleteCharAt", "(I)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteCharAtMethod, index));
}

void AbstractStringBuilder::ensureCapacity(std::int32_t minimumCapacity)
{
    static jmethodID ensureCapacityMethod = this->vm->GetMethodID(this->cls.get(), "ensureCapacity", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), ensureCapacityMethod, minimumCapacity);
}

void AbstractStringBuilder::getChars(std::int32_t srcBegin, std::int32_t srcEnd, Array<char>& dst, std::int32_t dstBegin)
{
    static jmethodID getCharsMethod = this->vm->GetMethodID(this->cls.get(), "getChars", "(II[CI)V");
    this->vm->CallVoidMethod(this->inst.get(), getCharsMethod, srcBegin, srcEnd, dst.ref().get(), dstBegin);
}

std::int32_t AbstractStringBuilder::indexOf(String str)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get());
}

std::int32_t AbstractStringBuilder::indexOf(String str, std::int32_t fromIndex)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get(), fromIndex);
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[CII)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, index, str.ref().get(), offset, len));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, Object obj)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, obj.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, String str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, Array<char>& str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[C)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t dstOffset, CharSequence s)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get(), start, end));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, bool b)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IZ)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, b));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, char c)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IC)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, c));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, std::int32_t i)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(II)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, i));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, std::int64_t l)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IJ)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, l));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, float f)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IF)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, f));
}

AbstractStringBuilder AbstractStringBuilder::insert(std::int32_t offset, double d)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ID)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, d));
}

std::int32_t AbstractStringBuilder::lastIndexOf(String str)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get());
}

std::int32_t AbstractStringBuilder::lastIndexOf(String str, std::int32_t fromIndex)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get(), fromIndex);
}

std::int32_t AbstractStringBuilder::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

std::int32_t AbstractStringBuilder::offsetByCodePoints(std::int32_t index, std::int32_t codePointOffset)
{
    static jmethodID offsetByCodePointsMethod = this->vm->GetMethodID(this->cls.get(), "offsetByCodePoints", "(II)I");
    return this->vm->CallIntMethod(this->inst.get(), offsetByCodePointsMethod, index, codePointOffset);
}

AbstractStringBuilder AbstractStringBuilder::replace(std::int32_t start, std::int32_t end, String str)
{
    static jmethodID replaceMethod = this->vm->GetMethodID(this->cls.get(), "replace", "(IILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceMethod, start, end, str.ref().get()));
}

AbstractStringBuilder AbstractStringBuilder::reverse()
{
    static jmethodID reverseMethod = this->vm->GetMethodID(this->cls.get(), "reverse", "()Ljava/lang/AbstractStringBuilder;");
    return AbstractStringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), reverseMethod));
}

void AbstractStringBuilder::setCharAt(std::int32_t index, char ch)
{
    static jmethodID setCharAtMethod = this->vm->GetMethodID(this->cls.get(), "setCharAt", "(IC)V");
    this->vm->CallVoidMethod(this->inst.get(), setCharAtMethod, index, ch);
}

void AbstractStringBuilder::setLength(std::int32_t newLength)
{
    static jmethodID setLengthMethod = this->vm->GetMethodID(this->cls.get(), "setLength", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), setLengthMethod, newLength);
}

CharSequence AbstractStringBuilder::subSequence(std::int32_t start, std::int32_t end)
{
    static jmethodID subSequenceMethod = this->vm->GetMethodID(this->cls.get(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return CharSequence(this->vm, this->vm->CallObjectMethod(this->inst.get(), subSequenceMethod, start, end));
}

String AbstractStringBuilder::substring(std::int32_t start)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(I)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, start));
}

String AbstractStringBuilder::substring(std::int32_t start, std::int32_t end)
{
    static jmethodID substringMethod = this->vm->GetMethodID(this->cls.get(), "substring", "(II)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), substringMethod, start, end));
}

String AbstractStringBuilder::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

void AbstractStringBuilder::trimToSize()
{
    static jmethodID trimToSizeMethod = this->vm->GetMethodID(this->cls.get(), "trimToSize", "()V");
    this->vm->CallVoidMethod(this->inst.get(), trimToSizeMethod);
}
