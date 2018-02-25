//
//  StringBuilder.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "StringBuilder.hxx"
#include "AbstractStringBuilder.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "StringBuffer.hxx"

using java::lang::StringBuilder;
using java::lang::AbstractStringBuilder;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::lang::StringBuffer;


StringBuilder::StringBuilder(JVM* vm, jobject instance) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuilder;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

StringBuilder::StringBuilder(JVM* vm) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuilder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

StringBuilder::StringBuilder(JVM* vm, std::int32_t capacity) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuilder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, capacity));
    }
}

StringBuilder::StringBuilder(JVM* vm, String str) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuilder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, str.ref().get()));
    }
}

StringBuilder::StringBuilder(JVM* vm, CharSequence seq) : AbstractStringBuilder(nullptr, nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StringBuilder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/CharSequence;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, seq.ref().get()));
    }
}

StringBuilder StringBuilder::append(Object obj)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/Object;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, obj.ref().get()));
}

StringBuilder StringBuilder::append(String str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

StringBuilder StringBuilder::append(StringBuffer sb)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, sb.ref().get()));
}

StringBuilder StringBuilder::append(CharSequence s)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get()));
}

StringBuilder StringBuilder::append(CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, s.ref().get(), start, end));
}

StringBuilder StringBuilder::append(Array<char>& str)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([C)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get()));
}

StringBuilder StringBuilder::append(Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "([CII)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, str.ref().get(), offset, len));
}

StringBuilder StringBuilder::append(bool b)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Z)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, b));
}

StringBuilder StringBuilder::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

StringBuilder StringBuilder::append(std::int32_t i)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(I)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, i));
}

StringBuilder StringBuilder::append(std::int64_t lng)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(J)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, lng));
}

StringBuilder StringBuilder::append(float f)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(F)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, f));
}

StringBuilder StringBuilder::append(double d)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(D)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, d));
}

StringBuilder StringBuilder::appendCodePoint(std::int32_t codePoint)
{
    static jmethodID appendCodePointMethod = this->vm->GetMethodID(this->cls.get(), "appendCodePoint", "(I)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendCodePointMethod, codePoint));
}

StringBuilder StringBuilder::remove(std::int32_t start, std::int32_t end)
{
    static jmethodID deleteMethod = this->vm->GetMethodID(this->cls.get(), "delete", "(II)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteMethod, start, end));
}

StringBuilder StringBuilder::deleteCharAt(std::int32_t index)
{
    static jmethodID deleteCharAtMethod = this->vm->GetMethodID(this->cls.get(), "deleteCharAt", "(I)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), deleteCharAtMethod, index));
}

std::int32_t StringBuilder::indexOf(String str)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get());
}

std::int32_t StringBuilder::indexOf(String str, std::int32_t fromIndex)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, str.ref().get(), fromIndex);
}

StringBuilder StringBuilder::insert(std::int32_t index, Array<char>& str, std::int32_t offset, std::int32_t len)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[CII)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, index, str.ref().get(), offset, len));
}

StringBuilder StringBuilder::insert(std::int32_t offset, Object obj)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, obj.ref().get()));
}

StringBuilder StringBuilder::insert(std::int32_t offset, String str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/String;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

StringBuilder StringBuilder::insert(std::int32_t offset, Array<char>& str)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(I[C)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, str.ref().get()));
}

StringBuilder StringBuilder::insert(std::int32_t dstOffset, CharSequence s)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get()));
}

StringBuilder StringBuilder::insert(std::int32_t dstOffset, CharSequence s, std::int32_t start, std::int32_t end)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, dstOffset, s.ref().get(), start, end));
}

StringBuilder StringBuilder::insert(std::int32_t offset, bool b)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IZ)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, b));
}

StringBuilder StringBuilder::insert(std::int32_t offset, char c)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IC)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, c));
}

StringBuilder StringBuilder::insert(std::int32_t offset, std::int32_t i)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(II)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, i));
}

StringBuilder StringBuilder::insert(std::int32_t offset, std::int64_t l)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IJ)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, l));
}

StringBuilder StringBuilder::insert(std::int32_t offset, float f)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(IF)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, f));
}

StringBuilder StringBuilder::insert(std::int32_t offset, double d)
{
    static jmethodID insertMethod = this->vm->GetMethodID(this->cls.get(), "insert", "(ID)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), insertMethod, offset, d));
}

std::int32_t StringBuilder::lastIndexOf(String str)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get());
}

std::int32_t StringBuilder::lastIndexOf(String str, std::int32_t fromIndex)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, str.ref().get(), fromIndex);
}

StringBuilder StringBuilder::replace(std::int32_t start, std::int32_t end, String str)
{
    static jmethodID replaceMethod = this->vm->GetMethodID(this->cls.get(), "replace", "(IILjava/lang/String;)Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceMethod, start, end, str.ref().get()));
}

StringBuilder StringBuilder::reverse()
{
    static jmethodID reverseMethod = this->vm->GetMethodID(this->cls.get(), "reverse", "()Ljava/lang/StringBuilder;");
    return StringBuilder(this->vm, this->vm->CallObjectMethod(this->inst.get(), reverseMethod));
}

String StringBuilder::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
