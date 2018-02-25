//
//  Inflater.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Inflater.hxx"

using java::util::zip::Inflater;
using java::lang::Object;


Inflater::Inflater(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/Inflater;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Inflater::Inflater(JVM* vm, bool nowrap) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/Inflater;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Z)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, nowrap));
    }
}

Inflater::Inflater(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/Inflater;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

void Inflater::end()
{
    static jmethodID endMethod = this->vm->GetMethodID(this->cls.get(), "end", "()V");
    this->vm->CallVoidMethod(this->inst.get(), endMethod);
}

bool Inflater::finished()
{
    static jmethodID finishedMethod = this->vm->GetMethodID(this->cls.get(), "finished", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), finishedMethod);
}

std::int32_t Inflater::getAdler()
{
    static jmethodID getAdlerMethod = this->vm->GetMethodID(this->cls.get(), "getAdler", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getAdlerMethod);
}

std::int64_t Inflater::getBytesRead()
{
    static jmethodID getBytesReadMethod = this->vm->GetMethodID(this->cls.get(), "getBytesRead", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getBytesReadMethod);
}

std::int64_t Inflater::getBytesWritten()
{
    static jmethodID getBytesWrittenMethod = this->vm->GetMethodID(this->cls.get(), "getBytesWritten", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getBytesWrittenMethod);
}

std::int32_t Inflater::getRemaining()
{
    static jmethodID getRemainingMethod = this->vm->GetMethodID(this->cls.get(), "getRemaining", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getRemainingMethod);
}

std::int32_t Inflater::getTotalIn()
{
    static jmethodID getTotalInMethod = this->vm->GetMethodID(this->cls.get(), "getTotalIn", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getTotalInMethod);
}

std::int32_t Inflater::getTotalOut()
{
    static jmethodID getTotalOutMethod = this->vm->GetMethodID(this->cls.get(), "getTotalOut", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getTotalOutMethod);
}

std::int32_t Inflater::inflate(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID inflateMethod = this->vm->GetMethodID(this->cls.get(), "inflate", "([BII)I");
    return this->vm->CallIntMethod(this->inst.get(), inflateMethod, b.ref().get(), off, len);
}

std::int32_t Inflater::inflate(Array<std::uint8_t>& b)
{
    static jmethodID inflateMethod = this->vm->GetMethodID(this->cls.get(), "inflate", "([B)I");
    return this->vm->CallIntMethod(this->inst.get(), inflateMethod, b.ref().get());
}

bool Inflater::needsDictionary()
{
    static jmethodID needsDictionaryMethod = this->vm->GetMethodID(this->cls.get(), "needsDictionary", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), needsDictionaryMethod);
}

bool Inflater::needsInput()
{
    static jmethodID needsInputMethod = this->vm->GetMethodID(this->cls.get(), "needsInput", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), needsInputMethod);
}

void Inflater::reset()
{
    static jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()V");
    this->vm->CallVoidMethod(this->inst.get(), resetMethod);
}

void Inflater::setDictionary(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID setDictionaryMethod = this->vm->GetMethodID(this->cls.get(), "setDictionary", "([BII)V");
    this->vm->CallVoidMethod(this->inst.get(), setDictionaryMethod, b.ref().get(), off, len);
}

void Inflater::setDictionary(Array<std::uint8_t>& b)
{
    static jmethodID setDictionaryMethod = this->vm->GetMethodID(this->cls.get(), "setDictionary", "([B)V");
    this->vm->CallVoidMethod(this->inst.get(), setDictionaryMethod, b.ref().get());
}

void Inflater::setInput(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len)
{
    static jmethodID setInputMethod = this->vm->GetMethodID(this->cls.get(), "setInput", "([BII)V");
    this->vm->CallVoidMethod(this->inst.get(), setInputMethod, b.ref().get(), off, len);
}

void Inflater::setInput(Array<std::uint8_t>& b)
{
    static jmethodID setInputMethod = this->vm->GetMethodID(this->cls.get(), "setInput", "([B)V");
    this->vm->CallVoidMethod(this->inst.get(), setInputMethod, b.ref().get());
}

void Inflater::finalize()
{
    static jmethodID finalizeMethod = this->vm->GetMethodID(this->cls.get(), "finalize", "()V");
    this->vm->CallVoidMethod(this->inst.get(), finalizeMethod);
}
