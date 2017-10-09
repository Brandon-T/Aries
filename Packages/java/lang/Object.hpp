//
//  Object.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <jni.h>
#include "JVM.hpp"
#include "JVMUtilities.hpp"
#include "JNIPackage.hpp"

namespace java
{
    namespace lang
    {
        using java::lang::Class;
        using java::lang::String;
        
        class Object
        {
        protected:
            jclass cls;
            jobject inst;
            JVM* vm;
            
        public:
            Object();
            Object(JVM* jvm);
            Object(JVM* jvm, jobject instance);
            Object(const Object &other);
            Object(Object &&other);
            virtual ~Object();
            
            JVMWeakRef<jobject> ref();
            
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
}

#endif /* Object_hpp */
