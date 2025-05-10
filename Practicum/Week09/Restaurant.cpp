#include "Restaurant.h"
#pragma warning(disable: 4996)

void Restaurant::setName(const char* name) {
    if (name == nullptr) {
        throw std::invalid_argument("Name cannot be nullptr!");
    }

    if (strlen(name) > MAX_RESTAURANT_NAME_LEN) {
        throw std::invalid_argument("Name is too long!");
    }

    strcpy(this->name, name);
}

void Restaurant::setProductList(const String* productList, size_t productListSize, size_t productListCapacity) {
    if (productList == nullptr) {
        throw std::invalid_argument("Your product list cannot be nullptr!");
    }

    if (productListSize > productListCapacity) {
        throw std::invalid_argument("The size of your products list cannot be more of its capacity!");
    }

    delete[] this->productList;

    this->productListSize = productListSize;
    this->productListCapacity = productListCapacity;
    this->productList = new String[productListCapacity];
    for (size_t i = 0; i < productListSize; ++i) {
        this->productList[i] = productList[i];
    }
}

const char* Restaurant::getName() const {
    return this->name;
}

const String* Restaurant::getProductList() const {
    return this->productList;
}

size_t Restaurant::getProductListSize() const {
    return this->productListSize;
}

size_t Restaurant::getProductListCapacity() const {
    return this->productListCapacity;
}

void Restaurant::addNewProductToList(const String& newPoroduct) {
    if (this->productListSize == this->productListCapacity) {
        resizeProductList();
    }

    this->productList[this->productListSize] = newPoroduct;
    ++this->productListSize;
}

void Restaurant::receiveOrder(const Order& order) const {
    if (strcmp(this->name, order.getRestaurantName()) != 0) {
        throw std::invalid_argument("Invalid restaurant name!");
    }

    for (size_t i = 0; i < order.getProductsCount(); ++i) {
        bool productFound = false;
        for (size_t j = 0; j < this->productListSize; ++j) {
            if (this->productList[j] == order.getProducts()[i]) {
                productFound = true;
                break;
            }
        }

        if (!productFound) {
            throw std::invalid_argument("Product is not offered by the restaurant!");
        }
    }

    std::cout << "Order received successfully!" << std::endl;
}

void Restaurant::resizeProductList() {
    size_t newCapacity = this->productListCapacity * 2;
    String* newProducts = new String[newCapacity];

    for (size_t i = 0; i < this->productListSize; ++i) {
        newProducts[i] = this->productList[i];
    }

    delete[] this->productList;
    this->productList = newProducts;
    this->productListCapacity = newCapacity;
}

void Restaurant::copyFrom(const Restaurant& other) {
    if (other.name == nullptr) {
        throw std::invalid_argument("Name cannot be nullptr!");
    }

    if (strlen(other.name) > MAX_RESTAURANT_NAME_LEN) {
        throw std::invalid_argument("Name is too long!");
    }

    strcpy(this->name, other.name);


    if (other.productList == nullptr) {
        throw std::invalid_argument("Your product list cannot be nullptr!");
    }

    if (other.productListSize > other.productListCapacity) {
        throw std::invalid_argument("The size of your products list cannot be more of its capacity!");
    }

    this->productListSize = other.productListSize;
    this->productListCapacity = other.productListCapacity;
    this->productList = new String[other.productListCapacity];
    for (size_t i = 0; i < other.productListSize; ++i) {
        this->productList[i] = other.productList[i];
    }
}

void Restaurant::moveFrom(Restaurant&& other) noexcept {
    strcpy(name, other.name);
    this->productList = other.productList;
    this->productListSize = other.productListSize;
    this->productListCapacity = other.productListCapacity;

    other.name[0] = '\0';
    other.productList = nullptr;
    other.productListSize = 0;
    other.productListCapacity = 0;
}

void Restaurant::freeProductList() {
    delete[] this->productList;
    this->productList = nullptr;
    this->productListSize = 0;
    this->productListCapacity = 0;
}

void Restaurant::free() {
    this->freeProductList();
    this->name[0] = '\0';
}

Restaurant::Restaurant(const char* name, const String* productList, size_t productListSize, size_t productListCapacity) {
    setName(name);
    setProductList(productList, productListSize, productListCapacity);
}

Restaurant::Restaurant() {
    this->name[0] = '\0';
    this->productListSize = 0;
    this->productListCapacity = 1;
    this->productList = new String[this->productListCapacity];
}

Restaurant::Restaurant(const Restaurant& other) {
    this->copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept {
    this->moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Restaurant::~Restaurant() {
    this->free();
}
