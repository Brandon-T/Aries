//
//  PathMatcher.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef PathMatcher_hxx
#define PathMatcher_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Object;
    using java::nio::file::Path;
    
    
    class PathMatcher : public Object
    {
    public:
        PathMatcher(JVM* vm, jobject instance);
        
        bool matches(Path path);
    };
}

#endif /* PathMatcher_hxx */
