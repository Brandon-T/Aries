//
//  Throwable.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Throwable.hxx"
#include "String.hxx"
#include "StackTraceElement.hxx"
#include "PrintStream.hxx"
#include "PrintWriter.hxx"

using java::lang::Throwable;
using java::lang::String;
using java::lang::StackTraceElement;

Throwable::Throwable(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), defaultConstructor));
    }
}

Throwable::Throwable(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Throwable::Throwable(JVM* jvm, String message) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get()));
    }
}

Throwable::Throwable(JVM* jvm, String message, Throwable cause) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get(), cause.ref().get()));
    }
}

Throwable::Throwable(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;ZZ)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, message.ref().get(), cause.ref().get(), enableSuppression, writableStackTrace));
    }
}

Throwable::Throwable(JVM* jvm, Throwable cause) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Throwable;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/Throwable;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, cause.ref().get()));
    }
}

void Throwable::addSuppressed(Throwable exception)
{
    jmethodID addSuppressedMethod = this->vm->GetMethodID(this->cls.get(), "addSuppressed", "(Ljava/lang/Throwable;)V");
    this->vm->CallVoidMethod(this->inst.get(), addSuppressedMethod, exception.ref().get());
}

Throwable Throwable::fillInStackTrace()
{
    jmethodID fillInStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "fillInStackTrace", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst.get(), fillInStackTraceMethod));
}

Throwable Throwable::getCause()
{
    jmethodID getCauseMethod = this->vm->GetMethodID(this->cls.get(), "getCause", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCauseMethod));
}

String Throwable::getLocalizedMessage()
{
    jmethodID getLocalizedMessageMethod = this->vm->GetMethodID(this->cls.get(), "getLocalizedMessage", "()Ljava/lang/String");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getLocalizedMessageMethod));
}

String Throwable::getMessage()
{
    jmethodID getMessageMethod = this->vm->GetMethodID(this->cls.get(), "getMessage", "()Ljava/lang/String");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMessageMethod));
}

Array<StackTraceElement> Throwable::getStackTrace()
{
    jmethodID getStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "getStackTrace", "()[Ljava/lang/StackTraceElement;");
    jobjectArray stackElements = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getStackTraceMethod));
    return Array<StackTraceElement>(this->vm, stackElements);
}

Array<Throwable> Throwable::getSuppressed()
{
    jmethodID getSuppressedMethod = this->vm->GetMethodID(this->cls.get(), "getSuppressed", "()[Ljava/lang/Throwable;");
    jobjectArray suppressedThrowables = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getSuppressedMethod));
    return Array<Throwable>(this->vm, suppressedThrowables);
}

Throwable Throwable::initCause(Throwable cause)
{
    jmethodID initCauseMethod = this->vm->GetMethodID(this->cls.get(), "initCause", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst.get(), initCauseMethod));
}

void Throwable::printStackTrace()
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "printStackTrace", "()V;");
    this->vm->CallVoidMethod(this->inst.get(), printStackTraceMethod);
}

void Throwable::printStackTrace(PrintStream stream)
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "printStackTrace", "(Ljava/lang/PrintStream;)V;");
    this->vm->CallVoidMethod(this->inst.get(), printStackTraceMethod, stream.ref().get());
}

void Throwable::printStackTrace(PrintWriter writer)
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "printStackTrace", "(Ljava/lang/PrintWriter;)V;");
    this->vm->CallVoidMethod(this->inst.get(), printStackTraceMethod, writer.ref().get());
}

void Throwable::setStackTrace(Array<StackTraceElement> stackTrace)
{
    jmethodID setStackTraceMethod = this->vm->GetMethodID(this->cls.get(), "setStackTrace", "([Ljava/lang/StackTraceElement;)V");
    this->vm->CallVoidMethod(this->inst.get(), setStackTraceMethod, stackTrace.ref().get());
}
