//
//  Constructor.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Constructor_hxx
#define Constructor_hxx

#include "Object.hxx"

namespace java::lang::reflect
{
    class Constructor : public Object
    {
    private:
        using Object::Object;
        
    public:
        Constructor(JVM* jvm);
        Constructor(JVM* jvm, jobject instance);
    };
}

#endif /* Constructor_hxx */
