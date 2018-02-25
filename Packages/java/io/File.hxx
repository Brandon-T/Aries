//
//  File.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef File_hxx
#define File_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::io
{
    using java::io::FileFilter;
    using java::io::FilenameFilter;
    using java::lang::Object;
    using java::lang::String;
    using java::net::URI;
    using java::net::URL;
    using java::nio::file::Path;
    
    
    class File : public Object
    {
    public:
        File(JVM* vm, jobject instance);
        File(JVM* vm, String pathname);
        File(JVM* vm, String parent, String child);
        File(JVM* vm, File parent, String child);
        File(JVM* vm, URI uri);
        
        bool canExecute();
        bool canRead();
        bool canWrite();
        std::int32_t compareTo(File pathname);
        bool createNewFile();
        static File createTempFile(JVM* vm, String prefix, String suffix, File directory);
        static File createTempFile(JVM* vm, String prefix, String suffix);
        bool delete();
        void deleteOnExit();
        bool equals(Object obj);
        bool exists();
        File getAbsoluteFile();
        String getAbsolutePath();
        File getCanonicalFile();
        String getCanonicalPath();
        std::int64_t getFreeSpace();
        String getName();
        String getParent();
        File getParentFile();
        String getPath();
        std::int64_t getTotalSpace();
        std::int64_t getUsableSpace();
        std::int32_t hashCode();
        bool isAbsolute();
        bool isDirectory();
        bool isFile();
        bool isHidden();
        std::int64_t lastModified();
        std::int64_t length();
        Array<String> list();
        Array<String> list(FilenameFilter filter);
        Array<File> listFiles();
        Array<File> listFiles(FilenameFilter filter);
        Array<File> listFiles(FileFilter filter);
        static Array<File> listRoots(JVM* vm);
        bool mkdir();
        bool mkdirs();
        bool renameTo(File dest);
        bool setExecutable(bool executable, bool ownerOnly);
        bool setExecutable(bool executable);
        bool setLastModified(std::int64_t time);
        bool setReadOnly();
        bool setReadable(bool readable, bool ownerOnly);
        bool setReadable(bool readable);
        bool setWritable(bool writable, bool ownerOnly);
        bool setWritable(bool writable);
        Path toPath();
        String toString();
        URI toURI();
        URL toURL();
    };
}

#endif /* File_hxx */
