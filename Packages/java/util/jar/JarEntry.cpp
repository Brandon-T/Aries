//
//  JarEntry.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "JarEntry.hpp"
#include "ZipEntry.hpp"
#include "String.hpp"

using namespace java::util::zip;
using namespace java::util::jar;
using namespace java::lang;

JarEntry::JarEntry(JVM* jvm, jobject instance) : ZipEntry(jvm, nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/jar/JarEntry;");
        this->inst = jvm->NewGlobalRef(instance);
    }
}

JarEntry::JarEntry(JVM* jvm, String name) : ZipEntry(jvm, nullptr)
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = this->vm->FindClass("Ljava/util/jar/JarEntry;");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, name.ref().get()));
    }
}

JarEntry::JarEntry(JVM* jvm, ZipEntry entry) : ZipEntry(jvm, nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/jar/JarEntry;");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/util/zip/ZipEntry;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, entry.ref().get()));
    }
}

JarEntry::~JarEntry()
{
    
}
