//
//  Appendable.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "Appendable.hxx"
#include "Object.hxx"
#include "CharSequence.hxx"

using java::lang::Appendable;
using java::lang::CharSequence;
using java::lang::Object;


Appendable::Appendable(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/Appendable;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Appendable Appendable::append(CharSequence csq)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/lang/Appendable;");
    return Appendable(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get()));
}

Appendable Appendable::append(CharSequence csq, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/lang/Appendable;");
    return Appendable(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get(), start, end));
}

Appendable Appendable::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/lang/Appendable;");
    return Appendable(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}
