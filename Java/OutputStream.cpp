//
//  OutputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "OutputStream.hpp"

using namespace java::io;

OutputStream::OutputStream(JVM* jvm) : Object()
{
    /*if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/io/OutputStream;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, defaultConstructor));
    }*/
}

OutputStream::OutputStream(JVM* jvm, jobject instance) : Object()
{
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/OutputStream;")));
    this->inst = this->vm->NewGlobalRef(instance);
}

OutputStream::~OutputStream()
{
    
}

void OutputStream::close()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "close", "()V");
    this->vm->CallVoidMethod(this->inst, method);
}

void OutputStream::flush()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "flush", "()V");
    this->vm->CallVoidMethod(this->inst, method);
}

void OutputStream::write(jbyte* buffer, int bufferLength)
{
    jbyteArray arr = this->vm->NewByteArray(bufferLength);
    this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
    jmethodID writeMethod = this->vm->GetMethodID(this->cls, "write", "([b)V");
    this->vm->CallVoidMethod(this->inst, writeMethod, arr);
}

void OutputStream::write(jbyte* buffer, int bufferLength, int off, int len)
{
    jbyteArray arr = this->vm->NewByteArray(bufferLength);
    this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
    jmethodID writeMethod = this->vm->GetMethodID(this->cls, "write", "([bIII)V");
    this->vm->CallVoidMethod(this->inst, writeMethod, arr, off, len);
}

void OutputStream::write(int b)
{
    jmethodID writeMethod = this->vm->GetMethodID(this->cls, "write", "(I)V");
    this->vm->CallVoidMethod(this->inst, writeMethod, b);
}
