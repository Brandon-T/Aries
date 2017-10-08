//
//  Array.hpp
//  Aries
//
//  Created by Brandon on 2017-10-08.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <vector>
#include "Object.hpp"

using namespace java::lang;

template<typename T>
class Array final : public Object
{
public:
    Array(JVM* jvm, jobject instance);
    Array(JVM* jvm, jsize length);
    virtual ~Array();
    
    /**
     Returns a primitive value.
     **/
    template<typename U = T>
    typename std::enable_if<JVMIsPrimitive<T>::value, U>::type
    get(jsize index);
    
    /**
     Returns a non-primitive value as a JVMRef.
     **/
    template<typename U = T>
    typename std::enable_if<!JVMIsPrimitive<T>::value, JVMRef<U>>::type
    get(jsize index);
    
    /**
     Sets a primitive value.
     **/
    template<typename U = T>
    void set(jsize index, typename std::enable_if<JVMIsPrimitive<T>::value, U>::type value);
    
    /**
     Sets a raw non-primitive value.
     **/
    template<typename U = T>
    void set(jsize index, typename std::enable_if<!JVMIsPrimitive<T>::value, U>::type value);
    
    /**
     Sets a non-primitive value as a JVMRef.
     **/
    template<typename U = T>
    void set(jsize index, typename std::enable_if<!JVMIsPrimitive<T>::value, JVMRef<U>>::type value);
    
    
    /**
     Returns a vector of primitive value if this array is primitive.
     Returns a vector of non-primitive value as a JVMRef if type "T" is scalar.
     Returns a vector of non-primitive value as a type T.
     **/
    typename std::conditional<JVMIsPrimitive<T>::value || !std::is_scalar<T>::value, std::vector<T>, std::vector<JVMRef<T>>>::type
    toVector();
    
    jsize length();
    
    
private:
    jarray createArray(jsize length);
    jsize arrayLength;
};


template<typename T>
Array<T>::Array(JVM* jvm, jobject instance) : Object(jvm), arrayLength(0)
{
    if (jvm)
    {
        this->arrayLength = jvm->GetArrayLength(static_cast<jarray>(instance));
        this->inst = this->vm->NewGlobalRef(instance);
    }
}

template<typename T>
Array<T>::Array(JVM* jvm, jsize length) : Object(jvm), arrayLength(length)
{
    if (jvm)
    {
        this->inst = this->createArray(this->arrayLength);
    }
}

template<typename T>
Array<T>::~Array()
{
    
}

template<typename T>
jarray Array<T>::createArray(jsize length)
{
    if constexpr (std::is_same<T, jchar>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewCharArray(length)));
    }
    else if constexpr (std::is_same<T, jboolean>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewBooleanArray(length)));
    }
    else if constexpr (std::is_same<T, jbyte>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewByteArray(length)));
    }
    else if constexpr (std::is_same<T, jshort>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewShortArray(length)));
    }
    else if constexpr (std::is_same<T, jint>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewIntArray(length)));
    }
    else if constexpr (std::is_same<T, jlong>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewLongArray(length)));
    }
    else if constexpr (std::is_same<T, jfloat>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewFloatArray(length)));
    }
    else if constexpr (std::is_same<T, jdouble>::value)
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewDoubleArray(length)));
    }
    else
    {
        return static_cast<jarray>(this->vm->NewGlobalRef(this->vm->NewObjectArray(length, this->vm->FindClass("Ljava/lang/Object;"), nullptr)));
    }
}

template<typename T>
template<typename U>
typename std::enable_if<JVMIsPrimitive<T>::value, U>::type
Array<T>::get(jsize index)
{
    if constexpr (std::is_same<T, jchar>::value)
    {
        jchar buff;
        this->vm->GetCharArrayRegion(static_cast<jcharArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jboolean>::value)
    {
        jboolean buff;
        this->vm->GetBooleanArrayRegion(static_cast<jbooleanArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jbyte>::value)
    {
        jbyte buff;
        this->vm->GetByteArrayRegion(static_cast<jbyteArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jshort>::value)
    {
        jshort buff;
        this->vm->GetShortArrayRegion(static_cast<jshortArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jint>::value)
    {
        jint buff;
        this->vm->GetIntArrayRegion(static_cast<jintArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jlong>::value)
    {
        jlong buff;
        this->vm->GetLongArrayRegion(static_cast<jlongArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jfloat>::value)
    {
        jfloat buff;
        this->vm->GetFloatArrayRegion(static_cast<jfloatArray>(this->inst), index, 1, &buff);
        return buff;
    }
    else if constexpr (std::is_same<T, jdouble>::value)
    {
        jdouble buff;
        this->vm->GetDoubleArrayRegion(static_cast<jdoubleArray>(this->inst), index, 1, &buff);
        return buff;
    }
}

template<typename T>
template<typename U>
typename std::enable_if<!JVMIsPrimitive<T>::value, JVMRef<U>>::type
Array<T>::get(jsize index)
{
    return JVMRef<jobject>{this->vm, this->vm->GetObjectArrayElement(static_cast<jobjectArray>(this->inst), index)};
}

template<typename T>
template<typename U>
void Array<T>::set(jsize index, typename std::enable_if<JVMIsPrimitive<T>::value, U>::type value)
{
    if constexpr (std::is_same<T, jchar>::value)
    {
        this->vm->SetCharArrayRegion(static_cast<jcharArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jboolean>::value)
    {
        this->vm->SetBooleanArrayRegion(static_cast<jbooleanArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jbyte>::value)
    {
        this->vm->SetByteArrayRegion(static_cast<jbyteArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jshort>::value)
    {
        this->vm->SetShortArrayRegion(static_cast<jshortArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jint>::value)
    {
        this->vm->SetIntArrayRegion(static_cast<jintArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jlong>::value)
    {
        this->vm->SetLongArrayRegion(static_cast<jlongArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jfloat>::value)
    {
        this->vm->SetFloatArrayRegion(static_cast<jfloatArray>(this->inst), index, 1, &value);
    }
    else if constexpr (std::is_same<T, jdouble>::value)
    {
        this->vm->GetDoubleArrayRegion(static_cast<jdoubleArray>(this->inst), index, 1, &value);
    }
    else
    {
        static_assert(!JVMIsPrimitive<T>::value, "Invalid Primitive Type");
    }
}

template<typename T>
template<typename U>
void Array<T>::set(jsize index, typename std::enable_if<!JVMIsPrimitive<T>::value, U>::type value)
{
    this->vm->SetObjectArrayElement(static_cast<jobjectArray>(this->inst), index, value);
}

template<typename T>
template<typename U>
void Array<T>::set(jsize index, typename std::enable_if<!JVMIsPrimitive<T>::value, JVMRef<U>>::type value)
{
    this->vm->SetObjectArrayElement(static_cast<jobjectArray>(this->inst), index, value.get());
}

template<typename T>
typename std::conditional<JVMIsPrimitive<T>::value || !std::is_scalar<T>::value, std::vector<T>, std::vector<JVMRef<T>>>::type
Array<T>::toVector()
{
    if constexpr (JVMIsPrimitive<T>::value)
    {
        if (this->inst && this->arrayLength > 0)
        {
            std::vector<T> result(this->arrayLength);
            void* ptr = this->vm->GetPrimitiveArrayCritical(static_cast<jarray>(this->inst), nullptr);
            std::memcpy(static_cast<void*>(&result[0]), ptr, sizeof(T) * result.size());
            this->vm->ReleasePrimitiveArrayCritical(static_cast<jarray>(this->inst), ptr, 0);
            return result;
        }
        return std::vector<T>();
    }
    else
    {
        using type = typename std::conditional<JVMIsPrimitive<T>::value || !std::is_scalar<T>::value, std::vector<T>, JVMRef<T>>::type;
        
        if (this->inst && this->arrayLength > 0)
        {
            std::vector<type> result(this->arrayLength);
            for (jsize i = 0; i < this->arrayLength; ++i)
            {
                jobject object = this->vm->GetObjectArrayElement(static_cast<jobjectArray>(this->inst), i);
                if constexpr (std::is_scalar<T>::value)
                {
                    result.emplace_back(JVMRef<T>{this->vm, object});
                }
                else
                {
                    result.emplace_back(T(this->vm, object));
                }
                this->vm->DeleteLocalRef(object);
            }
            return result;
        }
        return std::vector<type>();
    }
}

template<typename T>
jsize Array<T>::length()
{
    return this->arrayLength;
}

#endif /* Array_hpp */