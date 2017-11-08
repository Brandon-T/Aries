//
//  Package.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Package_hxx
#define Package_hxx

#include "Object.hxx"

namespace java::lang
{
    class Package : public Object
    {
    public:
        Package(JVM* jvm);
        Package(JVM* jvm, jobject instance);
    };
}

#endif /* Package_hxx */
