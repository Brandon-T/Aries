//
//  ByteArrayOutputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ByteArrayOutputStream.hxx"

using java::io::ByteArrayOutputStream;

ByteArrayOutputStream::ByteArrayOutputStream(JVM* jvm) : OutputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/ByteArrayOutputStream;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, vm->NewObject(this->cls.get(), constructor));
    }
}

ByteArrayOutputStream::ByteArrayOutputStream(JVM* jvm, jint size) : OutputStream(nullptr)
{
    if (jvm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/ByteArrayOutputStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, size));
    }
}

void ByteArrayOutputStream::reset()
{
    jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()V");
    this->vm->CallVoidMethod(this->inst.get(), resetMethod);
}

int ByteArrayOutputStream::size()
{
    jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()I");
    return this->vm->CallIntMethod(this->inst.get(), sizeMethod);
}

Array<jbyte> ByteArrayOutputStream::toByteArray()
{
    jmethodID toByteArrayMethod = this->vm->GetMethodID(this->cls.get(), "toByteArray", "()[B");
    jbyteArray bytes = static_cast<jbyteArray>(this->vm->CallObjectMethod(this->inst.get(), toByteArrayMethod));
    return Array<jbyte>(this->vm, bytes);
}

void ByteArrayOutputStream::writeTo(OutputStream out)
{
    jmethodID writeToMethod = this->vm->GetMethodID(this->cls.get(), "writeTo", "(Ljava/io/OutputStream;)V");
    this->vm->CallVoidMethod(this->inst.get(), writeToMethod, out.ref().get());
}
