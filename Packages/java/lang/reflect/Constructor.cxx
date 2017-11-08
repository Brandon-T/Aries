//
//  Constructor.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Constructor.hxx"

using java::lang::reflect::Constructor;

Constructor::Constructor(JVM* jvm) : Object()
{
    
}

Constructor::Constructor(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/Constructor;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
