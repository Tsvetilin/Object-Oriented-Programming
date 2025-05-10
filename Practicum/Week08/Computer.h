#pragma once
class Computer
{
private:
	static size_t pcCounter;
	size_t id;
	char* brand;
	char* proccessor;
	int video;
	size_t  hardDrive;
	size_t weight;
	size_t baterryLife;
	double price;
	size_t quantity;

	void copyFrom(const Computer& other);
	void free();
public:
	Computer();
	Computer(const char* name, const char* proccessor, int video, size_t hardDrive,
		size_t weight, size_t batteryLife, double price, size_t quantity);;
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();
	void setPrice(double price);
	void changeQuantity(int quantity);

	const char* getBrand() const;
	const char* getProccessor() const;
	int getVideo() const;
	const size_t getHDD() const;
	size_t getWeight() const;
	const size_t getBatteryLife() const;
	const double getPrice() const;
	const size_t getQuantity() const;
};

