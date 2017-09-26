//
//  main.cpp
//  Aries
//
//  Created by Brandon on 2017-08-25.
//  Copyright © 2017 Brandon. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include "JVM.hpp"

static std::unique_ptr<JVM> jvm {nullptr};

std::vector<std::uint8_t> readClass(JVM* vm, InputStream* in)
{
    ByteArrayOutputStream baos = ByteArrayOutputStream(vm);
    int value = -1;
    
    while((value = in->read()) != -1)
    {
        baos.write(value);
    }
    return baos.toByteArray();
}

bool loadJar(const char* jarPath)
{
    if (!jvm)
    {
        std::vector<unsigned char> jar;
        std::fstream file(jarPath, std::ios::in | std::ios::binary);
        
        if (file)
        {
            file.seekg(0, std::ios::end);
            jar.resize(file.tellg());
            file.seekg(0, std::ios::beg);
            file.read(reinterpret_cast<char*>(&jar[0]), jar.size());
        }
        
        const char* jvmArgs[] = {"-Djava.compiler=NONE", "-Djava.class.path=."}; //"-verbose:jni"
        jvm = std::unique_ptr<JVM>(new JVM(sizeof(jvmArgs) / sizeof(jvmArgs[0]), jvmArgs));
        
        if (!jvm->loaded())
        {
            std::cerr<<"Failed to allocated JVM\n";
            return false;
        }
        
        ByteArrayInputStream bais = ByteArrayInputStream(jvm.get(), jar.data(), (int)jar.size());
        JarInputStream jis = JarInputStream(jvm.get(), &bais);
        
        JarEntry* entry = nullptr;
        std::map<std::string, std::vector<unsigned char>> entries;
        
        while((entry = jis.getNextJarEntry()) != nullptr)
        {
            std::string ext = ".class";
            std::string name = entry->getName();
            
            if ((name.length() > ext.length()) && (name.rfind(ext) == name.length() - ext.length()))
            {
                entries.insert(std::make_pair(name, readClass(jvm.get(), &jis)));
            }
            
            delete entry;
            entry = nullptr;
        }
        
        jis.close();
        bais.close();
        
        while(entries.size())
        {
            for (auto it = entries.begin(); it != entries.end(); ++it)
            {
                std::string ext = ".class";
                std::string name = it->first;
                
                if ((name.length() > ext.length()) && (name.rfind(ext) == name.length() - ext.length()))
                {
                    auto ReplaceAll = [&](std::string str, const std::string& from, const std::string& to) -> std::string {
                        size_t start_pos = 0;
                        while((start_pos = str.find(from, start_pos)) != std::string::npos)
                        {
                            str.replace(start_pos, from.length(), to);
                        }
                        return str;
                    };
                    
                    std::vector<unsigned char> &bytes = it->second;
                    std::string canonicalName = ReplaceAll(ReplaceAll(name, "/", "."), ".class", "");
                    
                    jclass cls = jvm->DefineClass(ReplaceAll(name, ".class", "").c_str(), nullptr, reinterpret_cast<jbyte*>(bytes.data()), (int)bytes.size());
                    if (cls)
                    {
                        std::cerr<<"Defined: "<<canonicalName<<" Size: "<<bytes.size()<<"\n";
                        entries.erase(it->first);
                        break;
                    }
                    else
                    {
                        if(jvm->ExceptionCheck())
                        {
                            jvm->ExceptionDescribe();
                            jvm->ExceptionClear();
                        }
                        std::cerr<<"Failed to define: "<<canonicalName<<"  Size: "<<bytes.size()<<"\n";
                    }
                }
            }
        }
    }
    
    return jvm.get() != nullptr;
}



int main(int argc, const char * argv[]) {
    
    const char* jvmArgs[] = {"-Djava.compiler=NONE", "-Djava.class.path=."}; //"-verbose:jni"
    jvm = std::unique_ptr<JVM>(new JVM(sizeof(jvmArgs) / sizeof(jvmArgs[0]), jvmArgs));
    
    if (!jvm->loaded())
    {
        std::cerr<<"Failed to allocated JVM\n";
        return false;
    }
    
    return 0;
}
