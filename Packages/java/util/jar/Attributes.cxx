//
//  Attributes.cxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Attributes.hxx"

using java::util::jar::Attributes;

Attributes::Attributes(JVM* jvm) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Attributes;"));
        jmethodID constructor = jvm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

Attributes::Attributes(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Attributes;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Attributes::Attributes(JVM* jvm, Attributes attr) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Attributes;"));
        jmethodID constructor = jvm->GetMethodID(this->cls.get(), "<init>", "(Ljava/util/jar/Attributes;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, attr.ref().get()));
    }
}

Attributes::Attributes(JVM* jvm, int size) : Object()
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("java/util/jar/Attributes;"));
        jmethodID constructor = jvm->GetMethodID(this->cls.get(), "<init>", "(I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, size));
    }
}
