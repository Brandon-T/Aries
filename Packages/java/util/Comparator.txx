//
//  Comparator.txx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Comparator.hxx"
//
//using java::util::Comparator;

template<typename T>
Comparator<T>::Comparator(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Comparator;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
int Comparator<T>::compare(T o1, T o2)
{
    jmethodID compareMethod = this->vm->GetMethodID(this->cls.get(), "compare", "(Ljava/lang/Object;Ljava/lang/Object;)I");
    return this->vm->CallIntMethod(this->inst.get(), compareMethod, o1.ref().get(), o2.ref().get());
}

template<typename T>
bool Comparator<T>::equals(Object obj)
{
    jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}
