//
//  TypeVariable.hpp
//  Aries
//
//  Created by Brandon on 2017-10-09.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef TypeVariable_hpp
#define TypeVariable_hpp

#include "Object.hpp"
#include "Array.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            using java::lang::reflect::GenericDeclaration;
            using java::lang::reflect::AnnotatedType;
            
            class TypeVariable : public Object
            {
            public:
                TypeVariable(JVM* jvm);
                TypeVariable(JVM* jvm, jobject instance);
                virtual ~TypeVariable();
                
                virtual Array<Type> getBounds();
                virtual GenericDeclaration getGenericDeclaration();
                virtual String getName();
                virtual Array<AnnotatedType> getAnnotatedBounds();
            };
        }
    }
}

#endif /* TypeVariable_hpp */
