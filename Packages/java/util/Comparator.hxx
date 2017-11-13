//
//  Comparator.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Comparator_hxx
#define Comparator_hxx

#include "Object.hxx"

namespace java::util
{
    using java::lang::Object;
    
    template<typename T = Object>
    class Comparator : public Object
    {
    public:
        Comparator(JVM* jvm, jobject instance);
        
        virtual int compare(T o1, T o2);
        virtual bool equals(Object obj);
    };
    
    #include "Comparator.txx"
}

#endif /* Comparator_hxx */
