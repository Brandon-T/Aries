//
//  URLStreamHandler.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "URLStreamHandler.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "InetAddress.hxx"
#include "Proxy.hxx"
#include "URL.hxx"
#include "URLConnection.hxx"

using java::net::URLStreamHandler;
using java::lang::Object;
using java::lang::String;
using java::net::InetAddress;
using java::net::Proxy;
using java::net::URL;
using java::net::URLConnection;


URLStreamHandler::URLStreamHandler(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URLStreamHandler;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

URLStreamHandler::URLStreamHandler(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URLStreamHandler;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

bool URLStreamHandler::equals(URL u1, URL u2)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/net/URL;Ljava/net/URL;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, u1.ref().get(), u2.ref().get());
}

std::int32_t URLStreamHandler::getDefaultPort()
{
    static jmethodID getDefaultPortMethod = this->vm->GetMethodID(this->cls.get(), "getDefaultPort", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getDefaultPortMethod);
}

InetAddress URLStreamHandler::getHostAddress(URL u)
{
    static jmethodID getHostAddressMethod = this->vm->GetMethodID(this->cls.get(), "getHostAddress", "(Ljava/net/URL;)Ljava/net/InetAddress;");
    return InetAddress(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHostAddressMethod, u.ref().get()));
}

std::int32_t URLStreamHandler::hashCode(URL u)
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "(Ljava/net/URL;)I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod, u.ref().get());
}

bool URLStreamHandler::hostsEqual(URL u1, URL u2)
{
    static jmethodID hostsEqualMethod = this->vm->GetMethodID(this->cls.get(), "hostsEqual", "(Ljava/net/URL;Ljava/net/URL;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hostsEqualMethod, u1.ref().get(), u2.ref().get());
}

URLConnection URLStreamHandler::openConnection(URL u)
{
    static jmethodID openConnectionMethod = this->vm->GetMethodID(this->cls.get(), "openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;");
    return URLConnection(this->vm, this->vm->CallObjectMethod(this->inst.get(), openConnectionMethod, u.ref().get()));
}

URLConnection URLStreamHandler::openConnection(URL u, Proxy p)
{
    static jmethodID openConnectionMethod = this->vm->GetMethodID(this->cls.get(), "openConnection", "(Ljava/net/URL;Ljava/net/Proxy;)Ljava/net/URLConnection;");
    return URLConnection(this->vm, this->vm->CallObjectMethod(this->inst.get(), openConnectionMethod, u.ref().get(), p.ref().get()));
}

void URLStreamHandler::parseURL(URL u, String spec, std::int32_t start, std::int32_t limit)
{
    static jmethodID parseURLMethod = this->vm->GetMethodID(this->cls.get(), "parseURL", "(Ljava/net/URL;Ljava/lang/String;II)V");
    this->vm->CallVoidMethod(this->inst.get(), parseURLMethod, u.ref().get(), spec.ref().get(), start, limit);
}

bool URLStreamHandler::sameFile(URL u1, URL u2)
{
    static jmethodID sameFileMethod = this->vm->GetMethodID(this->cls.get(), "sameFile", "(Ljava/net/URL;Ljava/net/URL;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), sameFileMethod, u1.ref().get(), u2.ref().get());
}

void URLStreamHandler::setURL(URL u, String protocol, String host, std::int32_t port, String authority, String userInfo, String path, String query, String ref)
{
    static jmethodID setURLMethod = this->vm->GetMethodID(this->cls.get(), "setURL", "(Ljava/net/URL;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), setURLMethod, u.ref().get(), protocol.ref().get(), host.ref().get(), port, authority.ref().get(), userInfo.ref().get(), path.ref().get(), query.ref().get(), ref.ref().get());
}

void URLStreamHandler::setURL(URL u, String protocol, String host, std::int32_t port, String file, String ref)
{
    static jmethodID setURLMethod = this->vm->GetMethodID(this->cls.get(), "setURL", "(Ljava/net/URL;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), setURLMethod, u.ref().get(), protocol.ref().get(), host.ref().get(), port, file.ref().get(), ref.ref().get());
}

String URLStreamHandler::toExternalForm(URL u)
{
    static jmethodID toExternalFormMethod = this->vm->GetMethodID(this->cls.get(), "toExternalForm", "(Ljava/net/URL;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toExternalFormMethod, u.ref().get()));
}
