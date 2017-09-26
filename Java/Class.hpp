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

namespace java
{
    namespace lang
    {
        using java::lang::annotation::Annotation;
        using java::lang::reflect::Constructor;
        using java::lang::reflect::Field;
        using java::lang::reflect::Method;
        using java::lang::reflect::Type;
        using java::security::ProtectionDomain;
        using java::net::URL;
        
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
            virtual std::vector<Annotation> getAnnotations();
            virtual String getCanonicalName();
            virtual std::vector<Class> getClasses();
            virtual ClassLoader getClassLoader();
            virtual Class getComponentType();
            virtual Constructor getConstructor(std::vector<Class> parameterTypes);
            virtual std::vector<Constructor> getConstructors();
            virtual std::vector<Annotation> getDeclaredAnnotations();
            virtual std::vector<Class> getDeclaredClasses();
            virtual Constructor getDeclaredConstructor(std::vector<Class> parameterTypes);
            virtual std::vector<Constructor> getDeclaredConstructors();
            virtual Field getDeclaredField(String name);
            virtual std::vector<Field> getDeclaredFields();
            virtual Method getDeclaredMethod(String name, std::vector<Class> parameterTypes);
            virtual std::vector<Method> getDeclaredMethods();
            virtual Class getDeclaringClass();
            virtual Class getEnclosingClass();
            virtual Constructor getEnclosingConstructor();
            virtual Method getEnclosingMethod();
            virtual std::vector<Class> getEnumConstants();
            virtual Field getField(String name);
            virtual std::vector<Field> getFields();
            virtual std::vector<Type> getGenericInterfaces();
            virtual Type getGenericSuperclass();
            virtual std::vector<Class> getInterfaces();
            virtual Method getMethod(String name, std::vector<Class> parameterTypes);
            virtual std::vector<Method> getMethods();
            virtual int getModifiers();
            virtual String getName();
            virtual Package getPackage();
            virtual ProtectionDomain getProtectionDomain();
            virtual URL getResource(String name);
            virtual InputStream getResourceAsStream(String name);
        };
    }
}

#endif /* Class_hpp */
