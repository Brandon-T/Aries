//
//  ByteBuffer.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ByteBuffer.hxx"

using java::nio::ByteBuffer;
using java::lang::Object;
using java::lang::String;
using java::nio::Buffer;
using java::nio::ByteOrder;
using java::nio::CharBuffer;
using java::nio::DoubleBuffer;
using java::nio::FloatBuffer;
using java::nio::IntBuffer;
using java::nio::LongBuffer;
using java::nio::ShortBuffer;

ByteBuffer::ByteBuffer(JVM* vm, jobject instance) : Buffer(nullptr, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/ByteBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ByteBuffer ByteBuffer::allocate(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ByteBuffer;"));
    static jmethodID allocateMethod = vm->GetStaticMethodID(cls.get(), "allocate", "(I)Ljava/nio/ByteBuffer;");
    return ByteBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateMethod, capacity));
}

ByteBuffer ByteBuffer::allocateDirect(JVM* vm, std::int32_t capacity)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ByteBuffer;"));
    static jmethodID allocateDirectMethod = vm->GetStaticMethodID(cls.get(), "allocateDirect", "(I)Ljava/nio/ByteBuffer;");
    return ByteBuffer(vm, vm->CallStaticObjectMethod(cls.get(), allocateDirectMethod, capacity));
}

Array<std::uint8_t> ByteBuffer::array()
{
    static jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
    return Array<std::uint8_t>(this->vm, arr);
}

std::int32_t ByteBuffer::arrayOffset()
{
    static jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

CharBuffer ByteBuffer::asCharBuffer()
{
    static jmethodID asCharBufferMethod = this->vm->GetMethodID(this->cls.get(), "asCharBuffer", "()Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asCharBufferMethod));
}

DoubleBuffer ByteBuffer::asDoubleBuffer()
{
    static jmethodID asDoubleBufferMethod = this->vm->GetMethodID(this->cls.get(), "asDoubleBuffer", "()Ljava/nio/DoubleBuffer;");
    return DoubleBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asDoubleBufferMethod));
}

FloatBuffer ByteBuffer::asFloatBuffer()
{
    static jmethodID asFloatBufferMethod = this->vm->GetMethodID(this->cls.get(), "asFloatBuffer", "()Ljava/nio/FloatBuffer;");
    return FloatBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asFloatBufferMethod));
}

IntBuffer ByteBuffer::asIntBuffer()
{
    static jmethodID asIntBufferMethod = this->vm->GetMethodID(this->cls.get(), "asIntBuffer", "()Ljava/nio/IntBuffer;");
    return IntBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asIntBufferMethod));
}

LongBuffer ByteBuffer::asLongBuffer()
{
    static jmethodID asLongBufferMethod = this->vm->GetMethodID(this->cls.get(), "asLongBuffer", "()Ljava/nio/LongBuffer;");
    return LongBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asLongBufferMethod));
}

ByteBuffer ByteBuffer::asReadOnlyBuffer()
{
    static jmethodID asReadOnlyBufferMethod = this->vm->GetMethodID(this->cls.get(), "asReadOnlyBuffer", "()Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asReadOnlyBufferMethod));
}

ShortBuffer ByteBuffer::asShortBuffer()
{
    static jmethodID asShortBufferMethod = this->vm->GetMethodID(this->cls.get(), "asShortBuffer", "()Ljava/nio/ShortBuffer;");
    return ShortBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), asShortBufferMethod));
}

ByteBuffer ByteBuffer::compact()
{
    static jmethodID compactMethod = this->vm->GetMethodID(this->cls.get(), "compact", "()Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), compactMethod));
}

std::int32_t ByteBuffer::compareTo(ByteBuffer that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/ByteBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

ByteBuffer ByteBuffer::duplicate()
{
    static jmethodID duplicateMethod = this->vm->GetMethodID(this->cls.get(), "duplicate", "()Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), duplicateMethod));
}

bool ByteBuffer::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

std::uint8_t ByteBuffer::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()B");
    return this->vm->CallByteMethod(this->inst.get(), getMethod);
}

std::uint8_t ByteBuffer::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)B");
    return this->vm->CallByteMethod(this->inst.get(), getMethod, index);
}

ByteBuffer ByteBuffer::get(Array<std::uint8_t>& dst, std::int32_t offset, std::int32_t length)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([BII)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get(), offset, length));
}

ByteBuffer ByteBuffer::get(Array<std::uint8_t>& dst)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "([B)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, dst.ref().get()));
}

char ByteBuffer::getChar()
{
    static jmethodID getCharMethod = this->vm->GetMethodID(this->cls.get(), "getChar", "()C");
    return this->vm->CallCharMethod(this->inst.get(), getCharMethod);
}

char ByteBuffer::getChar(std::int32_t index)
{
    static jmethodID getCharMethod = this->vm->GetMethodID(this->cls.get(), "getChar", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), getCharMethod, index);
}

double ByteBuffer::getDouble()
{
    static jmethodID getDoubleMethod = this->vm->GetMethodID(this->cls.get(), "getDouble", "()D");
    return this->vm->CallDoubleMethod(this->inst.get(), getDoubleMethod);
}

double ByteBuffer::getDouble(std::int32_t index)
{
    static jmethodID getDoubleMethod = this->vm->GetMethodID(this->cls.get(), "getDouble", "(I)D");
    return this->vm->CallDoubleMethod(this->inst.get(), getDoubleMethod, index);
}

float ByteBuffer::getFloat()
{
    static jmethodID getFloatMethod = this->vm->GetMethodID(this->cls.get(), "getFloat", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), getFloatMethod);
}

float ByteBuffer::getFloat(std::int32_t index)
{
    static jmethodID getFloatMethod = this->vm->GetMethodID(this->cls.get(), "getFloat", "(I)F");
    return this->vm->CallFloatMethod(this->inst.get(), getFloatMethod, index);
}

std::int32_t ByteBuffer::getInt()
{
    static jmethodID getIntMethod = this->vm->GetMethodID(this->cls.get(), "getInt", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getIntMethod);
}

std::int32_t ByteBuffer::getInt(std::int32_t index)
{
    static jmethodID getIntMethod = this->vm->GetMethodID(this->cls.get(), "getInt", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), getIntMethod, index);
}

std::int64_t ByteBuffer::getLong()
{
    static jmethodID getLongMethod = this->vm->GetMethodID(this->cls.get(), "getLong", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getLongMethod);
}

std::int64_t ByteBuffer::getLong(std::int32_t index)
{
    static jmethodID getLongMethod = this->vm->GetMethodID(this->cls.get(), "getLong", "(I)J");
    return this->vm->CallLongMethod(this->inst.get(), getLongMethod, index);
}

std::int16_t ByteBuffer::getShort()
{
    static jmethodID getShortMethod = this->vm->GetMethodID(this->cls.get(), "getShort", "()S");
    return this->vm->CallShortMethod(this->inst.get(), getShortMethod);
}

std::int16_t ByteBuffer::getShort(std::int32_t index)
{
    static jmethodID getShortMethod = this->vm->GetMethodID(this->cls.get(), "getShort", "(I)S");
    return this->vm->CallShortMethod(this->inst.get(), getShortMethod, index);
}

bool ByteBuffer::hasArray()
{
    static jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

std::int32_t ByteBuffer::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool ByteBuffer::isDirect()
{
    static jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

ByteOrder ByteBuffer::order()
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "()Ljava/nio/ByteOrder;");
    return ByteOrder(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod));
}

ByteBuffer ByteBuffer::order(ByteOrder bo)
{
    static jmethodID orderMethod = this->vm->GetMethodID(this->cls.get(), "order", "(Ljava/nio/ByteOrder;)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), orderMethod, bo.ref().get()));
}

ByteBuffer ByteBuffer::put(std::uint8_t b)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(B)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, b));
}

ByteBuffer ByteBuffer::put(std::int32_t index, std::uint8_t b)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(IB)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, index, b));
}

ByteBuffer ByteBuffer::put(ByteBuffer src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

ByteBuffer ByteBuffer::put(Array<std::uint8_t>& src, std::int32_t offset, std::int32_t length)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([BII)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get(), offset, length));
}

ByteBuffer ByteBuffer::put(Array<std::uint8_t>& src)
{
    static jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "([B)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, src.ref().get()));
}

ByteBuffer ByteBuffer::putChar(char value)
{
    static jmethodID putCharMethod = this->vm->GetMethodID(this->cls.get(), "putChar", "(C)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putCharMethod, value));
}

ByteBuffer ByteBuffer::putChar(std::int32_t index, char value)
{
    static jmethodID putCharMethod = this->vm->GetMethodID(this->cls.get(), "putChar", "(IC)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putCharMethod, index, value));
}

ByteBuffer ByteBuffer::putDouble(double value)
{
    static jmethodID putDoubleMethod = this->vm->GetMethodID(this->cls.get(), "putDouble", "(D)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putDoubleMethod, value));
}

ByteBuffer ByteBuffer::putDouble(std::int32_t index, double value)
{
    static jmethodID putDoubleMethod = this->vm->GetMethodID(this->cls.get(), "putDouble", "(ID)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putDoubleMethod, index, value));
}

ByteBuffer ByteBuffer::putFloat(float value)
{
    static jmethodID putFloatMethod = this->vm->GetMethodID(this->cls.get(), "putFloat", "(F)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putFloatMethod, value));
}

ByteBuffer ByteBuffer::putFloat(std::int32_t index, float value)
{
    static jmethodID putFloatMethod = this->vm->GetMethodID(this->cls.get(), "putFloat", "(IF)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putFloatMethod, index, value));
}

ByteBuffer ByteBuffer::putInt(std::int32_t value)
{
    static jmethodID putIntMethod = this->vm->GetMethodID(this->cls.get(), "putInt", "(I)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putIntMethod, value));
}

ByteBuffer ByteBuffer::putInt(std::int32_t index, std::int32_t value)
{
    static jmethodID putIntMethod = this->vm->GetMethodID(this->cls.get(), "putInt", "(II)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putIntMethod, index, value));
}

ByteBuffer ByteBuffer::putLong(std::int64_t value)
{
    static jmethodID putLongMethod = this->vm->GetMethodID(this->cls.get(), "putLong", "(J)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putLongMethod, value));
}

ByteBuffer ByteBuffer::putLong(std::int32_t index, std::int64_t value)
{
    static jmethodID putLongMethod = this->vm->GetMethodID(this->cls.get(), "putLong", "(IJ)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putLongMethod, index, value));
}

ByteBuffer ByteBuffer::putShort(std::int16_t value)
{
    static jmethodID putShortMethod = this->vm->GetMethodID(this->cls.get(), "putShort", "(S)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putShortMethod, value));
}

ByteBuffer ByteBuffer::putShort(std::int32_t index, std::int16_t value)
{
    static jmethodID putShortMethod = this->vm->GetMethodID(this->cls.get(), "putShort", "(IS)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), putShortMethod, index, value));
}

ByteBuffer ByteBuffer::slice()
{
    static jmethodID sliceMethod = this->vm->GetMethodID(this->cls.get(), "slice", "()Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), sliceMethod));
}

String ByteBuffer::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

ByteBuffer ByteBuffer::wrap(JVM* vm, Array<std::uint8_t>& array, std::int32_t offset, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ByteBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([BII)Ljava/nio/ByteBuffer;");
    return ByteBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get(), offset, length));
}

ByteBuffer ByteBuffer::wrap(JVM* vm, Array<std::uint8_t>& array)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ByteBuffer;"));
    static jmethodID wrapMethod = vm->GetStaticMethodID(cls.get(), "wrap", "([B)Ljava/nio/ByteBuffer;");
    return ByteBuffer(vm, vm->CallStaticObjectMethod(cls.get(), wrapMethod, array.ref().get()));
}
