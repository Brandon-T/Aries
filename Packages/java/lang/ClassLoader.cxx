//
//  ClassLoader.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ClassLoader.hxx"
#include "InputStream.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "Package.hxx"
#include "String.hxx"
#include "URL.hxx"
#include "ByteBuffer.hxx"
#include "ProtectionDomain.hxx"
#include "Enumeration.hxx"

using java::lang::ClassLoader;
using java::io::InputStream;
using java::lang::Class;
using java::lang::Object;
using java::lang::Package;
using java::lang::String;
using java::net::URL;
using java::nio::ByteBuffer;
using java::security::ProtectionDomain;
using java::util::Enumeration;

ClassLoader::ClassLoader(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/ClassLoader;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ClassLoader::ClassLoader(const ClassLoader& parent) : Object()
{
    this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/ClassLoader;"));
    jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/ClassLoader;)V");
    this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, parent.ref().get()));
}

ClassLoader::ClassLoader() : Object()
{
    this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/ClassLoader;"));
    jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
    this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
}

void ClassLoader::clearAssertionStatus()
{
    static jmethodID clearAssertionStatusMethod = this->vm->GetMethodID(this->cls.get(), "clearAssertionStatus", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearAssertionStatusMethod);
}

ClassLoader ClassLoader::getParent()
{
    static jmethodID getParentMethod = this->vm->GetMethodID(this->cls.get(), "getParent", "()Ljava/lang/ClassLoader;");
    return ClassLoader(this->vm, this->vm->CallObjectMethod(this->inst.get(), getParentMethod));
}

URL ClassLoader::getResource(String name)
{
    static jmethodID getResourceMethod = this->vm->GetMethodID(this->cls.get(), "getResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->inst.get(), getResourceMethod, name.ref().get()));
}

InputStream ClassLoader::getResourceAsStream(String name)
{
    static jmethodID getResourceAsStreamMethod = this->vm->GetMethodID(this->cls.get(), "getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return InputStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), getResourceAsStreamMethod, name.ref().get()));
}

Enumeration<URL> ClassLoader::getResources(String name)
{
    static jmethodID getResourcesMethod = this->vm->GetMethodID(this->cls.get(), "getResources", "(Ljava/lang/String;)Ljava/util/Enumeration<java/net/URL>;");
    return Enumeration<URL>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getResourcesMethod, name.ref().get()));
}

ClassLoader ClassLoader::getSystemClassLoader(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/ClassLoader;"));
    static jmethodID getSystemClassLoaderMethod = vm->GetStaticMethodID(cls.get(), "getSystemClassLoader", "()Ljava/lang/ClassLoader;");
    return ClassLoader(vm, vm->CallStaticObjectMethod(cls.get(), getSystemClassLoaderMethod));
}

URL ClassLoader::getSystemResource(JVM* vm, String name)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/ClassLoader;"));
    static jmethodID getSystemResourceMethod = vm->GetStaticMethodID(cls.get(), "getSystemResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return URL(vm, vm->CallStaticObjectMethod(cls.get(), getSystemResourceMethod, name.ref().get()));
}

InputStream ClassLoader::getSystemResourceAsStream(JVM* vm, String name)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/ClassLoader;"));
    static jmethodID getSystemResourceAsStreamMethod = vm->GetStaticMethodID(cls.get(), "getSystemResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return InputStream(vm, vm->CallStaticObjectMethod(cls.get(), getSystemResourceAsStreamMethod, name.ref().get()));
}

Enumeration<URL> ClassLoader::getSystemResources(JVM* vm, String name)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/ClassLoader;"));
    static jmethodID getSystemResourcesMethod = vm->GetStaticMethodID(cls.get(), "getSystemResources", "(Ljava/lang/String;)Ljava/util/Enumeration;");
    return Enumeration<URL>(vm, vm->CallStaticObjectMethod(cls.get(), getSystemResourcesMethod, name.ref().get()));
}

Class ClassLoader::loadClass(String name)
{
    static jmethodID loadClassMethod = this->vm->GetMethodID(this->cls.get(), "loadClass", "(Ljava/lang/String;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), loadClassMethod, name.ref().get()));
}

void ClassLoader::setClassAssertionStatus(String className, bool enabled)
{
    static jmethodID setClassAssertionStatusMethod = this->vm->GetMethodID(this->cls.get(), "setClassAssertionStatus", "(Ljava/lang/String;Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setClassAssertionStatusMethod, className.ref().get(), enabled);
}

void ClassLoader::setDefaultAssertionStatus(bool enabled)
{
    static jmethodID setDefaultAssertionStatusMethod = this->vm->GetMethodID(this->cls.get(), "setDefaultAssertionStatus", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setDefaultAssertionStatusMethod, enabled);
}

void ClassLoader::setPackageAssertionStatus(String packageName, bool enabled)
{
    static jmethodID setPackageAssertionStatusMethod = this->vm->GetMethodID(this->cls.get(), "setPackageAssertionStatus", "(Ljava/lang/String;Z)V");
    this->vm->CallVoidMethod(this->inst.get(), setPackageAssertionStatusMethod, packageName.ref().get(), enabled);
}

Class ClassLoader::defineClass(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID defineClassMethod = this->vm->GetMethodID(this->cls.get(), "defineClass", "([BII)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), defineClassMethod, b.ref().get(), off, len));
}

Class ClassLoader::defineClass(String name, Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID defineClassMethod = this->vm->GetMethodID(this->cls.get(), "defineClass", "(Ljava/lang/String;[BII)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), defineClassMethod, name.ref().get(), b.ref().get(), off, len));
}

Class ClassLoader::defineClass(String name, Array<std::uint8_t>& b, std::int32_t off, std::int32_t len, ProtectionDomain protectionDomain)
{
    static jmethodID defineClassMethod = this->vm->GetMethodID(this->cls.get(), "defineClass", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), defineClassMethod, name.ref().get(), b.ref().get(), off, len, protectionDomain.ref().get()));
}

Class ClassLoader::defineClass(String name, ByteBuffer b, ProtectionDomain protectionDomain)
{
    static jmethodID defineClassMethod = this->vm->GetMethodID(this->cls.get(), "defineClass", "(Ljava/lang/String;Ljava/nio/ByteBuffer;Ljava/security/ProtectionDomain;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), defineClassMethod, name.ref().get(), b.ref().get(), protectionDomain.ref().get()));
}

Package ClassLoader::definePackage(String name, String specTitle, String specVersion, String specVendor, String implTitle, String implVersion, String implVendor, URL sealBase)
{
    static jmethodID definePackageMethod = this->vm->GetMethodID(this->cls.get(), "definePackage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;)Ljava/lang/Package;");
    return Package(this->vm, this->vm->CallObjectMethod(this->inst.get(), definePackageMethod, name.ref().get(), specTitle.ref().get(), specVersion.ref().get(), specVendor.ref().get(), implTitle.ref().get(), implVersion.ref().get(), implVendor.ref().get(), sealBase.ref().get()));
}

Class ClassLoader::findClass(String name)
{
    static jmethodID findClassMethod = this->vm->GetMethodID(this->cls.get(), "findClass", "(Ljava/lang/String;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), findClassMethod, name.ref().get()));
}

String ClassLoader::findLibrary(String libname)
{
    static jmethodID findLibraryMethod = this->vm->GetMethodID(this->cls.get(), "findLibrary", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), findLibraryMethod, libname.ref().get()));
}

Class ClassLoader::findLoadedClass(String name)
{
    static jmethodID findLoadedClassMethod = this->vm->GetMethodID(this->cls.get(), "findLoadedClass", "(Ljava/lang/String;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), findLoadedClassMethod, name.ref().get()));
}

URL ClassLoader::findResource(String name)
{
    static jmethodID findResourceMethod = this->vm->GetMethodID(this->cls.get(), "findResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->inst.get(), findResourceMethod, name.ref().get()));
}

Enumeration<URL> ClassLoader::findResources(String name)
{
    static jmethodID findResourcesMethod = this->vm->GetMethodID(this->cls.get(), "findResources", "(Ljava/lang/String;)Ljava/util/Enumeration<java/net/URL>;");
    return Enumeration<URL>(this->vm, this->vm->CallObjectMethod(this->inst.get(), findResourcesMethod, name.ref().get()));
}

Class ClassLoader::findSystemClass(String name)
{
    static jmethodID findSystemClassMethod = this->vm->GetMethodID(this->cls.get(), "findSystemClass", "(Ljava/lang/String;)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), findSystemClassMethod, name.ref().get()));
}

Object ClassLoader::getClassLoadingLock(String className)
{
    static jmethodID getClassLoadingLockMethod = this->vm->GetMethodID(this->cls.get(), "getClassLoadingLock", "(Ljava/lang/String;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getClassLoadingLockMethod, className.ref().get()));
}

Package ClassLoader::getPackage(String name)
{
    static jmethodID getPackageMethod = this->vm->GetMethodID(this->cls.get(), "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
    return Package(this->vm, this->vm->CallObjectMethod(this->inst.get(), getPackageMethod, name.ref().get()));
}

Array<Package> ClassLoader::getPackages()
{
    static jmethodID getPackagesMethod = this->vm->GetMethodID(this->cls.get(), "getPackages", "()[Ljava/lang/Package;");
    static jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), getPackagesMethod));
    return Array<Package>(this->vm, arr);
}

Class ClassLoader::loadClass(String name, bool resolve)
{
    static jmethodID loadClassMethod = this->vm->GetMethodID(this->cls.get(), "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class<?>;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), loadClassMethod, name.ref().get(), resolve));
}

bool ClassLoader::registerAsParallelCapable(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/lang/ClassLoader;"));
    static jmethodID registerAsParallelCapableMethod = vm->GetStaticMethodID(cls.get(), "registerAsParallelCapable", "()Z");
    return vm->CallStaticBooleanMethod(cls.get(), registerAsParallelCapableMethod);
}

void ClassLoader::resolveClass(Class c)
{
    static jmethodID resolveClassMethod = this->vm->GetMethodID(this->cls.get(), "resolveClass", "(Ljava/lang/Class<?>;)V");
    this->vm->CallVoidMethod(this->inst.get(), resolveClassMethod, c.ref().get());
}

void ClassLoader::setSigners(Class c, Array<Object>& signers)
{
    static jmethodID setSignersMethod = this->vm->GetMethodID(this->cls.get(), "setSigners", "(Ljava/lang/Class<?>;[Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), setSignersMethod, c.ref().get(), signers.ref().get());
}
