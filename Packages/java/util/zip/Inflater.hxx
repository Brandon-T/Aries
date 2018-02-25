//
//  Inflater.hxx
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Inflater_hxx
#define Inflater_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::util::zip
{
    using java::lang::Object;
    
    
    class Inflater : public Object
    {
    public:
        Inflater(JVM* vm, jobject instance);
        Inflater(JVM* vm, bool nowrap);
        Inflater(JVM* vm);
        
        void end();
        bool finished();
        std::int32_t getAdler();
        std::int64_t getBytesRead();
        std::int64_t getBytesWritten();
        std::int32_t getRemaining();
        std::int32_t getTotalIn();
        std::int32_t getTotalOut();
        std::int32_t inflate(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        std::int32_t inflate(Array<std::uint8_t>& b);
        bool needsDictionary();
        bool needsInput();
        void reset();
        void setDictionary(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        void setDictionary(Array<std::uint8_t>& b);
        void setInput(Array<std::uint8_t>& b, std::int32_t off, std::int32_t len);
        void setInput(Array<std::uint8_t>& b);
        
        
    protected:
        void finalize();
    };
}

#endif /* Inflater_hxx */
