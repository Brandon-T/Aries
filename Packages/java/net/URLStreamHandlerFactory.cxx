//
//  URLStreamHandlerFactory.cxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#include "URLStreamHandlerFactory.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "URLStreamHandler.hxx"

using java::net::URLStreamHandlerFactory;
using java::lang::Object;
using java::lang::String;
using java::net::URLStreamHandler;


URLStreamHandlerFactory::URLStreamHandlerFactory(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/net/URLStreamHandlerFactory;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

URLStreamHandler URLStreamHandlerFactory::createURLStreamHandler(String protocol)
{
    static jmethodID createURLStreamHandlerMethod = this->vm->GetMethodID(this->cls.get(), "createURLStreamHandler", "(Ljava/lang/String;)Ljava/net/URLStreamHandler;");
    return URLStreamHandler(this->vm, this->vm->CallObjectMethod(this->inst.get(), createURLStreamHandlerMethod, protocol.ref().get()));
}
