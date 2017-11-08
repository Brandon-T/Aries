//
//  Field.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Field.hxx"

using java::lang::reflect::Field;

Field::Field(JVM* jvm) : Object()
{
    
}

Field::Field(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/reflect/Field;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
