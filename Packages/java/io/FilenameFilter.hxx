//
//  FilenameFilter.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FilenameFilter_hxx
#define FilenameFilter_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::io
{
    using java::io::File;
    using java::lang::Object;
    using java::lang::String;
    
    
    class FilenameFilter : public Object
    {
    public:
        FilenameFilter(JVM* vm, jobject instance);
        
        bool accept(File dir, String name);
    };
}

#endif /* FilenameFilter_hxx */
