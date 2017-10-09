//
//  Constructor.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Constructor.hpp"

using namespace java::lang::reflect;

Constructor::Constructor(JVM* jvm) : Object()
{
    
}

Constructor::Constructor(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/Constructor;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Constructor::~Constructor()
{
    
}
