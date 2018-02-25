//
//  ByteOrder.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef ByteOrder_hxx
#define ByteOrder_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    
    
    class ByteOrder : public Object
    {
    public:
        ByteOrder(JVM* vm, jobject instance);
        
        static ByteOrder nativeOrder(JVM* vm);
        String toString();
    };
}

#endif /* ByteOrder_hxx */
