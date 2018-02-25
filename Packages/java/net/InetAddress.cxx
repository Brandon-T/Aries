//
//  InetAddress.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "InetAddress.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "NetworkInterface.hxx"

using java::net::InetAddress;
using java::lang::Object;
using java::lang::String;
using java::net::NetworkInterface;


InetAddress::InetAddress(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/InetAddress;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool InetAddress::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

Array<std::uint8_t> InetAddress::getAddress()
{
    static jmethodID getAddressMethod = this->vm->GetMethodID(this->cls.get(), "getAddress", "()[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getAddressMethod));
    return Array<std::uint8_t>(this->vm, arr);
}

Array<InetAddress> InetAddress::getAllByName(JVM* vm, String host)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getAllByNameMethod = vm->GetStaticMethodID(cls.get(), "getAllByName", "(Ljava/lang/String;)[Ljava/net/InetAddress;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), getAllByNameMethod, host.ref().get()));
    return Array<InetAddress>(vm, arr);
}

InetAddress InetAddress::getByAddress(JVM* vm, String host, Array<std::uint8_t>& addr)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getByAddressMethod = vm->GetStaticMethodID(cls.get(), "getByAddress", "(Ljava/lang/String;[B)Ljava/net/InetAddress;");
    return InetAddress(vm, vm->CallStaticObjectMethod(cls.get(), getByAddressMethod, host.ref().get(), addr.ref().get()));
}

InetAddress InetAddress::getByAddress(JVM* vm, Array<std::uint8_t>& addr)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getByAddressMethod = vm->GetStaticMethodID(cls.get(), "getByAddress", "([B)Ljava/net/InetAddress;");
    return InetAddress(vm, vm->CallStaticObjectMethod(cls.get(), getByAddressMethod, addr.ref().get()));
}

InetAddress InetAddress::getByName(JVM* vm, String host)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getByNameMethod = vm->GetStaticMethodID(cls.get(), "getByName", "(Ljava/lang/String;)Ljava/net/InetAddress;");
    return InetAddress(vm, vm->CallStaticObjectMethod(cls.get(), getByNameMethod, host.ref().get()));
}

String InetAddress::getCanonicalHostName()
{
    static jmethodID getCanonicalHostNameMethod = this->vm->GetMethodID(this->cls.get(), "getCanonicalHostName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCanonicalHostNameMethod));
}

String InetAddress::getHostAddress()
{
    static jmethodID getHostAddressMethod = this->vm->GetMethodID(this->cls.get(), "getHostAddress", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHostAddressMethod));
}

String InetAddress::getHostName()
{
    static jmethodID getHostNameMethod = this->vm->GetMethodID(this->cls.get(), "getHostName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHostNameMethod));
}

InetAddress InetAddress::getLocalHost(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getLocalHostMethod = vm->GetStaticMethodID(cls.get(), "getLocalHost", "()Ljava/net/InetAddress;");
    return InetAddress(vm, vm->CallStaticObjectMethod(cls.get(), getLocalHostMethod));
}

InetAddress InetAddress::getLoopbackAddress(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/InetAddress;"));
    static jmethodID getLoopbackAddressMethod = vm->GetStaticMethodID(cls.get(), "getLoopbackAddress", "()Ljava/net/InetAddress;");
    return InetAddress(vm, vm->CallStaticObjectMethod(cls.get(), getLoopbackAddressMethod));
}

std::int32_t InetAddress::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool InetAddress::isAnyLocalAddress()
{
    static jmethodID isAnyLocalAddressMethod = this->vm->GetMethodID(this->cls.get(), "isAnyLocalAddress", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAnyLocalAddressMethod);
}

bool InetAddress::isLinkLocalAddress()
{
    static jmethodID isLinkLocalAddressMethod = this->vm->GetMethodID(this->cls.get(), "isLinkLocalAddress", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLinkLocalAddressMethod);
}

bool InetAddress::isLoopbackAddress()
{
    static jmethodID isLoopbackAddressMethod = this->vm->GetMethodID(this->cls.get(), "isLoopbackAddress", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLoopbackAddressMethod);
}

bool InetAddress::isMCGlobal()
{
    static jmethodID isMCGlobalMethod = this->vm->GetMethodID(this->cls.get(), "isMCGlobal", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMCGlobalMethod);
}

bool InetAddress::isMCLinkLocal()
{
    static jmethodID isMCLinkLocalMethod = this->vm->GetMethodID(this->cls.get(), "isMCLinkLocal", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMCLinkLocalMethod);
}

bool InetAddress::isMCNodeLocal()
{
    static jmethodID isMCNodeLocalMethod = this->vm->GetMethodID(this->cls.get(), "isMCNodeLocal", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMCNodeLocalMethod);
}

bool InetAddress::isMCOrgLocal()
{
    static jmethodID isMCOrgLocalMethod = this->vm->GetMethodID(this->cls.get(), "isMCOrgLocal", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMCOrgLocalMethod);
}

bool InetAddress::isMCSiteLocal()
{
    static jmethodID isMCSiteLocalMethod = this->vm->GetMethodID(this->cls.get(), "isMCSiteLocal", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMCSiteLocalMethod);
}

bool InetAddress::isMulticastAddress()
{
    static jmethodID isMulticastAddressMethod = this->vm->GetMethodID(this->cls.get(), "isMulticastAddress", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMulticastAddressMethod);
}

bool InetAddress::isReachable(std::int32_t timeout)
{
    static jmethodID isReachableMethod = this->vm->GetMethodID(this->cls.get(), "isReachable", "(I)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReachableMethod, timeout);
}

bool InetAddress::isReachable(NetworkInterface netif, std::int32_t ttl, std::int32_t timeout)
{
    static jmethodID isReachableMethod = this->vm->GetMethodID(this->cls.get(), "isReachable", "(Ljava/net/NetworkInterface;II)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isReachableMethod, netif.ref().get(), ttl, timeout);
}

bool InetAddress::isSiteLocalAddress()
{
    static jmethodID isSiteLocalAddressMethod = this->vm->GetMethodID(this->cls.get(), "isSiteLocalAddress", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isSiteLocalAddressMethod);
}

String InetAddress::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
