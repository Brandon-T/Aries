//
//  PrintStream.cxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "PrintStream.hxx"
#include "FilterOutputStream.hxx"
#include "File.hxx"
#include "OutputStream.hxx"
#include "CharSequence.hxx"
#include "Object.hxx"
#include "String.hxx"
#include "Locale.hxx"

using java::io::PrintStream;
using java::io::File;
using java::io::FilterOutputStream;
using java::io::OutputStream;
using java::lang::CharSequence;
using java::lang::Object;
using java::lang::String;
using java::util::Locale;


PrintStream::PrintStream(JVM* vm, jobject instance) : FilterOutputStream()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

PrintStream::PrintStream(JVM* vm, OutputStream out) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get()));
    }
}

PrintStream::PrintStream(JVM* vm, OutputStream out, bool autoFlush) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;Z)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get(), autoFlush));
    }
}

PrintStream::PrintStream(JVM* vm, OutputStream out, bool autoFlush, String encoding) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/OutputStream;ZLjava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, out.ref().get(), autoFlush, encoding.ref().get()));
    }
}

PrintStream::PrintStream(JVM* vm, String fileName) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, fileName.ref().get()));
    }
}

PrintStream::PrintStream(JVM* vm, String fileName, String csn) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, fileName.ref().get(), csn.ref().get()));
    }
}

PrintStream::PrintStream(JVM* vm, File file) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/File;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, file.ref().get()));
    }
}

PrintStream::PrintStream(JVM* vm, File file, String csn) : FilterOutputStream()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/io/PrintStream;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/io/File;Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, file.ref().get(), csn.ref().get()));
    }
}

PrintStream PrintStream::append(CharSequence csq)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get()));
}

PrintStream PrintStream::append(CharSequence csq, std::int32_t start, std::int32_t end)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(Ljava/lang/CharSequence;II)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, csq.ref().get(), start, end));
}

PrintStream PrintStream::append(char c)
{
    static jmethodID appendMethod = this->vm->GetMethodID(this->cls.get(), "append", "(C)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), appendMethod, c));
}

bool PrintStream::checkError()
{
    static jmethodID checkErrorMethod = this->vm->GetMethodID(this->cls.get(), "checkError", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), checkErrorMethod);
}

void PrintStream::close()
{
    static jmethodID closeMethod = this->vm->GetMethodID(this->cls.get(), "close", "()V");
    this->vm->CallVoidMethod(this->inst.get(), closeMethod);
}

void PrintStream::flush()
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "()V");
    this->vm->CallVoidMethod(this->inst.get(), flushMethod);
}

PrintStream PrintStream::format(String arg0, Array<Object>& arg1)
{
    static jmethodID formatMethod = this->vm->GetMethodID(this->cls.get(), "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), formatMethod, arg0.ref().get(), arg1.ref().get()));
}

PrintStream PrintStream::format(Locale arg0, String arg1, Array<Object>& arg2)
{
    static jmethodID formatMethod = this->vm->GetMethodID(this->cls.get(), "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), formatMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

void PrintStream::print(bool b)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, b);
}

void PrintStream::print(char c)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(C)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, c);
}

void PrintStream::print(std::int32_t i)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, i);
}

void PrintStream::print(std::int64_t l)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, l);
}

void PrintStream::print(float f)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(F)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, f);
}

void PrintStream::print(double d)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(D)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, d);
}

void PrintStream::print(Array<char>& s)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "([C)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, s.ref().get());
}

void PrintStream::print(String s)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, s.ref().get());
}

void PrintStream::print(Object obj)
{
    static jmethodID printMethod = this->vm->GetMethodID(this->cls.get(), "print", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), printMethod, obj.ref().get());
}

PrintStream PrintStream::printf(String arg0, Array<Object>& arg1)
{
    static jmethodID printfMethod = this->vm->GetMethodID(this->cls.get(), "printf", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), printfMethod, arg0.ref().get(), arg1.ref().get()));
}

PrintStream PrintStream::printf(Locale arg0, String arg1, Array<Object>& arg2)
{
    static jmethodID printfMethod = this->vm->GetMethodID(this->cls.get(), "printf", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
    return PrintStream(this->vm, this->vm->CallObjectMethod(this->inst.get(), printfMethod, arg0.ref().get(), arg1.ref().get(), arg2.ref().get()));
}

void PrintStream::println()
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "()V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod);
}

void PrintStream::println(bool x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Z)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(char x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(C)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(std::int32_t x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(std::int64_t x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(J)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(float x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(F)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(double x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(D)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x);
}

void PrintStream::println(Array<char>& x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "([C)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintStream::println(String x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintStream::println(Object x)
{
    static jmethodID printlnMethod = this->vm->GetMethodID(this->cls.get(), "println", "(Ljava/lang/Object;)V");
    this->vm->CallVoidMethod(this->inst.get(), printlnMethod, x.ref().get());
}

void PrintStream::write(std::int32_t b)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "(I)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, b);
}

void PrintStream::write(Array<std::uint8_t>& buf, std::int32_t off, std::int32_t len)
{
    static jmethodID writeMethod = this->vm->GetMethodID(this->cls.get(), "write", "([BII)V");
    this->vm->CallVoidMethod(this->inst.get(), writeMethod, buf.ref().get(), off, len);
}

void PrintStream::clearError()
{
    static jmethodID clearErrorMethod = this->vm->GetMethodID(this->cls.get(), "clearError", "()V");
    this->vm->CallVoidMethod(this->inst.get(), clearErrorMethod);
}

void PrintStream::setError()
{
    static jmethodID setErrorMethod = this->vm->GetMethodID(this->cls.get(), "setError", "()V");
    this->vm->CallVoidMethod(this->inst.get(), setErrorMethod);
}
