//
//  Supplier.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Supplier.hxx"
#include "Object.hxx"
#include "Object.hxx"

using java::util::function::Supplier;
using java::lang::Object;


Supplier::Supplier(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/function/Supplier;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Object Supplier::get()
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod));
}
