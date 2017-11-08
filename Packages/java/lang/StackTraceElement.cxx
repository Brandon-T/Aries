//
//  StackTraceElement.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "StackTraceElement.hxx"
#include "String.hxx"

using java::lang::StackTraceElement;
using java::lang::String;

StackTraceElement::StackTraceElement(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StackTraceElement;"));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), defaultConstructor));
    }
}

StackTraceElement::StackTraceElement(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/StackTraceElement;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String StackTraceElement::getClassName()
{
    jmethodID getClassNameMethod = this->vm->GetMethodID(this->cls.get(), "getClassName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getClassNameMethod));
}

String StackTraceElement::getFileName()
{
    jmethodID getFileNameMethod = this->vm->GetMethodID(this->cls.get(), "getFileName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileNameMethod));
}

int StackTraceElement::getLineNumber()
{
    jmethodID getLineNumberMethod = this->vm->GetMethodID(this->cls.get(), "getLineNumber", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getLineNumberMethod);
}

String StackTraceElement::getMethodName()
{
    jmethodID getMethodNameMethod = this->vm->GetMethodID(this->cls.get(), "getMethodName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethodNameMethod));
}

bool StackTraceElement::isNativeMethod()
{
    jmethodID isNativeMethodMethod = this->vm->GetMethodID(this->cls.get(), "isNativeMethod", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isNativeMethodMethod);
}

