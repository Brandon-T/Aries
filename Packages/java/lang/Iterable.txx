//
//  Iterable.txx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Iterable.hxx"

using java::lang::Object;
using java::lang::Iterable;
using java::util::Iterator;

template<typename T>
Iterable<T>::Iterable(JVM* jvm) : Object()
{
    
}

template<typename T>
Iterable<T>::Iterable(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->inst = instance;
        this->cls = this->vm->FindClass("Ljava/lang/Iterable;");
    }
}

template<typename T>
Iterator<T> Iterable<T>::iterator()
{
    jmethodID iteratorMethod = this->vm->GetMethodID(this->cls.get(), "iterator", "()Ljava/util/Iterator;");
    return Iterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), iteratorMethod));
}
