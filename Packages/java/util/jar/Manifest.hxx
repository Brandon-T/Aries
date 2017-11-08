//
//  Manifest.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Manifest_hxx
#define Manifest_hxx

#include "Object.hxx"

namespace java::util::jar
{
    using java::lang::Object;
    using java::lang::String;
    using java::io::InputStream;
    using java::io::OutputStream;
    
    class Manifest : Object
    {
        Manifest(JVM* jvm);
        Manifest(JVM* jvm, jobject instance);
        
        void clear();
        Attributes getAttributes(String name);
        Map<String, Attributes> getEntries();
        Attributes getMainAttributes();
        virtual int hashCode();
        void read(InputStream is);
        void write(OutputStream out);
    };
}

#endif /* Manifest_hxx */
