//
//  URL.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "URL.hxx"
#include "Object.hxx"
#include "InputStream.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Proxy.hxx"
#include "URI.hxx"
#include "URLConnection.hxx"
#include "URLStreamHandler.hxx"
#include "URLStreamHandlerFactory.hxx"

using java::net::URL;
using java::io::InputStream;
using java::lang::Class;
using java::lang::Object;
using java::lang::String;
using java::net::Proxy;
using java::net::URI;
using java::net::URLConnection;
using java::net::URLStreamHandler;
using java::net::URLStreamHandlerFactory;


URL::URL(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

URL::URL(JVM* vm, String protocol, String host, std::int32_t port, String file) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, protocol.ref().get(), host.ref().get(), port, file.ref().get()));
    }
}

URL::URL(JVM* vm, String protocol, String host, String file) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, protocol.ref().get(), host.ref().get(), file.ref().get()));
    }
}

URL::URL(JVM* vm, String protocol, String host, std::int32_t port, String file, URLStreamHandler handler) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/net/URLStreamHandler;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, protocol.ref().get(), host.ref().get(), port, file.ref().get(), handler.ref().get()));
    }
}

URL::URL(JVM* vm, String file) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, file.ref().get()));
    }
}

URL::URL(JVM* vm, URL context, String spec) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/net/URL;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, context.ref().get(), spec.ref().get()));
    }
}

URL::URL(JVM* vm, URL context, String spec, URLStreamHandler handler) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URL;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/net/URL;Ljava/lang/String;Ljava/net/URLStreamHandler;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, context.ref().get(), spec.ref().get(), handler.ref().get()));
    }
}

bool URL::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

String URL::getAuthority()
{
    static jmethodID getAuthorityMethod = this->vm->GetMethodID(this->cls.get(), "getAuthority", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAuthorityMethod));
}

Object URL::getContent()
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod));
}

Object URL::getContent(Array<Class>& classes)
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "([Ljava/lang/Class;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod, classes.ref().get()));
}

std::int32_t URL::getDefaultPort()
{
    static jmethodID getDefaultPortMethod = this->vm->GetMethodID(this->cls.get(), "getDefaultPort", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getDefaultPortMethod);
}

String URL::getFile()
{
    static jmethodID getFileMethod = this->vm->GetMethodID(this->cls.get(), "getFile", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFileMethod));
}

String URL::getHost()
{
    static jmethodID getHostMethod = this->vm->GetMethodID(this->cls.get(), "getHost", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHostMethod));
}

String URL::getPath()
{
    static jmethodID getPathMethod = this->vm->GetMethodID(this->cls.get(), "getPath", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPathMethod));
}

std::int32_t URL::getPort()
{
    static jmethodID getPortMethod = this->vm->GetMethodID(this->cls.get(), "getPort", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getPortMethod);
}

String URL::getProtocol()
{
    static jmethodID getProtocolMethod = this->vm->GetMethodID(this->cls.get(), "getProtocol", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getProtocolMethod));
}

String URL::getQuery()
{
    static jmethodID getQueryMethod = this->vm->GetMethodID(this->cls.get(), "getQuery", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getQueryMethod));
}

String URL::getRef()
{
    static jmethodID getRefMethod = this->vm->GetMethodID(this->cls.get(), "getRef", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRefMethod));
}

String URL::getUserInfo()
{
    static jmethodID getUserInfoMethod = this->vm->GetMethodID(this->cls.get(), "getUserInfo", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getUserInfoMethod));
}

std::int32_t URL::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

URLConnection URL::openConnection()
{
    static jmethodID openConnectionMethod = this->vm->GetMethodID(this->cls.get(), "openConnection", "()Ljava/net/URLConnection;");
    return URLConnection(this->vm, this->vm->CallObjectMethod(this->inst.get(), openConnectionMethod));
}

URLConnection URL::openConnection(Proxy proxy)
{
    static jmethodID openConnectionMethod = this->vm->GetMethodID(this->cls.get(), "openConnection", "(Ljava/net/Proxy;)Ljava/net/URLConnection;");
    return URLConnection(this->vm, this->vm->CallObjectMethod(this->inst.get(), openConnectionMethod, proxy.ref().get()));
}

InputStream URL::openStream()
{
    static jmethodID openStreamMethod = this->vm->GetMethodID(this->cls.get(), "openStream", "()Ljava/io/InputStream;");
    return InputStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), openStreamMethod));
}

bool URL::sameFile(URL other)
{
    static jmethodID sameFileMethod = this->vm->GetMethodID(this->cls.get(), "sameFile", "(Ljava/net/URL;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), sameFileMethod, other.ref().get());
}

void URL::setURLStreamHandlerFactory(JVM* vm, URLStreamHandlerFactory fac)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URL;"));
    static jmethodID setURLStreamHandlerFactoryMethod = vm->GetStaticMethodID(cls.get(), "setURLStreamHandlerFactory", "(Ljava/net/URLStreamHandlerFactory;)V");
    vm->CallStaticVoidMethod(cls.get(), setURLStreamHandlerFactoryMethod, fac.ref().get());
}

String URL::toExternalForm()
{
    static jmethodID toExternalFormMethod = this->vm->GetMethodID(this->cls.get(), "toExternalForm", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toExternalFormMethod));
}

String URL::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

URI URL::toURI()
{
    static jmethodID toURIMethod = this->vm->GetMethodID(this->cls.get(), "toURI", "()Ljava/net/URI;");
    return URI(this->vm, this->vm->CallObjectMethod(this->inst.get(), toURIMethod));
}
