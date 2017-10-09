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
class JVMRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    
public:
    JVMRef() {}
    
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
    
    
    JVMWeakRef<T> weakRef(JVM* jvm)
    {
        return JVMWeakRef<T>(jvm, this->get());
    }
    
    typename std::remove_pointer<T>::type* get()
    {
        return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
    }
};


template<typename T>
struct JVMIsPrimitive : public std::integral_constant<bool, std::is_same<T, jboolean>::value ||
                                                            std::is_same<T, jchar>::value ||
                                                            std::is_same<T, jbyte>::value ||
                                                            std::is_same<T, jshort>::value ||
                                                            std::is_same<T, jint>::value ||
                                                            std::is_same<T, jlong>::value ||
                                                            std::is_same<T, jfloat>::value ||
                                                            std::is_same<T, jdouble>::value ||
                                                            std::is_same<T, jsize>::value ||
                                                            std::is_fundamental<T>::value>
{};

template<typename T>
typename std::enable_if<!JVMIsPrimitive<T>::value, JVMRef<jarray>>::type
VectorToJVMArray(JVM* jvm, jclass cls, std::vector<T> values)
{
    if (values.size())
    {
        jobjectArray array = jvm->NewObjectArray(static_cast<jint>(values.size()), cls, nullptr);
        
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            jvm->SetObjectArrayElement(array, static_cast<jint>(i), values[i].ref().get());
        }
        
        return JVMRef<jarray>(jvm, array);
    }
    return JVMRef<jarray>(jvm, nullptr);
}

template<typename T>
typename std::enable_if<JVMIsPrimitive<T>::value, JVMRef<jarray>>::type
VectorToJVMArray(JVM* jvm, jclass cls, std::vector<T> values)
{
    if (values.size())
    {
        if constexpr (std::is_same<T, jchar>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewCharArray(length);
            jvm->SetCharArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jboolean>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewBooleanArray(length);
            jvm->SetBooleanArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jbyte>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewByteArray(length);
            jvm->SetByteArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jshort>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewShortArray(length);
            jvm->SetShortArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jint>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewIntArray(length);
            jvm->SetIntArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jlong>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewLongArray(length);
            jvm->SetLongArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jfloat>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewFloatArray(length);
            jvm->SetFloatArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
        else if constexpr (std::is_same<T, jdouble>::value)
        {
            jint length = values.size();
            jarray array = jvm->NewDoubleArray(length);
            jvm->SetDoubleArrayRegion(array, 0, length, &values[0]);
            return JVMRef<jarray>(jvm, array);
        }
    }
    return JVMRef<jarray>(jvm, nullptr);
}

template<typename T>
typename std::enable_if<!JVMIsPrimitive<T>::value, std::vector<T>>::type
JVMArrayToVector(JVM* jvm, jarray array)
{
    if (array)
    {
        jsize size = jvm->GetArrayLength(array);
        if (size > 0)
        {
            std::vector<T> result(size);
            for (jsize i = 0; i < size; ++i)
            {
                jobject object = jvm->GetObjectArrayElement(static_cast<jobjectArray>(array), i);
                result.emplace_back(T(jvm, object));
                jvm->DeleteLocalRef(object);
            }
            return result;
        }
    }
    return std::vector<T>();
}

template<typename T>
typename std::enable_if<JVMIsPrimitive<T>::value, std::vector<T>>::type
JVMArrayToVector(JVM* jvm, jarray array)
{
    if (array)
    {
        jsize size = jvm->GetArrayLength(array);
        if (size > 0)
        {
            std::vector<T> result(size);
            
            void* ptr = jvm->GetPrimitiveArrayCritical(array, nullptr);
            std::memcpy(static_cast<void*>(&result[0]), ptr, sizeof(T) * result.size());
            jvm->ReleasePrimitiveArrayCritical(array, ptr, 0);
            return result;
        }
    }
    return std::vector<T>();
}

#endif /* JVMUtilities_hpp */
