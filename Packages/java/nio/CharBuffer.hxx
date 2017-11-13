//
//  CharBuffer.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharBuffer_hxx
#define CharBuffer_hxx

#include "Object.hxx"
#include "Buffer.hxx"

namespace java::nio
{
    using java::nio::Buffer;
    
    class CharBuffer : public Buffer
    {
    public:
        CharBuffer(JVM* jvm, jobject instance);
    };
}

#endif /* CharBuffer_hxx */
