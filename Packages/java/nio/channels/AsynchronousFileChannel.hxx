//
//  AsynchronousFileChannel.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef AsynchronousFileChannel_hxx
#define AsynchronousFileChannel_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::channels
{
    using java::lang::Object;
    using java::nio::ByteBuffer;
    using java::nio::channels::CompletionHandler;
    using java::nio::channels::FileLock;
    using java::nio::file::OpenOption;
    using java::nio::file::Path;
    using java::nio::file::attribute::FileAttribute;
    using java::util::Set;
    using java::util::concurrent::ExecutorService;
    using java::util::concurrent::Future;
    
    
    class AsynchronousFileChannel : public Object
    {
    public:
        AsynchronousFileChannel(JVM* vm, jobject instance);
        
        void force(bool metaData);
        void lock(std::int64_t position, std::int64_t size, bool shared, Object attachment, CompletionHandler handler);
        void lock(Object attachment, CompletionHandler handler);
        Future lock(std::int64_t position, std::int64_t size, bool shared);
        Future lock();
        static AsynchronousFileChannel open(JVM* arg0, Path arg1, Set arg2, ExecutorService arg3, Array<FileAttribute>& arg4);
        static AsynchronousFileChannel open(JVM* arg0, Path arg1, Array<OpenOption>& arg2);
        void read(ByteBuffer dst, std::int64_t position, Object attachment, CompletionHandler handler);
        Future read(ByteBuffer dst, std::int64_t position);
        std::int64_t size();
        AsynchronousFileChannel truncate(std::int64_t size);
        FileLock tryLock(std::int64_t position, std::int64_t size, bool shared);
        FileLock tryLock();
        void write(ByteBuffer src, std::int64_t position, Object attachment, CompletionHandler handler);
        Future write(ByteBuffer src, std::int64_t position);
        
        
    protected:
        AsynchronousFileChannel(JVM* vm);
    };
}

#endif /* AsynchronousFileChannel_hxx */
