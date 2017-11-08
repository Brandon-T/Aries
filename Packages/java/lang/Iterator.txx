//
//  Iterator.cxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Iterator.hxx"

using java::lang::Object;
using java::lang::Iterator;

template<typename T>
Iterator<T>::Iterator(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass(("Ljava/lang/Iterator;");
        this->inst = JVMRef<jobject>(this->vm, (instance);
    }
}

template<typename T>
bool Iterator<T>::hasNext()
{
    jmethodID hasNextMethod = this->vm->GetMethodID(this->cls.get(), "hasNext", "()Z");
    return this->vm->CallBooleanMethod(this->vm, hasNextMethod);
}

template<typename T>
T Iterator<T>::next()
{
    jmethodID nextMethod = this->vm->GetMethodID(this->cls.get(), "next", "()Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), nextMethod));
}

template<typename T>
void Iterator<T>::remove()
{
    jmethodID removeMethod = this->vm->GetMethodID(this->cls.get(), "remove", "()V");
    this->vm->CallVoidMethod(this->vm, removeMethod);
}
