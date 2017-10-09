//
//  JarEntry.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JarEntry_hpp
#define JarEntry_hpp

#include "ZipEntry.hpp"

namespace java
{
    namespace util
    {
        namespace jar
        {
            using java::lang::String;
            using java::util::zip::ZipEntry;
            
            class JarEntry : public ZipEntry
            {
            public:
                JarEntry(JVM* jvm, jobject instance);
                JarEntry(JVM* jvm, String name);
                JarEntry(JVM* jvm, ZipEntry entry);
                virtual ~JarEntry();
            };
        }
    }
}

#endif /* JarEntry_hpp */
