//
//  ByteArrayInputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteArrayInputStream_hpp
#define ByteArrayInputStream_hpp


#include "Object.hpp"
#include "InputStream.hpp"

namespace java
{
    namespace io
    {
        class ByteArrayInputStream : public InputStream
        {
        public:
            ByteArrayInputStream(JVM* jvm, jobject instance);
            ByteArrayInputStream(JVM* jvm, jbyte*, int bufferLength);
            ByteArrayInputStream(JVM* jvm, jbyte* buffer, int bufferLength, int offset, int length);
            virtual ~ByteArrayInputStream();
        };
    }
}

#endif /* ByteArrayInputStream_hpp */
