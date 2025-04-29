#include "Gallery.h"

Gallery::Gallery(const Picture* pictures, bool* moved, size_t gallerySize, size_t galleryCapacity) {
	setGallery(pictures, moved, gallerySize, galleryCapacity);
}

Gallery::Gallery() {
	this->gallerySize = 0;
	this->galleryCapacity = 1;
	this->moved = new bool[galleryCapacity];
	this->moved[0] = true;
	this->pictures = new Picture[galleryCapacity];
	this->pictures[0] = Picture();
}

Gallery::Gallery(const Gallery& other) {
	this->copyFrom(other);
}

Gallery& Gallery::operator=(const Gallery& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Gallery::Gallery(Gallery&& other) noexcept {
	this->moveFrom(std::move(other));
}

Gallery& Gallery::operator=(Gallery&& other) noexcept {
	if (this != &other) {
		this->free();
		this->moveFrom(std::move(other));
	}

	return *this;
}

Gallery::~Gallery() {
	this->freePictures();
}

void Gallery::setGallery(const Picture* pictures, bool* moved, size_t gallerySize, size_t galleryCapacity) {
	if (galleryCapacity < gallerySize) {
		throw std::invalid_argument("The size of the gallery cannot be bigger than its capacity!");
	}

	if (moved == nullptr) {
		throw std::invalid_argument("This array cannot be null!");
	}

	if (pictures == nullptr) {
		throw std::invalid_argument("Your gallery cannot be null!");
	}

	this->galleryCapacity = galleryCapacity;
	this->gallerySize = gallerySize;
	this->pictures = new Picture[galleryCapacity];
	for (size_t i = 0; i < gallerySize; ++i) {
		this->pictures[i] = pictures[i];
	}

	this->moved = new bool[galleryCapacity];
	for (size_t i = 0; i < gallerySize; ++i) {
		this->moved[i] = moved[i];
	}
}

const Picture* Gallery::getGallery() const {
	return this->pictures;
}

const bool* Gallery::getIfIsMoved() const {
	return this->moved;
}

size_t Gallery::getGallerySize() const {
	return this->gallerySize;
}

size_t Gallery::getGalleryCapacity() const {
	return this->galleryCapacity;
}

void Gallery::addNewPicture(const Picture& newPicture, bool newMoved) {
	if (this->gallerySize >= this->galleryCapacity) {
		this->resizeGallery();
	}

	this->pictures[this->gallerySize] = newPicture;
	this->moved[this->gallerySize] = newMoved;
	++this->gallerySize;
}

void Gallery::removePictureByIndex(size_t index) {
	if (index >= gallerySize) {
		throw std::out_of_range("Invalid index!");
	}

	for (size_t i = index; i < this->gallerySize - 1; ++i) {
		this->pictures[i] = this->pictures[i + 1];
		this->moved[i] = this->moved[i + 1];
	}

	--this->gallerySize;
}

void Gallery::applyFilterToAPicture(size_t index, Filter filtertype) {
	if (index > this->gallerySize) {
		throw std::invalid_argument("Invalid index!");
	}

	switch (filtertype) {
	case Filter::Grayscale:
		pictures[index].grayscale();
		break;
	case Filter::Monochrome:
		pictures[index].monochrome();
		break;
	case Filter::Negative:
		pictures[index].negative();
		break;
	default:
		throw std::invalid_argument("Unknown filter type!");
	}
}

void Gallery::applyFilterToAllPictures(Filter filtertype) {
	for (size_t i = 0; i < gallerySize; ++i) {
		applyFilterToAPicture(i, filtertype);
	}
}

const Picture& Gallery::operator[](size_t index) const {
	if (index >= this->gallerySize) {
		throw std::out_of_range("Index out of range!");
	}
	return this->pictures[index];
}

void Gallery::printGalleryInfo() const {
	if (this->gallerySize == 0) {
		throw std::invalid_argument("Gallery is empty!");
	}

	for (size_t i = 0; i < gallerySize; ++i) {
		std::cout << "Picture #" << i << (moved[i] ? " [MOVED]" : " [IN GALLERY]") << ":" << std::endl;
		pictures[i].printPicture();
		std::cout << std::endl;
	}
}

void Gallery::resizeGallery() {
	size_t newCapacity = this->galleryCapacity * 2;
	Picture* newPictures = new Picture[newCapacity];
	bool* newMoved = new bool[newCapacity];

	for (size_t i = 0; i < this->gallerySize; ++i) {
		newPictures[i] = this->pictures[i];
	}

	for (size_t i = 0; i < this->gallerySize; ++i) {
		newMoved[i] = this->moved[i];
	}

	delete[] this->pictures;
	delete[] this->moved;
	this->pictures = newPictures;
	this->moved = newMoved;
	this->galleryCapacity = newCapacity;
}

void Gallery::copyFrom(const Gallery& other) {
	if (other.galleryCapacity < other.gallerySize) {
		throw std::invalid_argument("The size of the gallery cannot be bigger than its capacity!");
	}

	if (other.moved == nullptr) {
		throw std::invalid_argument("This array cannot be null!");
	}

	if (other.pictures == nullptr) {
		throw std::invalid_argument("Your gallery cannot be null!");
	}

	this->galleryCapacity = other.galleryCapacity;
	this->gallerySize = other.gallerySize;
	this->pictures = new Picture[other.galleryCapacity];
	for (size_t i = 0; i < other.gallerySize; ++i) {
		this->pictures[i] = other.pictures[i];
	}

	this->moved = new bool[other.galleryCapacity];
	for (size_t i = 0; i < other.gallerySize; ++i) {
		this->moved[i] = other.moved[i];
	}
}

void Gallery::moveFrom(Gallery&& other) noexcept {
	this->pictures = other.pictures;
	this->moved = other.moved;
	this->galleryCapacity = other.galleryCapacity;
	this->gallerySize = other.gallerySize;

	other.pictures = nullptr;
	other.moved = nullptr;
	other.galleryCapacity = 0;
	other.gallerySize = 0;
}

void Gallery::freePictures() {
	delete[] this->pictures;
	this->pictures = nullptr;
}

void Gallery::freeMoved() {
	delete[] this->moved;
	this->moved = nullptr;
}

void Gallery::free() {
	this->freePictures();
	this->freeMoved();
	this->gallerySize = 0;
	this->galleryCapacity = 0;
}
