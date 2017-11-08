//
//  main.cxx
//  Aries
//
//  Created by Brandon on 2017-08-25.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include <iostream>
#include "JVM.hxx"
#include "Map.hxx"

static std::unique_ptr<JVM> jvm {nullptr};



int main(int argc, const char * argv[]) {
    
    const char* jvmArgs[] = {"-Djava.compiler=NONE", "-Djava.class.path=."}; //"-verbose:jni"
    jvm = std::unique_ptr<JVM>(new JVM(sizeof(jvmArgs) / sizeof(jvmArgs[0]), jvmArgs));
    
    if (!jvm->loaded())
    {
        std::cerr<<"Failed to allocated JVM\n";
        return 0;
    }
    
    java::util::Map<> m(jvm.get(), nullptr);
    
    return 0;
}
