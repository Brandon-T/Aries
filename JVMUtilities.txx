//
//  JVMUtilities.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

//#include "JVMUtilities.hxx"

template<typename T>
JVMWeakRef<T>::JVMWeakRef()
{
    
}

template<typename T>
JVMWeakRef<T>::JVMWeakRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr)
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

template<typename T>
JVMWeakRef<T>::JVMWeakRef(JVMWeakRef &&other) : data(std::move(other.data))
{
    other.data.reset();
}

template<typename T>
JVMWeakRef<T>& JVMWeakRef<T>::operator = (JVMWeakRef<T> &&other)
{
    std::swap(data, other.data);
    return *this;
}

template<typename T>
JVMWeakRef<T>::operator bool()
{
    return this->get() != nullptr;
}

template<typename T>
JVMWeakRef<T>::operator bool() const
{
    return this->get() != nullptr;
}

template<typename T>
typename std::remove_pointer<T>::type* JVMWeakRef<T>::get()
{
    return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
}

template<typename T>
typename std::remove_pointer<T>::type* JVMWeakRef<T>::get() const
{
    return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
}




template<typename T>
JVMRef<T>::JVMRef()
{
    
}

template<typename T>
JVMRef<T>::JVMRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr)
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

template<typename T>
JVMRef<T>::JVMRef(JVMRef &&other) : data(std::move(other.data))
{
    other.data.reset();
}

template<typename T>
JVMRef<T>& JVMRef<T>::operator = (JVMRef<T> &&other)
{
    std::swap(data, other.data);
    return *this;
}

template<typename T>
JVMRef<T>::operator bool()
{
    return this->get != nullptr;
}

template<typename T>
JVMRef<T>::operator bool() const
{
    return this->get() != nullptr;
}

template<typename T>
typename std::remove_pointer<T>::type* JVMRef<T>::get()
{
    return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
}

template<typename T>
typename std::remove_pointer<T>::type* JVMRef<T>::get() const
{
    return static_cast<typename std::remove_pointer<T>::type*>(this->data.get());
}

template<typename T>
JVMRef<T> JVMRef<T>::strongRef(JVM* jvm) const
{
    return JVMRef<T>(jvm, this->get());
}

template<typename T>
JVMWeakRef<T> JVMRef<T>::weakRef(JVM* jvm) const
{
    return JVMWeakRef<T>(jvm, this->get());
}

template<typename T>
void JVMRef<T>::reset()
{
    this->data.reset();
}



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
