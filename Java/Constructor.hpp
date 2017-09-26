//
//  Constructor.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Constructor_hpp
#define Constructor_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
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
    }
}

#endif /* Constructor_hpp */
