//
//  Class.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Class_hpp
#define Class_hpp

#include <vector>

#include "Object.hpp"
#include "Array.hpp"

namespace java
{
    namespace lang
    {
        using java::lang::annotation::Annotation;
        using java::lang::reflect::Constructor;
        using java::lang::reflect::Field;
        using java::lang::reflect::Method;
        using java::lang::reflect::Type;
        using java::lang::reflect::TypeVariable;
        using java::security::ProtectionDomain;
        using java::net::URL;
        using java::io::InputStream;
        
        class Class final : public Object
        {
        public:
            Class();
            Class(JVM* jvm, jobject instance);
            virtual ~Class();
            
            virtual Class asSubclass(Class clazz);
            virtual Object cast(Object obj);
            virtual bool desiredAssertionStatus();
            static Class forName(JVM* jvm, String className);
            static Class forName(JVM* jvm, String name, bool initialize, ClassLoader loader);
            virtual Annotation getAnnotation(Class annotationClass);
            virtual Array<Annotation> getAnnotations();
            virtual String getCanonicalName();
            virtual Array<Class> getClasses();
            virtual ClassLoader getClassLoader();
            virtual Class getComponentType();
            virtual Constructor getConstructor(Array<Class> parameterTypes);
            virtual Array<Constructor> getConstructors();
            virtual Array<Annotation> getDeclaredAnnotations();
            virtual Array<Class> getDeclaredClasses();
            virtual Constructor getDeclaredConstructor(Array<Class> parameterTypes);
            virtual Array<Constructor> getDeclaredConstructors();
            virtual Field getDeclaredField(String name);
            virtual Array<Field> getDeclaredFields();
            virtual Method getDeclaredMethod(String name, Array<Class> parameterTypes);
            virtual Array<Method> getDeclaredMethods();
            virtual Class getDeclaringClass();
            virtual Class getEnclosingClass();
            virtual Constructor getEnclosingConstructor();
            virtual Method getEnclosingMethod();
            virtual Array<Class> getEnumConstants();
            virtual Field getField(String name);
            virtual Array<Field> getFields();
            virtual Array<Type> getGenericInterfaces();
            virtual Type getGenericSuperclass();
            virtual Array<Class> getInterfaces();
            virtual Method getMethod(String name, Array<Class> parameterTypes);
            virtual Array<Method> getMethods();
            virtual int getModifiers();
            virtual String getName();
            virtual Package getPackage();
            virtual ProtectionDomain getProtectionDomain();
            virtual URL getResource(String name);
            virtual InputStream getResourceAsStream(String name);
            virtual Array<Object> getSigners();
            virtual String getSimpleName();
            virtual Class getSuperclass();
            virtual Array<TypeVariable> getTypeParameters();
            virtual bool isAnnotationPresent(Class annotationClass);
            virtual bool isAnnotation();
            virtual bool isAnonymousClass();
            virtual bool isArray();
            virtual bool isAssignableFrom(Class cls);
            virtual bool isEnum();
            virtual bool isInstance(Object obj);
            virtual bool isInterface();
            virtual bool isLocalClass();
            virtual bool isMemberClass();
            virtual bool isPrimitive();
            virtual bool isSynthetic();
            virtual Object newInstance();
        };
    }
}

#endif /* Class_hpp */
