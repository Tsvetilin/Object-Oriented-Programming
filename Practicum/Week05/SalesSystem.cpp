#include "SalesSystem.h"
#include <iostream>

void SalesSystem::copyFrom(const SalesSystem& other)
{
	this->users = other.users;
	this->products = other.products;
	this->prices = other.prices;
}

void SalesSystem::free()
{
	this->users.free();
	this->products.free();
	this->prices.free();
}


SalesSystem::SalesSystem()
{
	this->users = UserDatabase();
	this->products = ProductsDatabase();
	this->prices = PricesDatabase();
}

SalesSystem& SalesSystem::operator=(const SalesSystem& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

SalesSystem::SalesSystem(const SalesSystem& other)
{
	copyFrom(other);
}

SalesSystem::~SalesSystem()
{
	free();
}

State SalesSystem::addUser(User user)
{
	if (users.existUser(user.getId()) != State::OK)
	{
		users.addUser(user);
		return State::OK;
	}
	std::cout << "UserAlreadyInDatabase\n";
	return State::OK;
}

State SalesSystem::addProduct(Product product)
{
	if (users.existUser(product.getOwnerId()) != State::OK) return State::UserNotFound;
	products.addProduct(product);
	return State::OK;
}

State SalesSystem::addPrice(Price price)
{
	if (price.getPrice() < 0) return State::NegativePrice;
	if (products.existProduct(price.getId()) != State::OK) return State::ProductNotFound;
	prices.addPrice(price);
	return State::OK;
}

State SalesSystem::sell(size_t idFrom, size_t idTo, size_t productId, size_t quantity)
{
	if (users.existUser(idFrom) != State::OK || users.existUser(idTo) != State::OK) return State::UserNotFound;
	if (products.existProduct(productId) != State::OK) return State::ProductNotFound;
	if (!users.hasEnoughMoney(idTo, prices.getPrice(productId))) return State::ShortOnMoney;
	if (products.itemsOwned(idFrom, productId) < quantity) return State::NotEnoughItems;

	
	users.update(idFrom, prices.getPrice(productId));
	users.update(idTo, prices.getPrice(productId) * -1);

	products.update(idFrom, productId, ((int)quantity) * -1);
	products.update(idTo, productId, (int)quantity);
}

