//
//  Method.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Method_hxx
#define Method_hxx

#include "Object.hxx"

namespace java::lang::reflect
{
    class Method : public Object
    {
    private:
        using Object::Object;
        
    public:
        Method(JVM* jvm);
        Method(JVM* jvm, jobject instance);
    };
}

#endif /* Method_hxx */
