//
//  CharsetEncoder.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "CharsetEncoder.hxx"
#include "Object.hxx"
#include "CharSequence.hxx"
#include "ByteBuffer.hxx"
#include "CharBuffer.hxx"
#include "Charset.hxx"
#include "CoderResult.hxx"
#include "CodingErrorAction.hxx"

using java::nio::charset::CharsetEncoder;
using java::lang::CharSequence;
using java::lang::Object;
using java::nio::ByteBuffer;
using java::nio::CharBuffer;
using java::nio::charset::Charset;
using java::nio::charset::CoderResult;
using java::nio::charset::CodingErrorAction;


CharsetEncoder::CharsetEncoder(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CharsetEncoder;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

float CharsetEncoder::averageBytesPerChar()
{
    static jmethodID averageBytesPerCharMethod = this->vm->GetMethodID(this->cls.get(), "averageBytesPerChar", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), averageBytesPerCharMethod);
}

bool CharsetEncoder::canEncode(char c)
{
    static jmethodID canEncodeMethod = this->vm->GetMethodID(this->cls.get(), "canEncode", "(C)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canEncodeMethod, c);
}

bool CharsetEncoder::canEncode(CharSequence cs)
{
    static jmethodID canEncodeMethod = this->vm->GetMethodID(this->cls.get(), "canEncode", "(Ljava/lang/CharSequence;)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), canEncodeMethod, cs.ref().get());
}

Charset CharsetEncoder::charset()
{
    static jmethodID charsetMethod = this->vm->GetMethodID(this->cls.get(), "charset", "()Ljava/nio/charset/Charset;");
    return Charset(this->vm, this->vm->CallObjectMethod(this->inst.get(), charsetMethod));
}

CoderResult CharsetEncoder::encode(CharBuffer in, ByteBuffer out, bool endOfInput)
{
    static jmethodID encodeMethod = this->vm->GetMethodID(this->cls.get(), "encode", "(Ljava/nio/CharBuffer;Ljava/nio/ByteBuffer;Z)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), encodeMethod, in.ref().get(), out.ref().get(), endOfInput));
}

ByteBuffer CharsetEncoder::encode(CharBuffer in)
{
    static jmethodID encodeMethod = this->vm->GetMethodID(this->cls.get(), "encode", "(Ljava/nio/CharBuffer;)Ljava/nio/ByteBuffer;");
    return ByteBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), encodeMethod, in.ref().get()));
}

CoderResult CharsetEncoder::flush(ByteBuffer out)
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "(Ljava/nio/ByteBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), flushMethod, out.ref().get()));
}

bool CharsetEncoder::isLegalReplacement(Array<std::uint8_t>& repl)
{
    static jmethodID isLegalReplacementMethod = this->vm->GetMethodID(this->cls.get(), "isLegalReplacement", "([B)Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isLegalReplacementMethod, repl.ref().get());
}

CodingErrorAction CharsetEncoder::malformedInputAction()
{
    static jmethodID malformedInputActionMethod = this->vm->GetMethodID(this->cls.get(), "malformedInputAction", "()Ljava/nio/charset/CodingErrorAction;");
    return CodingErrorAction(this->vm, this->vm->CallObjectMethod(this->inst.get(), malformedInputActionMethod));
}

float CharsetEncoder::maxBytesPerChar()
{
    static jmethodID maxBytesPerCharMethod = this->vm->GetMethodID(this->cls.get(), "maxBytesPerChar", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), maxBytesPerCharMethod);
}

CharsetEncoder CharsetEncoder::onMalformedInput(CodingErrorAction newAction)
{
    static jmethodID onMalformedInputMethod = this->vm->GetMethodID(this->cls.get(), "onMalformedInput", "(Ljava/nio/charset/CodingErrorAction;)Ljava/nio/charset/CharsetEncoder;");
    return CharsetEncoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), onMalformedInputMethod, newAction.ref().get()));
}

CharsetEncoder CharsetEncoder::onUnmappableCharacter(CodingErrorAction newAction)
{
    static jmethodID onUnmappableCharacterMethod = this->vm->GetMethodID(this->cls.get(), "onUnmappableCharacter", "(Ljava/nio/charset/CodingErrorAction;)Ljava/nio/charset/CharsetEncoder;");
    return CharsetEncoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), onUnmappableCharacterMethod, newAction.ref().get()));
}

CharsetEncoder CharsetEncoder::replaceWith(Array<std::uint8_t>& newReplacement)
{
    static jmethodID replaceWithMethod = this->vm->GetMethodID(this->cls.get(), "replaceWith", "([B)Ljava/nio/charset/CharsetEncoder;");
    return CharsetEncoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceWithMethod, newReplacement.ref().get()));
}

Array<std::uint8_t> CharsetEncoder::replacement()
{
    static jmethodID replacementMethod = this->vm->GetMethodID(this->cls.get(), "replacement", "()[B");
    jarray arr = reinterpret_cast<jarray>(this->vm->CallObjectMethod(this->inst.get(), replacementMethod));
    return Array<std::uint8_t>(this->vm, arr);
}

CharsetEncoder CharsetEncoder::reset()
{
    static jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()Ljava/nio/charset/CharsetEncoder;");
    return CharsetEncoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), resetMethod));
}

CodingErrorAction CharsetEncoder::unmappableCharacterAction()
{
    static jmethodID unmappableCharacterActionMethod = this->vm->GetMethodID(this->cls.get(), "unmappableCharacterAction", "()Ljava/nio/charset/CodingErrorAction;");
    return CodingErrorAction(this->vm, this->vm->CallObjectMethod(this->inst.get(), unmappableCharacterActionMethod));
}

CharsetEncoder::CharsetEncoder(JVM* vm, Charset cs, float averageBytesPerChar, float maxBytesPerChar, Array<std::uint8_t>& replacement) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CharsetEncoder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/nio/charset/Charset;FF[B)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, cs.ref().get(), averageBytesPerChar, maxBytesPerChar, replacement.ref().get()));
    }
}

CharsetEncoder::CharsetEncoder(JVM* vm, Charset cs, float averageBytesPerChar, float maxBytesPerChar) : Object()
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CharsetEncoder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/nio/charset/Charset;FF)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, cs.ref().get(), averageBytesPerChar, maxBytesPerChar));
    }
}

CoderResult CharsetEncoder::encodeLoop(CharBuffer in, ByteBuffer out)
{
    static jmethodID encodeLoopMethod = this->vm->GetMethodID(this->cls.get(), "encodeLoop", "(Ljava/nio/CharBuffer;Ljava/nio/ByteBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), encodeLoopMethod, in.ref().get(), out.ref().get()));
}

CoderResult CharsetEncoder::implFlush(ByteBuffer out)
{
    static jmethodID implFlushMethod = this->vm->GetMethodID(this->cls.get(), "implFlush", "(Ljava/nio/ByteBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), implFlushMethod, out.ref().get()));
}

void CharsetEncoder::implOnMalformedInput(CodingErrorAction newAction)
{
    static jmethodID implOnMalformedInputMethod = this->vm->GetMethodID(this->cls.get(), "implOnMalformedInput", "(Ljava/nio/charset/CodingErrorAction;)V");
    this->vm->CallVoidMethod(this->inst.get(), implOnMalformedInputMethod, newAction.ref().get());
}

void CharsetEncoder::implOnUnmappableCharacter(CodingErrorAction newAction)
{
    static jmethodID implOnUnmappableCharacterMethod = this->vm->GetMethodID(this->cls.get(), "implOnUnmappableCharacter", "(Ljava/nio/charset/CodingErrorAction;)V");
    this->vm->CallVoidMethod(this->inst.get(), implOnUnmappableCharacterMethod, newAction.ref().get());
}

void CharsetEncoder::implReplaceWith(Array<std::uint8_t>& newReplacement)
{
    static jmethodID implReplaceWithMethod = this->vm->GetMethodID(this->cls.get(), "implReplaceWith", "([B)V");
    this->vm->CallVoidMethod(this->inst.get(), implReplaceWithMethod, newReplacement.ref().get());
}

void CharsetEncoder::implReset()
{
    static jmethodID implResetMethod = this->vm->GetMethodID(this->cls.get(), "implReset", "()V");
    this->vm->CallVoidMethod(this->inst.get(), implResetMethod);
}
