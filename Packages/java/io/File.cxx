//
//  File.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "File.hxx"
#include "Object.hxx"
#include "FileFilter.hxx"
#include "FilenameFilter.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "URI.hxx"
#include "URL.hxx"
#include "Path.hxx"

using java::io::File;
using java::io::FileFilter;
using java::io::FilenameFilter;
using java::lang::Object;
using java::lang::String;
using java::net::URI;
using java::net::URL;
using java::nio::file::Path;


File::File(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/File;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

File::File(JVM* vm, String pathname) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/File;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, pathname.ref().get()));
    }
}

File::File(JVM* vm, String parent, String child) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/File;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, parent.ref().get(), child.ref().get()));
    }
}

File::File(JVM* vm, File parent, String child) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/File;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, parent.ref().get(), child.ref().get()));
    }
}

File::File(JVM* vm, URI uri) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/File;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/net/URI;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, uri.ref().get()));
    }
}

bool File::canExecute()
{
    static jmethodID canExecuteMethod = this->vm->GetMethodID(this->cls.get(), "canExecute", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canExecuteMethod);
}

bool File::canRead()
{
    static jmethodID canReadMethod = this->vm->GetMethodID(this->cls.get(), "canRead", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canReadMethod);
}

bool File::canWrite()
{
    static jmethodID canWriteMethod = this->vm->GetMethodID(this->cls.get(), "canWrite", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canWriteMethod);
}

std::int32_t File::compareTo(File pathname)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/io/File;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, pathname.ref().get());
}

bool File::createNewFile()
{
    static jmethodID createNewFileMethod = this->vm->GetMethodID(this->cls.get(), "createNewFile", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), createNewFileMethod);
}

File File::createTempFile(JVM* vm, String prefix, String suffix, File directory)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/io/File;"));
    static jmethodID createTempFileMethod = vm->GetStaticMethodID(cls.get(), "createTempFile", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/File;)Ljava/io/File;");
    return File(vm, vm->CallStaticObjectMethod(cls.get(), createTempFileMethod, prefix.ref().get(), suffix.ref().get(), directory.ref().get()));
}

File File::createTempFile(JVM* vm, String prefix, String suffix)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/io/File;"));
    static jmethodID createTempFileMethod = vm->GetStaticMethodID(cls.get(), "createTempFile", "(Ljava/lang/String;Ljava/lang/String;)Ljava/io/File;");
    return File(vm, vm->CallStaticObjectMethod(cls.get(), createTempFileMethod, prefix.ref().get(), suffix.ref().get()));
}

bool File::delete()
{
    static jmethodID deleteMethod = this->vm->GetMethodID(this->cls.get(), "delete", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), deleteMethod);
}

void File::deleteOnExit()
{
    static jmethodID deleteOnExitMethod = this->vm->GetMethodID(this->cls.get(), "deleteOnExit", "()V");
    this->vm->CallVoidMethod(this->inst.get(), deleteOnExitMethod);
}

bool File::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

bool File::exists()
{
    static jmethodID existsMethod = this->vm->GetMethodID(this->cls.get(), "exists", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), existsMethod);
}

File File::getAbsoluteFile()
{
    static jmethodID getAbsoluteFileMethod = this->vm->GetMethodID(this->cls.get(), "getAbsoluteFile", "()Ljava/io/File;");
    return File(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAbsoluteFileMethod));
}

String File::getAbsolutePath()
{
    static jmethodID getAbsolutePathMethod = this->vm->GetMethodID(this->cls.get(), "getAbsolutePath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAbsolutePathMethod));
}

File File::getCanonicalFile()
{
    static jmethodID getCanonicalFileMethod = this->vm->GetMethodID(this->cls.get(), "getCanonicalFile", "()Ljava/io/File;");
    return File(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCanonicalFileMethod));
}

String File::getCanonicalPath()
{
    static jmethodID getCanonicalPathMethod = this->vm->GetMethodID(this->cls.get(), "getCanonicalPath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCanonicalPathMethod));
}

std::int64_t File::getFreeSpace()
{
    static jmethodID getFreeSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getFreeSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getFreeSpaceMethod);
}

String File::getName()
{
    static jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

String File::getParent()
{
    static jmethodID getParentMethod = this->vm->GetMethodID(this->cls.get(), "getParent", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getParentMethod));
}

File File::getParentFile()
{
    static jmethodID getParentFileMethod = this->vm->GetMethodID(this->cls.get(), "getParentFile", "()Ljava/io/File;");
    return File(this->vm, this->vm->CallObjectMethod(this->inst.get(), getParentFileMethod));
}

String File::getPath()
{
    static jmethodID getPathMethod = this->vm->GetMethodID(this->cls.get(), "getPath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPathMethod));
}

std::int64_t File::getTotalSpace()
{
    static jmethodID getTotalSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getTotalSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getTotalSpaceMethod);
}

std::int64_t File::getUsableSpace()
{
    static jmethodID getUsableSpaceMethod = this->vm->GetMethodID(this->cls.get(), "getUsableSpace", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getUsableSpaceMethod);
}

std::int32_t File::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool File::isAbsolute()
{
    static jmethodID isAbsoluteMethod = this->vm->GetMethodID(this->cls.get(), "isAbsolute", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAbsoluteMethod);
}

bool File::isDirectory()
{
    static jmethodID isDirectoryMethod = this->vm->GetMethodID(this->cls.get(), "isDirectory", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isDirectoryMethod);
}

bool File::isFile()
{
    static jmethodID isFileMethod = this->vm->GetMethodID(this->cls.get(), "isFile", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isFileMethod);
}

bool File::isHidden()
{
    static jmethodID isHiddenMethod = this->vm->GetMethodID(this->cls.get(), "isHidden", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isHiddenMethod);
}

std::int64_t File::lastModified()
{
    static jmethodID lastModifiedMethod = this->vm->GetMethodID(this->cls.get(), "lastModified", "()J");
    return this->vm->CallLongMethod(this->inst.get(), lastModifiedMethod);
}

std::int64_t File::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()J");
    return this->vm->CallLongMethod(this->inst.get(), lengthMethod);
}

Array<String> File::list()
{
    static jmethodID listMethod = this->vm->GetMethodID(this->cls.get(), "list", "()[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), listMethod));
    return Array<String>(this->vm, arr);
}

Array<String> File::list(FilenameFilter filter)
{
    static jmethodID listMethod = this->vm->GetMethodID(this->cls.get(), "list", "(Ljava/io/FilenameFilter;)[Ljava/lang/String;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), listMethod, filter.ref().get()));
    return Array<String>(this->vm, arr);
}

Array<File> File::listFiles()
{
    static jmethodID listFilesMethod = this->vm->GetMethodID(this->cls.get(), "listFiles", "()[Ljava/io/File;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), listFilesMethod));
    return Array<File>(this->vm, arr);
}

Array<File> File::listFiles(FilenameFilter filter)
{
    static jmethodID listFilesMethod = this->vm->GetMethodID(this->cls.get(), "listFiles", "(Ljava/io/FilenameFilter;)[Ljava/io/File;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), listFilesMethod, filter.ref().get()));
    return Array<File>(this->vm, arr);
}

Array<File> File::listFiles(FileFilter filter)
{
    static jmethodID listFilesMethod = this->vm->GetMethodID(this->cls.get(), "listFiles", "(Ljava/io/FileFilter;)[Ljava/io/File;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), listFilesMethod, filter.ref().get()));
    return Array<File>(this->vm, arr);
}

Array<File> File::listRoots(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/io/File;"));
    static jmethodID listRootsMethod = vm->GetStaticMethodID(cls.get(), "listRoots", "()[Ljava/io/File;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), listRootsMethod));
    return Array<File>(this->vm, arr);
}

bool File::mkdir()
{
    static jmethodID mkdirMethod = this->vm->GetMethodID(this->cls.get(), "mkdir", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), mkdirMethod);
}

bool File::mkdirs()
{
    static jmethodID mkdirsMethod = this->vm->GetMethodID(this->cls.get(), "mkdirs", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), mkdirsMethod);
}

bool File::renameTo(File dest)
{
    static jmethodID renameToMethod = this->vm->GetMethodID(this->cls.get(), "renameTo", "(Ljava/io/File;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), renameToMethod, dest.ref().get());
}

bool File::setExecutable(bool executable, bool ownerOnly)
{
    static jmethodID setExecutableMethod = this->vm->GetMethodID(this->cls.get(), "setExecutable", "(ZZ)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setExecutableMethod, executable, ownerOnly);
}

bool File::setExecutable(bool executable)
{
    static jmethodID setExecutableMethod = this->vm->GetMethodID(this->cls.get(), "setExecutable", "(Z)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setExecutableMethod, executable);
}

bool File::setLastModified(std::int64_t time)
{
    static jmethodID setLastModifiedMethod = this->vm->GetMethodID(this->cls.get(), "setLastModified", "(J)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setLastModifiedMethod, time);
}

bool File::setReadOnly()
{
    static jmethodID setReadOnlyMethod = this->vm->GetMethodID(this->cls.get(), "setReadOnly", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setReadOnlyMethod);
}

bool File::setReadable(bool readable, bool ownerOnly)
{
    static jmethodID setReadableMethod = this->vm->GetMethodID(this->cls.get(), "setReadable", "(ZZ)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setReadableMethod, readable, ownerOnly);
}

bool File::setReadable(bool readable)
{
    static jmethodID setReadableMethod = this->vm->GetMethodID(this->cls.get(), "setReadable", "(Z)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setReadableMethod, readable);
}

bool File::setWritable(bool writable, bool ownerOnly)
{
    static jmethodID setWritableMethod = this->vm->GetMethodID(this->cls.get(), "setWritable", "(ZZ)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setWritableMethod, writable, ownerOnly);
}

bool File::setWritable(bool writable)
{
    static jmethodID setWritableMethod = this->vm->GetMethodID(this->cls.get(), "setWritable", "(Z)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), setWritableMethod, writable);
}

Path File::toPath()
{
    static jmethodID toPathMethod = this->vm->GetMethodID(this->cls.get(), "toPath", "()Ljava/nio/file/Path;");
    return Path(this->vm, this->vm->CallObjectMethod(this->inst.get(), toPathMethod));
}

String File::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

URI File::toURI()
{
    static jmethodID toURIMethod = this->vm->GetMethodID(this->cls.get(), "toURI", "()Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), toURIMethod));
}

URL File::toURL()
{
    static jmethodID toURLMethod = this->vm->GetMethodID(this->cls.get(), "toURL", "()Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->inst.get(), toURLMethod));
}
