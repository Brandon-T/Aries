//
//  FloatBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FloatBuffer.hxx"

using java::nio::FloatBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;

FloatBuffer::FloatBuffer(JVM* vm, jobject instance) : Buffer(vm, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/FloatBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

FloatBuffer FloatBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/FloatBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/FloatBuffer;");
    return FloatBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

Array<float> FloatBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[F");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<float>(this->vm, arr);
}

std::int32_t FloatBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

FloatBuffer FloatBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

FloatBuffer FloatBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t FloatBuffer::compareTo(FloatBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/FloatBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

FloatBuffer FloatBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool FloatBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

float FloatBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), getMethod);
}

float FloatBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)F");
    return this->vm->CallFloatMethod(this->inst.get(), getMethod, index);
}

FloatBuffer FloatBuffer::get(Array<float>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([FII)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

FloatBuffer FloatBuffer::get(Array<float>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([F)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

bool FloatBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t FloatBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool FloatBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder FloatBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

FloatBuffer FloatBuffer::put(float f)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(F)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, f));
}

FloatBuffer FloatBuffer::put(std::int32_t index, float f)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(IF)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, f));
}

FloatBuffer FloatBuffer::put(FloatBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/FloatBuffer;)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

FloatBuffer FloatBuffer::put(Array<float>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([FII)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

FloatBuffer FloatBuffer::put(Array<float>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([F)Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

FloatBuffer FloatBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String FloatBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

FloatBuffer FloatBuffer::wrap(JVM* vm, Array<float>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/FloatBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([FII)Ljava/nio/FloatBuffer;");
    return FloatBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

FloatBuffer FloatBuffer::wrap(JVM* vm, Array<float>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/FloatBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([F)Ljava/nio/FloatBuffer;");
    return FloatBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
