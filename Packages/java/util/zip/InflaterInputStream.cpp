//
//  InflaterInputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "InflaterInputStream.hpp"
#include "InputStream.hpp"
#include "Inflater.hpp"

using namespace java::util::zip;

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/zip/InflaterInputStream");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get()));
    }
}

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/zip/InflaterInputStream");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;Ljava/util/zip/Inflater;)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get(), inflater.ref().get()));
    }
}

InflaterInputStream::InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater, int size) : FilterInputStream(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/util/zip/InflaterInputStream");
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "(Ljava/io/InputStream;Ljava/util/zip/Inflater;I)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, stream.ref().get(), inflater.ref().get(), size));
    }
}
