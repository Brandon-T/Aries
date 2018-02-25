//
//  IntStream.cxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "IntStream.hxx"

using java::util::stream::IntStream;
using java::lang::Object;

IntStream::IntStream(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/stream/IntStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}
