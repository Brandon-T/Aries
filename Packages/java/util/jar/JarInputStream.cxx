//
//  JarInputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "JarInputStream.hxx"
#include "ZipEntry.hxx"
#include "JarEntry.hxx"

using java::util::zip::ZipEntry;
using java::util::jar::JarEntry;
using java::util::jar::JarInputStream;

JarInputStream::JarInputStream(JVM* jvm, jobject instance) : InputStream(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarInputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

JarInputStream::JarInputStream(JVM* jvm, InputStream stream) : InputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarInputStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get()));
    }
}

JarInputStream::JarInputStream(JVM* jvm, InputStream stream, bool verify) : InputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarInputStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;Z)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get(), verify));
    }
}

ZipEntry JarInputStream::getNextEntry()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "getNextEntry", "()Ljava/util/zip/ZipEntry;");
    jobject localInstance = this->vm->CallObjectMethod(this->inst.get(), method);
    return ZipEntry(this->vm, localInstance);
}

JarEntry JarInputStream::getNextJarEntry()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "getNextJarEntry", "()Ljava/util/jar/JarEntry;");
    jobject localInstance = this->vm->CallObjectMethod(this->inst.get(), method);
    return JarEntry(this->vm, localInstance);
}
