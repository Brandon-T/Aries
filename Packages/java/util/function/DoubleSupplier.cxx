//
//  DoubleSupplier.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "DoubleSupplier.hxx"
#include "Object.hxx"

using java::util::function::DoubleSupplier;
using java::lang::Object;


DoubleSupplier::DoubleSupplier(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/function/DoubleSupplier;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

double DoubleSupplier::getAsDouble()
{
    static jmethodID getAsDoubleMethod = this->vm->GetMethodID(this->cls.get(), "getAsDouble", "()D");
    return this->vm->CallDoubleMethod(this->inst.get(), getAsDoubleMethod);
}
