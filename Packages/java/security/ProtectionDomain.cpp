//
//  ProtectionDomain.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ProtectionDomain.hpp"

using namespace java::security;

ProtectionDomain::ProtectionDomain(JVM* jvm) : Object()
{
    
}

ProtectionDomain::ProtectionDomain(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/security/ProtectionDomain;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

ProtectionDomain::~ProtectionDomain()
{
    
}
