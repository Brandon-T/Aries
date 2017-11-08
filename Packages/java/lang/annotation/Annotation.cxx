//
//  Annotation.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Annotation.hxx"

using java::lang::annotation::Annotation;

Annotation::Annotation(JVM* jvm) : Object()
{
    
}

Annotation::Annotation(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/Annotation;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
