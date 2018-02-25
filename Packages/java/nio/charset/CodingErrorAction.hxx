//
//  CodingErrorAction.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef CodingErrorAction_hxx
#define CodingErrorAction_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::charset
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class CodingErrorAction : public Object
    {
    public:
        CodingErrorAction(JVM* vm, jobject instance);
        
        String toString();
    };
}

#endif /* CodingErrorAction_hxx */
