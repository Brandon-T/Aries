//
//  Watchable.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Watchable.hxx"
#include "Object.hxx"
#include "WatchEvent.hxx"
#include "WatchKey.hxx"
#include "WatchService.hxx"

using java::nio::file::Watchable;
using java::lang::Object;
using java::nio::file::WatchEvent;
using java::nio::file::WatchKey;
using java::nio::file::WatchService;


Watchable::Watchable(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/Watchable;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

WatchKey Watchable::register(WatchService arg0, Array<WatchEvent::Kind>& arg1, Array<WatchEvent::Modifier>& arg2)
{
    static jmethodID registerMethod = this->vm->GetMethodID(this->cls.get(), "register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), registerMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

WatchKey Watchable::register(WatchService arg0, Array<WatchEvent::Kind>& arg1)
{
    static jmethodID registerMethod = this->vm->GetMethodID(this->cls.get(), "register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;)Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), registerMethod, arg0.ref().get(), arg1.ref().get()));
}
