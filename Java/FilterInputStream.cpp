//
//  FilterInputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "FilterInputStream.hpp"

using namespace java::io;

FilterInputStream::FilterInputStream(JVM* jvm) : InputStream(nullptr)
{
    
}

FilterInputStream::FilterInputStream(JVM* jvm, jobject instance) : InputStream(nullptr)
{
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/io/FilterInputStream;")));
    this->inst = this->vm->NewGlobalRef(instance);
}

FilterInputStream::FilterInputStream(JVM* jvm, InputStream stream) : InputStream(nullptr)
{
    this->vm = jvm;
    this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/io/FilterInputStream;")));
    
    jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;)V");
    this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get()));
}

FilterInputStream::~FilterInputStream()
{
    
}
