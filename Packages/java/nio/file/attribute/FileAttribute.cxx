//
//  FileAttribute.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileAttribute.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::nio::file::attribute::FileAttribute;
using java::lang::Object;
using java::lang::String;


FileAttribute::FileAttribute(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/FileAttribute;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String FileAttribute::name()
{
    static jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}

Object FileAttribute::value()
{
    static jmethodID valueMethod = this->vm->GetMethodID(this->cls.get(), "value", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), valueMethod));
}
