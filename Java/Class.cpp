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

using namespace java::lang;
using namespace java::lang::annotation;
using namespace java::lang::reflect;

Class::Class() : Object()
{
}

Class::Class(JVM* jvm, jobject instance) : Object()
{
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Class;")));
    this->inst = this->vm->NewGlobalRef(instance);
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

std::vector<Annotation> Class::getAnnotations()
{
    jmethodID getAnnotationsMethod = this->vm->GetMethodID(this->cls, "getAnnotations", "()Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getAnnotationsMethod));
    return JVMObjectArrayToVector<Annotation>(this->vm, annotations);
}

String Class::getCanonicalName()
{
    jmethodID getCanonicalNameMethod = this->vm->GetMethodID(this->cls, "getCanonicalName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getCanonicalNameMethod));
}

std::vector<Class> Class::getClasses()
{
    jmethodID getClassesMethod = this->vm->GetMethodID(this->cls, "getClasses", "()Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getClassesMethod));
    return JVMObjectArrayToVector<Class>(this->vm, classes);
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

Constructor Class::getConstructor(std::vector<Class> parameterTypes)
{
    auto parameters = VectorToJVMObjectArray(this->vm, this->cls, parameterTypes);
    jmethodID getConstructorMethod = this->vm->GetMethodID(this->cls, "getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst, getConstructorMethod, parameters.get()));
}

std::vector<Constructor> Class::getConstructors()
{
    jmethodID getConstructorsMethod = this->vm->GetMethodID(this->cls, "getConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getConstructorsMethod));
    return JVMObjectArrayToVector<Constructor>(this->vm, constructors);
}

std::vector<Annotation> Class::getDeclaredAnnotations()
{
    jmethodID getDeclaredAnnotationsMethod = this->vm->GetMethodID(this->cls, "getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;");
    jobjectArray annotations = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredAnnotationsMethod));
    return JVMObjectArrayToVector<Annotation>(this->vm, annotations);
}

std::vector<Class> Class::getDeclaredClasses()
{
    jmethodID getDeclaredClassesMethod = this->vm->GetMethodID(this->cls, "getDeclaredClasses", "()[Ljava/lang/Class;");
    jobjectArray classes = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredClassesMethod));
    return JVMObjectArrayToVector<Class>(this->vm, classes);
}

Constructor Class::getDeclaredConstructor(std::vector<Class> parameterTypes)
{
    auto parameters = VectorToJVMObjectArray(this->vm, this->cls, parameterTypes);
    jmethodID getDeclaredConstructorMethod = this->vm->GetMethodID(this->cls, "getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;");
    return Constructor(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredConstructorMethod));
}

std::vector<Constructor> Class::getDeclaredConstructors()
{
    jmethodID getDeclaredConstructorsMethod = this->vm->GetMethodID(this->cls, "getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;");
    jobjectArray constructors = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredConstructorsMethod));
    return JVMObjectArrayToVector<Constructor>(this->vm, constructors);
}

Field Class::getDeclaredField(String name)
{
    jmethodID getDeclaredFieldMethod = this->vm->GetMethodID(this->cls, "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredFieldMethod, name.ref().get()));
}

std::vector<Field> Class::getDeclaredFields()
{
    jmethodID getDeclaredFieldsMethod = this->vm->GetMethodID(this->cls, "getDeclaredFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredFieldsMethod));
    return JVMObjectArrayToVector<Field>(this->vm, fields);
}

Method Class::getDeclaredMethod(String name, std::vector<Class> parameterTypes)
{
    auto parameters = VectorToJVMObjectArray(this->vm, this->cls, parameterTypes);
    jmethodID getDeclaredMethodMethod = this->vm->GetMethodID(this->cls, "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst, getDeclaredMethodMethod, parameters.get()));
}

std::vector<Method> Class::getDeclaredMethods()
{
    jmethodID getDeclaredMethodsMethod = this->vm->GetMethodID(this->cls, "getDeclaredMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getDeclaredMethodsMethod));
    return JVMObjectArrayToVector<Method>(this->vm, methods);
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

std::vector<Class> Class::getEnumConstants()
{
    jmethodID getEnumConstantsMethod = this->vm->GetMethodID(this->cls, "getEnumConstants", "()[Ljava/lang/Object;");
    jobjectArray constants = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getEnumConstantsMethod));
    return JVMObjectArrayToVector<Class>(this->vm, constants);
}

Field Class::getField(String name)
{
    jmethodID getFieldMethod = this->vm->GetMethodID(this->cls, "getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    return Field(this->vm, this->vm->CallObjectMethod(this->inst, getFieldMethod, name.ref().get()));
}

std::vector<Field> Class::getFields()
{
    jmethodID getFieldsMethod = this->vm->GetMethodID(this->cls, "getFields", "()[Ljava/lang/reflect/Field;");
    jobjectArray fields = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getFieldsMethod));
    return JVMObjectArrayToVector<Field>(this->vm, fields);
}

std::vector<Type> Class::getGenericInterfaces()
{
    jmethodID getGenericInterfacesMethod = this->vm->GetMethodID(this->cls, "getGenericInterfaces", "()[Ljava/lang/reflect/Type;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getGenericInterfacesMethod));
    return JVMObjectArrayToVector<Type>(this->vm, interfaces);
}

Type Class::getGenericSuperclass()
{
    jmethodID getGenericSuperclassMethod = this->vm->GetMethodID(this->cls, "getGenericSuperclass", "()Ljava/lang/reflect/Type;");
    return Type(this->vm, this->vm->CallObjectMethod(this->inst, getGenericSuperclassMethod));
}

std::vector<Class> Class::getInterfaces()
{
    jmethodID getInterfacesMethod = this->vm->GetMethodID(this->cls, "getInterfaces", "()[Ljava/lang/reflect/Class;");
    jobjectArray interfaces = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getInterfacesMethod));
    return JVMObjectArrayToVector<Class>(this->vm, interfaces);
}

Method Class::getMethod(String name, std::vector<Class> parameterTypes)
{
    jmethodID getMethodMethod = this->vm->GetMethodID(this->cls, "getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    return Method(this->vm, this->vm->CallObjectMethod(this->inst, getMethodMethod));
}

std::vector<Method> Class::getMethods()
{
    jmethodID getMethodsMethod = this->vm->GetMethodID(this->cls, "getMethods", "()[Ljava/lang/reflect/Method;");
    jobjectArray methods = static_cast<jobjectArray>(this->vm->CallObjectMethod(this->inst, getMethodsMethod));
    return JVMObjectArrayToVector<Method>(this->vm, methods);
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
