//
//  Enum.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef Enum_hxx
#define Enum_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::lang
{
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    
    
    class Enum : public Object
    {
    public:
        Enum(JVM* vm, jobject instance);
        
        std::int32_t compareTo(Enum arg0);
        bool equals(Object other);
        Class getDeclaringClass();
        std::int32_t hashCode();
        String name();
        std::int32_t ordinal();
        String toString();
        static Enum valueOf(JVM* vm, Class clz, String value);
        
        
    protected:
        Enum(JVM* vm, String name, std::int32_t ordinal);
        
        void finalize();
    };
}

#endif /* Enum_hxx */
