//
//  ClassLoader.cpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include "ClassLoader.hpp"

using namespace java::lang;

ClassLoader::ClassLoader(JVM* jvm) : Object()
{
    
}

ClassLoader::ClassLoader(JVM* jvm, jobject instance) : Object(jvm, instance)
{
    
}

ClassLoader::~ClassLoader()
{
    
}
