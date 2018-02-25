//
//  FileSystemProvider.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef FileSystemProvider_hxx
#define FileSystemProvider_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::spi
{
    using java::io::InputStream;
    using java::io::OutputStream;
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    using java::net::URI;
    using java::nio::channels::AsynchronousFileChannel;
    using java::nio::channels::FileChannel;
    using java::nio::channels::SeekableByteChannel;
    using java::nio::file::AccessMode;
    using java::nio::file::CopyOption;
    using java::nio::file::DirectoryStream;
    using java::nio::file::DirectoryStream$Filter;
    using java::nio::file::FileStore;
    using java::nio::file::FileSystem;
    using java::nio::file::LinkOption;
    using java::nio::file::OpenOption;
    using java::nio::file::Path;
    using java::nio::file::attribute::BasicFileAttributes;
    using java::nio::file::attribute::FileAttribute;
    using java::nio::file::attribute::FileAttributeView;
    using java::util::List;
    using java::util::Map;
    using java::util::Set;
    using java::util::concurrent::ExecutorService;
    
    
    class FileSystemProvider : public Object
    {
    public:
        FileSystemProvider(JVM* vm, jobject instance);
        
        void checkAccess(Path arg0, Array<AccessMode>& arg1);
        void copy(Path arg0, Path arg1, Array<CopyOption>& arg2);
        void createDirectory(Path arg0, Array<FileAttribute>& arg1);
        void createLink(Path link, Path existing);
        void createSymbolicLink(Path arg0, Path arg1, Array<FileAttribute>& arg2);
        void delete(Path path);
        bool deleteIfExists(Path path);
        FileAttributeView getFileAttributeView(Path arg0, Class arg1, Array<LinkOption>& arg2);
        FileStore getFileStore(Path path);
        FileSystem getFileSystem(URI uri);
        Path getPath(URI uri);
        String getScheme();
        static List installedProviders(JVM* vm);
        bool isHidden(Path path);
        bool isSameFile(Path path, Path path2);
        void move(Path arg0, Path arg1, Array<CopyOption>& arg2);
        AsynchronousFileChannel newAsynchronousFileChannel(Path arg0, Set arg1, ExecutorService arg2, Array<FileAttribute>& arg3);
        SeekableByteChannel newByteChannel(Path arg0, Set arg1, Array<FileAttribute>& arg2);
        DirectoryStream newDirectoryStream(Path arg0, DirectoryStream$Filter arg1);
        FileChannel newFileChannel(Path arg0, Set arg1, Array<FileAttribute>& arg2);
        FileSystem newFileSystem(URI uri, Map env);
        FileSystem newFileSystem(Path path, Map env);
        InputStream newInputStream(Path arg0, Array<OpenOption>& arg1);
        OutputStream newOutputStream(Path arg0, Array<OpenOption>& arg1);
        BasicFileAttributes readAttributes(Path arg0, Class arg1, Array<LinkOption>& arg2);
        Map readAttributes(Path arg0, String arg1, Array<LinkOption>& arg2);
        Path readSymbolicLink(Path link);
        void setAttribute(Path arg0, String arg1, Object arg2, Array<LinkOption>& arg3);
        
        
    protected:
        FileSystemProvider(JVM* vm);
    };
}

#endif /* FileSystemProvider_hxx */
