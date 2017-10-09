//
//  Exception.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Exception.hpp"
#include "String.hpp"

using namespace java::lang;

Exception::Exception(JVM* jvm) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, defaultConstructor));
    }
}

Exception::Exception(JVM* jvm, jobject instance) : Throwable()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Exception::Exception(JVM* jvm, String message) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, message.ref().get()));
    }
}

Exception::Exception(JVM* jvm, String message, Throwable cause) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, message.ref().get(), cause.ref().get()));
    }
}

Exception::Exception(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;ZZ)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, message.ref().get(), cause.ref().get(), enableSuppression, writableStackTrace));
    }
}

Exception::Exception(JVM* jvm, Throwable cause) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Exception;")));
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/Throwable;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, cause.ref().get()));
    }
}

Exception::~Exception()
{
    
}
