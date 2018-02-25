//
//  CharsetDecoder.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharsetDecoder_hxx
#define CharsetDecoder_hxx

#include "Object.hxx"
#include "String.hxx"
#include "ByteBuffer.hxx"
#include "CharBuffer.hxx"
#include "Charset.hxx"
#include "CoderResult.hxx"
#include "CodingErrorAction.hxx"


namespace java::nio::charset
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::ByteBuffer;
    using java::nio::CharBuffer;
    using java::nio::charset::Charset;
    using java::nio::charset::CoderResult;
    using java::nio::charset::CodingErrorAction;
    
    
    class CharsetDecoder : public Object
    {
    public:
        CharsetDecoder(JVM* vm, jobject instance);
        
        float averageCharsPerByte();
        Charset charset();
        CoderResult decode(ByteBuffer in, CharBuffer out, bool endOfInput);
        CharBuffer decode(ByteBuffer in);
        Charset detectedCharset();
        CoderResult flush(CharBuffer out);
        bool isAutoDetecting();
        bool isCharsetDetected();
        CodingErrorAction malformedInputAction();
        float maxCharsPerByte();
        CharsetDecoder onMalformedInput(CodingErrorAction newAction);
        CharsetDecoder onUnmappableCharacter(CodingErrorAction newAction);
        CharsetDecoder replaceWith(String newReplacement);
        String replacement();
        CharsetDecoder reset();
        CodingErrorAction unmappableCharacterAction();
        
        
    protected:
        CharsetDecoder(JVM* vm, Charset cs, float averageCharsPerByte, float maxCharsPerByte);
        
        CoderResult decodeLoop(ByteBuffer in, CharBuffer out);
        CoderResult implFlush(CharBuffer out);
        void implOnMalformedInput(CodingErrorAction newAction);
        void implOnUnmappableCharacter(CodingErrorAction newAction);
        void implReplaceWith(String newReplacement);
        void implReset();
    };
}

#endif /* CharsetDecoder_hxx */
