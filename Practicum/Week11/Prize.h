#pragma once

namespace {
	const char penguinFile[] = "penguin.txt";
	const char pacmanFile[] = "pacman.txt";
	const char computerBoyFile[] = "computerBoy.txt";
	const char squidwardFile[] = "squidward.txt";
	const char sylvesterFile[] = "sylvester.txt";
}



class Prize
{
protected:
	double price;
	size_t points;
public:
	Prize(double price,size_t points);
	virtual void visualize() = 0;
};

class Penguin : public Prize
{
	static const size_t neededPoints = 50;
public:
	void visualize() override;
};

class Pacman : public Prize
{
	static const size_t neededPoints = 150;
public:
	void visualize() override;
};

class ComputerBoy : public Prize
{
	static const size_t neededPoints = 500;
public:
	void visualize() override;
};

class Squidward : public Prize
{
	static const size_t neededPoints = 1000;
public:
	void visualize() override;
};

class Sylvester : public Prize
{
	static const size_t neededPoints = 1500;
public:
	void visualize() override;
};
