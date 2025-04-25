#pragma once


enum class AccommType
{
	Apartament,Hotel,Villa
};

struct Point
{
	int x;
	int y;
};

class Accommodation
{
private:
	size_t id;
	char* name;
	AccommType type;
	Point point;
	double price;
	bool isFree;
	size_t days;
	
	void copyFrom(const Accommodation& other);
	void free();
public:
	Accommodation();
	Accommodation(const Accommodation& other);
	Accommodation& operator=(const Accommodation& other);
	~Accommodation();

	void setId(size_t id);
	void setName(const char* name);
	void setAccommType(AccommType);
	void setPoint(Point p);
	void setPrice(double price);
	void setDays(size_t days);

	size_t getId() const;
	const char* getName() const;
	AccommType getAccommType() const;
	Point getPoint() const;
	double getPrice() const;
	size_t getDays() const;
	bool getIsFree() const;

	void makeReservation(size_t days);
	void removeReservation();
	double total() const;
	
};

