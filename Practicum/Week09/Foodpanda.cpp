#include "Foodpanda.h"

void Foodpanda::setRestaurants(Restaurant* restaurants, size_t restaurantsCount, size_t restaurantsCapacity) {
    if (restaurants == nullptr) {
        throw std::invalid_argument("Your list of restaurants cannot be null!");
    }

    if (restaurantsCount > restaurantsCapacity) {
        throw std::invalid_argument("The size of your list of restaurants cannot be bigger than its capacity!");
    }

    delete[] this->restaurants;

    this->restaurantsCount = restaurantsCount;
    this->restaurantsCapacity = restaurantsCapacity;
    this->restaurants = new Restaurant[restaurantsCapacity];
    for (size_t i = 0; i < restaurantsCount; ++i) {
        this->restaurants[i] = restaurants[i];
    }
}

const Restaurant* Foodpanda::getRestaurants() const {
    return this->restaurants;
}

size_t Foodpanda::getRestaurantsCount() const {
    return this->restaurantsCount;
}

size_t Foodpanda::getRestaurantsCapacity() const {
    return this->restaurantsCapacity;
}

void Foodpanda::addNewRestaurant(const Restaurant& newRestaurant) {
    if (this->restaurantsCount == this->restaurantsCapacity) {
        resizeRestaurants();
    }

    this->restaurants[this->restaurantsCount] = newRestaurant;
    ++this->restaurantsCount;
}

void Foodpanda::addNewOrder(const Order& newOrder) {
    bool isRestaurantFound = false;

    for (size_t i = 0; i < this->restaurantsCount; ++i) {
        if (strcmp(newOrder.getRestaurantName(), this->restaurants[i].getName()) == 0) {
            isRestaurantFound = true;
            this->restaurants[i].receiveOrder(newOrder);
            break;
        }
    }

    if (isRestaurantFound == false) {
        throw std::invalid_argument("Your restaurant has not been found!");
    }
}

void Foodpanda::resizeRestaurants() {
    size_t newCapacity = this->restaurantsCapacity * 2;
    Restaurant* newRestaurants = new Restaurant[newCapacity];

    for (size_t i = 0; i < this->restaurantsCount; ++i) {
        newRestaurants[i] = this->restaurants[i];
    }

    delete[] this->restaurants;
    this->restaurants = newRestaurants;
    this->restaurantsCapacity = newCapacity;
}

void Foodpanda::copyFrom(const Foodpanda& other) {
    if (other.restaurants == nullptr) {
        throw std::invalid_argument("Your list of restaurants cannot be null!");
    }

    if (other.restaurantsCount > other.restaurantsCapacity) {
        throw std::invalid_argument("The size of your list of restaurants cannot be bigger than its capacity!");
    }

    this->restaurantsCount = other.restaurantsCount;
    this->restaurantsCapacity = other.restaurantsCapacity;
    this->restaurants = new Restaurant[other.restaurantsCapacity];
    for (size_t i = 0; i < other.restaurantsCount; ++i) {
        this->restaurants[i] = other.restaurants[i];
    }
}

void Foodpanda::moveFrom(Foodpanda&& other) {
    this->restaurants = other.restaurants;
    this->restaurantsCount = other.restaurantsCount;
    this->restaurantsCapacity = other.restaurantsCapacity;

    other.restaurants = nullptr;
    other.restaurantsCount = 0;
    other.restaurantsCapacity = 0;
}

void Foodpanda::freeRestaurants() {
    delete[] this->restaurants;
    this->restaurants = nullptr;
    this->restaurantsCount = 0;
    this->restaurantsCapacity = 0;
}

Foodpanda::Foodpanda(Restaurant* restaurants, size_t restaurantsCount, size_t restaurantsCapacity) {
    setRestaurants(restaurants, restaurantsCount, restaurantsCapacity);
}

Foodpanda::Foodpanda() {
    this->restaurantsCount = 0;
    this->restaurantsCapacity = 1;
    this->restaurants = new Restaurant[this->restaurantsCapacity];
}

Foodpanda::Foodpanda(const Foodpanda& other) {
    this->copyFrom(other);
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
    if (this != &other) {
        this->freeRestaurants();
        this->copyFrom(other);
    }

    return *this;
}

Foodpanda::Foodpanda(Foodpanda&& other) noexcept {
    this->moveFrom(std::move(other));
}

Foodpanda& Foodpanda::operator=(Foodpanda&& other) noexcept {
    if (this != &other) {
        this->freeRestaurants();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Foodpanda::~Foodpanda() {
    this->freeRestaurants();
}
