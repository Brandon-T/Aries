//
//  WatchService.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "WatchService.hxx"
#include "Object.hxx"
#include "WatchKey.hxx"
#include "TimeUnit.hxx"

using java::nio::file::WatchService;
using java::lang::Object;
using java::nio::file::WatchKey;
using java::util::concurrent::TimeUnit;


WatchService::WatchService(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/WatchService;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void WatchService::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

WatchKey WatchService::poll()
{
    static jmethodID pollMethod = this->vm->GetMethodID(this->cls.get(), "poll", "()Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), pollMethod));
}

WatchKey WatchService::poll(std::int64_t timeout, TimeUnit unit)
{
    static jmethodID pollMethod = this->vm->GetMethodID(this->cls.get(), "poll", "(JLjava/util/concurrent/TimeUnit;)Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), pollMethod, timeout, unit.ref().get()));
}

WatchKey WatchService::take()
{
    static jmethodID takeMethod = this->vm->GetMethodID(this->cls.get(), "take", "()Ljava/nio/file/WatchKey;");
    return WatchKey(this->vm, this->vm->CallObjectMethod(this->inst.get(), takeMethod));
}
