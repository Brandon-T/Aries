//
//  AnnotatedType.cxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "AnnotatedType.hxx"
#include "AnnotatedElement.hxx"
#include "Type.hxx"

using java::lang::reflect::Type;
using java::lang::reflect::AnnotatedType;

AnnotatedType::AnnotatedType(JVM* jvm) : AnnotatedElement()
{
    
}

AnnotatedType::AnnotatedType(JVM* jvm, jobject instance) : AnnotatedElement()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/AnnotatedType;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Type AnnotatedType::getType()
{
    jmethodID getTypeMethod = this->vm->GetMethodID(this->cls.get(), "getType", "()Ljava/lang/reflect/Type;");
    return Type(this->vm, this->vm->CallObjectMethod(this->inst.get(), getTypeMethod));
}
