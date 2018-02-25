//
//  Watchable.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Watchable_hxx
#define Watchable_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Object;
    using java::nio::file::WatchEvent;
    using java::nio::file::WatchKey;
    using java::nio::file::WatchService;
    
    
    class Watchable : public Object
    {
    public:
        Watchable(JVM* vm, jobject instance);
        
        WatchKey register(WatchService arg0, Array<WatchEvent::Kind>& arg1, Array<WatchEvent::Modifier>& arg2);
        WatchKey register(WatchService arg0, Array<WatchEvent::Kind>& arg1);
    };
}

#endif /* Watchable_hxx */
