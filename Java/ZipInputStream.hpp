//
//  ZipInputStream.hpp
//  Aries
//
//  Created by Brandon on 2017-08-27.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ZipInputStream_hpp
#define ZipInputStream_hpp

#include "Object.hpp"
#include "InflaterInputStream.hpp"

namespace java
{
    namespace util
    {
        namespace zip
        {
            class ZipInputStream : public InflaterInputStream
            {
                ZipInputStream(InputStream in);
            };
        }
    }
}

#endif /* ZipInputStream_hpp */
