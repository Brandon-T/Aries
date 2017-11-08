//
//  Exception.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Exception_hxx
#define Exception_hxx

#include "Throwable.hxx"

namespace java::lang
{
    class Exception : public Throwable
    {
    private:
        using Throwable::Throwable;
        
    public:
        Exception(JVM* jvm);
        Exception(JVM* jvm, jobject instance);
        Exception(JVM* jvm, String message);
        Exception(JVM* jvm, String message, Throwable cause);
        Exception(JVM* jvm, Throwable cause);
        
    protected:
        Exception(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace);
    };
}

#endif /* Exception_hxx */
