//
//  String.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef String_hxx
#define String_hxx

#include "Object.hxx"

namespace java::lang
{
    class String : public Object
    {
    private:
        using Object::Object;
        
    public:
        String(JVM* jvm);
        String(JVM* jvm, jobject instance);
    };
}

#endif /* String_hxx */
