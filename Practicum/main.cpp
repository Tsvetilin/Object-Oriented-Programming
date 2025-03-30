//I don't know how to push multiple files, so I have copied all of my header and cpp. files and pasted them here simultaneously.

//Exercise 1
//Waffle.h
#ifndef _WAFFLE_H
#define _WAFFLE_H
#include<cstring>

class Waffle {
private:
	char* brand;
	double weight;
	double priceForBulk;
	double priceForClient;

	void copy(const Waffle& other);
	void free();
public:
	Waffle(const char* newBrand, double newWeight, double newPriceForBulk, double newPriceForClient);
	Waffle();
	Waffle(const Waffle& other);
	Waffle& operator=(const Waffle& other);
	~Waffle();

	void setBrand(const char* brand);
	void setWeight(double newWeight);
	void setPriceForBulk(double newPrice);
	void setPriceForClient(double newPrice);

	const char* getBrand() const;
	const double getWeight() const;
	const double getPriceForBulk() const;
	const double getPriceForClient() const;
};

#endif // !_WAFFLE_H


//Waffle.cpp
#include "Waffle.h"
#include<cstring>

#pragma warning(disable:4996)

void Waffle::copy(const Waffle& other) {
	this->brand = new char[strlen(other.brand) + 1];
	strcpy(this->brand, other.brand);
	this->weight = other.weight;
	this->priceForBulk = other.priceForBulk;
	this->priceForClient = other.priceForClient;
}

void Waffle::free() {
	delete[] this->brand;
}

Waffle::Waffle(const char* newBrand, double newWeight, double newPriceForBulk, double newPriceForClient) {
	this->brand = new char[strlen(newBrand) + 1];
	strcpy(this->brand, newBrand);
	this->weight = newWeight;
	this->priceForBulk = newPriceForBulk;
	this->priceForClient = newPriceForClient;
}

Waffle::Waffle() {
	this->brand = nullptr;
	this->weight = 0;
	this->priceForBulk = 0;
	this->priceForClient = 0;
}

Waffle::Waffle(const Waffle& other) {
	this->copy(other);
}

Waffle& Waffle::operator=(const Waffle& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

Waffle::~Waffle() {
	this->free();
}

void Waffle::setBrand(const char* newBrand){
	if (!this->brand) {
		return;
	}
	if (this->brand == newBrand) {
		return;
	}
	if (this->brand != nullptr) {
		delete[] this->brand;
	}

	this->brand = new char[strlen(newBrand) + 1];
	strcpy(this->brand, newBrand);
}

void Waffle::setWeight(double newWeight) {
	this->weight = newWeight;
}

void Waffle::setPriceForBulk(double newPrice) {
	this->priceForBulk = newPrice;
}

void Waffle::setPriceForClient(double newPrice) {
	this->priceForClient = newPrice;
}

const char* Waffle::getBrand() const {
	return this->brand;
}

const double Waffle::getWeight() const {
	return this->weight;
}

const double Waffle::getPriceForBulk() const {
	return this->priceForBulk;
}

const double Waffle::getPriceForClient() const {
	return this->priceForClient;
}


//Store.h
#ifndef _STORE_H
#define _STORE_H
#include "Waffle.h"

class Store {
private:
	Waffle* waffles;
	size_t maxWaffleCount;
	double income;
	double expenses;

	void copy(const Store& other);
	void free();
public:
	Store(Waffle* newWaffles, size_t newMaxWaffleCount, double newIncome, double newExpenses);
	Store();
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	//getters
	Waffle* getWaffles();
	size_t getMaxWaffleCount();
	double getIncome();
	double getExpenses();

	//setters
	void setWaffles(Waffle* waffles);
	void setMaxWaffleCount(size_t newCount);
	void setIncome(double newIncome);
	void setExpenses(double newExpenses);

	//sell waffles based on brand
	void sellWaffles(const char* brand);
	//buy n waffles from brand
	void buyWaffles(const char* brand, size_t count);
	//display waffle stock based on brand
	int displayWaffles(const char* brand);
	//shows profit
	double showProfit();
};

#endif // !_STORE_H


//Store.cpp
#include "Store.h"
#include "Waffle.h"
#include<iostream>

void Store::copy(const Store& other) {
	this->maxWaffleCount = other.maxWaffleCount;
	this->waffles = new Waffle[other.maxWaffleCount];
	for (size_t i = 0; i < other.maxWaffleCount; ++i) {
		this->waffles[i] = other.waffles[i];
	}
	this->income = other.income;
	this->expenses = other.expenses;
}

void Store::free() {
	delete[] this->waffles;
}

Store::Store(Waffle* newWaffles, size_t newMaxWaffleCount, double newIncome, double newExpenses) {
	this->maxWaffleCount = newMaxWaffleCount;
	this->waffles = new Waffle[newMaxWaffleCount];
	for (size_t i = 0; i < newMaxWaffleCount; ++i) {
		this->waffles[i] = newWaffles[i];
	}
	this->income = newIncome;
	this->expenses = newExpenses;
}

Store::Store() {
	this->maxWaffleCount = 0;
	this->waffles = nullptr;
	this->income = 0;
	this->expenses = 0;
}

Store::Store(const Store& other) {
	this->copy(other);
}

Store& Store::operator=(const Store& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

Store::~Store() {
	this->free();
}

Waffle* Store::getWaffles() {
	return this->waffles;
}

size_t Store::getMaxWaffleCount() {
	return this->maxWaffleCount;
}

double Store::getIncome() {
	return this->income;
}

double Store::getExpenses() {
	return this->expenses;
}

void Store::setWaffles(Waffle* waffles) {
    if (this->maxWaffleCount > maxWaffleCount) {
        std::cout << "Too many waffles to store!" << std::endl;
        return;
    }

    for (size_t i = 0; i < this->maxWaffleCount; ++i) {
        this->waffles[i] = waffles[i];
    }
}

void Store::setMaxWaffleCount(size_t newMaxWaffleCount) {
    this->maxWaffleCount = newMaxWaffleCount;
}

void Store::setExpenses(double newExpenses) {
    this->expenses = newExpenses;
}

void Store::setIncome(double newIncome) {
    this->income = newIncome;
}

void Store::sellWaffles(const char* brand) {
    for (size_t i = 0; i < this->maxWaffleCount; ++i) {
        if (strcmp(this->waffles[i].getBrand(), brand) == 0) {
            this->income += this->waffles[i].getPriceForClient();

            for (size_t j = i; j < this->maxWaffleCount - 1; ++j) {
                this->waffles[j] = this->waffles[j + 1];
            }

            --this->maxWaffleCount;
            return;
        }
    }
    std::cout << "Waffle brand " << brand << " not found!" << std::endl;
}

void Store::buyWaffles(const char* brand, size_t count) {
    if (this->maxWaffleCount + count > this->maxWaffleCount) {
        std::cout << "Not enough space to store more waffles!" << std::endl;
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        this->waffles[this->maxWaffleCount++] = Waffle(brand, 0, 0, 0);
    }

    for (size_t i = 0; i < this->maxWaffleCount; ++i) {
        if (strcmp(this->waffles[i].getBrand(), brand) == 0) {
            this->expenses += this->waffles[i].getPriceForBulk() * count;
            return;
        }
    }
}

int Store::displayWaffles(const char* brand) {
    int counter = 0;
    for (size_t i = 0; i < this->maxWaffleCount; ++i) {
        if (strcmp(this->waffles[i].getBrand(), brand) == 0) {
            ++counter;
        }
    }
    return counter;
}

double Store::showProfit() {
    return this->income - this->expenses;
}

//__________________________________________________________________________________________________________________________________
//Exercise 2
//NumberSeries.h
#ifndef _NUMBERSERIES_H
#define _NUMBERSERIES_H

constexpr int DEF_BEG_SIZE = 1;
constexpr int DEF_CAPACITY = 10;

class NumberSeries {
private:
	int begining;
	int (*transitionfunction)(int);
	int* series;
	int size;
	int capacity;

	void copy(const NumberSeries& other);
	void free();
	void resizeSeries(int newCapacity);
	void generateNewSeries();
public:
	NumberSeries(int newBegining, int (*newtransitionfunction)(int));
	NumberSeries();
	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& other);

	//setter
	void setBegining(int newBegining);
	void setTransitionFunction(int (*newTransitionFunction)(int));

	//getters
	int getBegining();

	//generate i number
	int generateNumber(int i);
	//see if series contains a number
	bool contains(int value);
};

#endif // !_NUMBERSERIES_H


//NumberSeries.cpp
#include "NumberSeries.h"
#include<iostream>

void NumberSeries::copy(const NumberSeries& other) {
	this->begining = other.begining;
	this->transitionfunction = other.transitionfunction;
	this->size = other.size;
	this->capacity = other.capacity;
	this->series = new int[other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->series[i] = other.series[i];
	}
}

void NumberSeries::free() {
	delete[] this->series;
}

void NumberSeries::resizeSeries(int newCapacity) {
	int* resizedSeries = new int[newCapacity];
	for (size_t i = 0; i < this->size; ++i) {
		resizedSeries[i] = this->series[i];
	}
	delete[] this->series;
	this->series = resizedSeries;
	this->capacity = newCapacity;
}

void NumberSeries::generateNewSeries() {
	delete[] this->series;
	this->size = DEF_BEG_SIZE;
	this->capacity = DEF_BEG_SIZE;
	this->series = new int[this->capacity];
	this->series[0] = this->begining;
}

NumberSeries::NumberSeries(int newBegining, int(*newtransitionfunction)(int)) {
	this->begining = newBegining;
	this->transitionfunction = newtransitionfunction;
	this->size = 0;
	this->capacity = 0;
	this->series = new int[this->capacity];
}

NumberSeries::NumberSeries() {
	this->begining = 0;
	this->transitionfunction = nullptr;
	this->series = nullptr;
	this->capacity = DEF_CAPACITY;
	this->size = DEF_BEG_SIZE;
}

NumberSeries::NumberSeries(const NumberSeries& other) {
	this->copy(other);
}

NumberSeries& NumberSeries::operator=(const NumberSeries& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

void NumberSeries::setBegining(int newBegining) {
	this->begining = newBegining;
	this->generateNewSeries();
}

void NumberSeries::setTransitionFunction(int(*newTransitionFunction)(int)) {
	this->transitionfunction = newTransitionFunction;
	this->generateNewSeries();
}

int NumberSeries::getBegining() {
	return this->begining;
}

int NumberSeries::generateNumber(int i) {
	while (this->size <= i) {
		if (this->size == this->capacity) {
			this->resizeSeries(this->capacity);
		}
		this->series[this->size] = this->transitionfunction(this->series[this->size - 1]);
		++this->size;
	}
	return this->series[i];
}

bool NumberSeries::contains(int value) {
	for (int i = 0; i < this->size; i++) {
		if (this->series[i] == value) {
			return true;
		}
	}
	return false;
}

//___________________________________________________________________________________________________________________________________
//Exercise 3
//States.h
#ifndef _STATES_H

enum class State {
	OK,
	NegativeBalance,
	NegativeQuantity,
	UserFull,
	ProductFull,
	PriceFull,
	UserNotFound,
	ProductNotFound,
	ShortOnMoney,
	NotEnoughItems
};

const char* stateToString(State state) {
	switch (state) {
	case State::OK: return "OK!";
	case State::NegativeBalance: return "Negative balance!";
	case State::NegativeQuantity : return "Negative quantity!";
	case State::UserFull: return "User full!";
	case State::ProductFull: return "Product full!";
	case State::PriceFull: return "Price full!";
	case State::UserNotFound: return "User not found!";
	case State::ProductNotFound: return "Product not found!";
	case State::ShortOnMoney: return "Short on money!";
	case State::NotEnoughItems: return "Not enough items!";
	default: return "Unknown error!";
	}
}

#endif // !_STATES_H


//Price.h
#ifndef _PRICE_H
#define _PRICE_H

#include "States.h"

class Price {
private:
	size_t productId;
	double price;

public:
	Price(size_t newProductId, double newPrice);
	Price();

	double getPrice() const;
	size_t getProductId() const;
	State updatePrice(double amount);
};

#endif // !_PRICE_H



//Price.cpp
#include "Price.h"

#include "States.h"

Price::Price(size_t productId, double price) {
	this->productId = productId;
	this->price = price;
}

Price::Price() {
	this->productId = 0;
	this->price = 0;
}

double Price::getPrice() const {
	return this->price;
}

size_t Price::getProductId() const {
	return this->productId;
}

State Price::updatePrice(double amount) {
	double currentPrice = this->price;
	this->price += amount;

	if (this->price < 0) {
		this->price = currentPrice;
		return State::NegativeBalance;
	}

	return State::OK;
}


//Product.h
#ifndef _PRODUCT_H
#define _PRODUCT_H

#include "States.h"

class Product {
private:
	char* name;
	size_t ownerId;
	size_t quantity;
	size_t productId;

	void copy(const Product& other);
	void free();
public:
	Product(const char* newName, size_t newOwnerId, size_t newQuantity, size_t newProductId);
	Product();
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	size_t getQuantity() const;
	void setQuantity(size_t newQuantity);
	void setOwnerId(size_t newOwnerId);
	char* getName();
	State updateQuantity(int amount);
	size_t getProductId() const;
	size_t getOwnerId() const;
};

#endif // !_PRODUCT_H


//Product.cpp
#include "Product.h"
#include<cstring>
#include "States.h"

void Product::copy(const Product& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->ownerId = other.ownerId;
	this->quantity = other.quantity;
	this->productId = other.productId;
}

void Product::free() {
	delete[] this->name;
}

Product::Product(const char* newName, size_t newOwnerId, size_t newQuantity, size_t newProductId) {
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
	this->ownerId = newOwnerId;
	this->quantity = newQuantity;
	this->productId = newProductId;
}

Product::Product() {
	this->name = nullptr;
	this->ownerId = 0;
	this->quantity = 0;
	this->productId = 0;
}

Product::Product(const Product& other) {
	this->copy(other);
}

Product& Product::operator=(const Product& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

Product::~Product() {
	this->free();
}

size_t Product::getQuantity() const {
	return this->quantity;
}

void Product::setQuantity(size_t newQuantity) {
	this->quantity = newQuantity;
}

void Product::setOwnerId(size_t newOwnerId) {
	this->ownerId = newOwnerId;
}

char* Product::getName() {
	return this->name;
}

State Product::updateQuantity(int amount) {
	if (amount < 0) {
		return State::NegativeQuantity;
	}
	else {
		this->quantity = amount;
		return State::OK;
	}
}

size_t Product::getProductId() const {
	return this->productId;
}

size_t Product::getOwnerId() const {
	return this->ownerId;
}


//User.h
#ifndef _USER_H
#define _USER_H

#include<cstring>
#include "States.h"

class User {
private:
	size_t id;
	char* name;
	double balance;

	void copy(const User& other);
	void free();

public:
	User(size_t newId, const char* newName, double newBalance);
	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();

	//Setters
	void setId(size_t newId);
	void setName(const char* newName);
	void setBalance(double newBalance);

	//Getters
	size_t getId() const;
	const char* getName() const;
	double getBalance() const;

	State updateMoney(double factor);
	bool hasMoney(double arg);

	void displayUserInfo();
};
#endif // !_USER_H


//User.cpp
#include "User.h"
#include "States.h"
#include<cstring>
#include<iostream>

void User::copy(const User& other) {
	this->id = other.id;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->balance = other.balance;
}

void User::free() {
	delete[] this->name;
}

User::User(size_t newId, const char* newName, double newBalance) {
	this->id = newId;
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
	this->balance = newBalance;
}

User::User() {
	this->id = 0;
	this->name = nullptr;
	this->balance = 0;
}

User::User(const User& other) {
	this->copy(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

User::~User() {
	this->free();
}

void User::setId(size_t newId) {
	this->id = newId;
}

void User::setName(const char* newName) {
	if (!this->name) {
		return;
	}

	if (this->name == newName) {
		return;
	}

	if (this->name != nullptr) {
		delete[] this->name;
	}

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void User::setBalance(double newBalance) {
	this->balance = newBalance;
}

size_t User::getId() const {
	return this->id;
}

const char* User::getName() const {
	return this->name;
}

double User::getBalance() const {
	return this->balance;
}

State User::updateMoney(double factor) {
	double currentBalance = this->balance;
	this->balance += factor;

	if (this->balance < 0) {
		this->balance = currentBalance;
		return State::NegativeBalance;
	}

	return State::OK;
}

bool User::hasMoney(double arg) {
	return this->balance >= arg;
}

void User::displayUserInfo() {
	std::cout << "User's id: " << this->id << std::endl;
	std::cout << "User's name: " << this->name << std::endl;
	std::cout << "User's balance: " << this->balance << std::endl;
	std::cout << std::endl;
}


//PricesDatabase.h
#ifndef _PRICESDATABASE_H
#define _PRICESDATABASE_H

#include "Price.h"

class PricesDatabase {
private:
	Price* prices;
	size_t size;
	size_t capacity;

	void copy(const PricesDatabase& other);
	void free();

public:
	PricesDatabase(Price* newPrices, size_t newSize, size_t newCapacity);
	PricesDatabase();
	PricesDatabase(const PricesDatabase& other);
	PricesDatabase& operator=(const PricesDatabase& other);
	~PricesDatabase();

	State addPrice(size_t productId, double price);
	double getPrice(size_t id);
};

#endif // !_PRICESDATABASE_H


//PricesDatabase.cpp
#include "PricesDatabase.h"
#include "Price.h"
#include "Product.h"

State PricesDatabase::addPrice(size_t productId, double price) {
    if (this->size >= this->capacity) {
        return State::PriceFull;
    }

    for (size_t i = 0; i < this->size; i++) {
        if (this->prices[i].getProductId() == productId) {
            return State::OK;
        }
    }

    this->prices[this->size] = Price(productId, price);
    ++this->size;
    return State::OK;
}

void PricesDatabase::copy(const PricesDatabase& other) {
    this->size = other.size;
    this->capacity = other.capacity; this->prices = new Price[other.capacity];
    for (size_t i = 0; i < other.size; ++i) {
        this->prices[i] = other.prices[i];
    }
}

void PricesDatabase::free() {
    delete[] this->prices;
}

PricesDatabase::PricesDatabase(Price* newPrices, size_t newSize, size_t newCapacity) {
    this->size = newSize;
    this->capacity = newCapacity;
    this->prices = new Price[newCapacity];
    for (size_t i = 0; i < newSize; ++i) {
        this->prices[i] = newPrices[i];
    }
}

PricesDatabase::PricesDatabase() {
    this->size = 0;
    this->capacity = 0;
    this->prices = nullptr;
}

PricesDatabase::PricesDatabase(const PricesDatabase& other) {
    this->copy(other);
}

PricesDatabase& PricesDatabase::operator=(const PricesDatabase& other) {
    if (this != &other) {
        this->free();
        this->copy(other);
    }

    return *this;
}

PricesDatabase::~PricesDatabase() {
    this->free();
}

double PricesDatabase::getPrice(size_t id) {
    for (size_t i = 0; i < size; i++) {
        if (this->prices[i].getProductId() == id) {
            return this->prices[i].getPrice();
        }
    }
    return -1;
}


//UserDatabase.h
#ifndef _USERDATABASE_H
#define _USERDATABASE_H

#include "User.h"
#include "States.h"

constexpr size_t MAX_CAPACITY = 2000;

class UserDatabase {
private:
	User users[MAX_CAPACITY];
	size_t size;

	void copy(const UserDatabase& other);
public:
	UserDatabase(const User* users, size_t size);
	UserDatabase();
	UserDatabase(const UserDatabase& other);

	size_t getSize() const;
	void setSize(size_t newSize);

	State addUser(const User& user);
	bool hasEnoughMoney(size_t id, double money);
	bool existUser(size_t id);
	State removeUser(size_t userID);
	State updateUserBalance(size_t userID, double amount);
	void printUserInfo(size_t id);
	void printAllUsers();
};

#endif // !_USERDATABASE_H


//UserDatabase.cpp
#include "UserDatabase.h"
#include "States.h"
#include<iostream>

void UserDatabase::copy(const UserDatabase& other) {
	this->size = other.size;
	if (this->size > MAX_CAPACITY) {
		std::cerr << "Invalid input! The size of your database can;t be bigger than its capacity!" << std::endl;
		return;
	}
	for (size_t i = 0; i < other.size; ++i) {
		this->users[i] = other.users[i];
	}
}


UserDatabase::UserDatabase(const User* newUsers, size_t newSize) {
	this->size = newSize;
	if (size > MAX_CAPACITY) {
		std::cerr << "Invalid input! The size of your database can't be bigger than its capacity!" << std::endl;
		return;
	}
	for (size_t i = 0; i < newSize; ++i) {
		this->users[i] = users[i];
	}
}

UserDatabase::UserDatabase() {
	this->size = 0;
}

UserDatabase::UserDatabase(const UserDatabase& other) {
	this->copy(other);
}

State UserDatabase::addUser(const User& user) {
	if (this->size >= MAX_CAPACITY) {
		return State::UserFull;
	}

	this->users[this->size] = user;
	++this->size;

	return State::OK;
}

bool UserDatabase::hasEnoughMoney(size_t id, double money) {
	for (size_t i = 0; i < this->size; ++i) {
		if (this->users[i].getId() == id && this->users[i].getBalance()>=money) {
			return true;
		}
	}

	return false;
}

bool UserDatabase::existUser(size_t id) {
	for (size_t i = 0; i < this->size; ++i) {
		if (this->users[i].getId() == id) {
			return true;
		}
	}

	return false;
}

State UserDatabase::removeUser(size_t userID) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->users[i].getId() == userID) {
			for (size_t j = i; j < this->size - 1; j++) {
				this->users[j] = this->users[j + 1];
			}
			--this->size;
			return State::OK;
		}
	}
	return State::UserNotFound;
}

State UserDatabase::updateUserBalance(size_t userID, double amount) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->users[i].getId() == userID) {
			return this->users[i].updateMoney(amount);
		}
	}
	return State::UserNotFound;
}

void UserDatabase::printUserInfo(size_t id) {
	for (size_t i = 0; i < this->size; ++i) {
		if (this->users[i].getId() == id) {
			this->users[i].displayUserInfo();
		}
	}
}

void UserDatabase::printAllUsers() {
	for (size_t i = 0; i < this->size; ++i) {
		std::cout << "User " << i + 1 << ":" << std::endl;
		this->users[i].displayUserInfo();
	}
}

size_t UserDatabase::getSize() const {
	return this->size;
}

void UserDatabase::setSize(size_t newSize) {
	this->size = newSize;
}


//ProductDatabase.h
#ifndef _PRODUCT_DATABASE_H
#define _PRODUCT_DATABASE_H

#include "Product.h"
#include "States.h"

class ProductDatabase {
private:
	Product* products;
	size_t size;
	size_t capacity;

	void copy(const ProductDatabase& other);
	void free();

	void resizeDatabase();
public:
	ProductDatabase(Product* newProducts, size_t newSize, size_t newCapacity);
	ProductDatabase();
	ProductDatabase(const ProductDatabase* other);
	ProductDatabase& operator=(const ProductDatabase& other);
	~ProductDatabase();

	State addProduct(const Product& product);
	size_t itemsOwned(size_t id, size_t productId);
	State update(size_t id, size_t productID, int update);
	State removeProduct(size_t id);
	bool existProduct(size_t productId);
	State updateProductOwner(size_t productID, size_t newOwnerID);
	size_t findProductByName(const char* name);
	bool existProductForUser(size_t userID, size_t productID);
	const char* getProductName(size_t productId);
};

#endif // !_PRODUCT_DATABASE_H


//ProductDatabase.cpp
#include "ProductDatabase.h"
#include "Product.h"
#include<cstring>

void ProductDatabase::copy(const ProductDatabase& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->products = new Product[other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->products[i] = other.products[i];
	}
}

void ProductDatabase::free() {
	delete[] this->products;
}

void ProductDatabase::resizeDatabase() {
	size_t newCapacity = capacity * 2;
	Product* newPrds = new Product[newCapacity];
	for (size_t i = 0; i < size; i++) {
		newPrds[i] = products[i];
	}
	delete[] products;
	products = newPrds;
	capacity = newCapacity;
}

ProductDatabase::ProductDatabase(Product* newProducts, size_t newSize, size_t newCapacity) {
	this->size = newSize;
	this->capacity = newCapacity;
	this->products = new Product[newCapacity];
	for (size_t i = 0; i < newSize; ++i) {
		this->products[i] = newProducts[i];
	}
}

ProductDatabase::ProductDatabase() {
	this->size = 0;
	this->capacity = 0;
	this->products = nullptr;
}

ProductDatabase::ProductDatabase(const ProductDatabase* other) {
	this->copy(other);
}

ProductDatabase& ProductDatabase::operator=(const ProductDatabase& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}
	return *this;
}

ProductDatabase::~ProductDatabase() {
	this->free();
}

State ProductDatabase::addProduct(const Product& newProduct) {
	if (this->size >= this->capacity ) {
		return State::ProductFull;
	}
	
	this->products[this->size] = newProduct;
	++this->size;

	return State::OK;
}

size_t ProductDatabase::itemsOwned(size_t id, size_t productId) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->products[i].getOwnerId() == id && this->products[i].getProductId() == productId) {
			return this->products[i].getQuantity();
		}
	}
	return 0;
}

State ProductDatabase::update(size_t id, size_t productID, int update) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->products[i].getOwnerId() == id && this->products[i].getProductId() == productID) {
			if (update < 0 && (size_t)(update) > this->products[i].getQuantity()) {
				return State::ProductNotFound;
			}
			size_t newQuantity = this->products[i].getQuantity() + update;
			this->products[i].setQuantity(newQuantity);
			return State::OK;
		}
	}
	return State::ProductNotFound;
}

State ProductDatabase::removeProduct(size_t id) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->products[i].getProductId() == id) {
			for (size_t j = i; j < this->size - 1; j++) {
				this->products[j] = this->products[j + 1];
			}
			--this->size;
			return State::OK;
		}
	}
	return State::ProductNotFound;
}

bool ProductDatabase::existProduct(size_t productID) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->products[i].getProductId() == productID) {
			return true;
		}
	}
	return false;
}

State ProductDatabase::updateProductOwner(size_t productID, size_t newOwnerID) {
	for (size_t i = 0; i < this->size; i++) {
		if (this->products[i].getProductId() == productID) {
			this->products[i].setOwnerId(newOwnerID);
			return State::OK;
		}
	}
	return State::ProductNotFound;
}

size_t ProductDatabase::findProductByName(const char* name) {
	for (size_t i = 0; i < this->size; i++) {
		const char* productName = this->products[i].getName();
		if (productName && strcmp(productName, name) == 0) {
			return this->products[i].getProductId();
		}
	}
}

bool ProductDatabase::existProductForUser(size_t userID, size_t productID) {
	for (size_t i = 0; i < size; i++) {
		if (products[i].getProductId() == productID && products[i].getOwnerId() == userID) {
			return true;
		}
	}
	return false;
}

const char* ProductDatabase::getProductName(size_t productId) {
	for (size_t i = 0; i < size; i++) {
		if (products[i].getProductId() == productId) {
			return products[i].getName();
		}
	}
	return nullptr;
}


//SalesSystem.h
#ifndef _SALESSYSTEM_
#define _SALESSYSTEM_

#include "UserDatabase.h"
#include "ProductDatabase.h"
#include "PricesDatabase.h"

class SalesSystem {
private:
	UserDatabase users;
	ProductDatabase products;
	PricesDatabase prices;
public:
	SalesSystem(const UserDatabase& newUsers, const ProductDatabase& newProducts, const PricesDatabase& newPrices);
	SalesSystem();

	State addUser(const char* name, size_t id, double balance);
	State addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity);
	State addPrice(size_t productID, double price);
	State sell(size_t idFrom, size_t idTo, size_t productID, size_t quantity);
};

#endif // !_SALESSYSTEM_

//SalesSystem.cpp
#include "SalesSystem.h"

#include "UserDatabase.h"
#include "ProductDatabase.h"
#include "PricesDatabase.h"
#include "Product.h"

SalesSystem::SalesSystem(const UserDatabase& newUsers, const ProductDatabase& newProducts, const PricesDatabase& newPrices) {
	this->users = newUsers;
	this->products = newProducts;
	this->prices = newPrices;
}

SalesSystem::SalesSystem() {

}

State SalesSystem::addUser(const char* name, size_t id, double balance) {
	User newUser(id, name, balance);
	return users.addUser(newUser);
}

State SalesSystem::addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity) {
	if (!users.existUser(ownerID)) {
		return State::UserNotFound;
	}
	Product newProduct(name, ownerID, quantity, productID);
	return products.addProduct(newProduct);
}

State SalesSystem::addPrice(size_t productID, double price) {
	if (price < 0) {
		return State::NegativeQuantity;
	}
	if (!products.existProduct(productID)) {
		return State::ProductNotFound;
	}
	return prices.addPrice(productID, price);
}

State SalesSystem::sell(size_t idFrom, size_t idTo, size_t productID, size_t quantity) {
    if (!users.existUser(idFrom) || !users.existUser(idTo)) {
        return State::UserNotFound;
    }
    if (!products.existProduct(productID)) {
        return State::ProductNotFound;
    }
    if (products.itemsOwned(idFrom, productID) < quantity) {
        return State::NotEnoughItems;
    }

    double pricePerItem = prices.getPrice(productID);
    double totalPrice = pricePerItem * quantity;

    if (!users.hasEnoughMoney(idTo, totalPrice)) {
        return State::ShortOnMoney;
    }

    users.updateUserBalance(idTo, -totalPrice);
    users.updateUserBalance(idFrom, totalPrice);
    products.update(idFrom, productID, -quantity);

    if (!products.existProductForUser(idTo, productID)) {
        Product newProduct(products.getProductName(productID), idTo, quantity, productID);
        products.addProduct(newProduct);
    }
    else {
        products.update(idTo, productID, quantity);
    }

    return State::OK;
}
