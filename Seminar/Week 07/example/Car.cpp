#include "Car.h"

// Should initialize the static members
const IdGenerator Car::idGenerator = IdGenerator(typeid(Car).name());
Cache Car::cache = Cache();
size_t Car::createdInstances = 0;
size_t Car::destroyedInstances = 0;

Car::Car(const String &id) : id(id) /*, ...*/ { Car::createdInstances++; }
Car::Car() : Car(idGenerator.generateId()) {}

const String& Car::getId() const
{
    return this->id;
}

size_t Car::getCreatedInstances() { return Car::createdInstances; }
size_t Car::getDestroyedInstances() { return Car::destroyedInstances; }
size_t Car::getLiveInstances() { return Car::createdInstances - Car::destroyedInstances; }

Car* Car::getOrCreate(const String &id)
{
    if (cache.contains(id))
    {
        return (Car *)Car::cache.get(id);
    }

    Car *car;
    if (id.empty())
    {
        car = new Car();
    }
    else
    {
        car = new Car(id);
    }

    Car::cache.add(car->id, car);
    return car;
}

Car* Car::getOrCreate()
{
    return Car::getOrCreate(String::createEmpty());
}

void Car::freeCache()
{
    while (Car::cache.size() > 0)
    {
        delete (Car *)Car::cache.pop();
    }
}

Car::~Car()
{
    if (cache.contains(id))
    {
        Car::cache.remove(id);
    }

    Car::destroyedInstances++;
}
