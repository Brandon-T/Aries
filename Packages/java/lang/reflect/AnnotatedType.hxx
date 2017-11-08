//
//  AnnotatedType.hxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef AnnotatedType_hxx
#define AnnotatedType_hxx

#include "Object.hxx"
#include "AnnotatedElement.hxx"

namespace java::lang::reflect
{
    using java::lang::reflect::Type;
    using java::lang::reflect::AnnotatedElement;
    
    class AnnotatedType : public AnnotatedElement
    {
    public:
        AnnotatedType(JVM* jvm);
        AnnotatedType(JVM* jvm, jobject instance);
        
        Type getType();
    };
}

#endif /* AnnotatedType_hxx */
