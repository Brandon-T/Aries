//
//  FileAttribute.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileAttribute_hxx
#define FileAttribute_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::attribute
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class FileAttribute : public Object
    {
    public:
        FileAttribute(JVM* vm, jobject instance);
        
        String name();
        Object value();
    };
}

#endif /* FileAttribute_hxx */
