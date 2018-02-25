//
//  AsynchronousFileChannel.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "AsynchronousFileChannel.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "ByteBuffer.hxx"
#include "CompletionHandler.hxx"
#include "FileLock.hxx"
#include "OpenOption.hxx"
#include "Path.hxx"
#include "FileAttribute.hxx"
#include "Set.hxx"
#include "ExecutorService.hxx"
#include "Future.hxx"

using java::nio::channels::AsynchronousFileChannel;
using java::lang::Object;
using java::nio::ByteBuffer;
using java::nio::channels::CompletionHandler;
using java::nio::channels::FileLock;
using java::nio::file::OpenOption;
using java::nio::file::Path;
using java::nio::file::attribute::FileAttribute;
using java::util::Set;
using java::util::concurrent::ExecutorService;
using java::util::concurrent::Future;


AsynchronousFileChannel::AsynchronousFileChannel(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/AsynchronousFileChannel;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void AsynchronousFileChannel::force(bool metaData)
{
    static jmethodID forceMethod = this->vm->GetMethodID(this->cls.get(), "force", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), forceMethod, metaData);
}

void AsynchronousFileChannel::lock(std::int64_t position, std::int64_t size, bool shared, Object attachment, CompletionHandler handler)
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V");
    this->vm->CallVoidMethod(this->inst.get(), lockMethod, position, size, shared, attachment.ref().get(), handler.ref().get());
}

void AsynchronousFileChannel::lock(Object attachment, CompletionHandler handler)
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V");
    this->vm->CallVoidMethod(this->inst.get(), lockMethod, attachment.ref().get(), handler.ref().get());
}

Future AsynchronousFileChannel::lock(std::int64_t position, std::int64_t size, bool shared)
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "(JJZ)Ljava/util/concurrent/Future;");
    return Future(this->vm, this->vm->CallObjectMethod(this->inst.get(), lockMethod, position, size, shared));
}

Future AsynchronousFileChannel::lock()
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "()Ljava/util/concurrent/Future;");
    return Future(this->vm, this->vm->CallObjectMethod(this->inst.get(), lockMethod));
}

AsynchronousFileChannel AsynchronousFileChannel::open(JVM* arg0, Path arg1, Set arg2, ExecutorService arg3, Array<FileAttribute>& arg4)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/channels/AsynchronousFileChannel;"));
    static jmethodID openMethod = vm->GetStaticMethodID(cls.get(), "open", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;");
    return AsynchronousFileChannel(vm, vm->CallStaticObjectMethod(cls.get(), openMethod, arg1.ref().get(), arg2.ref().get(), arg3.ref().get(), arg4.ref().get()));
}

AsynchronousFileChannel AsynchronousFileChannel::open(JVM* arg0, Path arg1, Array<OpenOption>& arg2)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/channels/AsynchronousFileChannel;"));
    static jmethodID openMethod = vm->GetStaticMethodID(cls.get(), "open", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/nio/channels/AsynchronousFileChannel;");
    return AsynchronousFileChannel(vm, vm->CallStaticObjectMethod(cls.get(), openMethod, arg1.ref().get(), arg2.ref().get()));
}

void AsynchronousFileChannel::read(ByteBuffer dst, std::int64_t position, Object attachment, CompletionHandler handler)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V");
    this->vm->CallVoidMethod(this->inst.get(), readMethod, dst.ref().get(), position, attachment.ref().get(), handler.ref().get());
}

Future AsynchronousFileChannel::read(ByteBuffer dst, std::int64_t position)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;");
    return Future(this->vm, this->vm->CallObjectMethod(this->inst.get(), readMethod, dst.ref().get(), position));
}

std::int64_t AsynchronousFileChannel::size()
{
    static jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()J");
    return this->vm->CallLongMethod(this->inst.get(), sizeMethod);
}

AsynchronousFileChannel AsynchronousFileChannel::truncate(std::int64_t size)
{
    static jmethodID truncateMethod = this->vm->GetMethodID(this->cls.get(), "truncate", "(J)Ljava/nio/channels/AsynchronousFileChannel;");
    return AsynchronousFileChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), truncateMethod, size));
}

FileLock AsynchronousFileChannel::tryLock(std::int64_t position, std::int64_t size, bool shared)
{
    static jmethodID tryLockMethod = this->vm->GetMethodID(this->cls.get(), "tryLock", "(JJZ)Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), tryLockMethod, position, size, shared));
}

FileLock AsynchronousFileChannel::tryLock()
{
    static jmethodID tryLockMethod = this->vm->GetMethodID(this->cls.get(), "tryLock", "()Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), tryLockMethod));
}

void AsynchronousFileChannel::write(ByteBuffer src, std::int64_t position, Object attachment, CompletionHandler handler)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, src.ref().get(), position, attachment.ref().get(), handler.ref().get());
}

Future AsynchronousFileChannel::write(ByteBuffer src, std::int64_t position)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;");
    return Future(this->vm, this->vm->CallObjectMethod(this->inst.get(), writeMethod, src.ref().get(), position));
}

AsynchronousFileChannel::AsynchronousFileChannel(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/AsynchronousFileChannel;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}
