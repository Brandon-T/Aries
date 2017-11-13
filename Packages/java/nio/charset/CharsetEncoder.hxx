//
//  CharsetEncoder.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharsetEncoder_hxx
#define CharsetEncoder_hxx

#include "Object.hxx"

namespace java::nio::charset
{
    using java::lang::Object;
    
    class CharsetEncoder : public Object
    {
    public:
        CharsetEncoder(JVM* jvm, jobject instance);
    };
}

#endif /* CharsetEncoder_hxx */
