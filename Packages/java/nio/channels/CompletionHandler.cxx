//
//  CompletionHandler.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "CompletionHandler.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "Throwable.hxx"

using java::nio::channels::CompletionHandler;
using java::lang::Object;
using java::lang::Throwable;


CompletionHandler::CompletionHandler(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/channels/CompletionHandler;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void CompletionHandler::completed(Object result, Object attachment)
{
    static jmethodID completedMethod = this->vm->GetMethodID(this->cls.get(), "completed", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), completedMethod, result.ref().get(), attachment.ref().get());
}

void CompletionHandler::failed(Throwable exc, Object attachment)
{
    static jmethodID failedMethod = this->vm->GetMethodID(this->cls.get(), "failed", "(Ljava/lang/Throwable;Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), failedMethod, exc.ref().get(), attachment.ref().get());
}
