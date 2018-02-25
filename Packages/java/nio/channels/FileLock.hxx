//
//  FileLock.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileLock_hxx
#define FileLock_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::channels
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::channels::AsynchronousFileChannel;
    using java::nio::channels::Channel;
    using java::nio::channels::FileChannel;
    
    
    class FileLock : public Object
    {
    public:
        FileLock(JVM* vm, jobject instance);
        
        Channel acquiredBy();
        FileChannel channel();
        void close();
        bool isShared();
        bool isValid();
        bool overlaps(std::int64_t position, std::int64_t size);
        std::int64_t position();
        void release();
        std::int64_t size();
        String toString();
        
        
    protected:
        FileLock(JVM* vm, FileChannel channel, std::int64_t position, std::int64_t size, bool shared);
        FileLock(JVM* vm, AsynchronousFileChannel channel, std::int64_t position, std::int64_t size, bool shared);
    };
}

#endif /* FileLock_hxx */
