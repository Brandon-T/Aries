//
//  ProtectionDomain.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ProtectionDomain.hpp"

using namespace java::security;

ProtectionDomain::ProtectionDomain(JVM* jvm) : Object()
{
    
}

ProtectionDomain::ProtectionDomain(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    
}

ProtectionDomain::~ProtectionDomain()
{
    
}
