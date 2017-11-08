//
//  Object.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Object.hxx"
#include "Class.hxx"
#include "String.hxx"

using java::lang::Object;
using java::lang::Class;
using java::lang::String;

Object::Object()
{
    
}

Object::Object(JVM* jvm) : vm(jvm)
{
    if (jvm)
    {
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Object;"));
        jmethodID defaultConstructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), defaultConstructor));
    }
}

Object::Object(JVM* jvm, jobject instance) : vm(jvm)
{
    if (jvm && instance)
    {
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Object;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Object::Object(const Object &other)
{
    if (other.vm && other.cls && other.inst)
    {
        this->cls = other.cls.strongRef(other.vm);
        this->inst = other.inst.strongRef(other.vm);
    }
}

Object::Object(Object &&other) : vm(other.vm), cls(std::move(other.cls)), inst(std::move(other.inst))
{
    other.vm = nullptr;
    other.cls.reset();
    other.inst.reset();
}

Object::~Object()
{
    this->inst.reset();
    this->cls.reset();
    this->vm = nullptr;
}

JVMWeakRef<jobject> Object::ref()
{
    return this->inst.weakRef(this->vm);
}

Object* Object::clone()
{
    jmethodID cloneMethod = this->vm->GetMethodID(this->cls.get(), "clone", "()Ljava/lang/Object;");
    return new Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), cloneMethod));
}

void Object::finalize()
{
    jmethodID finalizeMethod = this->vm->GetMethodID(this->cls.get(), "finalize", "()V");
    this->vm->CallVoidMethod(this->inst.get(), finalizeMethod);
}

bool Object::equals(Object obj)
{
    jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.inst.get());
}

Class Object::getClass()
{
    jmethodID getClassMethod = this->vm->GetMethodID(this->cls.get(), "getClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getClassMethod));
}

int	Object::hashCode()
{
    jmethodID hashMethod = this->vm->GetMethodID(this->cls.get(), "hash", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashMethod);
}

void Object::notify()
{
    jmethodID notifyMethod = this->vm->GetMethodID(this->cls.get(), "notify", "()V");
    return this->vm->CallVoidMethod(this->inst.get(), notifyMethod);
}

void Object::notifyAll()
{
    jmethodID notifyAllMethod = this->vm->GetMethodID(this->cls.get(), "notifyAll", "()V");
    return this->vm->CallVoidMethod(this->inst.get(), notifyAllMethod);
}

String Object::toString()
{
    jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

void Object::wait()
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls.get(), "wait", "()V");
    this->vm->CallVoidMethod(this->inst.get(), waitMethod);
}

void Object::wait(jlong timeout)
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls.get(), "wait", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), waitMethod, timeout);
}

void Object::wait(jlong timeout, jint nanos)
{
    jmethodID waitMethod = this->vm->GetMethodID(this->cls.get(), "wait", "(JI)V");
    this->vm->CallVoidMethod(this->inst.get(), waitMethod, timeout, nanos);
}
