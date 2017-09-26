//
//  Field.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            class Field : public Object
            {
            private:
                using Object::Object;
                
            public:
                Field(JVM* jvm);
                Field(JVM* jvm, jobject instance);
            };
        }
    }
}

#endif /* Field_hpp */
