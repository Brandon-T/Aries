//
//  ByteArrayInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteArrayInputStream_hxx
#define ByteArrayInputStream_hxx


#include "Object.hxx"
#include "InputStream.hxx"

namespace java::io
{
    class ByteArrayInputStream : public InputStream
    {
    public:
        ByteArrayInputStream(JVM* jvm, jobject instance);
        ByteArrayInputStream(JVM* jvm, jbyte*, int bufferLength);
        ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength, int offset, int length);
    };
}

#endif /* ByteArrayInputStream_hxx */
