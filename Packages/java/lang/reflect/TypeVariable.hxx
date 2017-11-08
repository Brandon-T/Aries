//
//  TypeVariable.hxx
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef TypeVariable_hxx
#define TypeVariable_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::lang::reflect
{
    using java::lang::reflect::GenericDeclaration;
    using java::lang::reflect::AnnotatedType;
    
    class TypeVariable : public Object
    {
    public:
        TypeVariable(JVM* jvm);
        TypeVariable(JVM* jvm, jobject instance);
        
        virtual Array<Type> getBounds();
        virtual GenericDeclaration getGenericDeclaration();
        virtual String getName();
        virtual Array<AnnotatedType> getAnnotatedBounds();
    };
}

#endif /* TypeVariable_hxx */
