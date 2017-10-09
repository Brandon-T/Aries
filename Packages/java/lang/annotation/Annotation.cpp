//
//  Annotation.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Annotation.hpp"

using namespace java::lang::annotation;

Annotation::Annotation(JVM* jvm) : Object()
{
    
}

Annotation::Annotation(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/reflect/Annotation;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Annotation::~Annotation()
{
    
}
