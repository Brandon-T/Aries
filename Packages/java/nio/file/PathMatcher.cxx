//
//  PathMatcher.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "PathMatcher.hxx"
#include "Object.hxx"
#include "Path.hxx"

using java::nio::file::PathMatcher;
using java::lang::Object;
using java::nio::file::Path;


PathMatcher::PathMatcher(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/file/PathMatcher;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

bool PathMatcher::matches(Path path)
{
    static jmethodID matchesMethod = this->vm->GetMethodID(this->cls.get(), "matches", "(Ljava/nio/file/Path;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), matchesMethod, path.ref().get());
}
