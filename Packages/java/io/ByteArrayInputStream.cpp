//
//  ByteArrayInputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ByteArrayInputStream.hpp"

using namespace java::io;

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jobject instance) : InputStream(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/ByteArrayInputStream;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength) : InputStream(nullptr)
{
    if (jvm && buffer)
    {
        this->vm = jvm;
        this->cls = vm->FindClass("Ljava/io/ByteArrayInputStream;");
        
        jbyteArray arr = this->vm->NewByteArray(bufferLength);
        this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "([B)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, arr));
    }
}

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength, int offset, int length) : InputStream(nullptr)
{
    if (jvm && buffer)
    {
        this->vm = jvm;
        this->cls = this->vm->FindClass("Ljava/io/ByteArrayInputStream;");
        
        jbyteArray arr = this->vm->NewByteArray(bufferLength);
        this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
        
        jmethodID constructor = this->vm->GetMethodID(this->cls, "<init>", "([BII)V");
        this->inst = this->vm->NewGlobalRef(this->vm->NewObject(this->cls, constructor, arr, offset, length));
    }
}

ByteArrayInputStream::~ByteArrayInputStream()
{

}
