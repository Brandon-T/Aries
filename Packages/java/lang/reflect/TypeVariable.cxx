//
//  TypeVariable.cxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "TypeVariable.hxx"
#include "GenericDeclaration.hxx"
#include "AnnotatedType.hxx"
#include "String.hxx"

using java::lang::String;
using java::lang::reflect::Type;
using java::lang::reflect::TypeVariable;
using java::lang::reflect::AnnotatedType;
using java::lang::reflect::GenericDeclaration;

TypeVariable::TypeVariable(JVM* jvm) : Object()
{
    
}

TypeVariable::TypeVariable(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/TypeVariable;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Array<Type> TypeVariable::getBounds()
{
    jmethodID getBoundsMethod = this->vm->GetMethodID(this->cls.get(), "getBounds", "()[Ljava/lang/reflect/Type;");
    return Array<Type>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getBoundsMethod));
}

GenericDeclaration TypeVariable::getGenericDeclaration()
{
    jmethodID getGenericDeclarationMethod = this->vm->GetMethodID(this->cls.get(), "getGenericDeclaration", "()Ljava/lang/reflect/GenericDeclaration;");
    return GenericDeclaration(this->vm, this->vm->CallObjectMethod(this->inst.get(), getGenericDeclarationMethod));
}

String TypeVariable::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls.get(), "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getNameMethod));
}

Array<AnnotatedType> TypeVariable::getAnnotatedBounds()
{
    jmethodID getAnnotatedBoundsMethod = this->vm->GetMethodID(this->cls.get(), "getAnnotatedBounds", "()[Ljava/lang/reflect/AnnotatedType;");
    return Array<AnnotatedType>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getAnnotatedBoundsMethod));
}
