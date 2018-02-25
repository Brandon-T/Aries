//
//  ListIterator.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef ListIterator_hxx
#define ListIterator_hxx

#include "Array.hxx"
#include "Iterator.hxx"


namespace java::util
{
    using java::lang::Iterator;
    
    template<typename T>
    class ListIterator : public Iterator<T>
    {
    public:
        ListIterator(JVM* vm, jobject instance);
        
        void add(T e);
        bool hasNext();
        bool hasPrevious();
        T next();
        std::int32_t nextIndex();
        T previous();
        std::int32_t previousIndex();
        void remove();
        void set(T e);
    };
    
    #include "ListIterator.txx"
}

#endif /* ListIterator_hxx */
