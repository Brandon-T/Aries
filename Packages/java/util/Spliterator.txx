//
//  Spliterator.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//


template<typename T>
Spliterator<T>::Spliterator(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Spliterator;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
std::int32_t Spliterator<T>::characteristics()
{
    static jmethodID characteristicsMethod = this->vm->GetMethodID(this->cls.get(), "characteristics", "()I");
    return this->vm->CallIntMethod(this->inst.get(), characteristicsMethod);
}

template<typename T>
std::int64_t Spliterator<T>::estimateSize()
{
    static jmethodID estimateSizeMethod = this->vm->GetMethodID(this->cls.get(), "estimateSize", "()J");
    return this->vm->CallLongMethod(this->inst.get(), estimateSizeMethod);
}

template<typename T>
Comparator<T> Spliterator<T>::getComparator()
{
    static jmethodID getComparatorMethod = this->vm->GetMethodID(this->cls.get(), "getComparator", "()Ljava/util/Comparator;");
    return Comparator<T>(this->vm, this->vm->CallObjectMethod(this->inst.get(), getComparatorMethod));
}

template<typename T>
std::int64_t Spliterator<T>::getExactSizeIfKnown()
{
    static jmethodID getExactSizeIfKnownMethod = this->vm->GetMethodID(this->cls.get(), "getExactSizeIfKnown", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getExactSizeIfKnownMethod);
}

template<typename T>
bool Spliterator<T>::hasCharacteristics(std::int32_t characteristics)
{
    static jmethodID hasCharacteristicsMethod = this->vm->GetMethodID(this->cls.get(), "hasCharacteristics", "(I)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasCharacteristicsMethod, characteristics);
}

template<typename T>
Spliterator<T> Spliterator<T>::trySplit()
{
    static jmethodID trySplitMethod = this->vm->GetMethodID(this->cls.get(), "trySplit", "()Ljava/util/Spliterator;");
    return Spliterator(this->vm, this->vm->CallObjectMethod(this->inst.get(), trySplitMethod));
}
