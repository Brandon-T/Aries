//
//  FileChannel.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileChannel.hxx"
#include "AbstractInterruptibleChannel.hxx"
#include "ByteBuffer.hxx"
#include "MappedByteBuffer.hxx"
#include "FileChannel$MapMode.hxx"
#include "FileLock.hxx"
#include "ReadableByteChannel.hxx"
#include "WritableByteChannel.hxx"
#include "OpenOption.hxx"
#include "Path.hxx"
#include "FileAttribute.hxx"
#include "Set.hxx"

using java::nio::channels::FileChannel;
using java::nio::ByteBuffer;
using java::nio::MappedByteBuffer;
using java::nio::channels::FileChannel$MapMode;
using java::nio::channels::FileLock;
using java::nio::channels::ReadableByteChannel;
using java::nio::channels::WritableByteChannel;
using java::nio::channels::spi::AbstractInterruptibleChannel;
using java::nio::file::OpenOption;
using java::nio::file::Path;
using java::nio::file::attribute::FileAttribute;
using java::util::Set;


FileChannel::FileChannel(JVM* vm, jobject instance) : AbstractInterruptibleChannel()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/FileChannel;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void FileChannel::force(bool metaData)
{
    static jmethodID forceMethod = this->vm->GetMethodID(this->cls.get(), "force", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), forceMethod, metaData);
}

FileLock FileChannel::lock(std::int64_t position, std::int64_t size, bool shared)
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "(JJZ)Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), lockMethod, position, size, shared));
}

FileLock FileChannel::lock()
{
    static jmethodID lockMethod = this->vm->GetMethodID(this->cls.get(), "lock", "()Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), lockMethod));
}

MappedByteBuffer FileChannel::map(FileChannel$MapMode arg0, std::int64_t arg1, std::int64_t arg2)
{
    static jmethodID mapMethod = this->vm->GetMethodID(this->cls.get(), "map", "(Ljava/nio/channels/FileChannel$MapMode;JJ)Ljava/nio/MappedByteBuffer;");
    return MappedByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), mapMethod, arg0.ref().get(), arg1, arg2));
}

FileChannel FileChannel::open(JVM* arg0, Path arg1, Set arg2, Array<FileAttribute>& arg3)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/channels/FileChannel;"));
    static jmethodID openMethod = vm->GetStaticMethodID(cls.get(), "open", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;");
    return FileChannel(vm, vm->CallStaticObjectMethod(cls.get(), openMethod, arg1.ref().get(), arg2.ref().get(), arg3.ref().get()));
}

FileChannel FileChannel::open(JVM* arg0, Path arg1, Array<OpenOption>& arg2)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/channels/FileChannel;"));
    static jmethodID openMethod = vm->GetStaticMethodID(cls.get(), "open", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/nio/channels/FileChannel;");
    return FileChannel(vm, vm->CallStaticObjectMethod(cls.get(), openMethod, arg1.ref().get(), arg2.ref().get()));
}

std::int64_t FileChannel::position()
{
    static jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "()J");
    return this->vm->CallLongMethod(this->inst.get(), positionMethod);
}

FileChannel FileChannel::position(std::int64_t newPosition)
{
    static jmethodID positionMethod = this->vm->GetMethodID(this->cls.get(), "position", "(J)Ljava/nio/channels/FileChannel;");
    return FileChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), positionMethod, newPosition));
}

std::int32_t FileChannel::read(ByteBuffer dst)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/ByteBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), readMethod, dst.ref().get());
}

std::int64_t FileChannel::read(Array<ByteBuffer>& dsts, std::int32_t offset, std::int32_t length)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "([Ljava/nio/ByteBuffer;II)J");
    return this->vm->CallLongMethod(this->inst.get(), readMethod, dsts.ref().get(), offset, length);
}

std::int64_t FileChannel::read(Array<ByteBuffer>& dsts)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "([Ljava/nio/ByteBuffer;)J");
    return this->vm->CallLongMethod(this->inst.get(), readMethod, dsts.ref().get());
}

std::int32_t FileChannel::read(ByteBuffer dst, std::int64_t position)
{
    static jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "(Ljava/nio/ByteBuffer;J)I");
    return this->vm->CallIntMethod(this->inst.get(), readMethod, dst.ref().get(), position);
}

std::int64_t FileChannel::size()
{
    static jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()J");
    return this->vm->CallLongMethod(this->inst.get(), sizeMethod);
}

std::int64_t FileChannel::transferFrom(ReadableByteChannel src, std::int64_t position, std::int64_t count)
{
    static jmethodID transferFromMethod = this->vm->GetMethodID(this->cls.get(), "transferFrom", "(Ljava/nio/channels/ReadableByteChannel;JJ)J");
    return this->vm->CallLongMethod(this->inst.get(), transferFromMethod, src.ref().get(), position, count);
}

std::int64_t FileChannel::transferTo(std::int64_t position, std::int64_t count, WritableByteChannel target)
{
    static jmethodID transferToMethod = this->vm->GetMethodID(this->cls.get(), "transferTo", "(JJLjava/nio/channels/WritableByteChannel;)J");
    return this->vm->CallLongMethod(this->inst.get(), transferToMethod, position, count, target.ref().get());
}

FileChannel FileChannel::truncate(std::int64_t size)
{
    static jmethodID truncateMethod = this->vm->GetMethodID(this->cls.get(), "truncate", "(J)Ljava/nio/channels/FileChannel;");
    return FileChannel(this->vm, this->vm->CallObjectMethod(this->inst.get(), truncateMethod, size));
}

FileLock FileChannel::tryLock(std::int64_t position, std::int64_t size, bool shared)
{
    static jmethodID tryLockMethod = this->vm->GetMethodID(this->cls.get(), "tryLock", "(JJZ)Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), tryLockMethod, position, size, shared));
}

FileLock FileChannel::tryLock()
{
    static jmethodID tryLockMethod = this->vm->GetMethodID(this->cls.get(), "tryLock", "()Ljava/nio/channels/FileLock;");
    return FileLock(this->vm, this->vm->CallObjectMethod(this->inst.get(), tryLockMethod));
}

std::int32_t FileChannel::write(ByteBuffer src)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/nio/ByteBuffer;)I");
    return this->vm->CallIntMethod(this->inst.get(), writeMethod, src.ref().get());
}

std::int64_t FileChannel::write(Array<ByteBuffer>& srcs, std::int32_t offset, std::int32_t length)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([Ljava/nio/ByteBuffer;II)J");
    return this->vm->CallLongMethod(this->inst.get(), writeMethod, srcs.ref().get(), offset, length);
}

std::int64_t FileChannel::write(Array<ByteBuffer>& srcs)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([Ljava/nio/ByteBuffer;)J");
    return this->vm->CallLongMethod(this->inst.get(), writeMethod, srcs.ref().get());
}

std::int32_t FileChannel::write(ByteBuffer src, std::int64_t position)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/nio/ByteBuffer;J)I");
    return this->vm->CallIntMethod(this->inst.get(), writeMethod, src.ref().get(), position);
}

FileChannel::FileChannel(JVM* vm) : AbstractInterruptibleChannel()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/FileChannel;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}
