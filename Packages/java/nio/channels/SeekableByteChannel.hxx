//
//  SeekableByteChannel.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef SeekableByteChannel_hxx
#define SeekableByteChannel_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::channels
{
    using java::lang::Object;
    using java::nio::ByteBuffer;
    
    
    class SeekableByteChannel : public Object
    {
    public:
        SeekableByteChannel(JVM* vm, jobject instance);
        
        std::int64_t position();
        SeekableByteChannel position(std::int64_t newPosition);
        std::int32_t read(ByteBuffer dst);
        std::int64_t size();
        SeekableByteChannel truncate(std::int64_t size);
        std::int32_t write(ByteBuffer src);
    };
}

#endif /* SeekableByteChannel_hxx */
