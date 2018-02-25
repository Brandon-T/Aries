//
//  List.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

template<typename T>
List<T>::List(JVM* vm, jobject instance) : Collection<T>(vm, nullptr)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/List;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
void List<T>::add(std::int32_t index, T element)
{
    static jmethodID addMethod = this->vm->GetMethodID(this->cls.get(), "add", "(ILjava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), addMethod, index, element.ref().get());
}

template<typename T>
bool List<T>::addAll(std::int32_t index, Collection<T> c)
{
    static jmethodID addAllMethod = this->vm->GetMethodID(this->cls.get(), "addAll", "(ILjava/util/Collection;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), addAllMethod, index, c.ref().get());
}

template<typename T>
T List<T>::get(std::int32_t index)
{
    static jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(I)Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, index));
}

template<typename T>
std::int32_t List<T>::indexOf(T o)
{
    static jmethodID indexOfMethod = this->vm->GetMethodID(this->cls.get(), "indexOf", "(Ljava/lang/Object;)I");
    return this->vm->CallIntMethod(this->inst.get(), indexOfMethod, o.ref().get());
}

template<typename T>
std::int32_t List<T>::lastIndexOf(T o)
{
    static jmethodID lastIndexOfMethod = this->vm->GetMethodID(this->cls.get(), "lastIndexOf", "(Ljava/lang/Object;)I");
    return this->vm->CallIntMethod(this->inst.get(), lastIndexOfMethod, o.ref().get());
}

template<typename T>
ListIterator<T> List<T>::listIterator()
{
    static jmethodID listIteratorMethod = this->vm->GetMethodID(this->cls.get(), "listIterator", "()Ljava/util/ListIterator;");
    return ListIterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), listIteratorMethod));
}

template<typename T>
ListIterator<T> List<T>::listIterator(std::int32_t index)
{
    static jmethodID listIteratorMethod = this->vm->GetMethodID(this->cls.get(), "listIterator", "(I)Ljava/util/ListIterator;");
    return ListIterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), listIteratorMethod, index));
}

template<typename T>
T List<T>::remove(std::int32_t index)
{
    static jmethodID removeMethod = this->vm->GetMethodID(this->cls.get(), "remove", "(I)Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), removeMethod, index));
}

template<typename T>
T List<T>::set(std::int32_t index, T element)
{
    static jmethodID setMethod = this->vm->GetMethodID(this->cls.get(), "set", "(ILjava/lang/Object;)Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), setMethod, index, element.ref().get()));
}

template<typename T>
void List<T>::sort(Comparator<T> c)
{
    static jmethodID sortMethod = this->vm->GetMethodID(this->cls.get(), "sort", "(Ljava/util/Comparator;)V");
    this->vm->CallVoidMethod(this->inst.get(), sortMethod, c.ref().get());
}

template<typename T>
Spliterator<T> List<T>::spliterator()
{
    static jmethodID spliteratorMethod = this->vm->GetMethodID(this->cls.get(), "spliterator", "()Ljava/util/Spliterator;");
    return Spliterator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), spliteratorMethod));
}

template<typename T>
List<T> List<T>::subList(std::int32_t fromIndex, std::int32_t toIndex)
{
    static jmethodID subListMethod = this->vm->GetMethodID(this->cls.get(), "subList", "(II)Ljava/util/List;");
    return List<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), subListMethod, fromIndex, toIndex));
}

template<typename T>
Array<T> List<T>::toArray(Array<T>& a)
{
    static jmethodID toArrayMethod = this->vm->GetMethodID(this->cls.get(), "toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), toArrayMethod, a.ref().get()));
    return Array<T>(this->vm, arr);
}
