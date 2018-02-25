//
//  DoubleBuffer.hxx
//  Aries
//
//  Created by Brandon on 2018-02-24.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef DoubleBuffer_hxx
#define DoubleBuffer_hxx

#include "Array.hxx"
#include "Buffer.hxx"


namespace java::nio
{
    using java::lang::Object;
    using java::lang::String;
    using java::nio::Buffer;
    using java::nio::ByteOrder;
    
    
    class DoubleBuffer : public Buffer
    {
    public:
        DoubleBuffer(JVM* vm, jobject instance);
        
        static DoubleBuffer allocate(JVM* vm, std::int32_t capacity);
        Array<double> array();
        std::int32_t arrayOffset();
        DoubleBuffer asReadOnlyBuffer();
        DoubleBuffer compact();
        std::int32_t compareTo(DoubleBuffer that);
        DoubleBuffer duplicate();
        bool equals(Object ob);
        double get();
        double get(std::int32_t index);
        DoubleBuffer get(Array<double>& dst, std::int32_t offset, std::int32_t length);
        DoubleBuffer get(Array<double>& dst);
        bool hasArray();
        std::int32_t hashCode();
        bool isDirect();
        ByteOrder order();
        DoubleBuffer put(double d);
        DoubleBuffer put(std::int32_t index, double d);
        DoubleBuffer put(DoubleBuffer src);
        DoubleBuffer put(Array<double>& src, std::int32_t offset, std::int32_t length);
        DoubleBuffer put(Array<double>& src);
        DoubleBuffer slice();
        String toString();
        static DoubleBuffer wrap(JVM* vm, Array<double>& array, std::int32_t offset, std::int32_t length);
        static DoubleBuffer wrap(JVM* vm, Array<double>& array);
    };
}

#endif /* DoubleBuffer_hxx */
