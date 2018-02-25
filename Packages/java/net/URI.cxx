//
//  URI.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "URI.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "URL.hxx"

using java::net::URI;
using java::lang::Object;
using java::lang::String;
using java::net::URL;


URI::URI(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

URI::URI(JVM* vm, String str) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, str.ref().get()));
    }
}

URI::URI(JVM* vm, String scheme, String userInfo, String host, std::int32_t port, String path, String query, String fragment) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, scheme.ref().get(), userInfo.ref().get(), host.ref().get(), port, path.ref().get(), query.ref().get(), fragment.ref().get()));
    }
}

URI::URI(JVM* vm, String scheme, String authority, String path, String query, String fragment) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, scheme.ref().get(), authority.ref().get(), path.ref().get(), query.ref().get(), fragment.ref().get()));
    }
}

URI::URI(JVM* vm, String scheme, String host, String path, String fragment) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, scheme.ref().get(), host.ref().get(), path.ref().get(), fragment.ref().get()));
    }
}

URI::URI(JVM* vm, String scheme, String ssp, String fragment) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URI;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, scheme.ref().get(), ssp.ref().get(), fragment.ref().get()));
    }
}

std::int32_t URI::compareTo(URI that)
{
    static jmethodID compareToMethod = this->vm->GetMethodID(this->cls.get(), "compareTo", "(Ljava/net/URI;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareToMethod, that.ref().get());
}

URI URI::create(JVM* vm, String str)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URI;"));
    static jmethodID createMethod = vm->GetStaticMethodID(cls.get(), "create", "(Ljava/lang/String;)Ljava/net/URI;");
    return URI(vm, vm->CallStaticObjectMethod(cls.get(), createMethod, str.ref().get()));
}

bool URI::equals(Object ob)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, ob.ref().get());
}

String URI::getAuthority()
{
    static jmethodID getAuthorityMethod = this->vm->GetMethodID(this->cls.get(), "getAuthority", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAuthorityMethod));
}

String URI::getFragment()
{
    static jmethodID getFragmentMethod = this->vm->GetMethodID(this->cls.get(), "getFragment", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFragmentMethod));
}

String URI::getHost()
{
    static jmethodID getHostMethod = this->vm->GetMethodID(this->cls.get(), "getHost", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHostMethod));
}

String URI::getPath()
{
    static jmethodID getPathMethod = this->vm->GetMethodID(this->cls.get(), "getPath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPathMethod));
}

std::int32_t URI::getPort()
{
    static jmethodID getPortMethod = this->vm->GetMethodID(this->cls.get(), "getPort", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getPortMethod);
}

String URI::getQuery()
{
    static jmethodID getQueryMethod = this->vm->GetMethodID(this->cls.get(), "getQuery", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getQueryMethod));
}

String URI::getRawAuthority()
{
    static jmethodID getRawAuthorityMethod = this->vm->GetMethodID(this->cls.get(), "getRawAuthority", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawAuthorityMethod));
}

String URI::getRawFragment()
{
    static jmethodID getRawFragmentMethod = this->vm->GetMethodID(this->cls.get(), "getRawFragment", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawFragmentMethod));
}

String URI::getRawPath()
{
    static jmethodID getRawPathMethod = this->vm->GetMethodID(this->cls.get(), "getRawPath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawPathMethod));
}

String URI::getRawQuery()
{
    static jmethodID getRawQueryMethod = this->vm->GetMethodID(this->cls.get(), "getRawQuery", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawQueryMethod));
}

String URI::getRawSchemeSpecificPart()
{
    static jmethodID getRawSchemeSpecificPartMethod = this->vm->GetMethodID(this->cls.get(), "getRawSchemeSpecificPart", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawSchemeSpecificPartMethod));
}

String URI::getRawUserInfo()
{
    static jmethodID getRawUserInfoMethod = this->vm->GetMethodID(this->cls.get(), "getRawUserInfo", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRawUserInfoMethod));
}

String URI::getScheme()
{
    static jmethodID getSchemeMethod = this->vm->GetMethodID(this->cls.get(), "getScheme", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSchemeMethod));
}

String URI::getSchemeSpecificPart()
{
    static jmethodID getSchemeSpecificPartMethod = this->vm->GetMethodID(this->cls.get(), "getSchemeSpecificPart", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSchemeSpecificPartMethod));
}

String URI::getUserInfo()
{
    static jmethodID getUserInfoMethod = this->vm->GetMethodID(this->cls.get(), "getUserInfo", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUserInfoMethod));
}

std::int32_t URI::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

bool URI::isAbsolute()
{
    static jmethodID isAbsoluteMethod = this->vm->GetMethodID(this->cls.get(), "isAbsolute", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAbsoluteMethod);
}

bool URI::isOpaque()
{
    static jmethodID isOpaqueMethod = this->vm->GetMethodID(this->cls.get(), "isOpaque", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isOpaqueMethod);
}

URI URI::normalize()
{
    static jmethodID normalizeMethod = this->vm->GetMethodID(this->cls.get(), "normalize", "()Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), normalizeMethod));
}

URI URI::parseServerAuthority()
{
    static jmethodID parseServerAuthorityMethod = this->vm->GetMethodID(this->cls.get(), "parseServerAuthority", "()Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), parseServerAuthorityMethod));
}

URI URI::relativize(URI uri)
{
    static jmethodID relativizeMethod = this->vm->GetMethodID(this->cls.get(), "relativize", "(Ljava/net/URI;)Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), relativizeMethod, uri.ref().get()));
}

URI URI::resolve(URI uri)
{
    static jmethodID resolveMethod = this->vm->GetMethodID(this->cls.get(), "resolve", "(Ljava/net/URI;)Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveMethod, uri.ref().get()));
}

URI URI::resolve(String str)
{
    static jmethodID resolveMethod = this->vm->GetMethodID(this->cls.get(), "resolve", "(Ljava/lang/String;)Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), resolveMethod, str.ref().get()));
}

String URI::toASCIIString()
{
    static jmethodID toASCIIStringMethod = this->vm->GetMethodID(this->cls.get(), "toASCIIString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toASCIIStringMethod));
}

String URI::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

URL URI::toURL()
{
    static jmethodID toURLMethod = this->vm->GetMethodID(this->cls.get(), "toURL", "()Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->inst.get(), toURLMethod));
}
