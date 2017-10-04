//
//  ByteArrayOutputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ByteArrayOutputStream_hpp
#define ByteArrayOutputStream_hpp

#include "OutputStream.hpp"

namespace java
{
    namespace io
    {
        class ByteArrayOutputStream : public OutputStream
        {
        public:
            ByteArrayOutputStream(JVM* jvm);
            ByteArrayOutputStream(JVM* jvm, jobject instance);
            ByteArrayOutputStream(JVM* jvm, jint size);
            virtual ~ByteArrayOutputStream();
            
            virtual void reset();
            virtual int size();
            virtual std::vector<jbyte> toByteArray();
            virtual void writeTo(OutputStream out);
        };
    }
}

#endif /* ByteArrayOutputStream_hpp */
