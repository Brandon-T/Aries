//
//  FileChannel.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileChannel_hxx
#define FileChannel_hxx

#include "Array.hxx"
#include "AbstractInterruptibleChannel.hxx"


namespace java::nio::channels
{
    using java::nio::ByteBuffer;
    using java::nio::MappedByteBuffer;
    using java::nio::channels::FileChannel$MapMode;
    using java::nio::channels::FileLock;
    using java::nio::channels::ReadableByteChannel;
    using java::nio::channels::WritableByteChannel;
    using java::nio::channels::spi::AbstractInterruptibleChannel;
    using java::nio::file::OpenOption;
    using java::nio::file::Path;
    using java::nio::file::attribute::FileAttribute;
    using java::util::Set;
    
    
    class FileChannel : public AbstractInterruptibleChannel
    {
    public:
        FileChannel(JVM* vm, jobject instance);
        
        void force(bool metaData);
        FileLock lock(std::int64_t position, std::int64_t size, bool shared);
        FileLock lock();
        MappedByteBuffer map(FileChannel$MapMode arg0, std::int64_t arg1, std::int64_t arg2);
        static FileChannel open(JVM* arg0, Path arg1, Set arg2, Array<FileAttribute>& arg3);
        static FileChannel open(JVM* arg0, Path arg1, Array<OpenOption>& arg2);
        std::int64_t position();
        FileChannel position(std::int64_t newPosition);
        std::int32_t read(ByteBuffer dst);
        std::int64_t read(Array<ByteBuffer>& dsts, std::int32_t offset, std::int32_t length);
        std::int64_t read(Array<ByteBuffer>& dsts);
        std::int32_t read(ByteBuffer dst, std::int64_t position);
        std::int64_t size();
        std::int64_t transferFrom(ReadableByteChannel src, std::int64_t position, std::int64_t count);
        std::int64_t transferTo(std::int64_t position, std::int64_t count, WritableByteChannel target);
        FileChannel truncate(std::int64_t size);
        FileLock tryLock(std::int64_t position, std::int64_t size, bool shared);
        FileLock tryLock();
        std::int32_t write(ByteBuffer src);
        std::int64_t write(Array<ByteBuffer>& srcs, std::int32_t offset, std::int32_t length);
        std::int64_t write(Array<ByteBuffer>& srcs);
        std::int32_t write(ByteBuffer src, std::int64_t position);
        
        
    protected:
        FileChannel(JVM* vm);
    };
}

#endif /* FileChannel_hxx */
