//
//  GroupPrincipal.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "GroupPrincipal.hxx"
#include "Object.hxx"

using java::nio::file::attribute::GroupPrincipal;
using java::lang::Object;


GroupPrincipal::GroupPrincipal(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/attribute/GroupPrincipal;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
