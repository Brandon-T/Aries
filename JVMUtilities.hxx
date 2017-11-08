//
//  JVMUtilities.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JVMUtilities_hxx
#define JVMUtilities_hxx

#include <functional>
#include <vector>
#include "JVM.hxx"

template<typename T>
class JVMWeakRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    JVMWeakRef(const JVMWeakRef &other) = delete;
    JVMWeakRef<T>& operator = (const JVMWeakRef<T> &other) = delete;
    
public:
    JVMWeakRef();
    JVMWeakRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr);
    JVMWeakRef(JVMWeakRef &&other);
    
    JVMWeakRef<T>& operator = (JVMWeakRef<T> &&other);
    
    operator bool();
    operator bool() const;
    
    typename std::remove_pointer<T>::type* get();
    typename std::remove_pointer<T>::type* get() const;
};

template<typename T>
class JVMRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    JVMRef(const JVMRef &other) = delete;
    JVMRef<T>& operator = (const JVMRef<T> &other) = delete;
    
public:
    JVMRef();
    JVMRef(JVM* jvm, typename std::remove_pointer<T>::type* data_ptr);
    JVMRef(JVMRef &&other);
    
    
    JVMRef<T>& operator = (JVMRef<T> &&other);
    
    operator bool();
    operator bool() const;
    
    typename std::remove_pointer<T>::type* get();
    typename std::remove_pointer<T>::type* get() const;
    
    JVMRef<T> strongRef(JVM* jvm) const;
    JVMWeakRef<T> weakRef(JVM* jvm) const;
    
    void reset();
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
VectorToJVMArray(JVM* jvm, jclass cls, std::vector<T> values);

template<typename T>
typename std::enable_if<JVMIsPrimitive<T>::value, JVMRef<jarray>>::type
VectorToJVMArray(JVM* jvm, jclass cls, std::vector<T> values);

template<typename T>
typename std::enable_if<!JVMIsPrimitive<T>::value, std::vector<T>>::type
JVMArrayToVector(JVM* jvm, jarray array);

template<typename T>
typename std::enable_if<JVMIsPrimitive<T>::value, std::vector<T>>::type
JVMArrayToVector(JVM* jvm, jarray array);



#include "JVMUtilities.txx"

#endif /* JVMUtilities_hxx */
