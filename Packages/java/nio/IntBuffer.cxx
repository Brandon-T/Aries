//
//  IntBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "IntBuffer.hxx"

using java::nio::IntBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;

IntBuffer::IntBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/IntBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

IntBuffer IntBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/IntBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/IntBuffer;");
    return IntBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

Array<std::int32_t> IntBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[I");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<std::int32_t>(this->vm, arr);
}

std::int32_t IntBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

IntBuffer IntBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

IntBuffer IntBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t IntBuffer::compareTo(IntBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/IntBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

IntBuffer IntBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool IntBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

std::int32_t IntBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getMethod);
}

std::int32_t IntBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), getMethod, index);
}

IntBuffer IntBuffer::get(Array<std::int32_t>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([III)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

IntBuffer IntBuffer::get(Array<std::int32_t>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([I)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool IntBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t IntBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool IntBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder IntBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

IntBuffer IntBuffer::put(std::int32_t i)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(I)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, i));
}

IntBuffer IntBuffer::put(std::int32_t index, std::int32_t i)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(II)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, i));
}

IntBuffer IntBuffer::put(IntBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/IntBuffer;)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

IntBuffer IntBuffer::put(Array<std::int32_t>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([III)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

IntBuffer IntBuffer::put(Array<std::int32_t>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([I)Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

IntBuffer IntBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String IntBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

IntBuffer IntBuffer::wrap(JVM* vm, Array<std::int32_t>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/IntBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([III)Ljava/nio/IntBuffer;");
    return IntBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

IntBuffer IntBuffer::wrap(JVM* vm, Array<std::int32_t>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/IntBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([I)Ljava/nio/IntBuffer;");
    return IntBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
