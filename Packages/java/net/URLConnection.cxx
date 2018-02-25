//
//  URLConnection.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "URLConnection.hxx"
#include "Object.hxx"
#include "InputStream.hxx"
#include "OutputStream.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ContentHandlerFactory.hxx"
#include "FileNameMap.hxx"
#include "URL.hxx"
#include "Permission.hxx"
#include "Map.hxx"
#include "List.hxx"

using java::net::URLConnection;
using java::io::InputStream;
using java::io::OutputStream;
using java::lang::Class;
using java::lang::Object;
using java::lang::String;
using java::net::ContentHandlerFactory;
using java::net::FileNameMap;
using java::net::URL;
using java::security::Permission;
using java::util::Map;
using java::util::List;


URLConnection::URLConnection(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URLConnection;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

void URLConnection::addRequestProperty(String key, String value)
{
    static jmethodID addRequestPropertyMethod = this->vm->GetMethodID(this->cls.get(), "addRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), addRequestPropertyMethod, key.ref().get(), value.ref().get());
}

void URLConnection::connect()
{
    static jmethodID connectMethod = this->vm->GetMethodID(this->cls.get(), "connect", "()V");
    this->vm->CallVoidMethod(this->inst.get(), connectMethod);
}

bool URLConnection::getAllowUserInteraction()
{
    static jmethodID getAllowUserInteractionMethod = this->vm->GetMethodID(this->cls.get(), "getAllowUserInteraction", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), getAllowUserInteractionMethod);
}

std::int32_t URLConnection::getConnectTimeout()
{
    static jmethodID getConnectTimeoutMethod = this->vm->GetMethodID(this->cls.get(), "getConnectTimeout", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getConnectTimeoutMethod);
}

Object URLConnection::getContent()
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod));
}

Object URLConnection::getContent(Array<Class>& classes)
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "([Ljava/lang/Class;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod, classes.ref().get()));
}

String URLConnection::getContentEncoding()
{
    static jmethodID getContentEncodingMethod = this->vm->GetMethodID(this->cls.get(), "getContentEncoding", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentEncodingMethod));
}

std::int32_t URLConnection::getContentLength()
{
    static jmethodID getContentLengthMethod = this->vm->GetMethodID(this->cls.get(), "getContentLength", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getContentLengthMethod);
}

std::int64_t URLConnection::getContentLengthLong()
{
    static jmethodID getContentLengthLongMethod = this->vm->GetMethodID(this->cls.get(), "getContentLengthLong", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getContentLengthLongMethod);
}

String URLConnection::getContentType()
{
    static jmethodID getContentTypeMethod = this->vm->GetMethodID(this->cls.get(), "getContentType", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentTypeMethod));
}

std::int64_t URLConnection::getDate()
{
    static jmethodID getDateMethod = this->vm->GetMethodID(this->cls.get(), "getDate", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getDateMethod);
}

bool URLConnection::getDefaultAllowUserInteraction(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID getDefaultAllowUserInteractionMethod = vm->GetStaticMethodID(cls.get(), "getDefaultAllowUserInteraction", "()Z");
    return vm->CallStaticBooleanMethod(cls.get(), getDefaultAllowUserInteractionMethod);
}

String URLConnection::getDefaultRequestProperty(JVM* vm, String key)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID getDefaultRequestPropertyMethod = vm->GetStaticMethodID(cls.get(), "getDefaultRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), getDefaultRequestPropertyMethod, key.ref().get()));
}

bool URLConnection::getDefaultUseCaches()
{
    static jmethodID getDefaultUseCachesMethod = this->vm->GetMethodID(this->cls.get(), "getDefaultUseCaches", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), getDefaultUseCachesMethod);
}

bool URLConnection::getDoInput()
{
    static jmethodID getDoInputMethod = this->vm->GetMethodID(this->cls.get(), "getDoInput", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), getDoInputMethod);
}

bool URLConnection::getDoOutput()
{
    static jmethodID getDoOutputMethod = this->vm->GetMethodID(this->cls.get(), "getDoOutput", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), getDoOutputMethod);
}

std::int64_t URLConnection::getExpiration()
{
    static jmethodID getExpirationMethod = this->vm->GetMethodID(this->cls.get(), "getExpiration", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getExpirationMethod);
}

FileNameMap URLConnection::getFileNameMap(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID getFileNameMapMethod = vm->GetStaticMethodID(cls.get(), "getFileNameMap", "()Ljava/net/FileNameMap;");
    return FileNameMap(vm, vm->CallStaticObjectMethod(cls.get(), getFileNameMapMethod));
}

String URLConnection::getHeaderField(String name)
{
    static jmethodID getHeaderFieldMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderField", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHeaderFieldMethod, name.ref().get()));
}

String URLConnection::getHeaderField(std::int32_t n)
{
    static jmethodID getHeaderFieldMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderField", "(I)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHeaderFieldMethod, n));
}

std::int64_t URLConnection::getHeaderFieldDate(String name, std::int64_t Default)
{
    static jmethodID getHeaderFieldDateMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderFieldDate", "(Ljava/lang/String;J)J");
    return this->vm->CallLongMethod(this->inst.get(), getHeaderFieldDateMethod, name.ref().get(), Default);
}

std::int32_t URLConnection::getHeaderFieldInt(String name, std::int32_t Default)
{
    static jmethodID getHeaderFieldIntMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderFieldInt", "(Ljava/lang/String;I)I");
    return this->vm->CallIntMethod(this->inst.get(), getHeaderFieldIntMethod, name.ref().get(), Default);
}

String URLConnection::getHeaderFieldKey(std::int32_t n)
{
    static jmethodID getHeaderFieldKeyMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderFieldKey", "(I)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHeaderFieldKeyMethod, n));
}

std::int64_t URLConnection::getHeaderFieldLong(String name, std::int64_t Default)
{
    static jmethodID getHeaderFieldLongMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderFieldLong", "(Ljava/lang/String;J)J");
    return this->vm->CallLongMethod(this->inst.get(), getHeaderFieldLongMethod, name.ref().get(), Default);
}

Map<String,List<String>> URLConnection::getHeaderFields()
{
    static jmethodID getHeaderFieldsMethod = this->vm->GetMethodID(this->cls.get(), "getHeaderFields", "()Ljava/util/Map;");
    return Map<String,List<String>>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getHeaderFieldsMethod));
}

std::int64_t URLConnection::getIfModifiedSince()
{
    static jmethodID getIfModifiedSinceMethod = this->vm->GetMethodID(this->cls.get(), "getIfModifiedSince", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getIfModifiedSinceMethod);
}

InputStream URLConnection::getInputStream()
{
    static jmethodID getInputStreamMethod = this->vm->GetMethodID(this->cls.get(), "getInputStream", "()Ljava/io/InputStream;");
    return InputStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), getInputStreamMethod));
}

std::int64_t URLConnection::getLastModified()
{
    static jmethodID getLastModifiedMethod = this->vm->GetMethodID(this->cls.get(), "getLastModified", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getLastModifiedMethod);
}

OutputStream URLConnection::getOutputStream()
{
    static jmethodID getOutputStreamMethod = this->vm->GetMethodID(this->cls.get(), "getOutputStream", "()Ljava/io/OutputStream;");
    return OutputStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), getOutputStreamMethod));
}

Permission URLConnection::getPermission()
{
    static jmethodID getPermissionMethod = this->vm->GetMethodID(this->cls.get(), "getPermission", "()Ljava/security/Permission;");
    return Permission(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPermissionMethod));
}

std::int32_t URLConnection::getReadTimeout()
{
    static jmethodID getReadTimeoutMethod = this->vm->GetMethodID(this->cls.get(), "getReadTimeout", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getReadTimeoutMethod);
}

Map<String,List<String>> URLConnection::getRequestProperties()
{
    static jmethodID getRequestPropertiesMethod = this->vm->GetMethodID(this->cls.get(), "getRequestProperties", "()Ljava/util/Map;");
    return Map<String,List<String>>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRequestPropertiesMethod));
}

String URLConnection::getRequestProperty(String key)
{
    static jmethodID getRequestPropertyMethod = this->vm->GetMethodID(this->cls.get(), "getRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getRequestPropertyMethod, key.ref().get()));
}

URL URLConnection::getURL()
{
    static jmethodID getURLMethod = this->vm->GetMethodID(this->cls.get(), "getURL", "()Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->inst.get(), getURLMethod));
}

bool URLConnection::getUseCaches()
{
    static jmethodID getUseCachesMethod = this->vm->GetMethodID(this->cls.get(), "getUseCaches", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), getUseCachesMethod);
}

String URLConnection::guessContentTypeFromName(JVM* vm, String fname)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID guessContentTypeFromNameMethod = vm->GetStaticMethodID(cls.get(), "guessContentTypeFromName", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), guessContentTypeFromNameMethod, fname.ref().get()));
}

String URLConnection::guessContentTypeFromStream(JVM* vm, InputStream is)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID guessContentTypeFromStreamMethod = vm->GetStaticMethodID(cls.get(), "guessContentTypeFromStream", "(Ljava/io/InputStream;)Ljava/lang/String;");
    return String(vm, vm->CallStaticObjectMethod(cls.get(), guessContentTypeFromStreamMethod, is.ref().get()));
}

void URLConnection::setAllowUserInteraction(bool allowuserinteraction)
{
    static jmethodID setAllowUserInteractionMethod = this->vm->GetMethodID(this->cls.get(), "setAllowUserInteraction", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setAllowUserInteractionMethod, allowuserinteraction);
}

void URLConnection::setConnectTimeout(std::int32_t timeout)
{
    static jmethodID setConnectTimeoutMethod = this->vm->GetMethodID(this->cls.get(), "setConnectTimeout", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), setConnectTimeoutMethod, timeout);
}

void URLConnection::setContentHandlerFactory(JVM* vm, ContentHandlerFactory fac)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID setContentHandlerFactoryMethod = vm->GetStaticMethodID(cls.get(), "setContentHandlerFactory", "(Ljava/net/ContentHandlerFactory;)V");
    vm->CallStaticVoidMethod(cls.get(), setContentHandlerFactoryMethod, fac.ref().get());
}

void URLConnection::setDefaultAllowUserInteraction(JVM* vm, bool defaultallowuserinteraction)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID setDefaultAllowUserInteractionMethod = vm->GetStaticMethodID(cls.get(), "setDefaultAllowUserInteraction", "(Z)V");
    vm->CallStaticVoidMethod(cls.get(), setDefaultAllowUserInteractionMethod, defaultallowuserinteraction);
}

void URLConnection::setDefaultRequestProperty(JVM* vm, String key, String value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID setDefaultRequestPropertyMethod = vm->GetStaticMethodID(cls.get(), "setDefaultRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    vm->CallStaticVoidMethod(cls.get(), setDefaultRequestPropertyMethod, key.ref().get(), value.ref().get());
}

void URLConnection::setDefaultUseCaches(bool defaultusecaches)
{
    static jmethodID setDefaultUseCachesMethod = this->vm->GetMethodID(this->cls.get(), "setDefaultUseCaches", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setDefaultUseCachesMethod, defaultusecaches);
}

void URLConnection::setDoInput(bool doinput)
{
    static jmethodID setDoInputMethod = this->vm->GetMethodID(this->cls.get(), "setDoInput", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setDoInputMethod, doinput);
}

void URLConnection::setDoOutput(bool dooutput)
{
    static jmethodID setDoOutputMethod = this->vm->GetMethodID(this->cls.get(), "setDoOutput", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setDoOutputMethod, dooutput);
}

void URLConnection::setFileNameMap(JVM* vm, FileNameMap map)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/net/URLConnection;"));
    static jmethodID setFileNameMapMethod = vm->GetStaticMethodID(cls.get(), "setFileNameMap", "(Ljava/net/FileNameMap;)V");
    vm->CallStaticVoidMethod(cls.get(), setFileNameMapMethod, map.ref().get());
}

void URLConnection::setIfModifiedSince(std::int64_t ifmodifiedsince)
{
    static jmethodID setIfModifiedSinceMethod = this->vm->GetMethodID(this->cls.get(), "setIfModifiedSince", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), setIfModifiedSinceMethod, ifmodifiedsince);
}

void URLConnection::setReadTimeout(std::int32_t timeout)
{
    static jmethodID setReadTimeoutMethod = this->vm->GetMethodID(this->cls.get(), "setReadTimeout", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), setReadTimeoutMethod, timeout);
}

void URLConnection::setRequestProperty(String key, String value)
{
    static jmethodID setRequestPropertyMethod = this->vm->GetMethodID(this->cls.get(), "setRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), setRequestPropertyMethod, key.ref().get(), value.ref().get());
}

void URLConnection::setUseCaches(bool usecaches)
{
    static jmethodID setUseCachesMethod = this->vm->GetMethodID(this->cls.get(), "setUseCaches", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setUseCachesMethod, usecaches);
}

String URLConnection::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

URLConnection::URLConnection(JVM* vm, URL url) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URLConnection;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/net/URL;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, url.ref().get()));
    }
}
