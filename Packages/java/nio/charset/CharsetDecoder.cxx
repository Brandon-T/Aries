//
//  CharsetDecoder.cxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "CharsetDecoder.hxx"

using java::nio::charset::CharsetDecoder;
using java::lang::Object;
using java::lang::String;
using java::nio::ByteBuffer;
using java::nio::CharBuffer;
using java::nio::charset::Charset;
using java::nio::charset::CoderResult;
using java::nio::charset::CodingErrorAction;

CharsetDecoder::CharsetDecoder(JVM* vm, jobject instance) : Object()
{
    if (vm && instance)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CharsetDecoder;"));
        this->inst = JVMRef<jobject>(this->vm, instance);
    }
}

float CharsetDecoder::averageCharsPerByte()
{
    static jmethodID averageCharsPerByteMethod = this->vm->GetMethodID(this->cls.get(), "averageCharsPerByte", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), averageCharsPerByteMethod);
}

Charset CharsetDecoder::charset()
{
    static jmethodID charsetMethod = this->vm->GetMethodID(this->cls.get(), "charset", "()Ljava/nio/charset/Charset;");
    return Charset(this->vm, this->vm->CallObjectMethod(this->inst.get(), charsetMethod));
}

CoderResult CharsetDecoder::decode(ByteBuffer in, CharBuffer out, bool endOfInput)
{
    static jmethodID decodeMethod = this->vm->GetMethodID(this->cls.get(), "decode", "(Ljava/nio/ByteBuffer;Ljava/nio/CharBuffer;Z)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), decodeMethod, in.ref().get(), out.ref().get(), endOfInput));
}

CharBuffer CharsetDecoder::decode(ByteBuffer in)
{
    static jmethodID decodeMethod = this->vm->GetMethodID(this->cls.get(), "decode", "(Ljava/nio/ByteBuffer;)Ljava/nio/CharBuffer;");
    return CharBuffer(this->vm, this->vm->CallObjectMethod(this->inst.get(), decodeMethod, in.ref().get()));
}

Charset CharsetDecoder::detectedCharset()
{
    static jmethodID detectedCharsetMethod = this->vm->GetMethodID(this->cls.get(), "detectedCharset", "()Ljava/nio/charset/Charset;");
    return Charset(this->vm, this->vm->CallObjectMethod(this->inst.get(), detectedCharsetMethod));
}

CoderResult CharsetDecoder::flush(CharBuffer out)
{
    static jmethodID flushMethod = this->vm->GetMethodID(this->cls.get(), "flush", "(Ljava/nio/CharBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), flushMethod, out.ref().get()));
}

bool CharsetDecoder::isAutoDetecting()
{
    static jmethodID isAutoDetectingMethod = this->vm->GetMethodID(this->cls.get(), "isAutoDetecting", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isAutoDetectingMethod);
}

bool CharsetDecoder::isCharsetDetected()
{
    static jmethodID isCharsetDetectedMethod = this->vm->GetMethodID(this->cls.get(), "isCharsetDetected", "()Z");
    return this->vm->CallBooleanMethod(this->inst.get(), isCharsetDetectedMethod);
}

CodingErrorAction CharsetDecoder::malformedInputAction()
{
    static jmethodID malformedInputActionMethod = this->vm->GetMethodID(this->cls.get(), "malformedInputAction", "()Ljava/nio/charset/CodingErrorAction;");
    return CodingErrorAction(this->vm, this->vm->CallObjectMethod(this->inst.get(), malformedInputActionMethod));
}

float CharsetDecoder::maxCharsPerByte()
{
    static jmethodID maxCharsPerByteMethod = this->vm->GetMethodID(this->cls.get(), "maxCharsPerByte", "()F");
    return this->vm->CallFloatMethod(this->inst.get(), maxCharsPerByteMethod);
}

CharsetDecoder CharsetDecoder::onMalformedInput(CodingErrorAction newAction)
{
    static jmethodID onMalformedInputMethod = this->vm->GetMethodID(this->cls.get(), "onMalformedInput", "(Ljava/nio/charset/CodingErrorAction;)Ljava/nio/charset/CharsetDecoder;");
    return CharsetDecoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), onMalformedInputMethod, newAction.ref().get()));
}

CharsetDecoder CharsetDecoder::onUnmappableCharacter(CodingErrorAction newAction)
{
    static jmethodID onUnmappableCharacterMethod = this->vm->GetMethodID(this->cls.get(), "onUnmappableCharacter", "(Ljava/nio/charset/CodingErrorAction;)Ljava/nio/charset/CharsetDecoder;");
    return CharsetDecoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), onUnmappableCharacterMethod, newAction.ref().get()));
}

CharsetDecoder CharsetDecoder::replaceWith(String newReplacement)
{
    static jmethodID replaceWithMethod = this->vm->GetMethodID(this->cls.get(), "replaceWith", "(Ljava/lang/String;)Ljava/nio/charset/CharsetDecoder;");
    return CharsetDecoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), replaceWithMethod, newReplacement.ref().get()));
}

String CharsetDecoder::replacement()
{
    static jmethodID replacementMethod = this->vm->GetMethodID(this->cls.get(), "replacement", "()Ljava/lang/String;");
    return String(this->vm, this->vm->CallObjectMethod(this->inst.get(), replacementMethod));
}

CharsetDecoder CharsetDecoder::reset()
{
    static jmethodID resetMethod = this->vm->GetMethodID(this->cls.get(), "reset", "()Ljava/nio/charset/CharsetDecoder;");
    return CharsetDecoder(this->vm, this->vm->CallObjectMethod(this->inst.get(), resetMethod));
}

CodingErrorAction CharsetDecoder::unmappableCharacterAction()
{
    static jmethodID unmappableCharacterActionMethod = this->vm->GetMethodID(this->cls.get(), "unmappableCharacterAction", "()Ljava/nio/charset/CodingErrorAction;");
    return CodingErrorAction(this->vm, this->vm->CallObjectMethod(this->inst.get(), unmappableCharacterActionMethod));
}

CharsetDecoder::CharsetDecoder(JVM* vm, Charset cs, float averageCharsPerByte, float maxCharsPerByte)
{
    if (vm)
    {
        this->vm = vm;
        this->cls = JVMRef<jclass>(this->vm, this->vm->FindClass("Ljava/nio/charset/CharsetDecoder;"));
        jmethodID constructor = this->vm->GetMethodID(this->cls.get(), "<init>", "(Ljava/nio/charset/Charset;FF)V");
        this->inst = JVMRef<jobject>(this->vm, this->vm->NewObject(this->cls.get(), constructor, cs.ref().get(), averageCharsPerByte, maxCharsPerByte));
    }
}

CoderResult CharsetDecoder::decodeLoop(ByteBuffer in, CharBuffer out)
{
    static jmethodID decodeLoopMethod = this->vm->GetMethodID(this->cls.get(), "decodeLoop", "(Ljava/nio/ByteBuffer;Ljava/nio/CharBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), decodeLoopMethod, in.ref().get(), out.ref().get()));
}

CoderResult CharsetDecoder::implFlush(CharBuffer out)
{
    static jmethodID implFlushMethod = this->vm->GetMethodID(this->cls.get(), "implFlush", "(Ljava/nio/CharBuffer;)Ljava/nio/charset/CoderResult;");
    return CoderResult(this->vm, this->vm->CallObjectMethod(this->inst.get(), implFlushMethod, out.ref().get()));
}

void CharsetDecoder::implOnMalformedInput(CodingErrorAction newAction)
{
    static jmethodID implOnMalformedInputMethod = this->vm->GetMethodID(this->cls.get(), "implOnMalformedInput", "(Ljava/nio/charset/CodingErrorAction;)V");
    this->vm->CallVoidMethod(this->inst.get(), implOnMalformedInputMethod, newAction.ref().get());
}

void CharsetDecoder::implOnUnmappableCharacter(CodingErrorAction newAction)
{
    static jmethodID implOnUnmappableCharacterMethod = this->vm->GetMethodID(this->cls.get(), "implOnUnmappableCharacter", "(Ljava/nio/charset/CodingErrorAction;)V");
    this->vm->CallVoidMethod(this->inst.get(), implOnUnmappableCharacterMethod, newAction.ref().get());
}

void CharsetDecoder::implReplaceWith(String newReplacement)
{
    static jmethodID implReplaceWithMethod = this->vm->GetMethodID(this->cls.get(), "implReplaceWith", "(Ljava/lang/String;)V");
    this->vm->CallVoidMethod(this->inst.get(), implReplaceWithMethod, newReplacement.ref().get());
}

void CharsetDecoder::implReset()
{
    static jmethodID implResetMethod = this->vm->GetMethodID(this->cls.get(), "implReset", "()V");
    this->vm->CallVoidMethod(this->inst.get(), implResetMethod);
}
