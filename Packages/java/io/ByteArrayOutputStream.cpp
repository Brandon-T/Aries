//
//  ByteArrayOutputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ByteArrayOutputStream.hpp"

using namespace java::io;

ByteArrayOutputStream::ByteArrayOutputStream(JVM* jvm) : OutputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/io/ByteArrayOutputStream;");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(vm->NewObject(this->cls, constructor));
    }
}

ByteArrayOutputStream::ByteArrayOutputStream(JVM* jvm, jint size) : OutputStream(nullptr)
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = this->vm->FindClass("Ljava/io/ByteArrayOutputStream;");
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(I)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, size));
    }
}

ByteArrayOutputStream::~ByteArrayOutputStream()
{
    
}

void ByteArrayOutputStream::reset()
{
    jmethodID resetMethod = this->vm->GetMethodID(this->cls, "reset", "()V");
    this->vm->CallVoidMethod(this->inst, resetMethod);
}

int ByteArrayOutputStream::size()
{
    jmethodID sizeMethod = this->vm->GetMethodID(this->cls, "size", "()I");
    return this->vm->CallIntMethod(this->inst, sizeMethod);
}

Array<jbyte> ByteArrayOutputStream::toByteArray()
{
    jmethodID toByteArrayMethod = this->vm->GetMethodID(this->cls, "toByteArray", "()[B");
    jbyteArray bytes = static_cast<jbyteArray>(this->vm->CallObjectMethod(this->inst, toByteArrayMethod));
    return Array<jbyte>(this->vm, bytes);
}

void ByteArrayOutputStream::writeTo(OutputStream out)
{
    jmethodID writeToMethod = this->vm->GetMethodID(this->cls, "writeTo", "(Ljava/io/OutputStream;)V");
    this->vm->CallVoidMethod(this->inst, writeToMethod, out.ref().get());
}
