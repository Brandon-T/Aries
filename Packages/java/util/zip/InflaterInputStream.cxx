//
//  InflaterInputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "InflaterInputStream.hxx"
#include "InputStream.hxx"
#include "Inflater.hxx"

using java::util::zip::InflaterInputStream;

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/InflaterInputStream"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get()));
    }
}

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/InflaterInputStream"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;Ljava/util/zip/Inflater;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get(), inflater.ref().get()));
    }
}

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater, int size) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/zip/InflaterInputStream"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/InputStream;Ljava/util/zip/Inflater;I)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, stream.ref().get(), inflater.ref().get(), size));
    }
}
