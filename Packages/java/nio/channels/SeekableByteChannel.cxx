//
//  SeekableByteChannel.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "SeekableByteChannel.hxx"
#include "Object.hxx"
#include "ByteBuffer.hxx"

using java::nio::channels::SeekableByteChannel;
using java::lang::Object;
using java::nio::ByteBuffer;


SeekableByteChannel::SeekableByteChannel(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/SeekableByteChannel;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

std::int64_t SeekableByteChannel::position()
{
    static jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "()J");
    return this->vm->CallLongMethod(this->inst.get(), positionMethod);
}

SeekableByteChannel SeekableByteChannel::position(std::int64_t newPosition)
{
    static jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "(J)Ljava/nio/channels/SeekableByteChannel;");
    return SeekableByteChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), positionMethod, newPosition));
}

std::int32_t SeekableByteChannel::read(ByteBuffer dst)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/ByteBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), readMethod, dst.ref().get());
}

std::int64_t SeekableByteChannel::size()
{
    static jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()J");
    return this->vm->CallLongMethod(this->inst.get(), sizeMethod);
}

SeekableByteChannel SeekableByteChannel::truncate(std::int64_t size)
{
    static jmethodID truncateMethod = this->vm->GetMethodID(this->cls.get(), "truncate", "(J)Ljava/nio/channels/SeekableByteChannel;");
    return SeekableByteChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), truncateMethod, size));
}

std::int32_t SeekableByteChannel::write(ByteBuffer src)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/nio/ByteBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), writeMethod, src.ref().get());
}
