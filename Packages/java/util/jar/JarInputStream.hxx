//
//  JarInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JarInputStream_hxx
#define JarInputStream_hxx

#include "InputStream.hxx"

namespace java::util::jar
{
    using java::io::InputStream;
    using java::util::zip::ZipEntry;
    using java::util::jar::JarEntry;
    using java::util::jar::Manifest;
    
    class JarInputStream : public InputStream
    {
    public:
        JarInputStream(JVM* jvm, jobject instance);
        JarInputStream(JVM* vm, InputStream stream);
        JarInputStream(JVM* vm, InputStream stream, bool verify);
        
        Manifest getManifest();
        ZipEntry getNextEntry();
        JarEntry getNextJarEntry();
    };
}

#endif /* JarInputStream_hxx */
