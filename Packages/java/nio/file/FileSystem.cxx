//
//  FileSystem.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileSystem.hxx"
#include "Object.hxx"
#include "Iterable.hxx"
#include "String.hxx"
#include "Path.hxx"
#include "PathMatcher.hxx"
#include "WatchService.hxx"
#include "UserPrincipalLookupService.hxx"
#include "FileSystemProvider.hxx"
#include "Set.hxx"

using java::nio::file::FileSystem;
using java::lang::Iterable;
using java::lang::Object;
using java::lang::String;
using java::nio::file::Path;
using java::nio::file::PathMatcher;
using java::nio::file::WatchService;
using java::nio::file::attribute::UserPrincipalLookupService;
using java::nio::file::spi::FileSystemProvider;
using java::util::Set;


FileSystem::FileSystem(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/FileSystem;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void FileSystem::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

Iterable FileSystem::getFileStores()
{
    static jmethodID getFileStoresMethod = this->vm->GetMethodID(this->cls.get(), "getFileStores", "()Ljava/lang/Iterable;");
    return Iterable(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileStoresMethod));
}

Path FileSystem::getPath(String arg0, Array<String>& arg1)
{
    static jmethodID getPathMethod = this->vm->GetMethodID(this->cls.get(), "getPath", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPathMethod, arg0.ref().get(), arg1.ref().get()));
}

PathMatcher FileSystem::getPathMatcher(String syntaxAndPattern)
{
    static jmethodID getPathMatcherMethod = this->vm->GetMethodID(this->cls.get(), "getPathMatcher", "(Ljava/lang/String;)Ljava/nio/file/PathMatcher;");
    return PathMatcher(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPathMatcherMethod, syntaxAndPattern.ref().get()));
}

Iterable FileSystem::getRootDirectories()
{
    static jmethodID getRootDirectoriesMethod = this->vm->GetMethodID(this->cls.get(), "getRootDirectories", "()Ljava/lang/Iterable;");
    return Iterable(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRootDirectoriesMethod));
}

String FileSystem::getSeparator()
{
    static jmethodID getSeparatorMethod = this->vm->GetMethodID(this->cls.get(), "getSeparator", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSeparatorMethod));
}

UserPrincipalLookupService FileSystem::getUserPrincipalLookupService()
{
    static jmethodID getUserPrincipalLookupServiceMethod = this->vm->GetMethodID(this->cls.get(), "getUserPrincipalLookupService", "()Ljava/nio/file/attribute/UserPrincipalLookupService;");
    return UserPrincipalLookupService(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUserPrincipalLookupServiceMethod));
}

bool FileSystem::isOpen()
{
    static jmethodID isOpenMethod = this->vm->GetMethodID(this->cls.get(), "isOpen", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isOpenMethod);
}

bool FileSystem::isReadOnly()
{
    static jmethodID isReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "isReadOnly", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReadOnlyMethod);
}

WatchService FileSystem::newWatchService()
{
    static jmethodID newWatchServiceMethod = this->vm->GetMethodID(this->cls.get(), "newWatchService", "()Ljava/nio/file/WatchService;");
    return WatchService(this->vm, this->vm->CallObjectMethod(this->inst.get(), newWatchServiceMethod));
}

FileSystemProvider FileSystem::provider()
{
    static jmethodID providerMethod = this->vm->GetMethodID(this->cls.get(), "provider", "()Ljava/nio/file/spi/FileSystemProvider;");
    return FileSystemProvider(this->vm, this->vm->CallObjectMethod(this->inst.get(), providerMethod));
}

Set FileSystem::supportedFileAttributeViews()
{
    static jmethodID supportedFileAttributeViewsMethod = this->vm->GetMethodID(this->cls.get(), "supportedFileAttributeViews", "()Ljava/util/Set;");
    return Set(this->vm, this->vm->CallObjectMethod(this->inst.get(), supportedFileAttributeViewsMethod));
}

FileSystem::FileSystem(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/FileSystem;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}
