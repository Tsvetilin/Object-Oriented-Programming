#include "Pixel.h"

Pixel::Pixel(int red, int green, int blue) {
	setRedColour(red);
	setGreenColour(green);
	setBlueColour(blue);
}

Pixel::Pixel() {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

void Pixel::setRedColour(int red) {
	if (red < MIN_PIXEL_VALUE || red > MAX_PIXEL_VALUE) {
		throw std::invalid_argument("Invalid value of colour red!");
	}

	this->red = red;
}

void Pixel::setGreenColour(int green) {
	if (green < MIN_PIXEL_VALUE || green > MAX_PIXEL_VALUE) {
		throw std::invalid_argument("Invalid value of colour green!");
	}

	this->green = green;
}

void Pixel::setBlueColour(int blue) {
	if (blue < MIN_PIXEL_VALUE || blue > MAX_PIXEL_VALUE) {
		throw std::invalid_argument("Invalid value of colour blue!");
	}

	this->blue = blue;
}

int Pixel::getRedColourValue() const {
	return this->red;
}

int Pixel::getGreenColourValue() const {
	return this->green;
}

int Pixel::getBlueColourValue() const {
	return this->blue;
}

void Pixel::printColourValues() const {
	std::cout << "(" << this->red << ", " << this->green << ", " << this->blue << ")" << std::endl;
}
