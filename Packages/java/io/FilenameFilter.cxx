//
//  FilenameFilter.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FilenameFilter.hxx"
#include "Object.hxx"
#include "File.hxx"
#include "String.hxx"

using java::io::FilenameFilter;
using java::io::File;
using java::lang::Object;
using java::lang::String;


FilenameFilter::FilenameFilter(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FilenameFilter;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool FilenameFilter::accept(File dir, String name)
{
    static jmethodID acceptMethod = this->vm->GetMethodID(this->cls.get(), "accept", "(Ljava/io/File;Ljava/lang/String;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), acceptMethod, dir.ref().get(), name.ref().get());
}
