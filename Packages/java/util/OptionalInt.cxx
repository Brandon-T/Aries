//
//  OptionalInt.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "OptionalInt.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "IntConsumer.hxx"
#include "IntSupplier.hxx"
#include "Supplier.hxx"

using java::util::OptionalInt;
using java::lang::Object;
using java::lang::String;
using java::util::function::IntConsumer;
using java::util::function::IntSupplier;
using java::util::function::Supplier;


OptionalInt::OptionalInt(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/OptionalInt;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

OptionalInt OptionalInt::empty(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/OptionalInt;"));
    static jmethodID emptyMethod = vm->GetStaticMethodID(cls.get(), "empty", "()Ljava/util/OptionalInt;");
    return OptionalInt(vm, vm->CallStaticObjectMethod(cls.get(), emptyMethod));
}

bool OptionalInt::equals(Object obj)
{
    static jmethodID equalsMethod = this->vm->GetMethodID(this->cls.get(), "equals", "(Ljava/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), equalsMethod, obj.ref().get());
}

std::int32_t OptionalInt::getAsInt()
{
    static jmethodID getAsIntMethod = this->vm->GetMethodID(this->cls.get(), "getAsInt", "()I");
    return this->vm->CallIntMethod(this->inst.get(), getAsIntMethod);
}

std::int32_t OptionalInt::hashCode()
{
    static jmethodID hashCodeMethod = this->vm->GetMethodID(this->cls.get(), "hashCode", "()I");
    return this->vm->CallIntMethod(this->inst.get(), hashCodeMethod);
}

void OptionalInt::ifPresent(IntConsumer consumer)
{
    static jmethodID ifPresentMethod = this->vm->GetMethodID(this->cls.get(), "ifPresent", "(Ljava/util/function/IntConsumer;)V");
    this->vm->CallVoidMethod(this->inst.get(), ifPresentMethod, consumer.ref().get());
}

bool OptionalInt::isPresent()
{
    static jmethodID isPresentMethod = this->vm->GetMethodID(this->cls.get(), "isPresent", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isPresentMethod);
}

OptionalInt OptionalInt::of(JVM* vm, std::int32_t value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/util/OptionalInt;"));
    static jmethodID ofMethod = vm->GetStaticMethodID(cls.get(), "of", "(I)Ljava/util/OptionalInt;");
    return OptionalInt(vm, vm->CallStaticObjectMethod(cls.get(), ofMethod, value));
}

std::int32_t OptionalInt::orElse(std::int32_t other)
{
    static jmethodID orElseMethod = this->vm->GetMethodID(this->cls.get(), "orElse", "(I)I");
    return this->vm->CallIntMethod(this->inst.get(), orElseMethod, other);
}

std::int32_t OptionalInt::orElseGet(IntSupplier other)
{
    static jmethodID orElseGetMethod = this->vm->GetMethodID(this->cls.get(), "orElseGet", "(Ljava/util/function/IntSupplier;)I");
    return this->vm->CallIntMethod(this->inst.get(), orElseGetMethod, other.ref().get());
}

std::int32_t OptionalInt::orElseThrow(Supplier exceptionSupplier)
{
    static jmethodID orElseThrowMethod = this->vm->GetMethodID(this->cls.get(), "orElseThrow", "(Ljava/util/function/Supplier;)I");
    return this->vm->CallIntMethod(this->inst.get(), orElseThrowMethod, exceptionSupplier.ref().get());
}

String OptionalInt::toString()
{
    static jmethodID toStringMethod = this->vm->GetMethodID(this->cls.get(), "toString", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), toStringMethod));
}
