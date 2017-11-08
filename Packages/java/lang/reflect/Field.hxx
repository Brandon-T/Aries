//
//  Field.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Field_hxx
#define Field_hxx

#include "Object.hxx"

namespace java::lang::reflect
{
    class Field : public Object
    {
    private:
        using Object::Object;
        
    public:
        Field(JVM* jvm);
        Field(JVM* jvm, jobject instance);
    };
}

#endif /* Field_hxx */
