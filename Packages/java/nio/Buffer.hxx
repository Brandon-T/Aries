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
    
    class Buffer : public Object
    {
    public:
        Buffer(JVM* jvm, jobject instance);
    };
}

#endif /* Buffer_hxx */
