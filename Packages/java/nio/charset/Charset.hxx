//
//  Charset.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Charset_hxx
#define Charset_hxx

#include "Object.hxx"
#include "Array.hxx"
#include "Comparable.hxx"

namespace java::nio::charset
{
    using java::lang::Object;
    using java::lang::String;
    using java::lang::Comparable;
    using java::util::Set;
    using java::util::SortedMap;
    using java::util::Locale;
    using java::nio::ByteBuffer;
    using java::nio::CharBuffer;
    using java::nio::charset::CharsetDecoder;
    using java::nio::charset::CharsetEncoder;
    
    class Charset : public Comparable
    {
    protected:
        Charset(JVM* jvm, String canonicalName, Array<String> aliases);
        
    public:
        Charset(JVM* jvm, jobject instance);
        
        Set<String> aliases();
        static SortedMap<String, Charset> availableCharsets(JVM* jvm);
        bool canEncode();
        bool contains(Charset cs);
        CharBuffer decode(ByteBuffer bb);
        static Charset defaultCharset(JVM* jvm);
        String displayName();
        String displayName(Locale locale);
        ByteBuffer encode(CharBuffer cb);
        ByteBuffer encode(String str);
        static Charset forName(JVM* jvm, String charsetName);
        bool isRegistered();
        static bool isSupported(JVM* jvm, String charsetName);
        String name();
        CharsetDecoder newDecoder();
        CharsetEncoder newEncoder();
    };
}

#endif /* Charset_hxx */
