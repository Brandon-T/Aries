//
//  UserPrincipalLookupService.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef UserPrincipalLookupService_hxx
#define UserPrincipalLookupService_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file::attribute
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::file::attribute::GroupPrincipal;
    using java::nio::file::attribute::UserPrincipal;
    
    
    class UserPrincipalLookupService : public Object
    {
    public:
        UserPrincipalLookupService(JVM* vm, jobject instance);
        
        GroupPrincipal lookupPrincipalByGroupName(String group);
        UserPrincipal lookupPrincipalByName(String name);
        
        
    protected:
        UserPrincipalLookupService(JVM* vm);
    };
}

#endif /* UserPrincipalLookupService_hxx */
