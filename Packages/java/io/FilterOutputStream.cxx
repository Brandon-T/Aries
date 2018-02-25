//
//  FilterOutputStream.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FilterOutputStream.hxx"
#include "OutputStream.hxx"

using java::io::FilterOutputStream;
using java::io::OutputStream;


FilterOutputStream::FilterOutputStream(JVM* vm, jobject instance) : OutputStream(nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FilterOutputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

FilterOutputStream::FilterOutputStream(JVM* vm, OutputStream out) : OutputStream(nullptr)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FilterOutputStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get()));
    }
}

void FilterOutputStream::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

void FilterOutputStream::flush()
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "()V");
    this->vm->CallVoidMethod(this->inst.get(), flushMethod);
}

void FilterOutputStream::write(std::int32_t b)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b);
}

void FilterOutputStream::write(Array<std::uint8_t>& b)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([B)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b.ref().get());
}

void FilterOutputStream::write(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([BII)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b.ref().get(), off, len);
}
