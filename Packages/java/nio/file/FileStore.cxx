//
//  FileStore.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileStore.hxx"
#include "Object.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "FileStoreAttributeView.hxx"

using java::nio::file::FileStore;
using java::lang::Class;
using java::lang::Object;
using java::lang::String;
using java::nio::file::attribute::FileStoreAttributeView;


FileStore::FileStore(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/FileStore;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Object FileStore::getAttribute(String attribute)
{
    static jmethodID getAttributeMethod = this->vm->GetMethodID(this->cls.get(), "getAttribute", "(Ljava/lang/String;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAttributeMethod, attribute.ref().get()));
}

FileStoreAttributeView FileStore::getFileStoreAttributeView(Class arg0)
{
    static jmethodID getFileStoreAttributeViewMethod = this->vm->GetMethodID(this->cls.get(), "getFileStoreAttributeView", "(Ljava/lang/Class;)Ljava/nio/file/attribute/FileStoreAttributeView;");
    return FileStoreAttributeView(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileStoreAttributeViewMethod, arg0.ref().get()));
}

std::int64_t FileStore::getTotalSpace()
{
    static jmethodID getTotalSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getTotalSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getTotalSpaceMethod);
}

std::int64_t FileStore::getUnallocatedSpace()
{
    static jmethodID getUnallocatedSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getUnallocatedSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getUnallocatedSpaceMethod);
}

std::int64_t FileStore::getUsableSpace()
{
    static jmethodID getUsableSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getUsableSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getUsableSpaceMethod);
}

bool FileStore::isReadOnly()
{
    static jmethodID isReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "isReadOnly", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReadOnlyMethod);
}

String FileStore::name()
{
    static jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}

bool FileStore::supportsFileAttributeView(Class type)
{
    static jmethodID supportsFileAttributeViewMethod = this->vm->GetMethodID(this->cls.get(), "supportsFileAttributeView", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), supportsFileAttributeViewMethod, type.ref().get());
}

bool FileStore::supportsFileAttributeView(String name)
{
    static jmethodID supportsFileAttributeViewMethod = this->vm->GetMethodID(this->cls.get(), "supportsFileAttributeView", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), supportsFileAttributeViewMethod, name.ref().get());
}

String FileStore::type()
{
    static jmethodID typeMethod = this->vm->GetMethodID(this->cls.get(), "type", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), typeMethod));
}

FileStore::FileStore(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/FileStore;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}
