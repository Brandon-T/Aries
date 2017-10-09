//
//  Method.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Method_hpp
#define Method_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        namespace reflect
        {
            class Method : public Object
            {
            private:
                using Object::Object;
                
            public:
                Method(JVM* jvm);
                Method(JVM* jvm, jobject instance);
                virtual ~Method();
            };
        }
    }
}

#endif /* Method_hpp */
