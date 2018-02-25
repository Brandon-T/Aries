//
//  OutputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "OutputStream.hxx"
#include "Object.hxx"

using java::io::OutputStream;
using java::lang::Object;


OutputStream::OutputStream(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/OutputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

OutputStream::OutputStream(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/OutputStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

void OutputStream::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

void OutputStream::flush()
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "()V");
    this->vm->CallVoidMethod(this->inst.get(), flushMethod);
}

void OutputStream::write(std::int32_t b)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b);
}

void OutputStream::write(Array<std::uint8_t>& b)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([B)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b.ref().get());
}

void OutputStream::write(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([BII)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b.ref().get(), off, len);
}
