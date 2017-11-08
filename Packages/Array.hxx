//
//  Array.hxx
//  Aries
//
//  Created by Brandon on 2017-10-08.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Array_hxx
#define Array_hxx

#include <vector>
#include "Object.hxx"

using java::lang::Object;

template<typename T>
class Array final : public Object
{
public:
    Array(JVM* jvm, jobject instance);
    Array(JVM* jvm, jsize length);
    
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


#include "Array.txx"

#endif /* Array_hxx */
