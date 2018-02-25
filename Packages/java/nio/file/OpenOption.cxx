//
//  OpenOption.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "OpenOption.hxx"
#include "Object.hxx"

using java::nio::file::OpenOption;
using java::lang::Object;


OpenOption::OpenOption(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/OpenOption;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
