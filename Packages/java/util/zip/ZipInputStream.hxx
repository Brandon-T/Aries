//
//  ZipInputStream.hxx
//  Aries
//
//  Created by Brandon on 2017-08-27.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef ZipInputStream_hxx
#define ZipInputStream_hxx

#include "Object.hxx"
#include "InflaterInputStream.hxx"

namespace java::util::zip
{
    class ZipInputStream : public InflaterInputStream
    {
        ZipInputStream(InputStream in);
    };
}

#endif /* ZipInputStream_hxx */
