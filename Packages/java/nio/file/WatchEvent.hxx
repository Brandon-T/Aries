//
//  WatchEvent.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef WatchEvent_hxx
#define WatchEvent_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::file
{
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    
    
    class WatchEvent : public Object
    {
    public:
        class Kind : public Object
        {
        public:
            Kind(JVM* vm, jobject instance);
            
            String name();
            Class type();
        };
        
        class Modifier : public Object
        {
        public:
            Modifier(JVM* vm, jobject instance);
            
            String name();
        };
        
        WatchEvent(JVM* vm, jobject instance);
        
        Object context();
        std::int32_t count();
        Kind kind();
    };
}

#endif /* WatchEvent_hxx */
