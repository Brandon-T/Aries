//
//  DoubleBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "DoubleBuffer.hxx"

#include "Buffer.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ByteOrder.hxx"

using java::nio::DoubleBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;


DoubleBuffer::DoubleBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/DoubleBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

DoubleBuffer DoubleBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/DoubleBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

Array<double> DoubleBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[D");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<double>(this->vm, arr);
}

std::int32_t DoubleBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

DoubleBuffer DoubleBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

DoubleBuffer DoubleBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t DoubleBuffer::compareTo(DoubleBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/DoubleBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

DoubleBuffer DoubleBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool DoubleBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

double DoubleBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()D");
    return this->vm->CallDoubleMethod(this->inst.get(), getMethod);
}

double DoubleBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)D");
    return this->vm->CallDoubleMethod(this->inst.get(), getMethod, index);
}

DoubleBuffer DoubleBuffer::get(Array<double>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([DII)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

DoubleBuffer DoubleBuffer::get(Array<double>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([D)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool DoubleBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t DoubleBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool DoubleBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder DoubleBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

DoubleBuffer DoubleBuffer::put(double d)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(D)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, d));
}

DoubleBuffer DoubleBuffer::put(std::int32_t index, double d)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(ID)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, d));
}

DoubleBuffer DoubleBuffer::put(DoubleBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/DoubleBuffer;)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

DoubleBuffer DoubleBuffer::put(Array<double>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([DII)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

DoubleBuffer DoubleBuffer::put(Array<double>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([D)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

DoubleBuffer DoubleBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String DoubleBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

DoubleBuffer DoubleBuffer::wrap(JVM* vm, Array<double>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/DoubleBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([DII)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

DoubleBuffer DoubleBuffer::wrap(JVM* vm, Array<double>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/DoubleBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([D)Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
