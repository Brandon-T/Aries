//
//  Class.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Class.hpp"
#include "String.hpp"
#include "ClassLoader.hpp"
#include "Annotation.hpp"
#include "Constructor.hpp"
#include "Field.hpp"
#include "Method.hpp"
#include "Type.hpp"
#include "Package.hpp"
#include "ProtectionDomain.hpp"
#include "URL.hpp"
#include "InputStream.hpp"

using namespace java::lang;
using namespace java::lang::annotation;
using namespace java::lang::reflect;
using namespace java::security;
using namespace java::net;
using namespace java::io;

Class::Class() : Object()
{
}

Class::Class(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Class;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Class::~Class()
{
    
}

Class Class::asSubclass(Class clazz)
{
    jmethodID asSubClassMethod = this->vm->GetMethodID(this->cls, "asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, asSubClassMethod));
}

Object Class::cast(Object obj)
{
    jmethodID castMethod = this->vm->GetMethodID(this->cls, "cast", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst, castMethod, obj.ref().get()));
}

bool Class::desiredAssertionStatus()
{
    jmethodID desiredAssertionStatusMethod = this->vm->GetMethodID(this->cls, "desiredAssertionStatus", "()Z");
    return this->vm->CallBooleanMethod(this->inst, desiredAssertionStatusMethod);
}

Class Class::forName(JVM* jvm, String className)
{
    jclass cls = jvm->FindClass("Ljava/lang/Class;");
    jmethodID forNameMethod = jvm->GetStaticMethodID(cls, "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
    return Class(jvm, jvm->CallStaticObjectMethod(cls, forNameMethod));
}

Class Class::forName(JVM* jvm, String name, bool initialize, ClassLoader loader)
{
    jclass cls = jvm->FindClass("Ljava/lang/Class;");
    jmethodID forNameMethod = jvm->GetStaticMethodID(cls, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");
    return Class(jvm, jvm->CallStaticObjectMethod(cls, forNameMethod, initialize, loader.ref().get()));
}

Annotation Class::getAnnotation(Class annotationClass)
{
    jmethodID getAnnotationMethod = this->vm->GetMethodID(this->cls, "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst, getAnnotationMethod, annotationClass.ref().get()));
}

Array<Annotation> Class::getAnnotations()
{
    jmethodID getAnnotationsMethod = this->vm->GetMethodID(this->cls, "getAnnotations", "()Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getAnnotationsMethod));
    return Array<Annotation>(this->vm, annotations);
}

String Class::getCanonicalName()
{
    jmethodID getCanonicalNameMethod = this->vm->GetMethodID(this->cls, "getCanonicalName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getCanonicalNameMethod));
}

Array<Class> Class::getClasses()
{
    jmethodID getClassesMethod = this->vm->GetMethodID(this->cls, "getClasses", "()Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getClassesMethod));
    return Array<Class>(this->vm, classes);
}

ClassLoader Class::getClassLoader()
{
    jmethodID getClassLoaderMethod = this->vm->GetMethodID(this->cls, "getClassLoader", "()Ljava/lang/ClassLoader;");
    return ClassLoader(this->vm, this->vm->CallObjectMethod(this->inst, getClassLoaderMethod));
}

Class Class::getComponentType()
{
    jmethodID getComponentTypeMethod = this->vm->GetMethodID(this->cls, "getComponentType", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, getComponentTypeMethod));
}

Constructor Class::getConstructor(Array<Class> parameterTypes)
{
    jmethodID getConstructorMethod = this->vm->GetMethodID(this->cls, "getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst, getConstructorMethod, parameterTypes.ref().get()));
}

Array<Constructor> Class::getConstructors()
{
    jmethodID getConstructorsMethod = this->vm->GetMethodID(this->cls, "getConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getConstructorsMethod));
    return Array<Constructor>(this->vm, constructors);
}

Array<Annotation> Class::getDeclaredAnnotations()
{
    jmethodID getDeclaredAnnotationsMethod = this->vm->GetMethodID(this->cls, "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredAnnotationsMethod));
    return Array<Annotation>(this->vm, annotations);
}

Array<Class> Class::getDeclaredClasses()
{
    jmethodID getDeclaredClassesMethod = this->vm->GetMethodID(this->cls, "getDeclaredClasses", "()[Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredClassesMethod));
    return Array<Class>(this->vm, classes);
}

Constructor Class::getDeclaredConstructor(Array<Class> parameterTypes)
{
    jmethodID getDeclaredConstructorMethod = this->vm->GetMethodID(this->cls, "getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredConstructorMethod, parameterTypes.ref().get()));
}

Array<Constructor> Class::getDeclaredConstructors()
{
    jmethodID getDeclaredConstructorsMethod = this->vm->GetMethodID(this->cls, "getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredConstructorsMethod));
    return Array<Constructor>(this->vm, constructors);
}

Field Class::getDeclaredField(String name)
{
    jmethodID getDeclaredFieldMethod = this->vm->GetMethodID(this->cls, "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredFieldMethod, name.ref().get()));
}

Array<Field> Class::getDeclaredFields()
{
    jmethodID getDeclaredFieldsMethod = this->vm->GetMethodID(this->cls, "getDeclaredFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredFieldsMethod));
    return Array<Field>(this->vm, fields);
}

Method Class::getDeclaredMethod(String name, Array<Class> parameterTypes)
{
    jmethodID getDeclaredMethodMethod = this->vm->GetMethodID(this->cls, "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredMethodMethod, parameterTypes.ref().get()));
}

Array<Method> Class::getDeclaredMethods()
{
    jmethodID getDeclaredMethodsMethod = this->vm->GetMethodID(this->cls, "getDeclaredMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredMethodsMethod));
    return Array<Method>(this->vm, methods);
}

Class Class::getDeclaringClass()
{
    jmethodID getDeclaringClassMethod = this->vm->GetMethodID(this->cls, "getDeclaringClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaringClassMethod));
}

Class Class::getEnclosingClass()
{
    jmethodID getEnclosingClassMethod = this->vm->GetMethodID(this->cls, "getEnclosingClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, getEnclosingClassMethod));
}

Constructor Class::getEnclosingConstructor()
{
    jmethodID getEnclosingConstructorMethod = this->vm->GetMethodID(this->cls, "getEnclosingConstructor", "()Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst, getEnclosingConstructorMethod));
}

Method Class::getEnclosingMethod()
{
    jmethodID getEnclosingMethodMethod = this->vm->GetMethodID(this->cls, "getEnclosingMethod", "()Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst, getEnclosingMethodMethod));
}

Array<Class> Class::getEnumConstants()
{
    jmethodID getEnumConstantsMethod = this->vm->GetMethodID(this->cls, "getEnumConstants", "()[Ljava/lang/Object;");
    jobjectArray constants = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getEnumConstantsMethod));
    return Array<Class>(this->vm, constants);
}

Field Class::getField(String name)
{
    jmethodID getFieldMethod = this->vm->GetMethodID(this->cls, "getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst, getFieldMethod, name.ref().get()));
}

Array<Field> Class::getFields()
{
    jmethodID getFieldsMethod = this->vm->GetMethodID(this->cls, "getFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getFieldsMethod));
    return Array<Field>(this->vm, fields);
}

Array<Type> Class::getGenericInterfaces()
{
    jmethodID getGenericInterfacesMethod = this->vm->GetMethodID(this->cls, "getGenericInterfaces", "()[Ljava/lang/reflect/Type;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getGenericInterfacesMethod));
    return Array<Type>(this->vm, interfaces);
}

Type Class::getGenericSuperclass()
{
    jmethodID getGenericSuperclassMethod = this->vm->GetMethodID(this->cls, "getGenericSuperclass", "()Ljava/lang/reflect/Type;");
    return Type(this->vm, this->vm->CallObjectMethod(this->inst, getGenericSuperclassMethod));
}

Array<Class> Class::getInterfaces()
{
    jmethodID getInterfacesMethod = this->vm->GetMethodID(this->cls, "getInterfaces", "()[Ljava/lang/reflect/Class;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getInterfacesMethod));
    return Array<Class>(this->vm, interfaces);
}

Method Class::getMethod(String name, Array<Class> parameterTypes)
{
    jmethodID getMethodMethod = this->vm->GetMethodID(this->cls, "getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst, getMethodMethod, name.ref().get(), parameterTypes.ref().get()));
}

Array<Method> Class::getMethods()
{
    jmethodID getMethodsMethod = this->vm->GetMethodID(this->cls, "getMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getMethodsMethod));
    return Array<Method>(this->vm, methods);
}

int Class::getModifiers()
{
    jmethodID getModifiersMethod = this->vm->GetMethodID(this->cls, "getModifiers", "()I");
    return this->vm->CallIntMethod(this->inst, getModifiersMethod);
}

String Class::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls, "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getNameMethod));
}

Package Class::getPackage()
{
    jmethodID getPackageMethod = this->vm->GetMethodID(this->cls, "getPackage", "()Ljava/lang/Package;");
    return Package(this->vm, this->vm->CallObjectMethod(this->cls, getPackageMethod));
}

ProtectionDomain Class::getProtectionDomain()
{
    jmethodID getProtectionDomainMethod = this->vm->GetMethodID(this->cls, "getProtectionDomain", "()Ljava/security/ProtectionDomain;");
    return ProtectionDomain(this->vm, this->vm->CallObjectMethod(this->cls, getProtectionDomainMethod));
}

URL Class::getResource(String name)
{
    jmethodID getResourceMethod = this->vm->GetMethodID(this->cls, "getResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->cls, getResourceMethod, name.ref().get()));
}

InputStream Class::getResourceAsStream(String name)
{
    jmethodID getResourceAsStreamMethod = this->vm->GetMethodID(this->cls, "getResourceAsStreamMethod", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return InputStream(this->vm, this->vm->CallObjectMethod(this->cls, getResourceAsStreamMethod, name.ref().get()));
}

Array<Object> Class::getSigners()
{
    jmethodID getSignersMethod = this->vm->GetMethodID(this->cls, "getSigners", "()[Ljava/lang/Object;");
    jobjectArray signers = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getSignersMethod));
    return Array<Object>(this->vm, signers);
}

String Class::getSimpleName()
{
    jmethodID getSimpleNameMethod = this->vm->GetMethodID(this->cls, "getSimpleName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getSimpleNameMethod));
}

Class Class::getSuperclass()
{
    jmethodID getSuperclassMethod = this->vm->GetMethodID(this->cls, "getSuperclass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst, getSuperclassMethod));
}

Array<TypeVariable> Class::getTypeParameters()
{
    jmethodID getTypeParametersMethod = this->vm->GetMethodID(this->cls, "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return Array<TypeVariable>(this->vm, this->vm->CallObjectMethod(this->inst, getTypeParametersMethod));
}

bool Class::isAnnotationPresent(Class annotationClass)
{
    jmethodID isAnnotationPresentMethod = this->vm->GetMethodID(this->cls, "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst, isAnnotationPresentMethod, annotationClass.ref().get());
}

bool Class::isAnnotation()
{
    jmethodID isAnnotationMethod = this->vm->GetMethodID(this->cls, "isAnnotation", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isAnnotationMethod);
}

bool Class::isAnonymousClass()
{
    jmethodID isAnonymousClassMethod = this->vm->GetMethodID(this->cls, "isAnonymousClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isAnonymousClassMethod);
}

bool Class::isArray()
{
    jmethodID isArrayMethod = this->vm->GetMethodID(this->cls, "isArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isArrayMethod);
}

bool Class::isAssignableFrom(Class cls)
{
    jmethodID isAssignableFromMethod = this->vm->GetMethodID(this->cls, "isAssignableFrom", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst, isAssignableFromMethod, cls.ref().get());
}

bool Class::isEnum()
{
    jmethodID isEnumMethod = this->vm->GetMethodID(this->cls, "isEnum", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isEnumMethod);
}

bool Class::isInstance(Object obj)
{
    jmethodID isInstanceMethod = this->vm->GetMethodID(this->cls, "isInstance", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst, isInstanceMethod, obj.ref().get());
}

bool Class::isInterface()
{
    jmethodID isInterfaceMethod = this->vm->GetMethodID(this->cls, "isInterface", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isInterfaceMethod);
}

bool Class::isLocalClass()
{
    jmethodID isLocalClassMethod = this->vm->GetMethodID(this->cls, "isLocalClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isLocalClassMethod);
}

bool Class::isMemberClass()
{
    jmethodID isMemberClassMethod = this->vm->GetMethodID(this->cls, "isMemberClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isMemberClassMethod);
}

bool Class::isPrimitive()
{
    jmethodID isPrimitiveMethod = this->vm->GetMethodID(this->cls, "isPrimitive", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isPrimitiveMethod);
}

bool Class::isSynthetic()
{
    jmethodID isSyntheticMethod = this->vm->GetMethodID(this->cls, "isSynthetic", "()Z");
    return this->vm->CallBooleanMethod(this->inst, isSyntheticMethod);
}

Object Class::newInstance()
{
    jmethodID newInstanceMethod = this->vm->GetMethodID(this->cls, "newInstance", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst, newInstanceMethod));
}
