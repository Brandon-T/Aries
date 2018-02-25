//
//  IntSupplier.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef IntSupplier_hxx
#define IntSupplier_hxx

#include "Object.hxx"


namespace java::util::function
{
    using java::lang::Object;
    
    
    class IntSupplier : public Object
    {
    public:
        IntSupplier(JVM* vm, jobject instance);
        
        std::int32_t getAsInt();
    };
}

#endif /* IntSupplier_hxx */
