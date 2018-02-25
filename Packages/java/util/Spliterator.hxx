//
//  Spliterator.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Spliterator_hxx
#define Spliterator_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::util::Comparator;
    
    
    template<typename T>
    class Spliterator : public Object
    {
    public:
        Spliterator(JVM* vm, jobject instance);
        
        std::int32_t characteristics();
        std::int64_t estimateSize();
        Comparator<T> getComparator();
        std::int64_t getExactSizeIfKnown();
        bool hasCharacteristics(std::int32_t characteristics);
        Spliterator<T> trySplit();
    };
    
    #include "Spliterator.txx"
}

#endif /* Spliterator_hxx */
