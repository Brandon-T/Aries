//
//  Collection.hxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Collection_hxx
#define Collection_hxx

#include "Object.hxx"
#include "Array.hxx"
#include "Iterable.hxx"
#include "Spliterator.hxx"

namespace java::util
{
    using java::lang::Object;
    using java::lang::Iterable;
    using java::util::Iterator;
    using java::util::Spliterator;
    
    template<typename T>
    class Collection : public Iterable<T>
    {
    public:
        Collection(JVM* jvm, jobject instance);
        
        virtual bool add(T e);
        virtual bool addAll(Collection<T> c);
        virtual void clear();
        virtual bool contains(Object o);
        virtual bool containsAll(Collection<T> c);
        virtual bool isEmpty();
        virtual Iterator<T> iterator();
        virtual bool remove(Object o);
        virtual bool removeAll(Collection<T> c);
        virtual bool retainAll(Collection<T> c);
        virtual int size();
        virtual Spliterator<T> spliterator();
        virtual Array<Object> toArray();
        virtual Array<T> toArray(Array<T> a);
    };
    
    #include "Collection.txx"
}

#endif /* Collection_hxx */
