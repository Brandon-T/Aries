//
//  ZipEntry.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ZipEntry_hpp
#define ZipEntry_hpp

#include "Object.hpp"
#include "Array.hpp"

namespace java
{
    namespace util
    {
        namespace zip
        {
            using java::lang::Object;
            using java::lang::String;
            
            class ZipEntry : public Object
            {
            public:
                ZipEntry(JVM* jvm, jobject instance);
                ZipEntry(JVM* jvm, String name);
                ZipEntry(JVM* jvm, ZipEntry entry);
                virtual ~ZipEntry();
                
                virtual ZipEntry* clone();
                String getComment();
                jlong getCompressedSize();
                jlong getCrc();
                Array<jbyte> getExtra();
                jint getMethod();
                String getName();
                jlong getSize();
                jlong getTime();
                bool isDirectory();
            };
        }
    }
}

#endif /* ZipEntry_hpp */
