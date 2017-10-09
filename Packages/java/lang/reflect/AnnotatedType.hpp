//
//  AnnotatedType.hpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef AnnotatedType_hpp
#define AnnotatedType_hpp

#include "Object.hpp"
#include "AnnotatedElement.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            using java::lang::reflect::Type;
            using java::lang::reflect::AnnotatedElement;
            
            class AnnotatedType : public AnnotatedElement
            {
            public:
                AnnotatedType(JVM* jvm);
                AnnotatedType(JVM* jvm, jobject instance);
                virtual ~AnnotatedType();
                
                Type getType();
            };
        }
    }
}

#endif /* AnnotatedType_hpp */
