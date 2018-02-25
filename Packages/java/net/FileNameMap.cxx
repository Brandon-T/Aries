//
//  FileNameMap.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "FileNameMap.hxx"
#include "Object.hxx"
#include "String.hxx"

using java::net::FileNameMap;
using java::lang::Object;
using java::lang::String;


FileNameMap::FileNameMap(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/FileNameMap;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

String FileNameMap::getContentTypeFor(String fileName)
{
    static jmethodID getContentTypeForMethod = this->vm->GetMethodID(this->cls.get(), "getContentTypeFor", "(Ljava/lang/String;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentTypeForMethod, fileName.ref().get()));
}
