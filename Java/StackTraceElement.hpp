//
//  StackTraceElement.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef StackTraceElement_hpp
#define StackTraceElement_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        class StackTraceElement : public Object
        {
        private:
            using Object::Object;
            
        public:
            StackTraceElement(JVM* jvm);
            StackTraceElement(JVM* jvm, jobject instance);
            StackTraceElement(const Object &other);
            virtual ~StackTraceElement();
            
            virtual String getClassName();
            virtual String getFileName();
            virtual int getLineNumber();
            virtual String getMethodName();
            virtual bool isNativeMethod();
        };
    }
}

#endif /* StackTraceElement_hpp */
