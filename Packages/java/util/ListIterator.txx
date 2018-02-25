//
//  ListIterator.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

using java::util::ListIterator;
using java::lang::Object;


template<typename T>
ListIterator<T>::ListIterator(JVM* vm, jobject instance) : Iterator<T>()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/ListIterator;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
void ListIterator<T>::add(T e)
{
    static jmethodID addMethod = this->vm->GetMethodID(this->cls.get(), "add", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), addMethod, e.ref().get());
}

template<typename T>
bool ListIterator<T>::hasNext()
{
    static jmethodID hasNextMethod = this->vm->GetMethodID(this->cls.get(), "hasNext", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasNextMethod);
}

template<typename T>
bool ListIterator<T>::hasPrevious()
{
    static jmethodID hasPreviousMethod = this->vm->GetMethodID(this->cls.get(), "hasPrevious", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasPreviousMethod);
}

template<typename T>
T ListIterator<T>::next()
{
    static jmethodID nextMethod = this->vm->GetMethodID(this->cls.get(), "next", "()Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), nextMethod));
}

template<typename T>
std::int32_t ListIterator<T>::nextIndex()
{
    static jmethodID nextIndexMethod = this->vm->GetMethodID(this->cls.get(), "nextIndex", "()I");
    return this->vm->CallIntMethod(this->inst.get(), nextIndexMethod);
}

template<typename T>
T ListIterator<T>::previous()
{
    static jmethodID previousMethod = this->vm->GetMethodID(this->cls.get(), "previous", "()Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), previousMethod));
}

template<typename T>
std::int32_t ListIterator<T>::previousIndex()
{
    static jmethodID previousIndexMethod = this->vm->GetMethodID(this->cls.get(), "previousIndex", "()I");
    return this->vm->CallIntMethod(this->inst.get(), previousIndexMethod);
}

template<typename T>
void ListIterator<T>::remove()
{
    static jmethodID removeMethod = this->vm->GetMethodID(this->cls.get(), "remove", "()V");
    this->vm->CallVoidMethod(this->inst.get(), removeMethod);
}

template<typename T>
void ListIterator<T>::set(T e)
{
    static jmethodID setMethod = this->vm->GetMethodID(this->cls.get(), "set", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), setMethod, e.ref().get());
}
