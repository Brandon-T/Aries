//
//  InputStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "InputStream.hxx"

using java::io::InputStream;

InputStream::InputStream(JVM* jvm) : Object()
{

}

InputStream::InputStream(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/lang/InputStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

int InputStream::available()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "available", "()I");
    return this->vm->CallIntMethod(this->inst.get(), method);
}

void InputStream::close()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), method);
}

void InputStream::mark(int readAheadLimit)
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "mark", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), method, readAheadLimit);
}

bool InputStream::markSupported()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "markSupported", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), method);
}

int	InputStream::read()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "read", "()I");
    return this->vm->CallIntMethod(this->inst.get(), method);
}

int	InputStream::read(jbyte* buffer, int off, int len)
{
    jbyteArray arr = this->vm->NewByteArray(len);
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "read", "([BII)I");
    jint result = this->vm->CallIntMethod(this->inst.get(), method, arr, off, len);
    
    jsize arrSize = this->vm->GetArrayLength(arr);
    jbyte* jbytes = reinterpret_cast<jbyte*>(this->vm->GetPrimitiveArrayCritical(arr, nullptr));
    
    memcpy(buffer, jbytes, arrSize * sizeof(jbyte));
    
    this->vm->ReleasePrimitiveArrayCritical(arr, reinterpret_cast<void*>(jbytes), 0);
    return result;
}

void InputStream::reset()
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "reset", "()V");
    this->vm->CallVoidMethod(this->inst.get(), method);
}

long InputStream::skip(long n)
{
    jmethodID method = this->vm->GetMethodID(this->cls.get(), "skip", "(J)J");
    return this->vm->CallLongMethod(this->inst.get(), method);
}
