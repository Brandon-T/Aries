//
//  CharBuffer.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "CharBuffer.hxx"

#include "Buffer.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ByteOrder.hxx"
#include "IntStream.hxx"

using java::nio::CharBuffer;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;
using java::util::stream::IntStream;


CharBuffer::CharBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/CharBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

CharBuffer CharBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/CharBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/CharBuffer;");
    return CharBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

CharBuffer CharBuffer::append(CharSequence csq)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get()));
}

CharBuffer CharBuffer::append(CharSequence csq, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get(), start, end));
}

CharBuffer CharBuffer::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

Array<char> CharBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[C");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<char>(this->vm, arr);
}

std::int32_t CharBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

CharBuffer CharBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

char CharBuffer::charAt(std::int32_t index)
{
    static jmethodID charAtMethod = this->vm->GetMethodID(this->cls.get(), "charAt", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), charAtMethod, index);
}

IntStream CharBuffer::chars()
{
    static jmethodID charsMethod = this->vm->GetMethodID(this->cls.get(), "chars", "()Ljava/util/stream/IntStream;");
    return IntStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), charsMethod));
}

CharBuffer CharBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t CharBuffer::compareTo(CharBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/CharBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

CharBuffer CharBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool CharBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

char CharBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()C");
    return this->vm->CallCharMethod(this->inst.get(), getMethod);
}

char CharBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), getMethod, index);
}

CharBuffer CharBuffer::get(Array<char>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([CII)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

CharBuffer CharBuffer::get(Array<char>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([C)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool CharBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t CharBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool CharBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

std::int32_t CharBuffer::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

ByteOrder CharBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

CharBuffer CharBuffer::put(char c)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(C)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, c));
}

CharBuffer CharBuffer::put(std::int32_t index, char c)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(IC)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, c));
}

CharBuffer CharBuffer::put(CharBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/CharBuffer;)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

CharBuffer CharBuffer::put(Array<char>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([CII)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

CharBuffer CharBuffer::put(Array<char>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([C)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

CharBuffer CharBuffer::put(String src, std::int32_t start, std::int32_t end)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/lang/String;II)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), start, end));
}

CharBuffer CharBuffer::put(String src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/lang/String;)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

std::int32_t CharBuffer::read(CharBuffer target)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/CharBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), readMethod, target.ref().get());
}

CharBuffer CharBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

CharBuffer CharBuffer::subSequence(std::int32_t start, std::int32_t end)
{
    static jmethodID subSequenceMethod = this->vm->GetMethodID(this->cls.get(), "subSequence", "(II)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), subSequenceMethod, start, end));
}

String CharBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

CharBuffer CharBuffer::wrap(JVM* vm, Array<char>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/CharBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([CII)Ljava/nio/CharBuffer;");
    return CharBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

CharBuffer CharBuffer::wrap(JVM* vm, Array<char>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/CharBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([C)Ljava/nio/CharBuffer;");
    return CharBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}

CharBuffer CharBuffer::wrap(JVM* vm, CharSequence csq, std::int32_t start, std::int32_t end)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/CharBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "(Ljava/lang/CharSequence;II)Ljava/nio/CharBuffer;");
    return CharBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, csq.ref().get(), start, end));
}

CharBuffer CharBuffer::wrap(JVM* vm, CharSequence csq)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/CharBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "(Ljava/lang/CharSequence;)Ljava/nio/CharBuffer;");
    return CharBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, csq.ref().get()));
}
