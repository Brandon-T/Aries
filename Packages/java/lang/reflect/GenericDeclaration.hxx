//
//  GenericDeclaration.hxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef GenericDeclaration_hxx
#define GenericDeclaration_hxx

#include "Object.hxx"
#include "Array.hxx"
#include "AnnotatedElement.hxx"

namespace java::lang::reflect
{
    using java::lang::reflect::TypeVariable;
    using java::lang::reflect::AnnotatedElement;
    
    class GenericDeclaration : public AnnotatedElement
    {
    public:
        GenericDeclaration(JVM* jvm);
        GenericDeclaration(JVM* jvm, jobject instance);
        
        virtual Array<TypeVariable> getTypeParameters();
    };
}

#endif /* GenericDeclaration_hxx */
