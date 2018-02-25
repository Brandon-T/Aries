//
//  UserPrincipal.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef UserPrincipal_hxx
#define UserPrincipal_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::attribute
{
    using java::lang::Object;
    
    
    class UserPrincipal : public Object
    {
    public:
        UserPrincipal(JVM* vm, jobject instance);
    };
}

#endif /* UserPrincipal_hxx */
