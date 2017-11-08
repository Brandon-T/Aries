//
//  Iterable.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Iterable_hxx
#define Iterable_hxx

#include "Object.hxx"

namespace java::lang
{
    using java::util::Iterator;
    
    template<typename T = Object>
    class Iterable : Object
    {
    public:
        Iterable(JVM* jvm);
        Iterable(JVM* jvm, jobject instance);
        
        virtual Iterator<T> iterator();
        
        
        //void forEach(java.util.function.Consumer<? super T>);  //(Ljava/util/function/Consumer;)V
    };
    
    #include "Iterable.txx"
}

#endif /* Iterable_hxx */
