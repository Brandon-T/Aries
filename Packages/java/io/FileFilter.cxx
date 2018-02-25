//
//  FileFilter.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileFilter.hxx"
#include "Object.hxx"
#include "File.hxx"

using java::io::FileFilter;
using java::io::File;
using java::lang::Object;


FileFilter::FileFilter(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/FileFilter;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool FileFilter::accept(File pathname)
{
    static jmethodID acceptMethod = this->vm->GetMethodID(this->cls.get(), "accept", "(Ljava/io/File;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), acceptMethod, pathname.ref().get());
}
