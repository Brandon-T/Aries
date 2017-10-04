//
//  Constructor.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Constructor.hpp"

using namespace java::lang::reflect;

Constructor::Constructor(JVM* jvm) : Object()
{
    
}

Constructor::Constructor(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    
}

Constructor::~Constructor()
{
    
}
