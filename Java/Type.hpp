//
//  Type.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            class Type : public Object
            {
            private:
                using Object::Object;
                
            public:
                Type(JVM* jvm);
                Type(JVM* jvm, jobject instance);
                virtual ~Type();
            };
        }
    }
}

#endif /* Type_hpp */
