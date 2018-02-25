//
//  LongBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "LongBuffer.hxx"
#include "Buffer.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ByteOrder.hxx"

using java::nio::LongBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;


LongBuffer::LongBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/LongBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

LongBuffer LongBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/LongBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/LongBuffer;");
    return LongBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

Array<std::int64_t> LongBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[J");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<std::int64_t>(this->vm, arr);
}

std::int32_t LongBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

LongBuffer LongBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

LongBuffer LongBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t LongBuffer::compareTo(LongBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/LongBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

LongBuffer LongBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool LongBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

std::int64_t LongBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getMethod);
}

std::int64_t LongBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)J");
    return this->vm->CallLongMethod(this->inst.get(), getMethod, index);
}

LongBuffer LongBuffer::get(Array<std::int64_t>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([JII)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

LongBuffer LongBuffer::get(Array<std::int64_t>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([J)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool LongBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t LongBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool LongBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder LongBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

LongBuffer LongBuffer::put(std::int64_t l)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(J)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, l));
}

LongBuffer LongBuffer::put(std::int32_t index, std::int64_t l)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(IJ)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, l));
}

LongBuffer LongBuffer::put(LongBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/LongBuffer;)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

LongBuffer LongBuffer::put(Array<std::int64_t>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([JII)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

LongBuffer LongBuffer::put(Array<std::int64_t>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([J)Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

LongBuffer LongBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String LongBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

LongBuffer LongBuffer::wrap(JVM* vm, Array<std::int64_t>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/LongBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([JII)Ljava/nio/LongBuffer;");
    return LongBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

LongBuffer LongBuffer::wrap(JVM* vm, Array<std::int64_t>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/LongBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([J)Ljava/nio/LongBuffer;");
    return LongBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
