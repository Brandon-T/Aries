//
//  CompletionHandler.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef CompletionHandler_hxx
#define CompletionHandler_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::nio::channels
{
    using java::lang::Object;
    using java::lang::Throwable;
    
    
    class CompletionHandler : public Object
    {
    public:
        CompletionHandler(JVM* vm, jobject instance);
        
        void completed(Object result, Object attachment);
        void failed(Throwable exc, Object attachment);
    };
}

#endif /* CompletionHandler_hxx */
