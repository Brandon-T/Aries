//
//  URI.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef URI_hxx
#define URI_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::URL;
    
    
    class URI : public Object
    {
    public:
        URI(JVM* vm, jobject instance);
        URI(JVM* vm, String str);
        URI(JVM* vm, String scheme, String userInfo, String host, std::int32_t port, String path, String query, String fragment);
        URI(JVM* vm, String scheme, String authority, String path, String query, String fragment);
        URI(JVM* vm, String scheme, String host, String path, String fragment);
        URI(JVM* vm, String scheme, String ssp, String fragment);
        
        std::int32_t compareTo(URI that);
        static URI create(JVM* vm, String str);
        bool equals(Object ob);
        String getAuthority();
        String getFragment();
        String getHost();
        String getPath();
        std::int32_t getPort();
        String getQuery();
        String getRawAuthority();
        String getRawFragment();
        String getRawPath();
        String getRawQuery();
        String getRawSchemeSpecificPart();
        String getRawUserInfo();
        String getScheme();
        String getSchemeSpecificPart();
        String getUserInfo();
        std::int32_t hashCode();
        bool isAbsolute();
        bool isOpaque();
        URI normalize();
        URI parseServerAuthority();
        URI relativize(URI uri);
        URI resolve(URI uri);
        URI resolve(String str);
        String toASCIIString();
        String toString();
        URL toURL();
    };
}

#endif /* URI_hxx */
