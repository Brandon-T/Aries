//
//  GenericDeclaration.cpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "GenericDeclaration.hpp"
#include "TypeVariable.hpp"
#include "AnnotatedElement.hpp"

using namespace java::lang::reflect;

GenericDeclaration::GenericDeclaration(JVM* jvm) : AnnotatedElement()
{
    
}

GenericDeclaration::GenericDeclaration(JVM* jvm, jobject instance) : AnnotatedElement()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/GenericDeclaration;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

GenericDeclaration::~GenericDeclaration()
{
    
}

Array<TypeVariable> GenericDeclaration::getTypeParameters()
{
    jmethodID getTypeParametersMethod = this->vm->GetMethodID(this->cls, "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return Array<TypeVariable>(this->vm, this->vm->CallObjectMethod(this->inst, getTypeParametersMethod));
}
