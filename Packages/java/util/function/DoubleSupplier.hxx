//
//  DoubleSupplier.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef DoubleSupplier_hxx
#define DoubleSupplier_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util::function
{
    using java::lang::Object;
    
    
    class DoubleSupplier : public Object
    {
    public:
        DoubleSupplier(JVM* vm, jobject instance);
        
        double getAsDouble();
    };
}

#endif /* DoubleSupplier_hxx */
