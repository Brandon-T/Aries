//
//  ByteArrayInputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ByteArrayInputStream.hxx"

using java::io::ByteArrayInputStream;

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jobject instance) : InputStream(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/ByteArrayInputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength) : InputStream(nullptr)
{
    if (jvm && buffer)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, vm->FindClass("Ljava/io/ByteArrayInputStream;"));
        
        jbyteArray arr = this->vm->NewByteArray(bufferLength);
        this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([B)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, arr));
    }
}

ByteArrayInputStream::ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength, int offset, int length) : InputStream(nullptr)
{
    if (jvm && buffer)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/ByteArrayInputStream;"));
        
        jbyteArray arr = this->vm->NewByteArray(bufferLength);
        this->vm->SetByteArrayRegion(arr, 0, bufferLength, buffer);
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "([BII)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, arr, offset, length));
    }
}
