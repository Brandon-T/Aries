//
//  Set.hxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Set_hxx
#define Set_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::util
{
    using java::lang::Object;
    using java::lang::Iterable;
    using java::util::Iterator;
    
    template<typename T>
    class Set : public Collection<T>
    {
    public:
        Set(JVM* jvm);
        Set(JVM* jvm, jobject instance);
    };
    
    #include "Set.txx"
}

#endif /* Set_hxx */
