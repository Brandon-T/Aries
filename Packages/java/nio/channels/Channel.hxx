//
//  Channel.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Channel_hxx
#define Channel_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::channels
{
    using java::lang::Object;
    
    
    class Channel : public Object
    {
    public:
        Channel(JVM* vm, jobject instance);
        
        void close();
        bool isOpen();
    };
}

#endif /* Channel_hxx */
