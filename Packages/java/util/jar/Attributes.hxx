//
//  Attributes.hxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Attributes_hxx
#define Attributes_hxx

#include "Object.hxx"

namespace java::util::jar
{
    using java::lang::Object;
    
    class Attributes : public Object
    {
    public:
        Attributes(JVM* jvm);
        Attributes(JVM* jvm, jobject instance);
        Attributes(JVM* jvm, Attributes attr);
        Attributes(JVM* jvm, int size);
    };
}

#endif /* Attributes_hxx */
