//
//  ByteOrder.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "ByteOrder.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::nio::ByteOrder;
using java::lang::Object;
using java::lang::String;


ByteOrder::ByteOrder(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/ByteOrder;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ByteOrder ByteOrder::nativeOrder(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/ByteOrder;"));
    static jmethodID nativeOrderMethod = vm->GetStaticMethodID(cls.get(), "nativeOrder", "()Ljava/nio/ByteOrder;");
    return ByteOrder(vm, vm->CallStaticObjectMethod(cls.get(), nativeOrderMethod));
}

String ByteOrder::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
