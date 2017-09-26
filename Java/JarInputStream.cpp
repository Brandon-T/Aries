//
//  JarInputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "JarInputStream.hpp"

using namespace java::lang;
using namespace java::util::zip;
using namespace java::util::jar;

JarInputStream::JarInputStream(JVM* jvm, InputStream stream) : InputStream(nullptr)
{
    this->vm = jvm;
    this->cls = this->vm->FindClass("Ljava/util/jar/JarInputStream;");
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get()));
}

JarInputStream::JarInputStream(JVM* jvm, InputStream stream, bool verify)
{
    this->vm = jvm;
    this->cls = this->vm->FindClass("Ljava/util/jar/JarInputStream;");
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;Z)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get(), verify));
}

JarInputStream::~JarInputStream()
{

}

ZipEntry* JarInputStream::getNextEntry()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "getNextEntry", "()Ljava/util/zip/ZipEntry;");
    jobject localInstance = this->vm->CallObjectMethod(this->inst, method);
    return localInstance ? new ZipEntry(this->vm, nullptr, localInstance) : nullptr;
}

JarEntry* JarInputStream::getNextJarEntry()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "getNextJarEntry", "()Ljava/util/jar/JarEntry;");
    jobject localInstance = this->vm->CallObjectMethod(this->inst, method);
    return localInstance ? new JarEntry(this->vm, nullptr, localInstance) : nullptr;
}
