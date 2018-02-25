//
//  MappedByteBuffer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "MappedByteBuffer.hxx"
#include "ByteBuffer.hxx"

using java::nio::MappedByteBuffer;
using java::nio::ByteBuffer;


MappedByteBuffer::MappedByteBuffer(JVM* vm, jobject instance) : ByteBuffer()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/MappedByteBuffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

MappedByteBuffer MappedByteBuffer::force()
{
    static jmethodID forceMethod = this->vm->GetMethodID(this->cls.get(), "force", "()Ljava/nio/MappedByteBuffer;");
    return MappedByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), forceMethod));
}

bool MappedByteBuffer::isLoaded()
{
    static jmethodID isLoadedMethod = this->vm->GetMethodID(this->cls.get(), "isLoaded", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLoadedMethod);
}

MappedByteBuffer MappedByteBuffer::load()
{
    static jmethodID loadMethod = this->vm->GetMethodID(this->cls.get(), "load", "()Ljava/nio/MappedByteBuffer;");
    return MappedByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), loadMethod));
}
