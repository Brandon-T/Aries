//
//  FilterInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef FilterInputStream_hxx
#define FilterInputStream_hxx

#include "InputStream.hxx"

namespace java::io
{
    class FilterInputStream : public InputStream
    {
    protected:
        FilterInputStream(JVM* jvm);
        FilterInputStream(JVM* jvm, jobject instance);
        FilterInputStream(JVM* jvm, InputStream stream);
    };
}

#endif /* FilterInputStream_hxx */
