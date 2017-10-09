//
//  AnnotatedElement.hpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef AnnotatedElement_hpp
#define AnnotatedElement_hpp

#include "Object.hpp"
#include "Array.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            using java::lang::annotation::Annotation;
            
            class AnnotatedElement : public Object
            {
            private:
                using Object::Object;
                
            public:
                AnnotatedElement(JVM* jvm);
                AnnotatedElement(JVM* jvm, jobject instance);
                virtual ~AnnotatedElement();
                
                virtual bool isAnnotationPresent(Class annotatedClass);
                virtual Annotation getAnnotation(Class annotatedClass);
                virtual Array<Annotation> getAnnotations();
                virtual Array<Annotation> getAnnotationsByType(Class annotatedClass);
                virtual Annotation getDeclaredAnnotation(Class annotatedClass);
                virtual Array<Annotation> getDeclaredAnnotationsByType(Class annotatedClass);
                virtual Array<Annotation> getDeclaredAnnotations();
            };
        }
    }
}

#endif /* AnnotatedElement_hpp */
