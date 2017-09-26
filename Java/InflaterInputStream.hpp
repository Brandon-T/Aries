//
//  InflaterInputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef InflaterInputStream_hpp
#define InflaterInputStream_hpp

#include "FilterInputStream.hpp"

namespace java
{
    namespace util
    {
        namespace zip
        {
            using java::io::FilterInputStream;
            using java::util::zip::Inflater;
            
            class InflaterInputStream : public FilterInputStream
            {
            public:
                InflaterInputStream(JVM* jvm, InputStream stream);
                InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater);
                InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater, int size);
            };
        }
    }
}

#endif /* InflaterInputStream_hpp */
