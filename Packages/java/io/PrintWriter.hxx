//
//  PrintWriter.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef PrintWriter_hxx
#define PrintWriter_hxx

#include "Array.hxx"
#include "Writer.hxx"


namespace java::io
{
    using java::io::File;
    using java::io::OutputStream;
    using java::io::Writer;
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::lang::String;
    using java::util::Locale;
    
    
    class PrintWriter : public Writer
    {
    public:
        PrintWriter(JVM* vm, jobject instance);
        PrintWriter(JVM* vm, Writer out);
        PrintWriter(JVM* vm, Writer out, bool autoFlush);
        PrintWriter(JVM* vm, OutputStream out);
        PrintWriter(JVM* vm, OutputStream out, bool autoFlush);
        PrintWriter(JVM* vm, String fileName);
        PrintWriter(JVM* vm, String fileName, String csn);
        PrintWriter(JVM* vm, File file);
        PrintWriter(JVM* vm, File file, String csn);
        
        PrintWriter append(CharSequence csq);
        PrintWriter append(CharSequence csq, std::int32_t start, std::int32_t end);
        PrintWriter append(char c);
        bool checkError();
        void close();
        void flush();
        PrintWriter format(String arg0, Array<Object>& arg1);
        PrintWriter format(Locale arg0, String arg1, Array<Object>& arg2);
        void print(bool b);
        void print(char c);
        void print(std::int32_t i);
        void print(std::int64_t l);
        void print(float f);
        void print(double d);
        void print(Array<char>& s);
        void print(String s);
        void print(Object obj);
        PrintWriter printf(String arg0, Array<Object>& arg1);
        PrintWriter printf(Locale arg0, String arg1, Array<Object>& arg2);
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
        void write(std::int32_t c);
        void write(Array<char>& buf, std::int32_t off, std::int32_t len);
        void write(Array<char>& buf);
        void write(String s, std::int32_t off, std::int32_t len);
        void write(String s);
        
        
    protected:
        void clearError();
        void setError();
    };
}

#endif /* PrintWriter_hxx */
