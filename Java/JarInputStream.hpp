//
//  JarInputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JarInputStream_hpp
#define JarInputStream_hpp

#include "InputStream.hpp"

namespace java
{
    namespace util
    {
        namespace jar
        {
            using java::lang::String;
            using java::io::InputStream;
            using java::util::zip::ZipEntry;
            using java::util::jar::JarEntry;
            using java::util::jar::Manifest;
            
            class JarInputStream : public InputStream
            {
            public:
                JarInputStream(JVM* vm, InputStream stream);
                JarInputStream(JVM* vm, InputStream stream, bool verify);
                virtual ~JarInputStream();
                
                Manifest getManifest();
                ZipEntry* getNextEntry();
                JarEntry* getNextJarEntry();
                
            protected:
                ZipEntry createZipEntry(String name);
            };
        }
    }
}

#endif /* JarInputStream_hpp */
