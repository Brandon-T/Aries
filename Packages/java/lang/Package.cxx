//
//  Package.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Package.hxx"

using java::lang::Package;

Package::Package(JVM* jvm) : Object()
{
    
}

Package::Package(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Package;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
