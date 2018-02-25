//
//  CoderResult.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "CoderResult.hxx"

using java::nio::charset::CoderResult;
using java::lang::Object;
using java::lang::String;

CoderResult::CoderResult(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CoderResult;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool CoderResult::isError()
{
    static jmethodID isErrorMethod = this->vm->GetMethodID(this->cls.get(), "isError", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isErrorMethod);
}

bool CoderResult::isMalformed()
{
    static jmethodID isMalformedMethod = this->vm->GetMethodID(this->cls.get(), "isMalformed", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isMalformedMethod);
}

bool CoderResult::isOverflow()
{
    static jmethodID isOverflowMethod = this->vm->GetMethodID(this->cls.get(), "isOverflow", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isOverflowMethod);
}

bool CoderResult::isUnderflow()
{
    static jmethodID isUnderflowMethod = this->vm->GetMethodID(this->cls.get(), "isUnderflow", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isUnderflowMethod);
}

bool CoderResult::isUnmappable()
{
    static jmethodID isUnmappableMethod = this->vm->GetMethodID(this->cls.get(), "isUnmappable", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isUnmappableMethod);
}

std::int32_t CoderResult::length()
{
    static jmethodID lengthMethod = this->vm->GetMethodID(this->cls.get(), "length", "()I");
    return this->vm->CallIntMethod(this->inst.get(), lengthMethod);
}

CoderResult CoderResult::malformedForLength(JVM* vm, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/charset/CoderResult;"));
    static jmethodID malformedForLengthMethod = vm->GetStaticMethodID(cls.get(), "malformedForLength", "(I)Ljava/nio/charset/CoderResult;");
    return CoderResult(vm, vm->CallStaticObjectMethod(cls.get(), malformedForLengthMethod, length));
}

void CoderResult::throwException()
{
    static jmethodID throwExceptionMethod = this->vm->GetMethodID(this->cls.get(), "throwException", "()V");
    this->vm->CallVoidMethod(this->inst.get(), throwExceptionMethod);
}

String CoderResult::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}

CoderResult CoderResult::unmappableForLength(JVM* vm, std::int32_t length)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/charset/CoderResult;"));
    static jmethodID unmappableForLengthMethod = vm->GetStaticMethodID(cls.get(), "unmappableForLength", "(I)Ljava/nio/charset/CoderResult;");
    return CoderResult(vm, vm->CallStaticObjectMethod(cls.get(), unmappableForLengthMethod, length));
}
