//
//  LinkOption.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "LinkOption.hxx"
#include "Enum.hxx"
#include "String.hxx"

using java::nio::file::LinkOption;
using java::lang::Enum;
using java::lang::String;


LinkOption::LinkOption(JVM* vm, jobject instance) : Enum()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/LinkOption;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

LinkOption LinkOption::valueOf(JVM* vm, String value)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/file/LinkOption;"));
    static jmethodID valueOfMethod = vm->GetStaticMethodID(cls.get(), "valueOf", "(Ljava/lang/String;)Ljava/nio/file/LinkOption;");
    return LinkOption(vm, vm->CallStaticObjectMethod(cls.get(), valueOfMethod, value.ref().get()));
}

Array<LinkOption> LinkOption::values(JVM* vm)
{
    static JVMRef<jclass> cls = JVMRef<jclass>(vm, vm->FindClass("Ljava/nio/file/LinkOption;"));
    static jmethodID valuesMethod = vm->GetStaticMethodID(cls.get(), "values", "()[Ljava/nio/file/LinkOption;");
    jarray arr = reinterpret_cast<jarray>(vm->CallStaticObjectMethod(cls.get(), valuesMethod));
    return Array<LinkOption>(vm, arr);
}
