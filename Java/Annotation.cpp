//
//  Annotation.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Annotation.hpp"

using namespace java::lang::annotation;

Annotation::Annotation(JVM* jvm) : Object()
{
    
}

Annotation::Annotation(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    
}

Annotation::~Annotation()
{
    
}
