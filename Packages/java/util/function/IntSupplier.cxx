//
//  IntSupplier.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "IntSupplier.hxx"

using java::util::function::IntSupplier;
using java::lang::Object;

IntSupplier::IntSupplier(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/function/IntSupplier;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

std::int32_t IntSupplier::getAsInt()
{
    static jmethodID getAsIntMethod = this->vm->GetMethodID(this->cls.get(), "getAsInt", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getAsIntMethod);
}
