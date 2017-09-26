//
//  Exception.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include "Throwable.hpp"

namespace java
{
    namespace lang
    {
        class Exception : public Throwable
        {
        private:
            using Throwable::Throwable;
            
        public:
            Exception(JVM* jvm);
            Exception(JVM* jvm, jobject instance);
            Exception(JVM* jvm, String message);
            Exception(JVM* jvm, String message, Throwable cause);
            Exception(JVM* jvm, Throwable cause);
            virtual ~Exception();
            
        protected:
            Exception(JVM* jvm, String message, Throwable cause, bool enableSuppression, bool writableStackTrace);
        };
    }
}

#endif /* Exception_hpp */
