//
//  NetworkInterface.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "NetworkInterface.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "InetAddress.hxx"
#include "Enumeration.hxx"
#include "List.hxx"

using java::net::NetworkInterface;
using java::lang::Object;
using java::lang::String;
using java::net::InetAddress;
using java::util::Enumeration;
using java::util::List;


NetworkInterface::NetworkInterface(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/NetworkInterface;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool NetworkInterface::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

NetworkInterface NetworkInterface::getByIndex(JVM* vm, std::int32_t index)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/NetworkInterface;"));
    static jmethodID getByIndexMethod = vm->GetStaticMethodID(cls.get(), "getByIndex", "(I)Ljava/net/NetworkInterface;");
    return NetworkInterface(vm, vm->CallStaticObjectMethod(cls.get(), getByIndexMethod, index));
}

NetworkInterface NetworkInterface::getByInetAddress(JVM* vm, InetAddress addr)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/NetworkInterface;"));
    static jmethodID getByInetAddressMethod = vm->GetStaticMethodID(cls.get(), "getByInetAddress", "(Ljava/net/InetAddress;)Ljava/net/NetworkInterface;");
    return NetworkInterface(vm, vm->CallStaticObjectMethod(cls.get(), getByInetAddressMethod, addr.ref().get()));
}

NetworkInterface NetworkInterface::getByName(JVM* vm, String name)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/NetworkInterface;"));
    static jmethodID getByNameMethod = vm->GetStaticMethodID(cls.get(), "getByName", "(Ljava/lang/String;)Ljava/net/NetworkInterface;");
    return NetworkInterface(vm, vm->CallStaticObjectMethod(cls.get(), getByNameMethod, name.ref().get()));
}

String NetworkInterface::getDisplayName()
{
    static jmethodID getDisplayNameMethod = this->vm->GetMethodID(this->cls.get(), "getDisplayName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDisplayNameMethod));
}

Array<std::uint8_t> NetworkInterface::getHardwareAddress()
{
    static jmethodID getHardwareAddressMethod = this->vm->GetMethodID(this->cls.get(), "getHardwareAddress", "()[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getHardwareAddressMethod));
    return Array<std::uint8_t>(this->vm, arr);
}

std::int32_t NetworkInterface::getIndex()
{
    static jmethodID getIndexMethod = this->vm->GetMethodID(this->cls.get(), "getIndex", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getIndexMethod);
}

Enumeration<InetAddress> NetworkInterface::getInetAddresses()
{
    static jmethodID getInetAddressesMethod = this->vm->GetMethodID(this->cls.get(), "getInetAddresses", "()Ljava/util/Enumeration;");
    return Enumeration<InetAddress>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getInetAddressesMethod));
}

List<InetAddress> NetworkInterface::getInterfaceAddresses()
{
    static jmethodID getInterfaceAddressesMethod = this->vm->GetMethodID(this->cls.get(), "getInterfaceAddresses", "()Ljava/util/List;");
    return List<InetAddress>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getInterfaceAddressesMethod));
}

std::int32_t NetworkInterface::getMTU()
{
    static jmethodID getMTUMethod = this->vm->GetMethodID(this->cls.get(), "getMTU", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getMTUMethod);
}

String NetworkInterface::getName()
{
    static jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

Enumeration<InetAddress> NetworkInterface::getNetworkInterfaces(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/NetworkInterface;"));
    static jmethodID getNetworkInterfacesMethod = vm->GetStaticMethodID(cls.get(), "getNetworkInterfaces", "()Ljava/util/Enumeration;");
    return Enumeration<InetAddress>(vm, vm->CallStaticObjectMethod(cls.get(), getNetworkInterfacesMethod));
}

NetworkInterface NetworkInterface::getParent()
{
    static jmethodID getParentMethod = this->vm->GetMethodID(this->cls.get(), "getParent", "()Ljava/net/NetworkInterface;");
    return NetworkInterface(this->vm, this->vm->CallObjectMethod(this->inst.get(), getParentMethod));
}

Enumeration<InetAddress> NetworkInterface::getSubInterfaces()
{
    static jmethodID getSubInterfacesMethod = this->vm->GetMethodID(this->cls.get(), "getSubInterfaces", "()Ljava/util/Enumeration;");
    return Enumeration<InetAddress>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSubInterfacesMethod));
}

std::int32_t NetworkInterface::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool NetworkInterface::isLoopback()
{
    static jmethodID isLoopbackMethod = this->vm->GetMethodID(this->cls.get(), "isLoopback", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLoopbackMethod);
}

bool NetworkInterface::isPointToPoint()
{
    static jmethodID isPointToPointMethod = this->vm->GetMethodID(this->cls.get(), "isPointToPoint", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isPointToPointMethod);
}

bool NetworkInterface::isUp()
{
    static jmethodID isUpMethod = this->vm->GetMethodID(this->cls.get(), "isUp", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isUpMethod);
}

bool NetworkInterface::isVirtual()
{
    static jmethodID isVirtualMethod = this->vm->GetMethodID(this->cls.get(), "isVirtual", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isVirtualMethod);
}

bool NetworkInterface::supportsMulticast()
{
    static jmethodID supportsMulticastMethod = this->vm->GetMethodID(this->cls.get(), "supportsMulticast", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), supportsMulticastMethod);
}

String NetworkInterface::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
