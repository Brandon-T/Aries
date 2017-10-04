//
//  Utilities.hpp
//  Aries
//
//  Created by Brandon on 2017-08-26.
//  Copyright © 2017 Brandon. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <functional>

template<typename T>
class AnyRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    
public:
    AnyRef(T* data_ptr)
    {
        auto deleter = [](void* data) {
            delete static_cast<T*>(data);
        };
        
        this->data = std::unique_ptr<void, std::function<void(void*)>>(data_ptr, deleter);
    }
    
    AnyRef(AnyRef &&other) : data(std::move(other.data))
    {
    }
    
    AnyRef(const AnyRef &other) = delete;
    
    T* get()
    {
        return static_cast<T *>(this->data.get());
    }
};

class CastableAnyRef
{
private:
    std::unique_ptr<void, std::function<void(void*)>> data;
    
public:
    template<typename T>
    CastableAnyRef(T* data_ptr)
    {
        auto deleter = [](void* data) {
            delete static_cast<T*>(data);
        };
        
        this->data = std::unique_ptr<void, std::function<void(void*)>>(data_ptr, deleter);
    }
    
    CastableAnyRef(CastableAnyRef &&other) : data(std::move(other.data))
    {
    }
    
    CastableAnyRef(const CastableAnyRef &other) = delete;
    
    template<typename T>
    T* get()
    {
        return static_cast<T *>(this->data.get());
    }
};

#endif /* Utilities_hpp */
