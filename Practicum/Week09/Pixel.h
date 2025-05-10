#ifndef _PIXEL_H
#define _PIXEL_H

#include<stdexcept>
#include<iostream>

const int MAX_PIXEL_VALUE = 255;
const int MIN_PIXEL_VALUE = 0;

class Pixel {
public:
	Pixel(int red, int green, int blue);
	Pixel();

	void setRedColour(int red);
	void setGreenColour(int green);
	void setBlueColour(int blue);

	int getRedColourValue() const;
	int getGreenColourValue() const;
	int getBlueColourValue() const;

	void printColourValues() const;

private:
	int red;
	int green;
	int blue;
};

#endif // !_PIXEL_H