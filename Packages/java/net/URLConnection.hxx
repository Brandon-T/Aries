//
//  URLConnection.hxx
//  Aries
//
//  Created by Brandon on 2018-02-25.
//  Copyright © 2018 Brandon. All rights reserved.
//

#ifndef URLConnection_hxx
#define URLConnection_hxx

#include "Array.hxx"
#include "Object.hxx"


namespace java::net
{
    using java::io::InputStream;
    using java::io::OutputStream;
    using java::lang::Class;
    using java::lang::Object;
    using java::lang::String;
    using java::net::ContentHandlerFactory;
    using java::net::FileNameMap;
    using java::net::URL;
    using java::security::Permission;
    using java::util::Map;
    using java::util::List;
    
    
    class URLConnection : public Object
    {
    public:
        URLConnection(JVM* vm, jobject instance);
        
        void addRequestProperty(String key, String value);
        void connect();
        bool getAllowUserInteraction();
        std::int32_t getConnectTimeout();
        Object getContent();
        Object getContent(Array<Class>& classes);
        String getContentEncoding();
        std::int32_t getContentLength();
        std::int64_t getContentLengthLong();
        String getContentType();
        std::int64_t getDate();
        static bool getDefaultAllowUserInteraction(JVM* vm);
        static String getDefaultRequestProperty(JVM* vm, String key);
        bool getDefaultUseCaches();
        bool getDoInput();
        bool getDoOutput();
        std::int64_t getExpiration();
        static FileNameMap getFileNameMap(JVM* vm);
        String getHeaderField(String name);
        String getHeaderField(std::int32_t n);
        std::int64_t getHeaderFieldDate(String name, std::int64_t Default);
        std::int32_t getHeaderFieldInt(String name, std::int32_t Default);
        String getHeaderFieldKey(std::int32_t n);
        std::int64_t getHeaderFieldLong(String name, std::int64_t Default);
        Map<String, List<String>> getHeaderFields();
        std::int64_t getIfModifiedSince();
        InputStream getInputStream();
        std::int64_t getLastModified();
        OutputStream getOutputStream();
        Permission getPermission();
        std::int32_t getReadTimeout();
        Map<String, List<String>> getRequestProperties();
        String getRequestProperty(String key);
        URL getURL();
        bool getUseCaches();
        static String guessContentTypeFromName(JVM* vm, String fname);
        static String guessContentTypeFromStream(JVM* vm, InputStream is);
        void setAllowUserInteraction(bool allowuserinteraction);
        void setConnectTimeout(std::int32_t timeout);
        static void setContentHandlerFactory(JVM* vm, ContentHandlerFactory fac);
        static void setDefaultAllowUserInteraction(JVM* vm, bool defaultallowuserinteraction);
        static void setDefaultRequestProperty(JVM* vm, String key, String value);
        void setDefaultUseCaches(bool defaultusecaches);
        void setDoInput(bool doinput);
        void setDoOutput(bool dooutput);
        static void setFileNameMap(JVM* vm, FileNameMap map);
        void setIfModifiedSince(std::int64_t ifmodifiedsince);
        void setReadTimeout(std::int32_t timeout);
        void setRequestProperty(String key, String value);
        void setUseCaches(bool usecaches);
        String toString();
        
        
    protected:
        URLConnection(JVM* vm, URL url);
    };
}

#endif /* URLConnection_hxx */
