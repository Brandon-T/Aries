//
//  Charset.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Charset.hxx"
#include "Comparable.hxx"
#include "String.hxx"
#include "Set.hxx"
#include "SortedMap.hxx"
#include "ByteBuffer.hxx"
#include "CharBuffer.hxx"
#include "Locale.hxx"
#include "CharsetDecoder.hxx"
#include "CharsetEncoder.hxx"

using java::lang::Comparable;
using java::lang::String;
using java::util::Set;
using java::util::SortedMap;
using java::util::Locale;
using java::nio::ByteBuffer;
using java::nio::CharBuffer;
using java::nio::charset::Charset;
using java::nio::charset::CharsetDecoder;
using java::nio::charset::CharsetEncoder;

Charset::Charset(JVM* jvm, String canonicalName, Array<String> aliases) : Comparable(nullptr)
{
    if (jvm)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/Charset;"));
        
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/lang/String;[Ljava/lang/String;)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, canonicalName.ref().get(), aliases.ref().get()));
    }
}

Charset::Charset(JVM* jvm, jobject instance) : Comparable(nullptr)
{
    if (jvm && instance)
    {
        this->vm = jvm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/Charset;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

Set<String> Charset::aliases()
{
    jmethodID aliasesMethod = this->vm->GetMethodID(this->cls.get(), "aliases", "()Ljava/util/Set;");
    return Set<String>(this->vm, this->vm->CallObjectMethod(this->inst.get(), aliasesMethod));
}

SortedMap<String, Charset> Charset::availableCharsets(JVM* jvm)
{
    jclass cls = jvm->FindClass("Ljava/nio/charset/Charset;");
    jmethodID availableCharsetsMethod = jvm->GetStaticMethodID(cls, "availableCharsets", "()Ljava/util/SortedMap;");
    return SortedMap<String, Charset>(jvm, jvm->CallStaticObjectMethod(cls, availableCharsetsMethod));
}

bool Charset::canEncode()
{
    jmethodID canEncodeMethod = this->vm->GetMethodID(this->cls.get(), "canEncode", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canEncodeMethod);
}

bool Charset::contains(Charset cs)
{
    jmethodID containsMethod = this->vm->GetMethodID(this->cls.get(), "contains", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), containsMethod, cs.ref().get());
}

CharBuffer Charset::decode(ByteBuffer bb)
{
    jmethodID decodeMethod = this->vm->GetMethodID(this->cls.get(), "decode", "(Ljava/nio/ByteBuffer;)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), decodeMethod, bb.ref().get()));
}

Charset Charset::defaultCharset(JVM* jvm)
{
    jclass cls = jvm->FindClass("Ljava/nio/charset/Charset;");
    jmethodID defaultCharsetMethod = jvm->GetStaticMethodID(cls, "defaultCharset", "()Ljava/nio/charset/Charset;");
    return Charset(jvm, jvm->CallStaticObjectMethod(cls, defaultCharsetMethod));
}

String Charset::displayName()
{
    jmethodID displayNameMethod = this->vm->GetMethodID(this->cls.get(), "displayName", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), displayNameMethod));
}

String Charset::displayName(Locale locale)
{
    jmethodID displayNameMethod = this->vm->GetMethodID(this->cls.get(), "displayName", "(Ljava/util/Locale;)Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), displayNameMethod, locale.ref().get()));
}

ByteBuffer Charset::encode(CharBuffer cb)
{
    jmethodID encodeMethod = this->vm->GetMethodID(this->cls.get(), "encode", "(Ljava/nio/CharBuffer;)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), encodeMethod, cb.ref().get()));
}

ByteBuffer Charset::encode(String str)
{
    jmethodID encodeMethod = this->vm->GetMethodID(this->cls.get(), "encode", "(Ljava/lang/String;)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), encodeMethod, str.ref().get()));
}

Charset Charset::forName(JVM* jvm, String charsetName)
{
    jclass cls = jvm->FindClass("Ljava/nio/charset/Charset;");
    jmethodID forNameMethod = jvm->GetStaticMethodID(cls, "forName", "(Ljava/lang/String;)Ljava/nio/charset/Charset;");
    return Charset(jvm, jvm->CallStaticObjectMethod(cls, forNameMethod, charsetName.ref().get()));
}

bool Charset::isRegistered()
{
    jmethodID isRegisteredMethod = this->vm->GetMethodID(this->cls.get(), "isRegistered", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isRegisteredMethod);
}

bool Charset::isSupported(JVM* jvm, String charsetName)
{
    jclass cls = jvm->FindClass("Ljava/nio/charset/Charset;");
    jmethodID isSupportedMethod = jvm->GetStaticMethodID(cls, "isSupported", "(Ljava/lang/String;)Z");
    return jvm->CallStaticBooleanMethod(cls, isSupportedMethod, charsetName.ref().get());
}

String Charset::name()
{
    jmethodID nameMethod = this->vm->GetMethodID(this->cls.get(), "name", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), nameMethod));
}

CharsetDecoder Charset::newDecoder()
{
    jmethodID newDecoderMethod = this->vm->GetMethodID(this->cls.get(), "newDecoder", "()Ljava/nio/charset/CharsetDecoder;");
    return CharsetDecoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), newDecoderMethod));
}

CharsetEncoder Charset::newEncoder()
{
    jmethodID newEncoderMethod = this->vm->GetMethodID(this->cls.get(), "newEncoder", "()Ljava/nio/charset/CharsetEncoder;");
    return CharsetEncoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), newEncoderMethod));
}
