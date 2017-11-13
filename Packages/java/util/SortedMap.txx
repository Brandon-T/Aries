//
//  SortedMap.txx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "SortedMap.hxx"
//#include "Comparable.hxx"
//#include "Set.hxx"

using java::util::SortedMap;
using java::util::Comparator;
using java::util::Set;

template<typename K, typename V>
SortedMap<K, V>::SortedMap(JVM* jvm, jobject instance) : Map<K, V>(nullptr, nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/SortedMap;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename K, typename V>
Comparator<K> SortedMap<K, V>::comparator()
{
    jmethodID comparatorMethod = this->vm->GetMethodID(this->cls.get(), "comparator", "()Ljava/util/Comparator;");
    return Comparator<K>(this->vm, this->vm->CallObjectMethod(this->inst.get(), comparatorMethod));
}

template<typename K, typename V>
K SortedMap<K, V>::firstKey()
{
    jmethodID firstKeyMethod = this->vm->GetMethodID(this->cls.get(), "firstKey", "()Ljava/lang/Object;");
    return K(this->vm, this->vm->CallObjectMethod(this->inst.get(), firstKeyMethod));
}

template<typename K, typename V>
SortedMap<K, V> SortedMap<K, V>::headMap(K toKey)
{
    jmethodID headMapMethod = this->vm->GetMethodID(this->cls.get(), "headMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;");
    return SortedMap<K, V>(this->vm, this->vm->CallObjectMethod(this->inst.get(), headMapMethod, toKey.ref().get()));
}

template<typename K, typename V>
Set<K> SortedMap<K, V>::keySet()
{
    jmethodID keySetMethod = this->vm->GetMethodID(this->cls.get(), "keySet", "()Ljava/util/Set;");
    return Set<K>(this->vm, this->vm->CallObjectMethod(this->inst.get(), keySetMethod));
}

template<typename K, typename V>
K SortedMap<K, V>::lastKey()
{
    jmethodID lastKeyMethod = this->vm->GetMethodID(this->cls.get(), "lastKey", "()Ljava/lang/Object;");
    return K(this->vm, this->vm->CallObjectMethod(this->inst.get(), lastKeyMethod));
}

template<typename K, typename V>
SortedMap<K, V> SortedMap<K, V>::subMap(K fromKey, K toKey)
{
    jmethodID subMapMethod = this->vm->GetMethodID(this->cls.get(), "subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/SortedMap;");
    return SortedMap<K, V>(this->vm, this->vm->CallObjectMethod(this->inst.get(), subMapMethod, fromKey.ref().get(), toKey.ref().get()));
}

template<typename K, typename V>
SortedMap<K, V> SortedMap<K, V>::tailMap(K fromKey)
{
    jmethodID tailMap = this->vm->GetMethodID(this->cls.get(), "tailMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;");
    return SortedMap<K, V>(this->vm, this->vm->CallObjectMethod(this->inst.get(), tailMap, fromKey.ref().get()));
}
