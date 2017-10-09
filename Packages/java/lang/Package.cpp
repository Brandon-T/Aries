//
//  Package.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Package.hpp"

using namespace java::lang;

Package::Package(JVM* jvm) : Object()
{
    
}

Package::Package(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/Package;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

Package::~Package()
{
    
}
