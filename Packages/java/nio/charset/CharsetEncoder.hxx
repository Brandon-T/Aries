//
//  CharsetEncoder.hxx
//  Aries
//
//  Created by Brandon on 2017-11-12.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef CharsetEncoder_hxx
#define CharsetEncoder_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::charset
{
    using java::lang::CharSequence;
    using java::lang::Object;
    using java::nio::ByteBuffer;
    using java::nio::CharBuffer;
    using java::nio::charset::Charset;
    using java::nio::charset::CoderResult;
    using java::nio::charset::CodingErrorAction;
    
    
    class CharsetEncoder : public Object
    {
    public:
        CharsetEncoder(JVM* vm, jobject instance);
        
        float averageBytesPerChar();
        bool canEncode(char c);
        bool canEncode(CharSequence cs);
        Charset charset();
        CoderResult encode(CharBuffer in, ByteBuffer out, bool endOfInput);
        ByteBuffer encode(CharBuffer in);
        CoderResult flush(ByteBuffer out);
        bool isLegalReplacement(Array<std::uint8_t>& repl);
        CodingErrorAction malformedInputAction();
        float maxBytesPerChar();
        CharsetEncoder onMalformedInput(CodingErrorAction newAction);
        CharsetEncoder onUnmappableCharacter(CodingErrorAction newAction);
        CharsetEncoder replaceWith(Array<std::uint8_t>& newReplacement);
        Array<std::uint8_t> replacement();
        CharsetEncoder reset();
        CodingErrorAction unmappableCharacterAction();
        
        
    protected:
        CharsetEncoder(JVM* vm, Charset cs, float averageBytesPerChar, float maxBytesPerChar, Array<std::uint8_t>& replacement);
        CharsetEncoder(JVM* vm, Charset cs, float averageBytesPerChar, float maxBytesPerChar);
        
        CoderResult encodeLoop(CharBuffer in, ByteBuffer out);
        CoderResult implFlush(ByteBuffer out);
        void implOnMalformedInput(CodingErrorAction newAction);
        void implOnUnmappableCharacter(CodingErrorAction newAction);
        void implReplaceWith(Array<std::uint8_t>& newReplacement);
        void implReset();
    };
}

#endif /* CharsetEncoder_hxx */
