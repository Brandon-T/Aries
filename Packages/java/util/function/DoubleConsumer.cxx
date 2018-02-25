//
//  DoubleConsumer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "DoubleConsumer.hxx"

using java::util::function::DoubleConsumer;
using java::lang::Object;


DoubleConsumer::DoubleConsumer(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/function/DoubleConsumer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void DoubleConsumer::accept(double value)
{
    static jmethodID acceptMethod = this->vm->GetMethodID(this->cls.get(), "accept", "(D)V");
    this->vm->CallVoidMethod(this->inst.get(), acceptMethod, value);
}

DoubleConsumer DoubleConsumer::andThen(DoubleConsumer after)
{
    static jmethodID andThenMethod = this->vm->GetMethodID(this->cls.get(), "andThen", "(Ljava/util/function/DoubleConsumer;)Ljava/util/function/DoubleConsumer;");
    return DoubleConsumer(this->vm, this->vm->CallObjectMethod(this->inst.get(), andThenMethod, after.ref().get()));
}
