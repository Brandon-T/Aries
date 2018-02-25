//
//  Path.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Path.hxx"
#include "Object.hxx"
#include "File.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "URI.hxx"
#include "FileSystem.hxx"
#include "LinkOption.hxx"
#include "WatchEvent.hxx"
#include "WatchEvent$Modifier.hxx"
#include "WatchKey.hxx"
#include "WatchService.hxx"
#include "Iterator.hxx"

using java::nio::file::Path;
using java::io::File;
using java::lang::Object;
using java::lang::String;
using java::net::URI;
using java::nio::file::FileSystem;
using java::nio::file::LinkOption;
using java::nio::file::WatchEvent;
using java::nio::file::WatchKey;
using java::nio::file::WatchService;
using java::util::Iterator;


Path::Path(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/Path;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

std::int32_t Path::compareTo(Path other)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/nio/file/Path;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, other.ref().get());
}

bool Path::endsWith(Path other)
{
    static jmethodID endsWithMethod = this->vm->GetMethodID(this->cls.get(), "endsWith", "(Ljava/nio/file/Path;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), endsWithMethod, other.ref().get());
}

bool Path::endsWith(String other)
{
    static jmethodID endsWithMethod = this->vm->GetMethodID(this->cls.get(), "endsWith", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), endsWithMethod, other.ref().get());
}

bool Path::equals(Object other)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, other.ref().get());
}

Path Path::getFileName()
{
    static jmethodID getFileNameMethod = this->vm->GetMethodID(this->cls.get(), "getFileName", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileNameMethod));
}

FileSystem Path::getFileSystem()
{
    static jmethodID getFileSystemMethod = this->vm->GetMethodID(this->cls.get(), "getFileSystem", "()Ljava/nio/file/FileSystem;");
    return FileSystem(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileSystemMethod));
}

Path Path::getName(std::int32_t index)
{
    static jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "(I)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod, index));
}

std::int32_t Path::getNameCount()
{
    static jmethodID getNameCountMethod = this->vm->GetMethodID(this->cls.get(), "getNameCount", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getNameCountMethod);
}

Path Path::getParent()
{
    static jmethodID getParentMethod = this->vm->GetMethodID(this->cls.get(), "getParent", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), getParentMethod));
}

Path Path::getRoot()
{
    static jmethodID getRootMethod = this->vm->GetMethodID(this->cls.get(), "getRoot", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRootMethod));
}

std::int32_t Path::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool Path::isAbsolute()
{
    static jmethodID isAbsoluteMethod = this->vm->GetMethodID(this->cls.get(), "isAbsolute", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAbsoluteMethod);
}

Iterator Path::iterator()
{
    static jmethodID iteratorMethod = this->vm->GetMethodID(this->cls.get(), "iterator", "()Ljava/util/Iterator;");
    return Iterator(this->vm, this->vm->CallObjectMethod(this->inst.get(), iteratorMethod));
}

Path Path::normalize()
{
    static jmethodID normalizeMethod = this->vm->GetMethodID(this->cls.get(), "normalize", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), normalizeMethod));
}

WatchKey Path::registerService(WatchService arg0, Array<WatchEvent$Kind>& arg1, Array<WatchEvent$Modifier>& arg2)
{
    static jmethodID registerMethod = this->vm->GetMethodID(this->cls.get(), "register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), registerMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

WatchKey Path::registerService(WatchService arg0, Array<WatchEvent$Kind>& arg1)
{
    static jmethodID registerMethod = this->vm->GetMethodID(this->cls.get(), "register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;)Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), registerMethod, arg0.ref().get(), arg1.ref().get()));
}

Path Path::relativize(Path other)
{
    static jmethodID relativizeMethod = this->vm->GetMethodID(this->cls.get(), "relativize", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), relativizeMethod, other.ref().get()));
}

Path Path::resolve(Path other)
{
    static jmethodID resolveMethod = this->vm->GetMethodID(this->cls.get(), "resolve", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveMethod, other.ref().get()));
}

Path Path::resolve(String other)
{
    static jmethodID resolveMethod = this->vm->GetMethodID(this->cls.get(), "resolve", "(Ljava/lang/String;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveMethod, other.ref().get()));
}

Path Path::resolveSibling(Path other)
{
    static jmethodID resolveSiblingMethod = this->vm->GetMethodID(this->cls.get(), "resolveSibling", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveSiblingMethod, other.ref().get()));
}

Path Path::resolveSibling(String other)
{
    static jmethodID resolveSiblingMethod = this->vm->GetMethodID(this->cls.get(), "resolveSibling", "(Ljava/lang/String;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveSiblingMethod, other.ref().get()));
}

bool Path::startsWith(Path other)
{
    static jmethodID startsWithMethod = this->vm->GetMethodID(this->cls.get(), "startsWith", "(Ljava/nio/file/Path;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), startsWithMethod, other.ref().get());
}

bool Path::startsWith(String other)
{
    static jmethodID startsWithMethod = this->vm->GetMethodID(this->cls.get(), "startsWith", "(Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), startsWithMethod, other.ref().get());
}

Path Path::subpath(std::int32_t beginIndex, std::int32_t endIndex)
{
    static jmethodID subpathMethod = this->vm->GetMethodID(this->cls.get(), "subpath", "(II)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), subpathMethod, beginIndex, endIndex));
}

Path Path::toAbsolutePath()
{
    static jmethodID toAbsolutePathMethod = this->vm->GetMethodID(this->cls.get(), "toAbsolutePath", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), toAbsolutePathMethod));
}

File Path::toFile()
{
    static jmethodID toFileMethod = this->vm->GetMethodID(this->cls.get(), "toFile", "()Ljava/io/File;");
    return File(this->vm, this->vm->CallObjectMethod(this->inst.get(), toFileMethod));
}

Path Path::toRealPath(Array<LinkOption>& arg0)
{
    static jmethodID toRealPathMethod = this->vm->GetMethodID(this->cls.get(), "toRealPath", "([Ljava/nio/file/LinkOption;)Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), toRealPathMethod, arg0.ref().get()));
}

String Path::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

URI Path::toUri()
{
    static jmethodID toUriMethod = this->vm->GetMethodID(this->cls.get(), "toUri", "()Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), toUriMethod));
}
