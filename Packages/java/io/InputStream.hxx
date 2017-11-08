//
//  InputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef InputStream_hxx
#define InputStream_hxx

#include "Object.hxx"

namespace java::io
{
    using java::lang::Object;
    
    class InputStream : public Object
    {
    public:
        InputStream(JVM* jvm, jobject instance);
        
        virtual int available();
        virtual void close();
        virtual void mark(int readAheadLimit);
        virtual bool markSupported();
        virtual int read();
        virtual int read(jbyte* buffer, int off, int len);
        virtual void reset();
        virtual long skip(long n);
        
    protected:
        InputStream(JVM* jvm);
    };
}

#endif /* InputStream_hxx */
