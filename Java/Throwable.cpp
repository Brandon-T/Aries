//
//  Throwable.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Throwable.hpp"
#include "String.hpp"
#include "StackTraceElement.hpp"
#include "PrintStream.hpp"
#include "PrintWriter.hpp"

using namespace java::lang;

Throwable::Throwable(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, defaultConstructor));
    }
}

Throwable::Throwable(JVM* jvm, jobject instance) : Object()
{
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
    this->inst = this->vm->NewGlobalRef(instance);
}

Throwable::Throwable(JVM* jvm, String message) : Object()
{
    auto messageRef = message.ref();
    
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, messageRef.get()));
}

Throwable::Throwable(JVM* jvm, String message, Throwable cause) : Object()
{
    auto messageRef = message.ref();
    auto causeRef = cause.ref();
    
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, messageRef.get(), causeRef.get()));
}

Throwable::Throwable(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace) : Object()
{
    auto messageRef = message.ref();
    auto causeRef = cause.ref();
    
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;ZZ)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, messageRef.get(), causeRef.get(), enableSuppression, writableStackTrace));
}

Throwable::Throwable(JVM* jvm, Throwable cause) : Object()
{
    auto causeRef = cause.ref();
    
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Throwable;")));
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/lang/Throwable;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, causeRef.get()));
}

Throwable::~Throwable()
{
    
}

void Throwable::addSuppressed(Throwable exception)
{
    auto exceptionRef = exception.ref();
    jmethodID addSuppressedMethod = this->vm->GetMethodID(this->cls, "addSuppressed", "(Ljava/lang/Throwable;)V");
    this->vm->CallVoidMethod(this->inst, addSuppressedMethod, exceptionRef.get());
}

Throwable Throwable::fillInStackTrace()
{
    jmethodID fillInStackTraceMethod = this->vm->GetMethodID(this->cls, "fillInStackTrace", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst, fillInStackTraceMethod));
}

Throwable Throwable::getCause()
{
    jmethodID getCauseMethod = this->vm->GetMethodID(this->cls, "getCause", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst, getCauseMethod));
}

String Throwable::getLocalizedMessage()
{
    jmethodID getLocalizedMessageMethod = this->vm->GetMethodID(this->cls, "getLocalizedMessage", "()Ljava/lang/String");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getLocalizedMessageMethod));
}

String Throwable::getMessage()
{
    jmethodID getMessageMethod = this->vm->GetMethodID(this->cls, "getMessage", "()Ljava/lang/String");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getMessageMethod));
}

std::vector<StackTraceElement> Throwable::getStackTrace()
{
    jmethodID getStackTraceMethod = this->vm->GetMethodID(this->cls, "getStackTrace", "()[Ljava/lang/StackTraceElement;");
    jobjectArray stackElements = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getStackTraceMethod));
    jsize stackElementsSize = this->vm->GetArrayLength(stackElements);
    std::vector<StackTraceElement> result(stackElementsSize);
    
    for (jsize i = 0; i < stackElementsSize; ++i)
    {
        jobject stackElement = this->vm->GetObjectArrayElement(stackElements, i);
        result.emplace_back(StackTraceElement(this->vm, stackElement));
        this->vm->DeleteLocalRef(stackElement);
    }
    
    return result;
}

std::vector<Throwable> Throwable::getSuppressed()
{
    jmethodID getSuppressedMethod = this->vm->GetMethodID(this->cls, "getSuppressed", "()[Ljava/lang/Throwable;");
    jobjectArray suppressedThrowables = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getSuppressedMethod));
    jsize suppressedSize = this->vm->GetArrayLength(suppressedThrowables);
    std::vector<Throwable> result(suppressedSize);
    
    for (jsize i = 0; i < suppressedSize; ++i)
    {
        jobject suppressed = this->vm->GetObjectArrayElement(suppressedThrowables, i);
        result.emplace_back(Throwable(this->vm, suppressed));
        this->vm->DeleteLocalRef(suppressed);
    }
    
    return result;
}

Throwable Throwable::initCause(Throwable cause)
{
    jmethodID initCauseMethod = this->vm->GetMethodID(this->cls, "initCause", "()Ljava/lang/Throwable;");
    return Throwable(this->vm, this->vm->CallObjectMethod(this->inst, initCauseMethod));
}

void Throwable::printStackTrace()
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls, "printStackTrace", "()V;");
    this->vm->CallVoidMethod(this->inst, printStackTraceMethod);
}

void Throwable::printStackTrace(PrintStream stream)
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls, "printStackTrace", "(Ljava/lang/PrintStream;)V;");
    this->vm->CallVoidMethod(this->inst, printStackTraceMethod, stream.ref().get());
}

void Throwable::printStackTrace(PrintWriter writer)
{
    jmethodID printStackTraceMethod = this->vm->GetMethodID(this->cls, "printStackTrace", "(Ljava/lang/PrintWriter;)V;");
    this->vm->CallVoidMethod(this->inst, printStackTraceMethod, writer.ref().get());
}

void Throwable::setStackTrace(std::vector<StackTraceElement> stackTrace)
{
    jclass stackTraceElementCls = this->vm->FindClass("Ljava/lang/StackTraceElement;");
    jobjectArray stackTraceElements = this->vm->NewObjectArray(static_cast<jint>(stackTrace.size()), stackTraceElementCls, nullptr);
    
    for (std::size_t i = 0; i < stackTrace.size(); ++i)
    {
        this->vm->SetObjectArrayElement(stackTraceElements, static_cast<jint>(i), stackTrace[i].ref().get());
    }
    
    jmethodID setStackTraceMethod = this->vm->GetMethodID(this->cls, "setStackTrace", "([Ljava/lang/StackTraceElement;)V");
    this->vm->CallVoidMethod(this->inst, setStackTraceMethod, stackTraceElements);
}
