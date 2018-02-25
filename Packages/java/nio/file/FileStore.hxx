//
//  FileStore.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileStore_hxx
#define FileStore_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    using java::nio::file::attribute::FileStoreAttributeView;
    
    
    class FileStore : public Object
    {
    public:
        FileStore(JVM* vm, jobject instance);
        
        Object getAttribute(String attribute);
        FileStoreAttributeView getFileStoreAttributeView(Class arg0);
        std::int64_t getTotalSpace();
        std::int64_t getUnallocatedSpace();
        std::int64_t getUsableSpace();
        bool isReadOnly();
        String name();
        bool supportsFileAttributeView(Class type);
        bool supportsFileAttributeView(String name);
        String type();
        
        
    protected:
        FileStore(JVM* vm);
    };
}

#endif /* FileStore_hxx */
