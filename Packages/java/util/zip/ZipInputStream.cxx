//
//  ZipInputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-27.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ZipInputStream.hxx"
#include "ZipEntry.hxx"
#include "String.hxx"
#include "Charset.hxx"

using java::lang::String;
using java::util::zip::ZipEntry;
using java::util::zip::ZipInputStream;

ZipInputStream::ZipInputStream(JVM* jvm, InputStream in) : InflaterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/ZipInputStream;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, in.ref().get()));
    }
}

ZipInputStream::ZipInputStream(JVM* jvm, InputStream in, Charset charset) : InflaterInputStream(nullptr)
{
    this->vm = jvm;
    this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/ZipInputStream;"));
    
    jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;Ljava/nio/charset/Charset;)V");
    this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, in.ref().get(), charset.ref().get()));
}

void ZipInputStream::closeEntry()
{
    jmethodID closeEntryMethod = this->vm->GetMethodID(this->cls.get(), "closeEntry", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeEntryMethod);
}

ZipEntry ZipInputStream::getNextEntry()
{
    jmethodID getNextEntryMethod = this->vm->GetMethodID(this->cls.get(), "getNextEntry", "()Ljava/util/ZipEntry;");
    return ZipEntry(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNextEntryMethod));
}

ZipEntry ZipInputStream::createZipEntry(String name)
{
    jmethodID createZipEntryMethod = this->vm->GetMethodID(this->cls.get(), "createZipEntry", "(Ljava/lang/String;)Ljava/util/ZipEntry;");
    return ZipEntry(this->vm, this->vm->CallObjectMethod(this->inst.get(), createZipEntryMethod, name.ref().get()));
}
