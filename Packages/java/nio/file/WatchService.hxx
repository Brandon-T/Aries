//
//  WatchService.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef WatchService_hxx
#define WatchService_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Object;
    using java::nio::file::WatchKey;
    using java::util::concurrent::TimeUnit;
    
    
    class WatchService : public Object
    {
    public:
        WatchService(JVM* vm, jobject instance);
        
        void close();
        WatchKey poll();
        WatchKey poll(std::int64_t timeout, TimeUnit unit);
        WatchKey take();
    };
}

#endif /* WatchService_hxx */
