//
//  DoubleConsumer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef DoubleConsumer_hxx
#define DoubleConsumer_hxx

#include "Object.hxx"


namespace java::util::function
{
    using java::lang::Object;
    
    
    class DoubleConsumer : public Object
    {
    public:
        DoubleConsumer(JVM* vm, jobject instance);
        
        void accept(double value);
        DoubleConsumer andThen(DoubleConsumer after);
    };
}

#endif /* DoubleConsumer_hxx */
