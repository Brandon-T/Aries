//
//  ClassLoader.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ClassLoader.hpp"

using namespace java::lang;

ClassLoader::ClassLoader(JVM* jvm) : Object()
{
    
}

ClassLoader::ClassLoader(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/ClassLoader;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

ClassLoader::~ClassLoader()
{
    
}
