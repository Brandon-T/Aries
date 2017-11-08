//
//  ProtectionDomain.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ProtectionDomain.hxx"

using java::security::ProtectionDomain;

ProtectionDomain::ProtectionDomain(JVM* jvm) : Object()
{
    
}

ProtectionDomain::ProtectionDomain(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/security/ProtectionDomain;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
