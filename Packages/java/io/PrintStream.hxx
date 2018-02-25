//
//  PrintStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef PrintStream_hxx
#define PrintStream_hxx

#include "Array.hxx"
#include "FilterOutputStream.hxx"


namespace java::io
{
    using java::io::File;
    using java::io::FilterOutputStream;
    using java::io::OutputStream;
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    using java::util::Locale;
    
    
    class PrintStream : public FilterOutputStream
    {
    public:
        PrintStream(JVM* vm, jobject instance);
        PrintStream(JVM* vm, OutputStream out);
        PrintStream(JVM* vm, OutputStream out, bool autoFlush);
        PrintStream(JVM* vm, OutputStream out, bool autoFlush, String encoding);
        PrintStream(JVM* vm, String fileName);
        PrintStream(JVM* vm, String fileName, String csn);
        PrintStream(JVM* vm, File file);
        PrintStream(JVM* vm, File file, String csn);
        
        PrintStream append(CharSequence csq);
        PrintStream append(CharSequence csq, std::int32_t start, std::int32_t end);
        PrintStream append(char c);
        bool checkError();
        void close();
        void flush();
        PrintStream format(String arg0, Array<Object>& arg1);
        PrintStream format(Locale arg0, String arg1, Array<Object>& arg2);
        void print(bool b);
        void print(char c);
        void print(std::int32_t i);
        void print(std::int64_t l);
        void print(float f);
        void print(double d);
        void print(Array<char>& s);
        void print(String s);
        void print(Object obj);
        PrintStream printf(String arg0, Array<Object>& arg1);
        PrintStream printf(Locale arg0, String arg1, Array<Object>& arg2);
        void println();
        void println(bool x);
        void println(char x);
        void println(std::int32_t x);
        void println(std::int64_t x);
        void println(float x);
        void println(double x);
        void println(Array<char>& x);
        void println(String x);
        void println(Object x);
        void write(std::int32_t b);
        void write(Array<std::uint8_t>& buf, std::int32_t off, std::int32_t len);
        
        
    protected:
        void clearError();
        void setError();
    };
}

#endif /* PrintStream_hxx */
