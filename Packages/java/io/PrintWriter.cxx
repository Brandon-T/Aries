//
//  PrintWriter.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "PrintWriter.hxx"
#include "Writer.hxx"
#include "File.hxx"
#include "OutputStream.hxx"
#include "Writer.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Locale.hxx"

using java::io::PrintWriter;
using java::io::File;
using java::io::OutputStream;
using java::io::Writer;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::util::Locale;


PrintWriter::PrintWriter(JVM* vm, jobject instance) : Writer()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

PrintWriter::PrintWriter(JVM* vm, Writer out) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/Writer;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get()));
    }
}

PrintWriter::PrintWriter(JVM* vm, Writer out, bool autoFlush) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/Writer;Z)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get(), autoFlush));
    }
}

PrintWriter::PrintWriter(JVM* vm, OutputStream out) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get()));
    }
}

PrintWriter::PrintWriter(JVM* vm, OutputStream out, bool autoFlush) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;Z)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get(), autoFlush));
    }
}

PrintWriter::PrintWriter(JVM* vm, String fileName) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, fileName.ref().get()));
    }
}

PrintWriter::PrintWriter(JVM* vm, String fileName, String csn) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, fileName.ref().get(), csn.ref().get()));
    }
}

PrintWriter::PrintWriter(JVM* vm, File file) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/File;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, file.ref().get()));
    }
}

PrintWriter::PrintWriter(JVM* vm, File file, String csn) : Writer()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintWriter;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, file.ref().get(), csn.ref().get()));
    }
}

PrintWriter PrintWriter::append(CharSequence csq)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get()));
}

PrintWriter PrintWriter::append(CharSequence csq, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get(), start, end));
}

PrintWriter PrintWriter::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

bool PrintWriter::checkError()
{
    static jmethodID checkErrorMethod = this->vm->GetMethodID(this->cls.get(), "checkError", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), checkErrorMethod);
}

void PrintWriter::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

void PrintWriter::flush()
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "()V");
    this->vm->CallVoidMethod(this->inst.get(), flushMethod);
}

PrintWriter PrintWriter::format(String arg0, Array<Object>& arg1)
{
    static jmethodID formatMethod = this->vm->GetMethodID(this->cls.get(), "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), formatMethod, arg0.ref().get(), arg1.ref().get()));
}

PrintWriter PrintWriter::format(Locale arg0, String arg1, Array<Object>& arg2)
{
    static jmethodID formatMethod = this->vm->GetMethodID(this->cls.get(), "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), formatMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

void PrintWriter::print(bool b)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, b);
}

void PrintWriter::print(char c)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(C)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, c);
}

void PrintWriter::print(std::int32_t i)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, i);
}

void PrintWriter::print(std::int64_t l)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, l);
}

void PrintWriter::print(float f)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(F)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, f);
}

void PrintWriter::print(double d)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(D)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, d);
}

void PrintWriter::print(Array<char>& s)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "([C)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, s.ref().get());
}

void PrintWriter::print(String s)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, s.ref().get());
}

void PrintWriter::print(Object obj)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, obj.ref().get());
}

PrintWriter PrintWriter::printf(String arg0, Array<Object>& arg1)
{
    static jmethodID printfMethod = this->vm->GetMethodID(this->cls.get(), "printf", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), printfMethod, arg0.ref().get(), arg1.ref().get()));
}

PrintWriter PrintWriter::printf(Locale arg0, String arg1, Array<Object>& arg2)
{
    static jmethodID printfMethod = this->vm->GetMethodID(this->cls.get(), "printf", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
    return PrintWriter(this->vm, this->vm->CallObjectMethod(this->inst.get(), printfMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

void PrintWriter::println()
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "()V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod);
}

void PrintWriter::println(bool x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(char x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(C)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(std::int32_t x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(std::int64_t x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(float x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(F)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(double x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(D)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintWriter::println(Array<char>& x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "([C)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintWriter::println(String x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintWriter::println(Object x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintWriter::write(std::int32_t c)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, c);
}

void PrintWriter::write(Array<char>& buf, std::int32_t off, std::int32_t len)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([CII)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, buf.ref().get(), off, len);
}

void PrintWriter::write(Array<char>& buf)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([C)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, buf.ref().get());
}

void PrintWriter::write(String s, std::int32_t off, std::int32_t len)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/lang/String;II)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, s.ref().get(), off, len);
}

void PrintWriter::write(String s)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, s.ref().get());
}

void PrintWriter::clearError()
{
    static jmethodID clearErrorMethod = this->vm->GetMethodID(this->cls.get(), "clearError", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearErrorMethod);
}

void PrintWriter::setError()
{
    static jmethodID setErrorMethod = this->vm->GetMethodID(this->cls.get(), "setError", "()V");
    this->vm->CallVoidMethod(this->inst.get(), setErrorMethod);
}
