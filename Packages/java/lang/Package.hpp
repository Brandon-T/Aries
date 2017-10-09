//
//  Package.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Package_hpp
#define Package_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        class Package : public Object
        {
        public:
            Package(JVM* jvm);
            Package(JVM* jvm, jobject instance);
            virtual ~Package();
        };
    }
}

#endif /* Package_hpp */
