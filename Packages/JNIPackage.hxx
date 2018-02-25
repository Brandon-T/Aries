//
//  JNIPackage.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JNIPackage_hxx
#define JNIPackage_hxx

namespace java::lang
{
    class Class;
    class String;
    class ClassLoader;
    class Package;
    class Throwable;
    class Exception;
    class StackTraceElement;
    class Object;
    class Comparable;
    class Appendable;
    class CharSequence;
    class StringBuffer;
    class StringBuilder;
    class AbstractStringBuilder;
    class Enum;
    class Character;
    
    template<typename T>
    class Iterable;
}

namespace java::lang::reflect
{
    class Constructor;
    class Field;
    class Method;
    class Type;
    class AnnotatedElement;
    class GenericDeclaration;
    class TypeVariable;
    class AnnotatedType;
}

namespace java::lang::annotation
{
    class Annotation;
}


namespace java::io
{
    class PrintStream;
    class PrintWriter;
    class InputStream;
    class ByteArrayInputStream;
    class FilterInputStream;
    class FilterOutputStream;
    class OutputStream;
    class ByteArrayOutputStream;
    class File;
    class FileFilter;
    class FilenameFilter;
}

namespace java::nio
{
    class Buffer;
    class ByteBuffer;
    class CharBuffer;
    class DoubleBuffer;
    class FloatBuffer;
    class IntBuffer;
    class LongBuffer;
    class ShortBuffer;
    class ByteOrder;
}

namespace java::nio::charset
{
    class Charset;
    class CharsetDecoder;
    class CharsetEncoder;
    class CoderResult;
    class CodingErrorAction;
}

namespace java::nio::file
{
    class FileSystem;
    class LinkOption;
    class FileStore;
    class Path;
    class PathMatcher;
    class WatchEvent;
    class WatchKey;
    class WatchService;
    class AccessMode;
    class CopyOption;
    class DirectoryStream;
    class OpenOption;
}

namespace java::nio::file::attribute
{
    class UserPrincipalLookupService;
    class FileStoreAttributeView;
    class GroupPrincipal;
    class UserPrincipal;
    class BasicFileAttributes;
    class FileAttribute;
    class FileAttributeView;
}

namespace java::nio::file::spi
{
    class FileSystemProvider;
}

namespace java::nio::channels
{
    class AsynchronousFileChannel;
    class FileChannel;
    class SeekableByteChannel;
}

namespace java::security
{
    class ProtectionDomain;
    class Permission;
    class PermissionCollection;
}

namespace java::net
{
    class URL;
    class Proxy;
    class URI;
    class URLConnection;
    class URLStreamHandler;
    class URLStreamHandlerFactory;
    class InetAddress;
    class SocketAddress;
    class NetworkInterface;
    class ContentHandlerFactory;
    class ContentHandler;
    class FileNameMap;
}

namespace java::util
{
    class Locale;
    
    template<typename T>
    class List;
    
    template<typename T>
    class Enumeration;
    
    template<typename T>
    class Comparator;
    
    template<typename T>
    class Iterator;
    
    template<typename T>
    class ListIterator;
    
    template<typename T>
    class Spliterator;
    
    template<typename T>
    class Collection;
    
    template<typename T>
    class Set;
    
    template<typename K, typename V>
    class Map;
    
    template<typename K, typename V>
    class SortedMap;
}

namespace java::util::zip
{
    class Inflater;
    class ZipEntry;
    class InflaterInputStream;
    class ZipInputStream;
}

namespace java::util::jar
{
    class JarEntry;
    class Manifest;
    class JarInputStream;
    class Attributes;
}

namespace java::util::stream
{
    class IntStream;
}

namespace java::util::function
{
    class IntConsumer;
    class IntSupplier;
    class Supplier;
    class DoubleConsumer;
    class DoubleSupplier;
}

namespace java::util::concurrent
{
    class TimeUnit;
}

#endif /* JNIPackage_hxx */
