//
//  IntSummaryStatistics.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "IntSummaryStatistics.hxx"

using java::util::IntSummaryStatistics;
using java::lang::Object;
using java::lang::String;

IntSummaryStatistics::IntSummaryStatistics(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/IntSummaryStatistics;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

IntSummaryStatistics::IntSummaryStatistics(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/IntSummaryStatistics;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

void IntSummaryStatistics::accept(std::int32_t value)
{
    static jmethodID acceptMethod = this->vm->GetMethodID(this->cls.get(), "accept", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), acceptMethod, value);
}

void IntSummaryStatistics::combine(IntSummaryStatistics other)
{
    static jmethodID combineMethod = this->vm->GetMethodID(this->cls.get(), "combine", "(Ljava/util/IntSummaryStatistics;)V");
    this->vm->CallVoidMethod(this->inst.get(), combineMethod, other.ref().get());
}

double IntSummaryStatistics::getAverage()
{
    static jmethodID getAverageMethod = this->vm->GetMethodID(this->cls.get(), "getAverage", "()D");
    return this->vm->CallDoubleMethod(this->inst.get(), getAverageMethod);
}

std::int64_t IntSummaryStatistics::getCount()
{
    static jmethodID getCountMethod = this->vm->GetMethodID(this->cls.get(), "getCount", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getCountMethod);
}

std::int32_t IntSummaryStatistics::getMax()
{
    static jmethodID getMaxMethod = this->vm->GetMethodID(this->cls.get(), "getMax", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getMaxMethod);
}

std::int32_t IntSummaryStatistics::getMin()
{
    static jmethodID getMinMethod = this->vm->GetMethodID(this->cls.get(), "getMin", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getMinMethod);
}

std::int64_t IntSummaryStatistics::getSum()
{
    static jmethodID getSumMethod = this->vm->GetMethodID(this->cls.get(), "getSum", "()J");
    return this->vm->CallLongMethod(this->inst.get(), getSumMethod);
}

String IntSummaryStatistics::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
