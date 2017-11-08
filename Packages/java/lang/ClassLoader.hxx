//
//  ClassLoader.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ClassLoader_hxx
#define ClassLoader_hxx

#include "Object.hxx"

namespace java::lang
{
    class ClassLoader : public Object
    {
    public:
        ClassLoader(JVM* jvm);
        ClassLoader(JVM* jvm, jobject instance);
    };
}

#endif /* ClassLoader_hxx */
