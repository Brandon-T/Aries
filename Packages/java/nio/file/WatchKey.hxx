//
//  WatchKey.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef WatchKey_hxx
#define WatchKey_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Object;
    using java::nio::file::Watchable;
    using java::util::List;
    
    
    class WatchKey : public Object
    {
    public:
        WatchKey(JVM* vm, jobject instance);
        
        void cancel();
        bool isValid();
        List pollEvents();
        bool reset();
        Watchable watchable();
    };
}

#endif /* WatchKey_hxx */
