//
//  Iterator.hxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Iterator_hxx
#define Iterator_hxx

#include "Object.hxx"

namespace java::lang
{
    template<typename T = Object>
    class Iterator : Object
    {
    public:
        Iterator(JVM* jvm, jobject instance);
        
        bool hasNext();
        T next();
        void remove();
    };
    
    #include "Iterator.txx"
}

#endif /* Iterator_hxx */
