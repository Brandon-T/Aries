//
//  JarEntry.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "JarEntry.hxx"
#include "ZipEntry.hxx"
#include "String.hxx"

using java::util::zip::ZipEntry;
using java::util::jar::JarEntry;

JarEntry::JarEntry(JVM* jvm, jobject instance) : ZipEntry(jvm, nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarEntry;"));
        this->inst = JVMRef<jobject>(this->vm, (instance));
    }
}

JarEntry::JarEntry(JVM* jvm, String name) : ZipEntry(jvm, nullptr)
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarEntry;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, name.ref().get()));
    }
}

JarEntry::JarEntry(JVM* jvm, ZipEntry entry) : ZipEntry(jvm, nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/jar/JarEntry;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/util/zip/ZipEntry;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, entry.ref().get()));
    }
}
