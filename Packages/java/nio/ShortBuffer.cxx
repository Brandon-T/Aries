//
//  ShortBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "ShortBuffer.hxx"
#include "Buffer.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ByteOrder.hxx"

using java::nio::ShortBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;


ShortBuffer::ShortBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/ShortBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ShortBuffer ShortBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ShortBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/ShortBuffer;");
    return ShortBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

Array<std::int16_t> ShortBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[S");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<std::int16_t>(this->vm, arr);
}

std::int32_t ShortBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

ShortBuffer ShortBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

ShortBuffer ShortBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t ShortBuffer::compareTo(ShortBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/ShortBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

ShortBuffer ShortBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool ShortBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

std::int16_t ShortBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()S");
    return this->vm->CallShortMethod(this->inst.get(), getMethod);
}

std::int16_t ShortBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)S");
    return this->vm->CallShortMethod(this->inst.get(), getMethod, index);
}

ShortBuffer ShortBuffer::get(Array<std::int16_t>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([SII)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

ShortBuffer ShortBuffer::get(Array<std::int16_t>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([S)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool ShortBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t ShortBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool ShortBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder ShortBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

ShortBuffer ShortBuffer::put(std::int16_t s)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(S)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, s));
}

ShortBuffer ShortBuffer::put(std::int32_t index, std::int16_t s)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(IS)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, s));
}

ShortBuffer ShortBuffer::put(ShortBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/ShortBuffer;)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

ShortBuffer ShortBuffer::put(Array<std::int16_t>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([SII)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

ShortBuffer ShortBuffer::put(Array<std::int16_t>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([S)Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

ShortBuffer ShortBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String ShortBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

ShortBuffer ShortBuffer::wrap(JVM* vm, Array<std::int16_t>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ShortBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([SII)Ljava/nio/ShortBuffer;");
    return ShortBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

ShortBuffer ShortBuffer::wrap(JVM* vm, Array<std::int16_t>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ShortBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([S)Ljava/nio/ShortBuffer;");
    return ShortBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
