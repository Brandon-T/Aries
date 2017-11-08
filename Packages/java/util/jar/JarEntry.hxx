//
//  JarEntry.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JarEntry_hxx
#define JarEntry_hxx

#include "ZipEntry.hxx"

namespace java::util::jar
{
    using java::lang::String;
    using java::util::zip::ZipEntry;
    
    class JarEntry : public ZipEntry
    {
    public:
        JarEntry(JVM* jvm, jobject instance);
        JarEntry(JVM* jvm, String name);
        JarEntry(JVM* jvm, ZipEntry entry);
    };
}

#endif /* JarEntry_hxx */
