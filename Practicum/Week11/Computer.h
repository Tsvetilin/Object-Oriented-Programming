#pragma once


class Computer
{
private:
	double CPU = 0;
	char* GPU = nullptr;
	size_t PSU = 0;
	size_t RAM = 0;

	void free();
	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other);
public:
	Computer();
	Computer(double CPU,const char* GPU,size_t PSU,size_t RAM);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	Computer(Computer&& other) noexcept;
	Computer& operator=(Computer&& other) noexcept;
	~Computer();

	void setCPU(double CPU);
	void setGPU(const char* GPU);
	void setPSU(size_t PSU);
	void setRAM(size_t RAM);

	virtual void getComputerType() const = 0;
	virtual void accessories() const = 0;

};

