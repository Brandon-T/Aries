//
//  FileSystem.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileSystem_hxx
#define FileSystem_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Iterable;
    using java::lang::Object;
    using java::lang::String;
    using java::nio::file::FileStore;
    using java::nio::file::Path;
    using java::nio::file::PathMatcher;
    using java::nio::file::WatchService;
    using java::nio::file::attribute::UserPrincipalLookupService;
    using java::nio::file::spi::FileSystemProvider;
    using java::util::Set;
    
    
    class FileSystem : public Object
    {
    public:
        FileSystem(JVM* vm, jobject instance);
        
        void close();
        Iterable<FileStore> getFileStores();
        Path getPath(String arg0, Array<String>& arg1);
        PathMatcher getPathMatcher(String syntaxAndPattern);
        Iterable<Path> getRootDirectories();
        String getSeparator();
        UserPrincipalLookupService getUserPrincipalLookupService();
        bool isOpen();
        bool isReadOnly();
        WatchService newWatchService();
        FileSystemProvider provider();
        Set<String> supportedFileAttributeViews();
        
        
    protected:
        FileSystem(JVM* vm);
    };
}

#endif /* FileSystem_hxx */
