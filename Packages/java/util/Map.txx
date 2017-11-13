//
//  Map.txx
//  Aries
//
//  Created by Brandon on 2017-11-07.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "Map.hxx"

using java::lang::Object;
using java::util::Map;
using java::util::Set;
using java::util::Collection;

template<typename K, typename V>
Map<K, V>::Map(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/util/Map;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

template<typename K, typename V>
void Map<K, V>::clear()
{
    jmethodID clearMethod = this->vm->GetMethodID(this->cls.get(), "clear", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearMethod);
}

template<typename K, typename V>
bool Map<K, V>::containsKey(Object key)
{
    jmethodID containsKeyMethod = this->vm->GetMethodID(this->cls.get(), "containsKey", "(java/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsKeyMethod, key.ref().get());
}

template<typename K, typename V>
bool Map<K, V>::containsValue(Object value)
{
    jmethodID containsValueMethod = this->vm->GetMethodID(this->cls.get(), "containsValue", "(java/lang/Object;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsValueMethod, value.ref().get());
}

template<typename K, typename V>
Set<typename Map<K, V>::Entry> Map<K, V>::entrySet()
{
    jmethodID entrySetMethod = this->vm->GetMethodID(this->cls.get(), "entrySet", "()Ljava/util/Set;");
    return Set<typename Map<K, V>::Entry>(this->vm, this->vm->CallObjectMethod(this->inst.get(), entrySetMethod));
}

template<typename K, typename V>
V Map<K, V>::get(Object key)
{
    jmethodID getMethod = this->vm->GetMethodID(this->cls.get(), "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return V(this->vm, this->vm->CallObjectMethod(this->inst.get(), getMethod, key.ref().get()));
}

template<typename K, typename V>
bool Map<K, V>::isEmpty()
{
    jmethodID isEmptyMethod = this->vm->GetMethodID(this->cls.get(), "isEmpty", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isEmptyMethod);
}

template<typename K, typename V>
Set<K> Map<K, V>::keySet()
{
    jmethodID keySetMethod = this->vm->GetMethodID(this->cls.get(), "keySet", "()Ljava/util/Set;");
    return Set<K>(this->vm, this->vm->CallObjectMethod(this->inst.get(), keySetMethod));
}

template<typename K, typename V>
V Map<K, V>::put(K key, V value)
{
    jmethodID putMethod = this->vm->GetMethodID(this->cls.get(), "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    return V(this->vm, this->vm->CallObjectMethod(this->inst.get(), putMethod, key.ref().get(), value.ref().get()));
}

template<typename K, typename V>
void Map<K, V>::putAll(Map<K, V> m)
{
    jmethodID putAllMethod = this->vm->GetMethodID(this->cls.get(), "putAll", "(Ljava/util/Map)V");
    this->vm->CallVoidMethod(this->inst.get(), putAllMethod, m.ref().get());
}

template<typename K, typename V>
V Map<K, V>::remove(Object key)
{
    jmethodID removeMethod = this->vm->GetMethodID(this->cls.get(), "remove", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return V(this->vm, this->vm->CallObjectMethod(this->inst.get(), removeMethod, key.ref().get()));
}

template<typename K, typename V>
int Map<K, V>::size()
{
    jmethodID sizeMethod = this->vm->GetMethodID(this->cls.get(), "size", "()I");
    return this->vm->CallIntMethod(this->inst.get(), sizeMethod);
}

template<typename K, typename V>
Collection<V> Map<K, V>::values()
{
    jmethodID valuesMethod = this->vm->GetMethodID(this->cls.get(), "values", "()Ljava/util/Collection;");
    return Collection<V>(this->vm, this->vm->CallObjectMethod(this->inst.get(), valuesMethod));
}





template<typename K, typename V>
Map<K, V>::Entry::Entry(JVM* jvm, jobject instance) : Object()
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->inst = instance;
        this->cls = this->vm->FindClass("Ljava/util/Map$Entry;");
    }
}

template<typename K, typename V>
K Map<K, V>::Entry::getKey()
{
    jmethodID getKeyMethod = this->vm->GetMethodID(this->cls.get(), "getKey", "()Ljava/lang/Object;");
    return K(this->vm, this->vm->CallObjectMethod(this->inst.get(), getKeyMethod));
}

template<typename K, typename V>
V Map<K, V>::Entry::getValue()
{
    jmethodID getValueMethod = this->vm->GetMethodID(this->cls.get(), "getValue", "()Ljava/lang/Object;");
    return V(this->vm, this->vm->CallObjectMethod(this->inst.get(), getValueMethod));
}

template<typename K, typename V>
V Map<K, V>::Entry::setValue(V value)
{
    jmethodID setValueMethod = this->vm->GetMethodID(this->cls.get(), "setValue", "(Ljava/lang/Object;)Ljava/lang/Object;");
    return V(this->vm, this->vm->CallObjectMethod(this->inst.get(), setValueMethod));
}
