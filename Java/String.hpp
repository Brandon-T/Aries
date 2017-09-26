//
//  String.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        class String : public Object
        {
        private:
            using Object::Object;
            
        public:
            String(JVM* jvm, jobject instance);
        };
    }
}

#endif /* String_hpp */
