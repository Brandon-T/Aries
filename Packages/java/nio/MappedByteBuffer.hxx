//
//  MappedByteBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef MappedByteBuffer_hxx
#define MappedByteBuffer_hxx

#include "Array.hxx"
#include "ByteBuffer.hxx"


namespace java::nio
{
    using java::nio::ByteBuffer;
    
    
    class MappedByteBuffer : public ByteBuffer
    {
    public:
        MappedByteBuffer(JVM* vm, jobject instance);
        
        MappedByteBuffer force();
        bool isLoaded();
        MappedByteBuffer load();
    };
}

#endif /* MappedByteBuffer_hxx */
