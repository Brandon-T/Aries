//
//  FilterInputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef FilterInputStream_hpp
#define FilterInputStream_hpp

#include "InputStream.hpp"

namespace java
{
    namespace io
    {
        class FilterInputStream : public InputStream
        {
        public:
            virtual ~FilterInputStream();
            
        protected:
            FilterInputStream(JVM* jvm);
            FilterInputStream(JVM* jvm, jobject instance);
            FilterInputStream(JVM* jvm, InputStream stream);
        };
    }
}

#endif /* FilterInputStream_hpp */
