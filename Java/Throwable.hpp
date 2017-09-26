//
//  Throwable.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Throwable_hpp
#define Throwable_hpp

#include "Object.hpp"
#include <vector>

namespace java
{
    namespace lang
    {
        using java::lang::String;
        using java::lang::StackTraceElement;
        using java::io::PrintStream;
        using java::io::PrintWriter;
        
        class Throwable : public Object
        {
        private:
            using Object::Object;
            
        public:
            Throwable(JVM* jvm);
            Throwable(JVM* jvm, jobject instance);
            Throwable(JVM* jvm, String message);
            Throwable(JVM* jvm, String message, Throwable cause);
            Throwable(JVM* jvm, Throwable cause);
            virtual ~Throwable();
            
            virtual void addSuppressed(Throwable exception);
            virtual Throwable fillInStackTrace();
            virtual Throwable getCause();
            virtual String getLocalizedMessage();
            virtual String getMessage();
            virtual std::vector<StackTraceElement> getStackTrace();
            virtual std::vector<Throwable> getSuppressed();
            virtual Throwable initCause(Throwable cause);
            virtual void printStackTrace();
            virtual void printStackTrace(PrintStream stream);
            virtual void printStackTrace(PrintWriter writer);
            virtual void setStackTrace(std::vector<StackTraceElement> stackTrace);
            
        protected:
            Throwable(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace);
        };
    }
}

#endif /* Throwable_hpp */
