//
//  TypeVariable.cpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "TypeVariable.hpp"
#include "GenericDeclaration.hpp"
#include "AnnotatedType.hpp"
#include "String.hpp"

using namespace java::lang;
using namespace java::lang::reflect;

TypeVariable::TypeVariable(JVM* jvm) : Object()
{
    
}

TypeVariable::TypeVariable(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/TypeVariable;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

TypeVariable::~TypeVariable()
{
    
}

Array<Type> TypeVariable::getBounds()
{
    jmethodID getBoundsMethod = this->vm->GetMethodID(this->cls, "getBounds", "()[Ljava/lang/reflect/Type;");
    return Array<Type>(this->vm, this->vm->CallObjectMethod(this->inst, getBoundsMethod));
}

GenericDeclaration TypeVariable::getGenericDeclaration()
{
    jmethodID getGenericDeclarationMethod = this->vm->GetMethodID(this->cls, "getGenericDeclaration", "()Ljava/lang/reflect/GenericDeclaration;");
    return GenericDeclaration(this->vm, this->vm->CallObjectMethod(this->inst, getGenericDeclarationMethod));
}

String TypeVariable::getName()
{
    jmethodID getNameMethod = this->vm->GetMethodID(this->cls, "getName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst, getNameMethod));
}

Array<AnnotatedType> TypeVariable::getAnnotatedBounds()
{
    jmethodID getAnnotatedBoundsMethod = this->vm->GetMethodID(this->cls, "getAnnotatedBounds", "()[Ljava/lang/reflect/AnnotatedType;");
    return Array<AnnotatedType>(this->vm, this->vm->CallObjectMethod(this->inst, getAnnotatedBoundsMethod));
}
