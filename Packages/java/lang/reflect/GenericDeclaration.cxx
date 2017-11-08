//
//  GenericDeclaration.cxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "GenericDeclaration.hxx"
#include "TypeVariable.hxx"
#include "AnnotatedElement.hxx"

using java::lang::reflect::TypeVariable;
using java::lang::reflect::GenericDeclaration;

GenericDeclaration::GenericDeclaration(JVM* jvm) : AnnotatedElement()
{
    
}

GenericDeclaration::GenericDeclaration(JVM* jvm, jobject instance) : AnnotatedElement()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/GenericDeclaration;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Array<TypeVariable> GenericDeclaration::getTypeParameters()
{
    jmethodID getTypeParametersMethod = this->vm->GetMethodID(this->cls.get(), "getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;");
    return Array<TypeVariable>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getTypeParametersMethod));
}
