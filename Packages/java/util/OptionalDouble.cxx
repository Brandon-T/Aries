//
//  OptionalDouble.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "OptionalDouble.hxx"
#include "Object.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "DoubleConsumer.hxx"
#include "DoubleSupplier.hxx"
#include "Supplier.hxx"

using java::util::OptionalDouble;
using java::lang::Object;
using java::lang::String;
using java::util::function::DoubleConsumer;
using java::util::function::DoubleSupplier;
using java::util::function::Supplier;


OptionalDouble::OptionalDouble(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/OptionalDouble;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

OptionalDouble OptionalDouble::empty(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/OptionalDouble;"));
    static jmethodID emptyMethod = vm->GetStaticMethodID(cls.get(), "empty", "()Ljava/util/OptionalDouble;");
    return OptionalDouble(vm, vm->CallStaticObjectMethod(cls.get(), emptyMethod));
}

bool OptionalDouble::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

double OptionalDouble::getAsDouble()
{
    static jmethodID getAsDoubleMethod = this->vm->GetMethodID(this->cls.get(), "getAsDouble", "()D");
    return this->vm->CallDoubleMethod(this->inst.get(), getAsDoubleMethod);
}

std::int32_t OptionalDouble::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

void OptionalDouble::ifPresent(DoubleConsumer consumer)
{
    static jmethodID ifPresentMethod = this->vm->GetMethodID(this->cls.get(), "ifPresent", "(Ljava/util/function/DoubleConsumer;)V");
    this->vm->CallVoidMethod(this->inst.get(), ifPresentMethod, consumer.ref().get());
}

bool OptionalDouble::isPresent()
{
    static jmethodID isPresentMethod = this->vm->GetMethodID(this->cls.get(), "isPresent", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isPresentMethod);
}

OptionalDouble OptionalDouble::of(JVM* vm, double value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/OptionalDouble;"));
    static jmethodID ofMethod = vm->GetStaticMethodID(cls.get(), "of", "(D)Ljava/util/OptionalDouble;");
    return OptionalDouble(vm, vm->CallStaticObjectMethod(cls.get(), ofMethod, value));
}

double OptionalDouble::orElse(double other)
{
    static jmethodID orElseMethod = this->vm->GetMethodID(this->cls.get(), "orElse", "(D)D");
    return this->vm->CallDoubleMethod(this->inst.get(), orElseMethod, other);
}

double OptionalDouble::orElseGet(DoubleSupplier other)
{
    static jmethodID orElseGetMethod = this->vm->GetMethodID(this->cls.get(), "orElseGet", "(Ljava/util/function/DoubleSupplier;)D");
    return this->vm->CallDoubleMethod(this->inst.get(), orElseGetMethod, other.ref().get());
}

double OptionalDouble::orElseThrow(Supplier exceptionSupplier)
{
    static jmethodID orElseThrowMethod = this->vm->GetMethodID(this->cls.get(), "orElseThrow", "(Ljava/util/function/Supplier;)D");
    return this->vm->CallDoubleMethod(this->inst.get(), orElseThrowMethod, exceptionSupplier.ref().get());
}

String OptionalDouble::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
