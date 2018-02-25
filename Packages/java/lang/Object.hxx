//
//  Object.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Object_hxx
#define Object_hxx

#include <jni.h>
#include "JVM.hxx"
#include "JVMUtilities.hxx"
#include "JNIPackage.hxx"

namespace java::lang
{
    using java::lang::Class;
    using java::lang::String;
    
    class Object
    {
    protected:
        JVMRef<jclass> cls;
        JVMRef<jobject> inst;
        JVM* vm;
        
    public:
        Object();
        Object(JVM* jvm);
        Object(JVM* jvm, jobject instance);
        Object(const Object &other);
        Object(Object &&other);
        virtual ~Object();
        
        JVMWeakRef<jobject> ref();
        JVMWeakRef<jobject> ref() const;
        
        virtual bool equals(Object obj);
        virtual Class getClass() final;
        virtual int hashCode();
        virtual void notify() final;
        virtual void notifyAll() final;
        virtual String toString();
        virtual void wait() final;
        virtual void wait(jlong timeout) final;
        virtual void wait(jlong timeout, jint nanos) final;
        
    protected:
        virtual Object* clone();
        virtual void finalize();
    };
}

#endif /* Object_hxx */
