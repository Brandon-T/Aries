//
//  IntConsumer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef IntConsumer_hxx
#define IntConsumer_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util::function
{
    using java::lang::Object;
    
    
    class IntConsumer : public Object
    {
    public:
        IntConsumer(JVM* vm, jobject instance);
        
        void accept(std::int32_t value);
        IntConsumer andThen(IntConsumer after);
    };
}

#endif /* IntConsumer_hxx */
