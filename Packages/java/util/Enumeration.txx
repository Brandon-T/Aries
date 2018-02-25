//
//  Enumeration.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

template<typename T>
Enumeration<T>::Enumeration(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Enumeration;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename T>
bool Enumeration<T>::hasMoreElements()
{
    static jmethodID hasMoreElementsMethod = this->vm->GetMethodID(this->cls.get(), "hasMoreElements", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), hasMoreElementsMethod);
}

template<typename T>
T Enumeration<T>::nextElement()
{
    static jmethodID nextElementMethod = this->vm->GetMethodID(this->cls.get(), "nextElement", "()Ljava/lang/Object;");
    return T(this->vm, this->vm->CallObjectMethod(this->inst.get(), nextElementMethod));
}
