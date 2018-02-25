//
//  OptionalInt.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef OptionalInt_hxx
#define OptionalInt_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::lang::String;
    using java::util::function::IntConsumer;
    using java::util::function::IntSupplier;
    using java::util::function::Supplier;
    
    
    class OptionalInt : public Object
    {
    public:
        OptionalInt(JVM* vm, jobject instance);
        
        static OptionalInt empty(JVM* vm);
        bool equals(Object obj);
        std::int32_t getAsInt();
        std::int32_t hashCode();
        void ifPresent(IntConsumer consumer);
        bool isPresent();
        static OptionalInt of(JVM* vm, std::int32_t value);
        std::int32_t orElse(std::int32_t other);
        std::int32_t orElseGet(IntSupplier other);
        std::int32_t orElseThrow(Supplier exceptionSupplier);
        String toString();
    };
}

#endif /* OptionalInt_hxx */
