//
//  IntSummaryStatistics.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef IntSummaryStatistics_hxx
#define IntSummaryStatistics_hxx

#include "Object.hxx"
#include "String.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class IntSummaryStatistics : public Object
    {
    public:
        IntSummaryStatistics(JVM* vm, jobject instance);
        IntSummaryStatistics(JVM* vm);
        
        void accept(std::int32_t value);
        void combine(IntSummaryStatistics other);
        double getAverage();
        std::int64_t getCount();
        std::int32_t getMax();
        std::int32_t getMin();
        std::int64_t getSum();
        String toString();
    };
}

#endif /* IntSummaryStatistics_hxx */
