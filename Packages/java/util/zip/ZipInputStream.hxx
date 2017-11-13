//
//  ZipInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-27.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ZipInputStream_hxx
#define ZipInputStream_hxx

#include "Object.hxx"
#include "InflaterInputStream.hxx"

namespace java::util::zip
{
    using java::lang::String;
    using java::nio::charset::Charset;
    
    class ZipInputStream : public InflaterInputStream
    {
    public:
        ZipInputStream(JVM* jvm, InputStream in);
        ZipInputStream(JVM* jvm, InputStream in, Charset charset);
        
        void closeEntry();
        ZipEntry getNextEntry();
        
    protected:
        ZipEntry createZipEntry(String name);
    };
}

#endif /* ZipInputStream_hxx */
