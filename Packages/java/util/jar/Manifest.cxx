//
//  Manifest.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Manifest.hxx"
#include "String.hxx"
#include "Attributes.hxx"
#include "Map.hxx"
#include "InputStream.hxx"
#include "OutputStream.hxx"

using java::util::jar::Manifest;
using java::util::jar::Attributes;
using java::util::Map;
using java::lang::String;

Manifest::Manifest(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Manifest;"));
        jmethodID constructor = jvm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

Manifest::Manifest(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Manifest;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void Manifest::clear()
{
    jmethodID clearMethod = this->vm->GetMethodID(this->cls.get(), "clear", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearMethod);
}

Attributes Manifest::getAttributes(String name)
{
    jmethodID getAttributesMethod = this->vm->GetMethodID(this->cls.get(), "getAttributes", "(Ljava/lang/String;)Ljava/util/jar/Attributes;");
    return Attributes(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAttributesMethod, name.ref().get()));
}

Map<String, Attributes> Manifest::getEntries()
{
    jmethodID getEntriesMethod = this->vm->GetMethodID(this->cls.get(), "getEntries", "()Ljava/util/Map;");
    return Map<String, Attributes>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getEntriesMethod));
}

Attributes Manifest::getMainAttributes()
{
    jmethodID getMainAttributesMethod = this->vm->GetMethodID(this->cls.get(), "getMainAttributes", "()Ljava/util/jar/Attributes;");
    return Attributes(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMainAttributesMethod));
}

int Manifest::hashCode()
{
    jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

void Manifest::read(InputStream is)
{
    jmethodID readMethod = this->vm->GetMethodID(this->cls.get(), "read", "()Ljava/io/InputStream;");
    this->vm->CallVoidMethod(this->inst.get(), readMethod, is.ref().get());
}

void Manifest::write(OutputStream out)
{
    jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "()Ljava/io/OutputStream;");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, out.ref().get());
}
