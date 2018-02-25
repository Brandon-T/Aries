//
//  Proxy.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Proxy.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "SocketAddress.hxx"

using java::net::Proxy;
using java::lang::Object;
using java::lang::String;
using java::net::SocketAddress;


Proxy::Proxy(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/Proxy;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Proxy::Proxy(JVM* vm, Proxy::Type proxyType, SocketAddress address) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/Proxy;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/net/Proxy$Type;Ljava/net/SocketAddress;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, proxyType.ref().get(), address.ref().get()));
    }
}

SocketAddress Proxy::address()
{
    static jmethodID addressMethod = this->vm->GetMethodID(this->cls.get(), "address", "()Ljava/net/SocketAddress;");
    return SocketAddress(this->vm, this->vm->CallObjectMethod(this->inst.get(), addressMethod));
}

bool Proxy::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

std::int32_t Proxy::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

String Proxy::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

Proxy::Type Proxy::type()
{
    static jmethodID typeMethod = this->vm->GetMethodID(this->cls.get(), "type", "()Ljava/net/Proxy$Type;");
    return Proxy::Type(this->vm, this->vm->CallObjectMethod(this->inst.get(), typeMethod));
}



using java::lang::Enum;
using java::lang::String;


Proxy::Type::Type(JVM* vm, jobject instance) : Enum(vm, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/Proxy$Type;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Proxy::Type Proxy::Type::valueOf(JVM* vm, String value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/Proxy$Type;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/String;)Ljava/net/Proxy$Type;");
    return Proxy::Type(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, value.ref().get()));
}

Array<Proxy::Type> Proxy::Type::values(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/Proxy$Type;"));
    static jmethodID valuesMethod = vm->GetStaticMethodID(cls.get(), "values", "()[Ljava/net/Proxy$Type;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), valuesMethod));
    return Array<Proxy::Type>(vm, arr);
}
