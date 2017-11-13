//
//  ByteBuffer.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteBuffer_hxx
#define ByteBuffer_hxx

#include "Object.hxx"
#include "Buffer.hxx"

namespace java::nio
{
    using java::nio::Buffer;
    
    class ByteBuffer : public Buffer
    {
    public:
        ByteBuffer(JVM* jvm, jobject instance);
    };
}

#endif /* ByteBuffer_hxx */
