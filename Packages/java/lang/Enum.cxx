//
//  Enum.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Enum.hxx"
#include "Object.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::lang::Enum;
using java::lang::Class;
using java::lang::Object;
using java::lang::String;


Enum::Enum(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Enum;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

std::int32_t Enum::compareTo(Enum arg0)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/lang/Enum;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, arg0.ref().get());
}

bool Enum::equals(Object other)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, other.ref().get());
}

Class Enum::getDeclaringClass()
{
    static jmethodID getDeclaringClassMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaringClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaringClassMethod));
}

std::int32_t Enum::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

String Enum::name()
{
    static jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}

std::int32_t Enum::ordinal()
{
    static jmethodID ordinalMethod = this->vm->GetMethodID(this->cls.get(), "ordinal", "()I");
    return this->vm->CallIntMethod(this->inst.get(), ordinalMethod);
}

String Enum::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

Enum Enum::valueOf(JVM* vm, Class clz, String value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/Enum;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/Class;Ljava/lang/String;)Ljava/lang/Enum;");
    return Enum(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, clz.ref().get(), value.ref().get()));
}

Enum::Enum(JVM* vm, String name, std::int32_t ordinal) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Enum;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, name.ref().get(), ordinal));
    }
}

void Enum::finalize()
{
    static jmethodID finalizeMethod = this->vm->GetMethodID(this->cls.get(), "finalize", "()V");
    this->vm->CallVoidMethod(this->inst.get(), finalizeMethod);
}
