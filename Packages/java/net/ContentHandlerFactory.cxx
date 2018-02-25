//
//  ContentHandlerFactory.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "ContentHandlerFactory.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "ContentHandler.hxx"

using java::net::ContentHandlerFactory;
using java::lang::Object;
using java::lang::String;
using java::net::ContentHandler;


ContentHandlerFactory::ContentHandlerFactory(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/ContentHandlerFactory;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

ContentHandler ContentHandlerFactory::createContentHandler(String mimetype)
{
    static jmethodID createContentHandlerMethod = this->vm->GetMethodID(this->cls.get(), "createContentHandler", "(Ljava/lang/String;)Ljava/net/ContentHandler;");
    return ContentHandler(this->vm, this->vm->CallObjectMethod(this->inst.get(), createContentHandlerMethod, mimetype.ref().get()));
}
