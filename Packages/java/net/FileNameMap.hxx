//
//  FileNameMap.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileNameMap_hxx
#define FileNameMap_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class FileNameMap : public Object
    {
    public:
        FileNameMap(JVM* vm, jobject instance);
        
        String getContentTypeFor(String fileName);
    };
}

#endif /* FileNameMap_hxx */
