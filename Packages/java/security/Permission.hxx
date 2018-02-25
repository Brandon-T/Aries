//
//  Permission.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Permission_hxx
#define Permission_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::security
{
    using java::lang::Object;
    using java::lang::String;
    using java::security::PermissionCollection;
    
    
    class Permission : public Object
    {
    public:
        Permission(JVM* vm, jobject instance);
        Permission(JVM* vm, String name);
        
        void checkGuard(Object object);
        bool equals(Object obj);
        String getActions();
        String getName();
        std::int32_t hashCode();
        bool implies(Permission permission);
        PermissionCollection newPermissionCollection();
        String toString();
    };
}

#endif /* Permission_hxx */
