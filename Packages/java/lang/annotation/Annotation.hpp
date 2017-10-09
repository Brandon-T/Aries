//
//  Annotation.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Annotation_hpp
#define Annotation_hpp

#include "Object.hpp"

namespace java
{
    namespace lang
    {
        namespace annotation
        {
            class Annotation : public Object
            {
            private:
                using Object::Object;
                
            public:
                Annotation(JVM* jvm);
                Annotation(JVM* jvm, jobject instance);
                virtual ~Annotation();
            };
        }
    }
}

#endif /* Annotation_hpp */
