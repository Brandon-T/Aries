//
//  FileFilter.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileFilter_hxx
#define FileFilter_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::io
{
    using java::io::File;
    using java::lang::Object;
    
    
    class FileFilter : public Object
    {
    public:
        FileFilter(JVM* vm, jobject instance);
        
        bool accept(File pathname);
    };
}

#endif /* FileFilter_hxx */
