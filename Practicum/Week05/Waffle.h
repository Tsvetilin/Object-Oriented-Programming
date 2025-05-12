#pragma once

class Waffle
{
public:
	Waffle();
	Waffle(const char* brand, double weight, double price, double priceForSale);;
	Waffle(const Waffle& other);
	Waffle& operator=(const Waffle& other);
	~Waffle();
	void copyFrom(const Waffle& other);
	void free();
	char* getBrand() const;
	double getWeight() const;
	double getPrice() const;
	double getPriceForSale() const;
	void setBrand(const char* str);
	void setWeight(double weight);
	void setPrice(double price);
	void setPriceForSale(double priceForSale);

private:
	char* brand;
	double weight;
	double price;
	double priceForSale;
};