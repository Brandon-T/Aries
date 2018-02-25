//
//  Enumeration.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Enumeration_hxx
#define Enumeration_hxx

#include "Object.hxx"

namespace java::util
{
    using java::lang::Object;
    
    
    template<typename T = Object>
    class Enumeration : public Object
    {
    public:
        Enumeration(JVM* vm, jobject instance);
        
        bool hasMoreElements();
        T nextElement();
    };
    
    #include "Enumeration.txx"
}

#endif /* Enumeration_hxx */
