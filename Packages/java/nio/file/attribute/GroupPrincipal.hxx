//
//  GroupPrincipal.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef GroupPrincipal_hxx
#define GroupPrincipal_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::attribute
{
    using java::lang::Object;
    
    
    class GroupPrincipal : public Object
    {
    public:
        GroupPrincipal(JVM* vm, jobject instance);
    };
}

#endif /* GroupPrincipal_hxx */
