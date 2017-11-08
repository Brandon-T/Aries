//
//  AnnotatedElement.hxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef AnnotatedElement_hxx
#define AnnotatedElement_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::lang::reflect
{
    using java::lang::annotation::Annotation;
    
    class AnnotatedElement : public Object
    {
    private:
        using Object::Object;
        
    public:
        AnnotatedElement(JVM* jvm);
        AnnotatedElement(JVM* jvm, jobject instance);
        
        virtual bool isAnnotationPresent(Class annotatedClass);
        virtual Annotation getAnnotation(Class annotatedClass);
        virtual Array<Annotation> getAnnotations();
        virtual Array<Annotation> getAnnotationsByType(Class annotatedClass);
        virtual Annotation getDeclaredAnnotation(Class annotatedClass);
        virtual Array<Annotation> getDeclaredAnnotationsByType(Class annotatedClass);
        virtual Array<Annotation> getDeclaredAnnotations();
    };
}

#endif /* AnnotatedElement_hxx */
