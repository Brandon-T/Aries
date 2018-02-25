//
//  InetAddress.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef InetAddress_hxx
#define InetAddress_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::NetworkInterface;
    
    
    class InetAddress : public Object
    {
    public:
        InetAddress(JVM* vm, jobject instance);
        
        bool equals(Object obj);
        Array<std::uint8_t> getAddress();
        static Array<InetAddress> getAllByName(JVM* vm, String host);
        static InetAddress getByAddress(JVM* vm, String host, Array<std::uint8_t>& addr);
        static InetAddress getByAddress(JVM* vm, Array<std::uint8_t>& addr);
        static InetAddress getByName(JVM* vm, String host);
        String getCanonicalHostName();
        String getHostAddress();
        String getHostName();
        static InetAddress getLocalHost(JVM* vm);
        static InetAddress getLoopbackAddress(JVM* vm);
        std::int32_t hashCode();
        bool isAnyLocalAddress();
        bool isLinkLocalAddress();
        bool isLoopbackAddress();
        bool isMCGlobal();
        bool isMCLinkLocal();
        bool isMCNodeLocal();
        bool isMCOrgLocal();
        bool isMCSiteLocal();
        bool isMulticastAddress();
        bool isReachable(std::int32_t timeout);
        bool isReachable(NetworkInterface netif, std::int32_t ttl, std::int32_t timeout);
        bool isSiteLocalAddress();
        String toString();
    };
}

#endif /* InetAddress_hxx */
