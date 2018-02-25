//
//  IntConsumer.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "IntConsumer.hxx"
#include "Object.hxx"

using java::util::function::IntConsumer;
using java::lang::Object;


IntConsumer::IntConsumer(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/function/IntConsumer;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void IntConsumer::accept(std::int32_t value)
{
    static jmethodID acceptMethod = this->vm->GetMethodID(this->cls.get(), "accept", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), acceptMethod, value);
}

IntConsumer IntConsumer::andThen(IntConsumer after)
{
    static jmethodID andThenMethod = this->vm->GetMethodID(this->cls.get(), "andThen", "(Ljava/util/function/IntConsumer;)Ljava/util/function/IntConsumer;");
    return IntConsumer(this->vm, this->vm->CallObjectMethod(this->inst.get(), andThenMethod, after.ref().get()));
}
