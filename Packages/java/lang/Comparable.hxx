//
//  Comparable.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Comparable_hxx
#define Comparable_hxx

#include "Object.hxx"

namespace java::lang
{
    using java::lang::Object;
    
    class Comparable : public Object
    {
    protected:
        Comparable(JVM* jvm);
        
    public:
        virtual int compareTo(Object o);
    };
}

#endif /* Comparable_hxx */
