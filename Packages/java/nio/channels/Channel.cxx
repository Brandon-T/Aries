//
//  Channel.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Channel.hxx"
#include "Object.hxx"

using java::nio::channels::Channel;
using java::lang::Object;


Channel::Channel(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/Channel;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void Channel::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

bool Channel::isOpen()
{
    static jmethodID isOpenMethod = this->vm->GetMethodID(this->cls.get(), "isOpen", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isOpenMethod);
}
