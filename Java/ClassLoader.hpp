//
//  ClassLoader.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ClassLoader_hpp
#define ClassLoader_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        class ClassLoader : public Object
        {
        public:
            ClassLoader(JVM* jvm);
            ClassLoader(JVM* jvm, jobject instance);
        };
    }
}

#endif /* ClassLoader_hpp */
