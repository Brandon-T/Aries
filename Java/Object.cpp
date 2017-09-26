//
//  Object.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Object.hpp"
#include "Class.hpp"
#include "String.hpp"

using namespace java::lang;

Object::Object()
{
    
}

Object::Object(JVM* jvm) : vm(jvm)
{
    if (jvm)
    {
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Object;")));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls, "<init>", "()V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, defaultConstructor));
    }
}

Object::Object(JVM* jvm, jobject instance) : vm(jvm)
{
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Object;")));
    this->inst = this->vm->NewGlobalRef(instance);
}

Object::Object(const Object &other) : vm(other.vm)
{
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(other.cls));
    this->inst = this->vm->NewGlobalRef(other.inst);
}

Object::Object(Object &&other) : vm(other.vm), cls(other.cls), inst(other.inst)
{
    other.vm = nullptr;
    other.cls = nullptr;
    other.inst = nullptr;
}

Object::~Object()
{
    if (this->cls && this->vm && this->inst)
    {
        this->vm->DeleteGlobalRef(this->inst);
        this->vm->DeleteGlobalRef(this->cls);
        this->inst = nullptr;
        this->cls = nullptr;
        this->vm = nullptr;
    }
}

JVMWeakRef<jobject> Object::ref()
{
    return JVMWeakRef<jobject>{this->vm, this->inst};
}

Object* Object::clone()
{
    jmethodID cloneMethod = this->vm->GetMethodID(this->cls, "clone", "()Ljava/lang/Object;");
    return new Object(this->vm, this->vm->CallObjectMethod(this->inst, cloneMethod));
}

void Object::finalize()
{
    jmethodID finalizeMethod = this->vm->GetMethodID(this->cls, "finalize", "()V");
    this->vm->CallVoidMethod(this->inst, finalizeMethod);
}

bool Object::equals(Object obj)
{
    jmethodID equalsMethod = this->vm->GetMethodID(this->cls, "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst, equalsMethod, obj.inst);
}

Class Object::getClass()
{
    jmethodID getClassMethod = this->vm->GetMethodID(this->cls, "getClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, getClassMethod));
}

int	Object::hashCode()
{
    jmethodID hashMethod = this->vm->GetMethodID(this->cls, "hash", "()I");
    return this->vm->CallIntMethod(this->inst, hashMethod);
}

void Object::notify()
{
    jmethodID notifyMethod = this->vm->GetMethodID(this->cls, "notify", "()V");
    return this->vm->CallVoidMethod(this->inst, notifyMethod);
}

void Object::notifyAll()
{
    jmethodID notifyAllMethod = this->vm->GetMethodID(this->cls, "notifyAll", "()V");
    return this->vm->CallVoidMethod(this->inst, notifyAllMethod);
}

String Object::toString()
{
    jmethodID toStringMethod = this->vm->GetMethodID(this->cls, "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, toStringMethod));
}

void Object::wait()
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls, "wait", "()V");
    this->vm->CallVoidMethod(this->inst, waitMethod);
}

void Object::wait(jlong timeout)
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls, "wait", "(J)V");
    this->vm->CallVoidMethod(this->inst, waitMethod, timeout);
}

void Object::wait(jlong timeout, jint nanos)
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls, "wait", "(JI)V");
    this->vm->CallVoidMethod(this->inst, waitMethod, timeout, nanos);
}
