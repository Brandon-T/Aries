//
//  FileLock.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileLock.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "AsynchronousFileChannel.hxx"
#include "Channel.hxx"
#include "FileChannel.hxx"

using java::nio::channels::FileLock;
using java::lang::Object;
using java::lang::String;
using java::nio::channels::AsynchronousFileChannel;
using java::nio::channels::Channel;
using java::nio::channels::FileChannel;


FileLock::FileLock(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/FileLock;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Channel FileLock::acquiredBy()
{
    static jmethodID acquiredByMethod = this->vm->GetMethodID(this->cls.get(), "acquiredBy", "()Ljava/nio/channels/Channel;");
    return Channel(this->vm, this->vm->CallObjectMethod(this->inst.get(), acquiredByMethod));
}

FileChannel FileLock::channel()
{
    static jmethodID channelMethod = this->vm->GetMethodID(this->cls.get(), "channel", "()Ljava/nio/channels/FileChannel;");
    return FileChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), channelMethod));
}

void FileLock::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

bool FileLock::isShared()
{
    static jmethodID isSharedMethod = this->vm->GetMethodID(this->cls.get(), "isShared", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isSharedMethod);
}

bool FileLock::isValid()
{
    static jmethodID isValidMethod = this->vm->GetMethodID(this->cls.get(), "isValid", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isValidMethod);
}

bool FileLock::overlaps(std::int64_t position, std::int64_t size)
{
    static jmethodID overlapsMethod = this->vm->GetMethodID(this->cls.get(), "overlaps", "(JJ)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), overlapsMethod, position, size);
}

std::int64_t FileLock::position()
{
    static jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "()J");
    return this->vm->CallLongMethod(this->inst.get(), positionMethod);
}

void FileLock::release()
{
    static jmethodID releaseMethod = this->vm->GetMethodID(this->cls.get(), "release", "()V");
    this->vm->CallVoidMethod(this->inst.get(), releaseMethod);
}

std::int64_t FileLock::size()
{
    static jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()J");
    return this->vm->CallLongMethod(this->inst.get(), sizeMethod);
}

String FileLock::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

FileLock::FileLock(JVM* vm, FileChannel channel, std::int64_t position, std::int64_t size, bool shared) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/FileLock;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/nio/channels/FileChannel;JJZ)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, channel.ref().get(), position, size, shared));
    }
}

FileLock::FileLock(JVM* vm, AsynchronousFileChannel channel, std::int64_t position, std::int64_t size, bool shared) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/FileLock;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/nio/channels/AsynchronousFileChannel;JJZ)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, channel.ref().get(), position, size, shared));
    }
}
