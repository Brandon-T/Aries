//
//  CharSequence.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "CharSequence.hxx"

using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::util::stream::IntStream;

CharSequence::CharSequence(JVM* vm, jobject instance)
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/CharSequence;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

char CharSequence::charAt(std::int32_t index)
{
    static jmethodID charAtMethod = this->vm->GetMethodID(this->cls.get(), "charAt", "(I)C");
    return this->vm->CallCharMethod(this->inst.get(), charAtMethod, index);
}

IntStream CharSequence::chars()
{
    static jmethodID charsMethod = this->vm->GetMethodID(this->cls.get(), "chars", "()Ljava/util/stream/IntStream;");
    return IntStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), charsMethod));
}

IntStream CharSequence::codePoints()
{
    static jmethodID codePointsMethod = this->vm->GetMethodID(this->cls.get(), "codePoints", "()Ljava/util/stream/IntStream;");
    return IntStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), codePointsMethod));
}

std::int32_t CharSequence::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

CharSequence CharSequence::subSequence(std::int32_t start, std::int32_t end)
{
    static jmethodID subSequenceMethod = this->vm->GetMethodID(this->cls.get(), "subSequence", "(II)Ljava/lang/CharSequence;");
    return CharSequence(this->vm, this->vm->CallObjectMethod(this->inst.get(), subSequenceMethod, start, end));
}

String CharSequence::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
