//
//  Comparable.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Comparable.hxx"

using java::lang::Comparable;

Comparable::Comparable(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Comparable;"));
    }
}

int Comparable::compareTo(Object o)
{
    jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/lang/Object;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, o.ref().get());
}
