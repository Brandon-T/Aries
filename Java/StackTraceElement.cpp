//
//  StackTraceElement.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "StackTraceElement.hpp"
#include "String.hpp"

using namespace java::lang;

StackTraceElement::StackTraceElement(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/StackTraceElement;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, defaultConstructor));
    }
}

StackTraceElement::StackTraceElement(JVM* jvm, jobject instance) : Object()
{
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/StackTraceElement;")));
    this->inst = this->vm->NewGlobalRef(instance);
}

StackTraceElement::~StackTraceElement()
{
    
}

String StackTraceElement::getClassName()
{
    jmethodID getClassNameMethod = this->vm->GetMethodID(this->cls, "getClassName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getClassNameMethod));
}

String StackTraceElement::getFileName()
{
    jmethodID getFileNameMethod = this->vm->GetMethodID(this->cls, "getFileName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getFileNameMethod));
}

int StackTraceElement::getLineNumber()
{
    jmethodID getLineNumberMethod = this->vm->GetMethodID(this->cls, "getLineNumber", "()I");
    return this->vm->CallIntMethod(this->inst, getLineNumberMethod);
}

String StackTraceElement::getMethodName()
{
    jmethodID getMethodNameMethod = this->vm->GetMethodID(this->cls, "getMethodName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getMethodNameMethod));
}

bool StackTraceElement::isNativeMethod()
{
    jmethodID isNativeMethodMethod = this->vm->GetMethodID(this->cls, "isNativeMethod", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isNativeMethodMethod);
}

