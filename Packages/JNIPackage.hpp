//
//  JNIPackage.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef JNIPackage_hpp
#define JNIPackage_hpp

namespace java
{
    namespace lang
    {
        class Class;
        class String;
        class ClassLoader;
        class Package;
        class Throwable;
        class Exception;
        class StackTraceElement;
        class Iterable;
        class Object;
        
        namespace annotation
        {
            class Annotation;
        }
        
        namespace reflect
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
    }
    
    namespace io
    {
        class PrintStream;
        class PrintWriter;
        class InputStream;
        class ByteArrayInputStream;
        class FilterInputStream;
        class OutputStream;
        class ByteArrayOutputStream;
    }
    
    namespace security
    {
        class ProtectionDomain;
    }
    
    namespace net
    {
        class URL;
    }
    
    namespace util
    {
        class List;
        
        namespace zip
        {
            class Inflater;
            class ZipEntry;
            class InflaterInputStream;
            class ZipInputStream;
        }
        
        namespace jar
        {
            class JarEntry;
            class Manifest;
            class JarInputStream;
        }
    }
}

#endif /* JNIPackage_hpp */
