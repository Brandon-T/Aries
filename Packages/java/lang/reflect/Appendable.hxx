//
//  Appendable.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Appendable_hxx
#define Appendable_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::lang
{
    using java::lang::CharSequence;
    using java::lang::Object;
    
    
    class Appendable : public Object
    {
    public:
        Appendable(JVM* vm, jobject instance);
        
        Appendable append(CharSequence csq);
        Appendable append(CharSequence csq, std::int32_t start, std::int32_t end);
        Appendable append(char c);
    };
}

#endif /* Appendable_hxx */
