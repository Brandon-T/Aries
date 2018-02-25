//
//  TimeUnit.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "TimeUnit.hxx"
#include "Enum.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Thread.hxx"

using java::util::concurrent::TimeUnit;
using java::lang::Enum;
using java::lang::Object;
using java::lang::String;
using java::lang::Thread;


TimeUnit::TimeUnit(JVM* arg0, jobject arg1) : Enum()
{
    if (arg0 && arg1)
    {
        this->vm = arg0;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/concurrent/TimeUnit;"));
        this->inst = JVMRef<jobject>(this->vm, arg1);
    }
}

std::int64_t TimeUnit::convert(std::int64_t arg0, TimeUnit arg1)
{
    static jmethodID convertMethod = this->vm->GetMethodID(this->cls.get(), "convert", "(JLjava/util/concurrent/TimeUnit;)J");
    return this->vm->CallLongMethod(this->inst.get(), convertMethod, arg0, arg1.ref().get());
}

void TimeUnit::sleep(std::int64_t arg0)
{
    static jmethodID sleepMethod = this->vm->GetMethodID(this->cls.get(), "sleep", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), sleepMethod, arg0);
}

void TimeUnit::timedJoin(Thread arg0, std::int64_t arg1)
{
    static jmethodID timedJoinMethod = this->vm->GetMethodID(this->cls.get(), "timedJoin", "(Ljava/lang/Thread;J)V");
    this->vm->CallVoidMethod(this->inst.get(), timedJoinMethod, arg0.ref().get(), arg1);
}

void TimeUnit::timedWait(Object arg0, std::int64_t arg1)
{
    static jmethodID timedWaitMethod = this->vm->GetMethodID(this->cls.get(), "timedWait", "(Ljava/lang/Object;J)V");
    this->vm->CallVoidMethod(this->inst.get(), timedWaitMethod, arg0.ref().get(), arg1);
}

std::int64_t TimeUnit::toDays(std::int64_t arg0)
{
    static jmethodID toDaysMethod = this->vm->GetMethodID(this->cls.get(), "toDays", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toDaysMethod, arg0);
}

std::int64_t TimeUnit::toHours(std::int64_t arg0)
{
    static jmethodID toHoursMethod = this->vm->GetMethodID(this->cls.get(), "toHours", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toHoursMethod, arg0);
}

std::int64_t TimeUnit::toMicros(std::int64_t arg0)
{
    static jmethodID toMicrosMethod = this->vm->GetMethodID(this->cls.get(), "toMicros", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toMicrosMethod, arg0);
}

std::int64_t TimeUnit::toMillis(std::int64_t arg0)
{
    static jmethodID toMillisMethod = this->vm->GetMethodID(this->cls.get(), "toMillis", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toMillisMethod, arg0);
}

std::int64_t TimeUnit::toMinutes(std::int64_t arg0)
{
    static jmethodID toMinutesMethod = this->vm->GetMethodID(this->cls.get(), "toMinutes", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toMinutesMethod, arg0);
}

std::int64_t TimeUnit::toNanos(std::int64_t arg0)
{
    static jmethodID toNanosMethod = this->vm->GetMethodID(this->cls.get(), "toNanos", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toNanosMethod, arg0);
}

std::int64_t TimeUnit::toSeconds(std::int64_t arg0)
{
    static jmethodID toSecondsMethod = this->vm->GetMethodID(this->cls.get(), "toSeconds", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), toSecondsMethod, arg0);
}

TimeUnit TimeUnit::valueOf(JVM* arg0, String arg1)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/concurrent/TimeUnit;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/String;)Ljava/util/concurrent/TimeUnit;");
    return TimeUnit(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, arg1.ref().get()));
}

Array<TimeUnit> TimeUnit::values(JVM* arg0)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/concurrent/TimeUnit;"));
    static jmethodID valuesMethod = vm->GetStaticMethodID(cls.get(), "values", "()[Ljava/util/concurrent/TimeUnit;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), valuesMethod));
    return Array<TimeUnit>(this->vm, arr);
}
