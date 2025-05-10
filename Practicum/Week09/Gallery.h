#ifndef _GALLERY_H
#define _GALLERY_H

#include<iostream>
#include "Picture.h"
#include "Pixel.h"

enum class Filter {
	Grayscale,
	Monochrome,
	Negative
};

class Gallery {
public:
	Gallery(const Picture* pictures, bool* moved, size_t gallerySize, size_t galleryCapacity);
	Gallery();
	Gallery(const Gallery& other);
	Gallery& operator=(const Gallery& other);
	Gallery(Gallery&& other) noexcept;
	Gallery& operator=(Gallery&& other) noexcept;
	~Gallery();

	void setGallery(const Picture* pictures, bool* moved, size_t gallerySize, size_t galleryCapacity);

	const Picture* getGallery() const;
	const bool* getIfIsMoved() const;
	size_t getGallerySize() const;
	size_t getGalleryCapacity() const;

	void addNewPicture(const Picture& newPicture, bool newMoved);
	void removePictureByIndex(size_t index);
	void applyFilterToAPicture(size_t index, Filter filtertype);
	void applyFilterToAllPictures(Filter filtertype);
	const Picture& operator[](size_t index) const;

	void printGalleryInfo() const;

private:
	Picture* pictures;
	bool* moved;
	size_t gallerySize;
	size_t galleryCapacity;

	void resizeGallery();
	void copyFrom(const Gallery& other);
	void moveFrom(Gallery&& other) noexcept;
	void freePictures();
	void freeMoved();
	void free();
};

#endif // !_GALLERY_H
