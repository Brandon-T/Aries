//
//  Buffer.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Buffer_hxx
#define Buffer_hxx

#include "Object.hxx"

namespace java::nio
{
    using java::lang::Object;
    
    class Buffer : public virtual Object
    {
    public:
        Buffer(JVM* jvm, jobject instance);
        
        Object array();
        virtual int arrayOffset();
        virtual int capacity();
        virtual Buffer& clear();
        virtual Buffer& flip();
        virtual bool hasArray();
        virtual bool isDirect();
        virtual bool isReadOnly();
        virtual int limit();
        virtual Buffer& mark();
        virtual int position();
        virtual Buffer& position(int newPosition);
        virtual int remaining();
        virtual Buffer& reset();
        virtual Buffer& rewind();
    };
}

#endif /* Buffer_hxx */
