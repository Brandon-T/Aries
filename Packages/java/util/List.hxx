//
//  List.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef List_hxx
#define List_hxx

#include "Array.hxx"
#include "Object.hxx"
#include "Collection.hxx"
#include "Comparator.hxx"
#include "Iterator.hxx"
#include "ListIterator.hxx"
#include "Spliterator.hxx"


namespace java::util
{
    using java::lang::Object;
    using java::util::Collection;
    using java::util::Comparator;
    using java::util::Iterator;
    using java::util::ListIterator;
    using java::util::Spliterator;
    
    template<typename T>
    class List : public Collection<T>
    {
    public:
        List(JVM* vm, jobject instance);
        
        void add(std::int32_t index, T element);
        bool addAll(std::int32_t index, Collection<T> c);
        T get(std::int32_t index);
        std::int32_t indexOf(T o);
        std::int32_t lastIndexOf(T o);
        ListIterator<T> listIterator();
        ListIterator<T> listIterator(std::int32_t index);
        T remove(std::int32_t index);
        T set(std::int32_t index, T element);
        void sort(Comparator<T> c);
        Spliterator<T> spliterator();
        List subList(std::int32_t fromIndex, std::int32_t toIndex);
        
        Array<T> toArray(Array<T>& a);
    };
    
    #include "List.txx"
}

#endif /* List_hxx */
