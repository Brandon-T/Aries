//
//  Throwable.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Throwable_hxx
#define Throwable_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::lang
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
        
        virtual void addSuppressed(Throwable exception);
        virtual Throwable fillInStackTrace();
        virtual Throwable getCause();
        virtual String getLocalizedMessage();
        virtual String getMessage();
        virtual Array<StackTraceElement> getStackTrace();
        virtual Array<Throwable> getSuppressed();
        virtual Throwable initCause(Throwable cause);
        virtual void printStackTrace();
        virtual void printStackTrace(PrintStream stream);
        virtual void printStackTrace(PrintWriter writer);
        virtual void setStackTrace(Array<StackTraceElement> stackTrace);
        
    protected:
        Throwable(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace);
    };
}

#endif /* Throwable_hxx */
