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
    class OutputStream;
    class ByteArrayOutputStream;
}

namespace java::security
{
    class ProtectionDomain;
}

namespace java::net
{
    class URL;
}

namespace java::util
{
    class List;
    
    template<typename T>
    class Iterator;
    
    template<typename T>
    class Collection;
    
    template<typename T>
    class Set;
    
    template<typename K, typename V>
    class Map;
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

#endif /* JNIPackage_hxx */
