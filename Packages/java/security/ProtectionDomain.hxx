//
//  ProtectionDomain.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ProtectionDomain_hxx
#define ProtectionDomain_hxx

#include "Object.hxx"

namespace java::security
{
    using java::lang::Object;
    
    class ProtectionDomain : public Object
    {
    private:
        using Object::Object;
        
    public:
        ProtectionDomain(JVM* jvm);
        ProtectionDomain(JVM* jvm, jobject instance);
    };
}

#endif /* ProtectionDomain_hxx */
