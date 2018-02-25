//
//  OptionalDouble.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef OptionalDouble_hxx
#define OptionalDouble_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::lang::String;
    using java::util::function::DoubleConsumer;
    using java::util::function::DoubleSupplier;
    using java::util::function::Supplier;
    
    
    class OptionalDouble : public Object
    {
    public:
        OptionalDouble(JVM* vm, jobject instance);
        
        static OptionalDouble empty(JVM* vm);
        bool equals(Object obj);
        double getAsDouble();
        std::int32_t hashCode();
        void ifPresent(DoubleConsumer consumer);
        bool isPresent();
        static OptionalDouble of(JVM* vm, double value);
        double orElse(double other);
        double orElseGet(DoubleSupplier other);
        double orElseThrow(Supplier exceptionSupplier);
        String toString();
    };
}

#endif /* OptionalDouble_hxx */
