//
//  Method.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Method.hxx"

using java::lang::reflect::Method;

Method::Method(JVM* jvm) : Object()
{
    
}

Method::Method(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/Method;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
