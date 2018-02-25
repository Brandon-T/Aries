//
//  Path.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Path_hxx
#define Path_hxx

#include "Array.hxx"
#include "Object.hxx"
#include "WatchEvent.hxx"


namespace java::nio::file
{
    using java::io::File;
    using java::lang::Object;
    using java::lang::String;
    using java::net::URI;
    using java::nio::file::FileSystem;
    using java::nio::file::LinkOption;
    using java::nio::file::WatchEvent;
    using java::nio::file::WatchKey;
    using java::nio::file::WatchService;
    using java::util::Iterator;
    
    
    class Path : public Object
    {
    public:
        Path(JVM* vm, jobject instance);
        
        std::int32_t compareTo(Path other);
        bool endsWith(Path other);
        bool endsWith(String other);
        bool equals(Object other);
        Path getFileName();
        FileSystem getFileSystem();
        Path getName(std::int32_t index);
        std::int32_t getNameCount();
        Path getParent();
        Path getRoot();
        std::int32_t hashCode();
        bool isAbsolute();
        Iterator<Path> iterator();
        Path normalize();
        WatchKey registerService(WatchService arg0, Array<WatchEvent::Kind>& arg1, Array<WatchEvent::Modifier>& arg2); //register
        WatchKey registerService(WatchService arg0, Array<WatchEvent::Kind>& arg1); //register
        Path relativize(Path other);
        Path resolve(Path other);
        Path resolve(String other);
        Path resolveSibling(Path other);
        Path resolveSibling(String other);
        bool startsWith(Path other);
        bool startsWith(String other);
        Path subpath(std::int32_t beginIndex, std::int32_t endIndex);
        Path toAbsolutePath();
        File toFile();
        Path toRealPath(Array<LinkOption>& arg0);
        String toString();
        URI toUri();
    };
}

#endif /* Path_hxx */
