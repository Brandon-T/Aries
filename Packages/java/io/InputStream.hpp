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
            InputStream(JVM* jvm, jobject instance);
            virtual ~InputStream();
            
            virtual int	available();
            virtual void close();
            virtual void mark(int readAheadLimit);
            virtual bool markSupported();
            virtual int	read();
            virtual int	read(jbyte* buffer, int off, int len);
            virtual void reset();
            virtual long skip(long n);
            
        protected:
            InputStream(JVM* jvm);
        };
    }
}

#endif /* InputStream_hpp */
