//
//  ByteArrayOutputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteArrayOutputStream_hxx
#define ByteArrayOutputStream_hxx

#include "OutputStream.hxx"
#include "Array.hxx"

namespace java::io
{
    class ByteArrayOutputStream : public OutputStream
    {
    public:
        ByteArrayOutputStream(JVM* jvm);
        ByteArrayOutputStream(JVM* jvm, jobject instance);
        ByteArrayOutputStream(JVM* jvm, jint size);
        
        virtual void reset();
        virtual int size();
        virtual Array<jbyte> toByteArray();
        virtual void writeTo(OutputStream out);
    };
}

#endif /* ByteArrayOutputStream_hxx */
