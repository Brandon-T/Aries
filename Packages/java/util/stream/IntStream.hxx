//
//  IntStream.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef IntStream_hxx
#define IntStream_hxx

#include "Object.hxx"
#include "IntSummaryStatistics.hxx"
#include "OptionalDouble.hxx"
#include "OptionalInt.hxx"


namespace java::util::stream
{
    using java::lang::Object;
    
    class IntStream : public Object
    {
    public:
        IntStream(JVM* vm, jobject instance);
    };
}

#endif /* IntStream_hxx */
