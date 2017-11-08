//
//  OutputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "OutputStream.hxx"

using java::io::OutputStream;

OutputStream::OutputStream(JVM* jvm) : Object()
{
    /*if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/OutputStream;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), defaultConstructor));
    }*/
}

OutputStream::OutputStream(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/OutputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void OutputStream::close()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), method);
}

void OutputStream::flush()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "flush", "()V");
    this->vm->CallVoidMethod(this->inst.get(), method);
}

void OutputStream::write(jbyte* buffer, int bufferLength)
{
    jbyteArray arr = this->vm->NewByteArray(bufferLength);
    this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
    jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([b)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, arr);
}

void OutputStream::write(jbyte* buffer, int bufferLength, int off, int len)
{
    jbyteArray arr = this->vm->NewByteArray(bufferLength);
    this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
    jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([bIII)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, arr, off, len);
}

void OutputStream::write(int b)
{
    jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b);
}
