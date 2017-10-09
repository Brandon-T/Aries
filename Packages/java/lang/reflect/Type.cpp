//
//  Type.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Type.hpp"

using namespace java::lang::reflect;

Type::Type(JVM* jvm) : Object()
{
    
}

Type::Type(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/Type;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Type::~Type()
{
    
}
