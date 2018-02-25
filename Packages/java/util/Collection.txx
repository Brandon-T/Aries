//
//  Collection.txx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Collection.hxx"

using java::lang::Object;
using java::util::Collection;
using java::util::Iterator;
using java::util::Spliterator;

template<typename T>
Collection<T>::Collection(JVM* jvm, jobject instance) : Iterable<T>(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Collection;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
bool Collection<T>::add(T e)
{
    jmethodID addMethod = this->vm->GetMethodID(this->cls.get(), "add", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), addMethod, e.ref().get());
}

template<typename T>
bool Collection<T>::addAll(Collection<T> c)
{
    jmethodID addAllMethod = this->vm->GetMethodID(this->cls.get(), "addAll", "(Ljava/util/Collection;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), addAllMethod, c.ref().get());
}

template<typename T>
void Collection<T>::clear()
{
    jmethodID clearMethod = this->vm->GetMethodID(this->cls.get(), "clear", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearMethod);
}

template<typename T>
bool Collection<T>::contains(Object o)
{
    jmethodID containsMethod = this->vm->GetMethodID(this->cls.get(), "contains", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsMethod, o.ref().get());
}

template<typename T>
bool Collection<T>::containsAll(Collection<T> c)
{
    jmethodID containsAllMethod = this->vm->GetMethodID(this->cls.get(), "containsAll", "(Ljava/util/Collection;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsAllMethod, c.ref().get());
}

template<typename T>
bool Collection<T>::isEmpty()
{
    jmethodID isEmptyMethod = this->vm->GetMethodID(this->cls.get(), "isEmpty", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isEmptyMethod);
}

template<typename T>
Iterator<T> Collection<T>::iterator()
{
    jmethodID iteratorMethod = this->vm->GetMethodID(this->cls.get(), "iterator", "()Ljava/util/Iterator;");
    return Iterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), iteratorMethod));
}

template<typename T>
bool Collection<T>::remove(Object o)
{
    jmethodID removeMethod = this->vm->GetMethodID(this->cls.get(), "remove", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), removeMethod, o.ref().get());
}

template<typename T>
bool Collection<T>::removeAll(Collection<T> c)
{
    jmethodID removeAllMethod = this->vm->GetMethodID(this->cls.get(), "removeAll", "(Ljava/util/Collection;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), removeAllMethod, c.ref().get());
}

template<typename T>
bool Collection<T>::retainAll(Collection<T> c)
{
    jmethodID retainAllMethod = this->vm->GetMethodID(this->cls.get(), "retainAll", "(Ljava/util/Collection;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), retainAllMethod, c.ref().get());
}

template<typename T>
int Collection<T>::size()
{
    jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()I");
    return this->vm->CallIntMethod(this->inst.get(), sizeMethod);
}

template<typename T>
Spliterator<T> Collection<T>::spliterator()
{
    static jmethodID spliteratorMethod = this->vm->GetMethodID(this->cls.get(), "spliterator", "()Ljava/util/Spliterator;");
    return Spliterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), spliteratorMethod));
}

template<typename T>
Array<Object> Collection<T>::toArray()
{
    jmethodID toArrayMethod = this->vm->GetMethodID(this->cls.get(), "toArray", "()[Ljava/lang/Object;");
    return Array<Object>(this->vm, this->vm->CallObjectMethod(this->inst.get(), toArrayMethod));
}

template<typename T>
Array<T> Collection<T>::toArray(Array<T> a)
{
    jmethodID toArrayMethod = this->vm->GetMethodID(this->cls.get(), "toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;");
    return Array<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), toArrayMethod, a.ref().get()));
}
