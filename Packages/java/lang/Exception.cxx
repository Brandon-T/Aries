//
//  Exception.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Exception.hxx"
#include "String.hxx"

using java::lang::Exception;

Exception::Exception(JVM* jvm) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), defaultConstructor));
    }
}

Exception::Exception(JVM* jvm, jobject instance) : Throwable()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Exception::Exception(JVM* jvm, String message) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get()));
    }
}

Exception::Exception(JVM* jvm, String message, Throwable cause) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get(), cause.ref().get()));
    }
}

Exception::Exception(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;ZZ)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get(), cause.ref().get(), enableSuppression, writableStackTrace));
    }
}

Exception::Exception(JVM* jvm, Throwable cause) : Throwable()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Exception;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/Throwable;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, cause.ref().get()));
    }
}
