//
//  Type.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Type_hxx
#define Type_hxx

#include "Object.hxx"

namespace java::lang::reflect
{
    class Type : public Object
    {
    private:
        using Object::Object;
        
    public:
        Type(JVM* jvm);
        Type(JVM* jvm, jobject instance);
    };
}

#endif /* Type_hxx */
