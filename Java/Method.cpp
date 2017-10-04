//
//  Method.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "Method.hpp"

using namespace java::lang::reflect;

Method::Method(JVM* jvm) : Object()
{
    
}

Method::Method(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    
}

Method::~Method()
{
    
}
