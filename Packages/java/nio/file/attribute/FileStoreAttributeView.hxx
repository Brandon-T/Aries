//
//  FileStoreAttributeView.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileStoreAttributeView_hxx
#define FileStoreAttributeView_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::attribute
{
    using java::lang::Object;
    
    
    class FileStoreAttributeView : public Object
    {
    public:
        FileStoreAttributeView(JVM* vm, jobject instance);
    };
}

#endif /* FileStoreAttributeView_hxx */
