//
//  CharSequence.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef CharSequence_hxx
#define CharSequence_hxx

#include "Object.hxx"
#include "String.hxx"
#include "IntStream.hxx"


namespace java::lang
{
    using java::lang::Object;
    using java::lang::String;
    using java::util::stream::IntStream;
    
    
    class CharSequence : public Object
    {
    public:
        CharSequence(JVM* vm, jobject instance);
        
        char charAt(std::int32_t index);
        IntStream chars();
        IntStream codePoints();
        std::int32_t length();
        CharSequence subSequence(std::int32_t start, std::int32_t end);
        String toString();
    };
}

#endif /* CharSequence_hxx */
