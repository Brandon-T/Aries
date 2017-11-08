//
//  StackTraceElement.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef StackTraceElement_hxx
#define StackTraceElement_hxx

#include "Object.hxx"

namespace java::lang
{
    class StackTraceElement : public Object
    {
    private:
        using Object::Object;
        
    public:
        StackTraceElement(JVM* jvm);
        StackTraceElement(JVM* jvm, jobject instance);
        
        virtual String getClassName();
        virtual String getFileName();
        virtual int getLineNumber();
        virtual String getMethodName();
        virtual bool isNativeMethod();
    };
}

#endif /* StackTraceElement_hxx */
