#pragma once
#include <unordered_map>
#include "String.h"

namespace {
    struct StringHash
    {
        bool operator()(const String& x) const
        {
            return x.hash();
        }
    };
}

class Cache
{
    std::unordered_map<String, void*, StringHash> cache;

public:
    void add(const String& id, void* object);
    void* get(const String& id);
    void remove(const String& id);
    void* pop();
    bool contains(const String& id);
    size_t size();
};
