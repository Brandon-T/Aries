//
//  UserPrincipal.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "UserPrincipal.hxx"
#include "Object.hxx"

using java::nio::file::attribute::UserPrincipal;
using java::lang::Object;


UserPrincipal::UserPrincipal(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/UserPrincipal;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
