//
//  JVMUtilities.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JVMUtilities_hpp
#define JVMUtilities_hpp

#include <functional>
#include <vector>
#include "JVM.hpp"

template<typename T>
class JVMRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    
public:
    JVMRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr)
    {
        auto deleter = [&](void* data) {
            if (data)
            {
                jvm->DeleteGlobalRef(static_cast<jobject>(data));
            }
        };
        
        if (data_ptr)
        {
            this->data = std::unique_ptr<void, std::function<void(void*)>>(jvm->NewGlobalRef(data_ptr), deleter);
        }
    }
    
    JVMRef(JVMRef &&other) : data(std::move(other.data))
    {
    }
    
    JVMRef(const JVMRef &other) = delete;
    
    typename std::remove_pointer<T>::type* get()
    {
        return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
    }
};

template<typename T>
class JVMWeakRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    
public:
    JVMWeakRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr)
    {
        auto deleter = [&](void* data) {
            if (data)
            {
                jvm->DeleteWeakGlobalRef(static_cast<jobject>(data));
            }
        };
        
        if (data_ptr)
        {
            this->data = std::unique_ptr<void, std::function<void(void*)>>(jvm->NewWeakGlobalRef(data_ptr), deleter);
        }
    }
    
    JVMWeakRef(JVMWeakRef &&other) : data(std::move(other.data))
    {
    }
    
    JVMWeakRef(const JVMWeakRef &other) = delete;
    
    typename std::remove_pointer<T>::type* get()
    {
        return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
    }
};


template<typename T>
JVMRef<jobjectArray> VectorToJVMObjectArray(JVM* jvm, jclass cls, std::vector<T> values)
{
    if (values.size())
    {
        jobjectArray array = jvm->NewObjectArray(static_cast<jint>(values.size()), cls, nullptr);
        
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            jvm->SetObjectArrayElement(array, static_cast<jint>(i), values[i].ref().get());
        }
        
        return JVMRef<jobjectArray>(jvm, array);
    }
    return JVMRef<jobjectArray>(jvm, nullptr);
}

template<typename T>
std::vector<T> JVMObjectArrayToVector(JVM* jvm, jobjectArray array)
{
    if (array)
    {
        jsize size = jvm->GetArrayLength(array);
        if (size > 0)
        {
            std::vector<T> result(size);
            for (jsize i = 0; i < size; ++i)
            {
                jobject object = jvm->GetObjectArrayElement(array, i);
                result.emplace_back(T(jvm, object));
                jvm->DeleteLocalRef(object);
            }
            return result;
        }
    }
    return std::vector<T>();
}

#endif /* JVMUtilities_hpp */
