//
//  ContentHandler.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "ContentHandler.hxx"
#include "Object.hxx"
#include "Class.hxx"
#include "Object.hxx"
#include "URLConnection.hxx"

using java::net::ContentHandler;
using java::lang::Class;
using java::lang::Object;
using java::net::URLConnection;


ContentHandler::ContentHandler(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/ContentHandler;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ContentHandler::ContentHandler(JVM* vm) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/ContentHandler;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "()V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor));
    }
}

Object ContentHandler::getContent(URLConnection urlc)
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "(Ljava/net/URLConnection;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod, urlc.ref().get()));
}

Object ContentHandler::getContent(URLConnection urlc, Array<Class>& classes)
{
    static jmethodID getContentMethod = this->vm->GetMethodID(this->cls.get(), "getContent", "(Ljava/net/URLConnection;[Ljava/lang/Class;)Ljava/lang/Object;");
    return Object(this->vm, this->vm->CallObjectMethod(this->inst.get(), getContentMethod, urlc.ref().get(), classes.ref().get()));
}
