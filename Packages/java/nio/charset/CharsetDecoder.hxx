//
//  CharsetDecoder.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharsetDecoder_hxx
#define CharsetDecoder_hxx

#include "Object.hxx"

namespace java::nio::charset
{
    using java::lang::Object;
    
    class CharsetDecoder : public Object
    {
    public:
        CharsetDecoder(JVM* jvm, jobject instance);
    };
}

#endif /* CharsetDecoder_hxx */
