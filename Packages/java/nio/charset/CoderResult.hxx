//
//  CoderResult.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef CoderResult_hxx
#define CoderResult_hxx

#include "Object.hxx"
#include "String.hxx"


namespace java::nio::charset
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class CoderResult : public Object
    {
    public:
        CoderResult(JVM* vm, jobject instance);
        
        bool isError();
        bool isMalformed();
        bool isOverflow();
        bool isUnderflow();
        bool isUnmappable();
        std::int32_t length();
        static CoderResult malformedForLength(JVM* vm, std::int32_t length);
        void throwException();
        String toString();
        static CoderResult unmappableForLength(JVM* vm, std::int32_t length);
    };
}

#endif /* CoderResult_hxx */
