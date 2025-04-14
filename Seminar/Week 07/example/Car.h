#pragma once
#include "String.h"
#include "Cache.h"
#include "IdGenerator.h"

class Car
{
    static const IdGenerator idGenerator;
    static Cache cache;
    static size_t createdInstances;
    static size_t destroyedInstances;
    String id;
    
    // state...

    Car(const String& id);
    Car();

public:
    const String& getId() const;

    static size_t getCreatedInstances();
    static size_t getDestroyedInstances();
    static size_t getLiveInstances();

    // Should handle the disposal of the object appropriately (a.k.a. calling delete) by using the freeCache helper function or manually with delete
    static Car* getOrCreate(const String& id);
    static Car* getOrCreate();

    static void freeCache();
    ~Car();

    // other interface...
};