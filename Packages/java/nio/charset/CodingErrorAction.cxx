//
//  CodingErrorAction.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "CodingErrorAction.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::nio::charset::CodingErrorAction;
using java::lang::Object;
using java::lang::String;


CodingErrorAction::CodingErrorAction(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CodingErrorAction;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String CodingErrorAction::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
