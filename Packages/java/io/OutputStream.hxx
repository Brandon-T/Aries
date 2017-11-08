//
//  OutputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef OutputStream_hxx
#define OutputStream_hxx

#include "Object.hxx"

namespace java::io
{
    using java::lang::Object;
    
    class OutputStream : public Object
    {
    public:
        virtual void close();
        virtual void flush();
        virtual void write(jbyte* buffer, int bufferLength);
        virtual void write(jbyte* buffer, int bufferLength, int off, int len);
        virtual void write(int b) = 0;
        
    protected:
        OutputStream(JVM* jvm);
        OutputStream(JVM* jvm, jobject instance);
    };
}

#endif /* OutputStream_hxx */
