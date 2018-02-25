//
//  OpenOption.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef OpenOption_hxx
#define OpenOption_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Object;
    
    
    class OpenOption : public Object
    {
    public:
        OpenOption(JVM* vm, jobject instance);
    };
}

#endif /* OpenOption_hxx */
