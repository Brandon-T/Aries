//
//  Annotation.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Annotation_hxx
#define Annotation_hxx

#include "Object.hxx"

namespace java::lang::annotation
{
    class Annotation : public Object
    {
    private:
        using Object::Object;
        
    public:
        Annotation(JVM* jvm);
        Annotation(JVM* jvm, jobject instance);
    };
}

#endif /* Annotation_hxx */
