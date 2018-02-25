//
//  WatchKey.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "WatchKey.hxx"
#include "Object.hxx"
#include "Watchable.hxx"
#include "List.hxx"

using java::nio::file::WatchKey;
using java::lang::Object;
using java::nio::file::Watchable;
using java::util::List;


WatchKey::WatchKey(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/WatchKey;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void WatchKey::cancel()
{
    static jmethodID cancelMethod = this->vm->GetMethodID(this->cls.get(), "cancel", "()V");
    this->vm->CallVoidMethod(this->inst.get(), cancelMethod);
}

bool WatchKey::isValid()
{
    static jmethodID isValidMethod = this->vm->GetMethodID(this->cls.get(), "isValid", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isValidMethod);
}

List WatchKey::pollEvents()
{
    static jmethodID pollEventsMethod = this->vm->GetMethodID(this->cls.get(), "pollEvents", "()Ljava/util/List;");
    return List(this->vm, this->vm->CallObjectMethod(this->inst.get(), pollEventsMethod));
}

bool WatchKey::reset()
{
    static jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), resetMethod);
}

Watchable WatchKey::watchable()
{
    static jmethodID watchableMethod = this->vm->GetMethodID(this->cls.get(), "watchable", "()Ljava/nio/file/Watchable;");
    return Watchable(this->vm, this->vm->CallObjectMethod(this->inst.get(), watchableMethod));
}
