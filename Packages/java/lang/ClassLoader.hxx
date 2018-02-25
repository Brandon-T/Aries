//
//  ClassLoader.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ClassLoader_hxx
#define ClassLoader_hxx

#include "Object.hxx"
#include "Array.hxx"

namespace java::lang
{
    using java::lang::Object;
    using java::io::InputStream;
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::Package;
    using java::lang::String;
    using java::net::URL;
    using java::nio::ByteBuffer;
    using java::security::ProtectionDomain;
    using java::util::Enumeration;
    
    class ClassLoader : public Object
    {
    public:
        ClassLoader(JVM* vm, jobject instance);
        
        void clearAssertionStatus();
        ClassLoader getParent();
        URL getResource(String name);
        InputStream getResourceAsStream(String name);
        Enumeration<URL> getResources(String name);
        static ClassLoader getSystemClassLoader(JVM* vm);
        static URL getSystemResource(JVM* vm, String name);
        static InputStream getSystemResourceAsStream(JVM* vm, String name);
        static Enumeration<URL> getSystemResources(JVM* vm, String name);
        Class loadClass(String name);
        void setClassAssertionStatus(String className, bool enabled);
        void setDefaultAssertionStatus(bool enabled);
        void setPackageAssertionStatus(String packageName, bool enabled);
        
        
    protected:
        ClassLoader(const ClassLoader &parent);
        ClassLoader();
        
        Class defineClass(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        Class defineClass(String name, Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        Class defineClass(String name, Array<std::uint8_t>& b, std::int32_t off, std::int32_t len, ProtectionDomain protectionDomain);
        Class defineClass(String name, ByteBuffer b, ProtectionDomain protectionDomain);
        Package definePackage(String name, String specTitle, String specVersion, String specVendor, String implTitle, String implVersion, String implVendor, URL sealBase);
        Class findClass(String name);
        String findLibrary(String libname);
        Class findLoadedClass(String name);
        URL findResource(String name);
        Enumeration<URL> findResources(String name);
        Class findSystemClass(String name);
        Object getClassLoadingLock(String className);
        Package getPackage(String name);
        Array<Package> getPackages();
        Class loadClass(String name, bool resolve);
        static bool registerAsParallelCapable(JVM* vm);
        void resolveClass(Class c);
        void setSigners(Class c, Array<Object>& signers);
    };
}

#endif /* ClassLoader_hxx */
