//
//  Map.hxx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Map_hxx
#define Map_hxx

#include "Object.hxx"
#include "Set.hxx"

namespace java::util
{
    using java::lang::Object;
    using java::util::Set;
    
    template<typename K = Object, typename V = Object>
    class Map : public Object
    {
    protected:
        class Entry;
        
    public:
        Map(JVM* jvm, jobject instance);
        
        
        virtual void clear();
        virtual bool containsKey(Object key);
        virtual bool containsValue(Object value);
        
        virtual Set<Map<K, V>::Entry> entrySet();
        virtual V get(Object key);
        virtual bool isEmpty();
        
        virtual Set<K> keySet();
        virtual V put(K key, V value);
        virtual void putAll(Map<K, V> m);
        virtual V remove(Object key);
        virtual int size();
        virtual Collection<V> values();
        
        
    protected:
        class Entry : public Object
        {
        public:
            Entry(JVM* jvm, jobject instance);
            
            K getKey();
            V getValue();
            
            virtual int hashCode();
            V setValue(V value);
        };
    };
    
    #include "Map.txx"
}

#endif /* Map_hxx */
