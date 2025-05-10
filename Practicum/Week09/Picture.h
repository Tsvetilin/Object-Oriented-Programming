#ifndef _PICTURE_H
#define _PICTURE_H

#include<stdexcept>
#include<iostream>

#include "Pixel.h"

class Picture {
public:
	Picture(const Pixel** picture, size_t width, size_t length);
	Picture();
	Picture(const Picture& other);
	Picture& operator=(const Picture& other);
	Picture(Picture&& other) noexcept;
	Picture& operator=(Picture&& other) noexcept;
	~Picture();

	void setPicture(const Pixel** picture, size_t width, size_t length);
	void setWidth(size_t width);
	void setLength(size_t length);

	const Pixel** getPicture() const;
	size_t getPictureWidth() const;
	size_t getPictureLength() const;

	bool isColourful() const;
	bool isMonochrome() const;

	Pixel** grayscale() const;
	Pixel** monochrome() const;
	Pixel** negative() const;

	void printPicture() const;

private:
	Pixel** picture;
	size_t width;
	size_t length;

	void copyFrom(const Picture& other);
	void moveFrom(Picture&& other) noexcept;
	void freePicture();
};

#endif // !_PICTURE_H
