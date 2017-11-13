//
//  Locale.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Locale_hxx
#define Locale_hxx

#include "Object.hxx"

namespace java::util
{
    using java::lang::Object;
    
    class Locale : public Object
    {
    public:
        Locale(JVM* jvm, jobject instance);
    };
}

#endif /* Locale_hxx */
