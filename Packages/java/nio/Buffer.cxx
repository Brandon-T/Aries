//
//  Buffer.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Buffer.hxx"

using java::lang::Object;
using java::nio::Buffer;

Buffer::Buffer(JVM* jvm, jobject instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/Buffer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}


Object Buffer::array()
{
    jmethodID arrayMethod = this->vm->GetMethodID(this->cls.get(), "array", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), arrayMethod));
}

int Buffer::arrayOffset()
{
    jmethodID arrayOffsetMethod = this->vm->GetMethodID(this->cls.get(), "arrayOffset", "()I");
    return this->vm->CallIntMethod(this->inst.get(), arrayOffsetMethod);
}

int Buffer::capacity()
{
    jmethodID capacityMethod = this->vm->GetMethodID(this->cls.get(), "capacity", "()I");
    return this->vm->CallIntMethod(this->inst.get(), capacityMethod);
}

Buffer& Buffer::clear()
{
    jmethodID clearMethod = this->vm->GetMethodID(this->cls.get(), "clear", "()Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), clearMethod);
    return *this;
}

Buffer& Buffer::flip()
{
    jmethodID flipMethod = this->vm->GetMethodID(this->cls.get(), "flip", "()Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), flipMethod);
    return *this;
}

bool Buffer::hasArray()
{
    jmethodID hasArrayMethod = this->vm->GetMethodID(this->cls.get(), "hasArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasArrayMethod);
}

bool Buffer::isDirect()
{
    jmethodID isDirectMethod = this->vm->GetMethodID(this->cls.get(), "isDirect", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectMethod);
}

bool Buffer::isReadOnly()
{
    jmethodID isReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "isReadOnly", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReadOnlyMethod);
}

int Buffer::limit()
{
    jmethodID limitMethod = this->vm->GetMethodID(this->cls.get(), "limit", "()I");
    return this->vm->CallIntMethod(this->inst.get(), limitMethod);
}

Buffer& Buffer::mark()
{
    jmethodID markMethod = this->vm->GetMethodID(this->cls.get(), "mark", "()Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), markMethod);
    return *this;
}

int Buffer::position()
{
    jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "()I");
    return this->vm->CallIntMethod(this->inst.get(), positionMethod);
}

Buffer& Buffer::position(int newPosition)
{
    jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "(I)Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), positionMethod, newPosition);
    return *this;
}

int Buffer::remaining()
{
    jmethodID remainingMethod = this->vm->GetMethodID(this->cls.get(), "remaining", "()I");
    return this->vm->CallIntMethod(this->inst.get(), remainingMethod);
}

Buffer& Buffer::reset()
{
    jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), resetMethod);
    return *this;
}

Buffer& Buffer::rewind()
{
    jmethodID rewindMethod = this->vm->GetMethodID(this->cls.get(), "rewind", "()Ljava/nio/Buffer;");
    this->vm->CallObjectMethod(this->inst.get(), rewindMethod);
    return *this;
}
