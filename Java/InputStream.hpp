//
//  InputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef InputStream_hpp
#define InputStream_hpp

#include "Object.hpp"

namespace java
{
    namespace io
    {
        using java::lang::Object;
        
        class InputStream : public Object
        {
        public:
            virtual ~InputStream();
            
            virtual int	available();
            virtual void close();
            virtual void mark(int readAheadLimit);
            virtual bool markSupported();
            virtual int	read() = 0;
            virtual int	read(jbyte* buffer, int off, int len);
            virtual void reset();
            virtual long skip(long n);
            
        protected:
            InputStream(JVM* jvm);
            InputStream(JVM* jvm, jobject instance);
        };
    }
}

#endif /* InputStream_hpp */
