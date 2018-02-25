//
//  TimeUnit.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef TimeUnit_hxx
#define TimeUnit_hxx

#include "Array.hxx"
#include "Enum.hxx"


namespace java::util::concurrent
{
    using java::lang::Enum;
    using java::lang::Object;
    using java::lang::String;
    using java::lang::Thread;
    
    
    class TimeUnit : public Enum
    {
    public:
        TimeUnit(JVM* arg0, jobject arg1);
        
        std::int64_t convert(std::int64_t arg0, TimeUnit arg1);
        void sleep(std::int64_t arg0);
        void timedJoin(Thread arg0, std::int64_t arg1);
        void timedWait(Object arg0, std::int64_t arg1);
        std::int64_t toDays(std::int64_t arg0);
        std::int64_t toHours(std::int64_t arg0);
        std::int64_t toMicros(std::int64_t arg0);
        std::int64_t toMillis(std::int64_t arg0);
        std::int64_t toMinutes(std::int64_t arg0);
        std::int64_t toNanos(std::int64_t arg0);
        std::int64_t toSeconds(std::int64_t arg0);
        static TimeUnit valueOf(JVM* arg0, String arg1);
        static Array<TimeUnit> values(JVM* arg0);
    };
}

#endif /* TimeUnit_hxx */
