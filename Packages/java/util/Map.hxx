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

namespace java::util
{
    using java::lang::Object;
    using java::util::Set;
    
    template<typename K = Object, typename V = Object>
    class Map : Object
    {
    private:
        class Entry;
        
    public:
        Map(JVM* jvm, jobject instance);
        
        
        void clear();
        bool containsKey(Object key);
        bool containsValue(Object value);
        
        Set<Map<K, V>::Entry> entrySet();
        V get(Object key);
        bool isEmpty();
        
        Set<K> keySet();
        V put(K key, V value);
        void putAll(Map<K, V> m);
        V remove(Object key);
        int size();
        Collection<V> values();
        
        
    private:
        class Entry : Object
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
