//
//  InputStream.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "InputStream.hpp"

using namespace java::io;

InputStream::InputStream(JVM* jvm) : Object()
{

}

InputStream::InputStream(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = static_cast<jclass>(this->vm->NewGlobalRef(this->vm->FindClass("Ljava/lang/InputStream;")));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

InputStream::~InputStream()
{
    
}

int InputStream::available()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "available", "()I");
    return this->vm->CallIntMethod(this->inst, method);
}

void InputStream::close()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "close", "()V");
    this->vm->CallVoidMethod(this->inst, method);
}

void InputStream::mark(int readAheadLimit)
{
    jmethodID method = this->vm->GetMethodID(this->cls, "mark", "(I)V");
    this->vm->CallVoidMethod(this->inst, method, readAheadLimit);
}

bool InputStream::markSupported()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "markSupported", "()Z");
    return this->vm->CallBooleanMethod(this->inst, method);
}

int	InputStream::read()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "read", "()I");
    return this->vm->CallIntMethod(this->inst, method);
}

int	InputStream::read(jbyte* buffer, int off, int len)
{
    jbyteArray arr = this->vm->NewByteArray(len);
    jmethodID method = this->vm->GetMethodID(this->cls, "read", "([BII)I");
    jint result = this->vm->CallIntMethod(this->inst, method, arr, off, len);
    
    jsize arrSize = this->vm->GetArrayLength(arr);
    jbyte* jbytes = reinterpret_cast<jbyte*>(this->vm->GetPrimitiveArrayCritical(arr, nullptr));
    
    memcpy(buffer, jbytes, arrSize * sizeof(jbyte));
    
    this->vm->ReleasePrimitiveArrayCritical(arr, reinterpret_cast<void*>(jbytes), 0);
    return result;
}

void InputStream::reset()
{
    jmethodID method = this->vm->GetMethodID(this->cls, "reset", "()V");
    this->vm->CallVoidMethod(this->inst, method);
}

long InputStream::skip(long n)
{
    jmethodID method = this->vm->GetMethodID(this->cls, "skip", "(J)J");
    return this->vm->CallLongMethod(this->inst, method);
}
