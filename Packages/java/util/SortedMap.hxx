//
//  SortedMap.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef SortedMap_hxx
#define SortedMap_hxx

#include "Object.hxx"
#include "Map.hxx"

namespace java::util
{
    using java::lang::Object;
    using java::util::Map;
    using java::util::Comparator;
    
    template<typename K = Object, typename V = Object>
    class SortedMap : public Map<K, V>
    {
    public:
        SortedMap(JVM* jvm, jobject instance);
        
        Comparator<K> comparator();
        K firstKey();
        SortedMap<K, V> headMap(K toKey);
        Set<K> keySet();
        K lastKey();
        SortedMap<K, V> subMap(K fromKey, K toKey);
        SortedMap<K, V> tailMap(K fromKey);
    };
    
    #include "SortedMap.txx"
}

#endif /* SortedMap_hxx */
