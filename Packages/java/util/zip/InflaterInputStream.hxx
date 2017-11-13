//
//  InflaterInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef InflaterInputStream_hxx
#define InflaterInputStream_hxx

#include "FilterInputStream.hxx"

namespace java::util::zip
{
    using java::io::FilterInputStream;
    using java::util::zip::Inflater;
    
    class InflaterInputStream : public FilterInputStream
    {
    public:
        InflaterInputStream(JVM* jvm, InputStream stream);
        InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater);
        InflaterInputStream(JVM* jvm, InputStream stream, Inflater inflater, int size);
        
    protected:
        InflaterInputStream(JVM* jvm);
        void fill();
    };
}

#endif /* InflaterInputStream_hxx */
