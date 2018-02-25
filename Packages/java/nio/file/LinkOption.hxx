//
//  LinkOption.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef LinkOption_hxx
#define LinkOption_hxx

#include "Array.hxx"
#include "Enum.hxx"


namespace java::nio::file
{
    using java::lang::Enum;
    using java::lang::String;
    
    
    class LinkOption : public Enum
    {
    public:
        LinkOption(JVM* vm, jobject instance);
        
        static LinkOption valueOf(JVM* vm, String value);
        static Array<LinkOption> values(JVM* vm);
    };
}

#endif /* LinkOption_hxx */
