//
//  PermissionCollection.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef PermissionCollection_hxx
#define PermissionCollection_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::security
{
    using java::lang::Object;
    using java::lang::String;
    using java::security::Permission;
    using java::util::Enumeration;
    
    
    class PermissionCollection : public Object
    {
    public:
        PermissionCollection(JVM* vm, jobject instance);
        PermissionCollection(JVM* vm);
        
        void add(Permission permission);
        Enumeration<Permission> elements();
        bool implies(Permission permission);
        bool isReadOnly();
        void setReadOnly();
        String toString();
    };
}

#endif /* PermissionCollection_hxx */
