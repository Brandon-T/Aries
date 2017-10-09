//
//  Field.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Field.hpp"

using namespace java::lang::reflect;

Field::Field(JVM* jvm) : Object()
{
    
}

Field::Field(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/Field;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Field::~Field()
{
    
}
