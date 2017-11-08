//
//  FilterInputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "FilterInputStream.hxx"

using java::io::FilterInputStream;

FilterInputStream::FilterInputStream(JVM* jvm) : InputStream(nullptr)
{
    
}

FilterInputStream::FilterInputStream(JVM* jvm, jobject instance) : InputStream(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FilterInputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

FilterInputStream::FilterInputStream(JVM* jvm, InputStream stream) : InputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FilterInputStream;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get()));
    }
}
