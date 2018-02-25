//
//  WatchEvent.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "WatchEvent.hxx"
#include "Object.hxx"
#include "Class.hxx"
#include "String.hxx"

using java::nio::file::WatchEvent;
using java::lang::Object;


WatchEvent::WatchEvent(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/WatchEvent;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Object WatchEvent::context()
{
    static jmethodID contextMethod = this->vm->GetMethodID(this->cls.get(), "context", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), contextMethod));
}

std::int32_t WatchEvent::count()
{
    static jmethodID countMethod = this->vm->GetMethodID(this->cls.get(), "count", "()I");
    return this->vm->CallIntMethod(this->inst.get(), countMethod);
}

WatchEvent::Kind WatchEvent::kind()
{
    static jmethodID kindMethod = this->vm->GetMethodID(this->cls.get(), "kind", "()Ljava/nio/file/WatchEvent$Kind;");
    return WatchEvent::Kind(this->vm, this->vm->CallObjectMethod(this->inst.get(), kindMethod));
}



using java::lang::Class;
using java::lang::Object;
using java::lang::String;


WatchEvent::Kind::Kind(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/WatchEvent$Kind;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String WatchEvent::Kind::name()
{
    static jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}

Class WatchEvent::Kind::type()
{
    static jmethodID typeMethod = this->vm->GetMethodID(this->cls.get(), "type", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), typeMethod));
}



WatchEvent::Modifier::Modifier(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/WatchEvent$Modifier;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String WatchEvent::Modifier::name()
{
    static jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}
