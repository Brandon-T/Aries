//
//  Type.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Type.hxx"

using java::lang::reflect::Type;

Type::Type(JVM* jvm) : Object()
{
    
}

Type::Type(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/Type;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
