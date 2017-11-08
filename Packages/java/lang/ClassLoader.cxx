//
//  ClassLoader.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ClassLoader.hxx"

using java::lang::ClassLoader;

ClassLoader::ClassLoader(JVM* jvm) : Object()
{
    
}

ClassLoader::ClassLoader(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/ClassLoader;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
