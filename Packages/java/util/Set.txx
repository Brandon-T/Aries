//
//  Set.txx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Set.hxx"

using java::lang::Object;
using java::util::Set;
using java::util::Iterator;

template<typename T>
Set<T>::Set(JVM* jvm) : Collection<T>(nullptr, nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jobject>(this->vm, JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Set;")));
        jmethodID constructor = jvm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, jvm->NewObject(this->cls.get(), constructor));
    }
}

template<typename T>
Set<T>::Set(JVM* jvm, jobject instance) : Collection<T>(nullptr, nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Set;"));
        this->inst = JVMRef<jobject>(this->vm, (instance));
    }
}
