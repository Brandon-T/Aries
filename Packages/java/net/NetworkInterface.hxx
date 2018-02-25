//
//  NetworkInterface.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef NetworkInterface_hxx
#define NetworkInterface_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::lang::Object;
    using java::lang::String;
    using java::net::InetAddress;
    using java::util::Enumeration;
    using java::util::List;
    
    
    class NetworkInterface : public Object
    {
    public:
        NetworkInterface(JVM* vm, jobject instance);
        
        bool equals(Object obj);
        static NetworkInterface getByIndex(JVM* vm, std::int32_t index);
        static NetworkInterface getByInetAddress(JVM* vm, InetAddress addr);
        static NetworkInterface getByName(JVM* vm, String name);
        String getDisplayName();
        Array<std::uint8_t> getHardwareAddress();
        std::int32_t getIndex();
        Enumeration<InetAddress> getInetAddresses();
        List<InetAddress> getInterfaceAddresses();
        std::int32_t getMTU();
        String getName();
        static Enumeration<InetAddress> getNetworkInterfaces(JVM* vm);
        NetworkInterface getParent();
        Enumeration<InetAddress> getSubInterfaces();
        std::int32_t hashCode();
        bool isLoopback();
        bool isPointToPoint();
        bool isUp();
        bool isVirtual();
        bool supportsMulticast();
        String toString();
    };
}

#endif /* NetworkInterface_hxx */
