//
//  GenericDeclaration.hpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef GenericDeclaration_hpp
#define GenericDeclaration_hpp

#include "Object.hpp"
#include "Array.hpp"
#include "AnnotatedElement.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            using java::lang::reflect::TypeVariable;
            using java::lang::reflect::AnnotatedElement;
            
            class GenericDeclaration : public AnnotatedElement
            {
            public:
                GenericDeclaration(JVM* jvm);
                GenericDeclaration(JVM* jvm, jobject instance);
                virtual ~GenericDeclaration();
                
                virtual Array<TypeVariable> getTypeParameters();
            };
        }
    }
}

#endif /* GenericDeclaration_hpp */
