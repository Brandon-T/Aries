//
//  AnnotatedType.cpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "AnnotatedType.hpp"
#include "AnnotatedElement.hpp"
#include "Type.hpp"

using namespace java::lang::reflect;

AnnotatedType::AnnotatedType(JVM* jvm) : AnnotatedElement()
{
    
}

AnnotatedType::AnnotatedType(JVM* jvm, jobject instance) : AnnotatedElement()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/AnnotatedType;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

AnnotatedType::~AnnotatedType()
{
    
}

Type AnnotatedType::getType()
{
    jmethodID getTypeMethod = this->vm->GetMethodID(this->cls, "getType", "()Ljava/lang/reflect/Type;");
    return Type(this->vm, this->vm->CallObjectMethod(this->inst, getTypeMethod));
}
