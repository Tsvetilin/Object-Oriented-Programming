#include "Cache.h"

void Cache::add(const String &id, void *object)
{
    cache[id] = object;
}

void* Cache::get(const String &id)
{
    if (!contains(id))
    {
        return nullptr;
    }

    return cache[id];
}

void Cache::remove(const String &id)
{
    auto it = cache.find(id);
    if (it != cache.end())
    {
        cache.erase(it);
    }
}

void* Cache::pop()
{
    if(cache.empty())
    {
        return nullptr;
    }
    
    auto it = cache.begin();
    void *object = it->second;
    cache.erase(it);
    return object;
}

bool Cache::contains(const String &id)
{
    return cache.find(id) != cache.end();
}

size_t Cache::size()
{
    return cache.size();
}