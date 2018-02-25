//
//  Supplier.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Supplier_hxx
#define Supplier_hxx

#include "Object.hxx"


#include "Array.hxx"
#include "Object.hxx"


namespace java::util::function
{
    using java::lang::Object;
    
    
    class Supplier : public Object
    {
    public:
        Supplier(JVM* vm, jobject instance);
        
        Object get();
    };
}

#endif /* Supplier_hxx */
