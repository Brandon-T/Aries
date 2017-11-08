//
//  Class.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Class.hxx"
#include "String.hxx"
#include "ClassLoader.hxx"
#include "Annotation.hxx"
#include "Constructor.hxx"
#include "Field.hxx"
#include "Method.hxx"
#include "Type.hxx"
#include "Package.hxx"
#include "ProtectionDomain.hxx"
#include "URL.hxx"
#include "InputStream.hxx"

using java::lang::Class;
using java::lang::String;
using java::lang::ClassLoader;
using java::lang::Package;
using java::lang::annotation::Annotation;
using java::lang::reflect::Constructor;
using java::lang::reflect::Field;
using java::lang::reflect::Method;
using java::lang::reflect::Type;
using java::lang::reflect::TypeVariable;
using java::security::ProtectionDomain;
using java::net::URL;
using java::io::InputStream;

Class::Class() : Object()
{
}

Class::Class(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Class;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Class Class::asSubclass(Class clazz)
{
    jmethodID asSubClassMethod = this->vm->GetMethodID(this->cls.get(), "asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), asSubClassMethod));
}

Object Class::cast(Object obj)
{
    jmethodID castMethod = this->vm->GetMethodID(this->cls.get(), "cast", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), castMethod, obj.ref().get()));
}

bool Class::desiredAssertionStatus()
{
    jmethodID desiredAssertionStatusMethod = this->vm->GetMethodID(this->cls.get(), "desiredAssertionStatus", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), desiredAssertionStatusMethod);
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
    jmethodID getAnnotationMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;");
    return Annotation(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAnnotationMethod, annotationClass.ref().get()));
}

Array<Annotation> Class::getAnnotations()
{
    jmethodID getAnnotationsMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotations", "()Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getAnnotationsMethod));
    return Array<Annotation>(this->vm, annotations);
}

String Class::getCanonicalName()
{
    jmethodID getCanonicalNameMethod = this->vm->GetMethodID(this->cls.get(), "getCanonicalName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getCanonicalNameMethod));
}

Array<Class> Class::getClasses()
{
    jmethodID getClassesMethod = this->vm->GetMethodID(this->cls.get(), "getClasses", "()Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getClassesMethod));
    return Array<Class>(this->vm, classes);
}

ClassLoader Class::getClassLoader()
{
    jmethodID getClassLoaderMethod = this->vm->GetMethodID(this->cls.get(), "getClassLoader", "()Ljava/lang/ClassLoader;");
    return ClassLoader(this->vm, this->vm->CallObjectMethod(this->inst.get(), getClassLoaderMethod));
}

Class Class::getComponentType()
{
    jmethodID getComponentTypeMethod = this->vm->GetMethodID(this->cls.get(), "getComponentType", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getComponentTypeMethod));
}

Constructor Class::getConstructor(Array<Class> parameterTypes)
{
    jmethodID getConstructorMethod = this->vm->GetMethodID(this->cls.get(), "getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst.get(), getConstructorMethod, parameterTypes.ref().get()));
}

Array<Constructor> Class::getConstructors()
{
    jmethodID getConstructorsMethod = this->vm->GetMethodID(this->cls.get(), "getConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getConstructorsMethod));
    return Array<Constructor>(this->vm, constructors);
}

Array<Annotation> Class::getDeclaredAnnotations()
{
    jmethodID getDeclaredAnnotationsMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getDeclaredAnnotationsMethod));
    return Array<Annotation>(this->vm, annotations);
}

Array<Class> Class::getDeclaredClasses()
{
    jmethodID getDeclaredClassesMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredClasses", "()[Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getDeclaredClassesMethod));
    return Array<Class>(this->vm, classes);
}

Constructor Class::getDeclaredConstructor(Array<Class> parameterTypes)
{
    jmethodID getDeclaredConstructorMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredConstructorMethod, parameterTypes.ref().get()));
}

Array<Constructor> Class::getDeclaredConstructors()
{
    jmethodID getDeclaredConstructorsMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getDeclaredConstructorsMethod));
    return Array<Constructor>(this->vm, constructors);
}

Field Class::getDeclaredField(String name)
{
    jmethodID getDeclaredFieldMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredFieldMethod, name.ref().get()));
}

Array<Field> Class::getDeclaredFields()
{
    jmethodID getDeclaredFieldsMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getDeclaredFieldsMethod));
    return Array<Field>(this->vm, fields);
}

Method Class::getDeclaredMethod(String name, Array<Class> parameterTypes)
{
    jmethodID getDeclaredMethodMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaredMethodMethod, parameterTypes.ref().get()));
}

Array<Method> Class::getDeclaredMethods()
{
    jmethodID getDeclaredMethodsMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaredMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getDeclaredMethodsMethod));
    return Array<Method>(this->vm, methods);
}

Class Class::getDeclaringClass()
{
    jmethodID getDeclaringClassMethod = this->vm->GetMethodID(this->cls.get(), "getDeclaringClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getDeclaringClassMethod));
}

Class Class::getEnclosingClass()
{
    jmethodID getEnclosingClassMethod = this->vm->GetMethodID(this->cls.get(), "getEnclosingClass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getEnclosingClassMethod));
}

Constructor Class::getEnclosingConstructor()
{
    jmethodID getEnclosingConstructorMethod = this->vm->GetMethodID(this->cls.get(), "getEnclosingConstructor", "()Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst.get(), getEnclosingConstructorMethod));
}

Method Class::getEnclosingMethod()
{
    jmethodID getEnclosingMethodMethod = this->vm->GetMethodID(this->cls.get(), "getEnclosingMethod", "()Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst.get(), getEnclosingMethodMethod));
}

Array<Class> Class::getEnumConstants()
{
    jmethodID getEnumConstantsMethod = this->vm->GetMethodID(this->cls.get(), "getEnumConstants", "()[Ljava/lang/Object;");
    jobjectArray constants = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getEnumConstantsMethod));
    return Array<Class>(this->vm, constants);
}

Field Class::getField(String name)
{
    jmethodID getFieldMethod = this->vm->GetMethodID(this->cls.get(), "getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst.get(), getFieldMethod, name.ref().get()));
}

Array<Field> Class::getFields()
{
    jmethodID getFieldsMethod = this->vm->GetMethodID(this->cls.get(), "getFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getFieldsMethod));
    return Array<Field>(this->vm, fields);
}

Array<Type> Class::getGenericInterfaces()
{
    jmethodID getGenericInterfacesMethod = this->vm->GetMethodID(this->cls.get(), "getGenericInterfaces", "()[Ljava/lang/reflect/Type;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getGenericInterfacesMethod));
    return Array<Type>(this->vm, interfaces);
}

Type Class::getGenericSuperclass()
{
    jmethodID getGenericSuperclassMethod = this->vm->GetMethodID(this->cls.get(), "getGenericSuperclass", "()Ljava/lang/reflect/Type;");
    return Type(this->vm, this->vm->CallObjectMethod(this->inst.get(), getGenericSuperclassMethod));
}

Array<Class> Class::getInterfaces()
{
    jmethodID getInterfacesMethod = this->vm->GetMethodID(this->cls.get(), "getInterfaces", "()[Ljava/lang/reflect/Class;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getInterfacesMethod));
    return Array<Class>(this->vm, interfaces);
}

Method Class::getMethod(String name, Array<Class> parameterTypes)
{
    jmethodID getMethodMethod = this->vm->GetMethodID(this->cls.get(), "getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethodMethod, name.ref().get(), parameterTypes.ref().get()));
}

Array<Method> Class::getMethods()
{
    jmethodID getMethodsMethod = this->vm->GetMethodID(this->cls.get(), "getMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getMethodsMethod));
    return Array<Method>(this->vm, methods);
}

int Class::getModifiers()
{
    jmethodID getModifiersMethod = this->vm->GetMethodID(this->cls.get(), "getModifiers", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getModifiersMethod);
}

String Class::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

Package Class::getPackage()
{
    jmethodID getPackageMethod = this->vm->GetMethodID(this->cls.get(), "getPackage", "()Ljava/lang/Package;");
    return Package(this->vm, this->vm->CallObjectMethod(this->cls.get(), getPackageMethod));
}

ProtectionDomain Class::getProtectionDomain()
{
    jmethodID getProtectionDomainMethod = this->vm->GetMethodID(this->cls.get(), "getProtectionDomain", "()Ljava/security/ProtectionDomain;");
    return ProtectionDomain(this->vm, this->vm->CallObjectMethod(this->cls.get(), getProtectionDomainMethod));
}

URL Class::getResource(String name)
{
    jmethodID getResourceMethod = this->vm->GetMethodID(this->cls.get(), "getResource", "(Ljava/lang/String;)Ljava/net/URL;");
    return URL(this->vm, this->vm->CallObjectMethod(this->cls.get(), getResourceMethod, name.ref().get()));
}

InputStream Class::getResourceAsStream(String name)
{
    jmethodID getResourceAsStreamMethod = this->vm->GetMethodID(this->cls.get(), "getResourceAsStreamMethod", "(Ljava/lang/String;)Ljava/io/InputStream;");
    return InputStream(this->vm, this->vm->CallObjectMethod(this->cls.get(), getResourceAsStreamMethod, name.ref().get()));
}

Array<Object> Class::getSigners()
{
    jmethodID getSignersMethod = this->vm->GetMethodID(this->cls.get(), "getSigners", "()[Ljava/lang/Object;");
    jobjectArray signers = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst.get(), getSignersMethod));
    return Array<Object>(this->vm, signers);
}

String Class::getSimpleName()
{
    jmethodID getSimpleNameMethod = this->vm->GetMethodID(this->cls.get(), "getSimpleName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSimpleNameMethod));
}

Class Class::getSuperclass()
{
    jmethodID getSuperclassMethod = this->vm->GetMethodID(this->cls.get(), "getSuperclass", "()Ljava/lang/Class;");
    return Class(this->vm, this->vm->CallObjectMethod(this->inst.get(), getSuperclassMethod));
}

Array<TypeVariable> Class::getTypeParameters()
{
    jmethodID getTypeParametersMethod = this->vm->GetMethodID(this->cls.get(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return Array<TypeVariable>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getTypeParametersMethod));
}

bool Class::isAnnotationPresent(Class annotationClass)
{
    jmethodID isAnnotationPresentMethod = this->vm->GetMethodID(this->cls.get(), "isAnnotationPresent", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAnnotationPresentMethod, annotationClass.ref().get());
}

bool Class::isAnnotation()
{
    jmethodID isAnnotationMethod = this->vm->GetMethodID(this->cls.get(), "isAnnotation", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAnnotationMethod);
}

bool Class::isAnonymousClass()
{
    jmethodID isAnonymousClassMethod = this->vm->GetMethodID(this->cls.get(), "isAnonymousClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAnonymousClassMethod);
}

bool Class::isArray()
{
    jmethodID isArrayMethod = this->vm->GetMethodID(this->cls.get(), "isArray", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isArrayMethod);
}

bool Class::isAssignableFrom(Class cls)
{
    jmethodID isAssignableFromMethod = this->vm->GetMethodID(this->cls.get(), "isAssignableFrom", "(Ljava/lang/Class;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAssignableFromMethod, cls.ref().get());
}

bool Class::isEnum()
{
    jmethodID isEnumMethod = this->vm->GetMethodID(this->cls.get(), "isEnum", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isEnumMethod);
}

bool Class::isInstance(Object obj)
{
    jmethodID isInstanceMethod = this->vm->GetMethodID(this->cls.get(), "isInstance", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isInstanceMethod, obj.ref().get());
}

bool Class::isInterface()
{
    jmethodID isInterfaceMethod = this->vm->GetMethodID(this->cls.get(), "isInterface", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isInterfaceMethod);
}

bool Class::isLocalClass()
{
    jmethodID isLocalClassMethod = this->vm->GetMethodID(this->cls.get(), "isLocalClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLocalClassMethod);
}

bool Class::isMemberClass()
{
    jmethodID isMemberClassMethod = this->vm->GetMethodID(this->cls.get(), "isMemberClass", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMemberClassMethod);
}

bool Class::isPrimitive()
{
    jmethodID isPrimitiveMethod = this->vm->GetMethodID(this->cls.get(), "isPrimitive", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isPrimitiveMethod);
}

bool Class::isSynthetic()
{
    jmethodID isSyntheticMethod = this->vm->GetMethodID(this->cls.get(), "isSynthetic", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isSyntheticMethod);
}

Object Class::newInstance()
{
    jmethodID newInstanceMethod = this->vm->GetMethodID(this->cls.get(), "newInstance", "()Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), newInstanceMethod));
}
