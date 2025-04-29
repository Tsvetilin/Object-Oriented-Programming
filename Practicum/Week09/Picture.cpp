#include "Picture.h"

void Picture::setPicture(const Pixel** picture, size_t width, size_t length) {
    setWidth(width);
    setLength(length);

    if (picture == nullptr) {
        throw std::invalid_argument("Picture cannot be null!");
    }

    this->picture = new Pixel * [this->length];
    for (size_t i = 0; i < this->length; ++i) {
        this->picture[i] = new Pixel[this->width];
    }

    for (size_t i = 0; i < this->length; ++i) {
        for (size_t j = 0; j < this->width; ++j) {
            this->picture[i][j] = picture[i][j];
        }
    }
}

void Picture::setWidth(size_t width) {
    this->width = width;
}

void Picture::setLength(size_t length) {
    this->length = length;
}

const Pixel** Picture::getPicture() const {
    return (const Pixel**)(this->picture);
}

size_t Picture::getPictureWidth() const {
    return this->width;
}

size_t Picture::getPictureLength() const {
    return this->length;
}

bool Picture::isColourful() const {
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j < width; ++j) {
            int r = picture[i][j].getRedColourValue();
            int g = picture[i][j].getGreenColourValue();
            int b = picture[i][j].getBlueColourValue();
            if (!(r == g && g == b)) {
                return true;
            }
        }
    }
    return false;
}

bool Picture::isMonochrome() const {
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j < width; ++j) {
            int r = picture[i][j].getRedColourValue();
            int g = picture[i][j].getGreenColourValue();
            int b = picture[i][j].getBlueColourValue();
            if (!((r == 0 && g == 0 && b == 0) || (r == 255 && g == 255 && b == 255))) {
                return false;
            }
        }
    }
    return true;
}

Pixel** Picture::grayscale() const {
    if (!isColourful()) {
        throw std::logic_error("Cannot apply grayscale to a grayscale or monochrome picture!");
    }

    Pixel** grayPicture = new Pixel * [this->length];
    for (size_t i = 0; i < this->length; ++i) {
        grayPicture[i] = new Pixel[this->width];
    }

    for (size_t i = 0; i < this->length; ++i) {
        for (size_t j = 0; j < this->width; ++j) {
            double grayValue = picture[i][j].getRedColourValue() * 0.299 + picture[i][j].getGreenColourValue() * 0.587 + picture[i][j].getBlueColourValue() * 0.114;
            int gray = static_cast<int>(grayValue);
            grayPicture[i][j] = Pixel(gray, gray, gray);
        }
    }

    return grayPicture;
}

Pixel** Picture::monochrome() const {
    if (isMonochrome()) {
        throw std::logic_error("Cannot apply monochrome to an already monochrome picture!");
    }

    Pixel** monoPicture = new Pixel * [this->length];
    for (size_t i = 0; i < this->length; ++i) {
        monoPicture[i] = new Pixel[this->width];
    }

    for (size_t i = 0; i < this->length; ++i) {
        for (size_t j = 0; j < this->width; ++j) {
            double grayValue = picture[i][j].getRedColourValue() * 0.299
                + picture[i][j].getGreenColourValue() * 0.587
                + picture[i][j].getBlueColourValue() * 0.114;
            if (grayValue < 128) {
                monoPicture[i][j] = Pixel(0, 0, 0);
            }
            else {
                monoPicture[i][j] = Pixel(255, 255, 255);
            }
        }
    }

    return monoPicture;
}

Pixel** Picture::negative() const {
    Pixel** negPicture = new Pixel * [this->length];
    for (size_t i = 0; i < this->length; ++i) {
        negPicture[i] = new Pixel[this->width];
    }

    for (size_t i = 0; i < this->length; ++i) {
        for (size_t j = 0; j < this->width; ++j) {
            int newR = 255 - picture[i][j].getRedColourValue();
            int newG = 255 - picture[i][j].getGreenColourValue();
            int newB = 255 - picture[i][j].getBlueColourValue();
            negPicture[i][j] = Pixel(newR, newG, newB);
        }
    }

    return negPicture;
}

void Picture::printPicture() const {
    for (size_t i = 0; i < this->length; ++i) {
        for (size_t j = 0; j < this->width; ++j) {
            picture[i][j].printColourValues();
        }
        std::cout << std::endl;
    }
}

Picture::Picture(const Pixel** picture, size_t width, size_t length) {
    setPicture(picture, width, length);
}

Picture::Picture() {
    this->length = 1;
    this->width = 1;
    picture = new Pixel * [this->length];
    for (size_t i = 0; i < this->length; ++i) {
        picture[i] = new Pixel[this->width];
    }
}

Picture::Picture(const Picture& other) {
    this->copyFrom(other);
}

Picture& Picture::operator=(const Picture& other) {
    if (this != &other) {
        this->freePicture();
        this->copyFrom(other);
    }

    return *this;
}

Picture::Picture(Picture&& other) noexcept {
    this->moveFrom(std::move(other));
}

Picture& Picture::operator=(Picture&& other) noexcept {
    if (this != &other) {
        this->freePicture();
        this->moveFrom(std::move(other));
    }

    return *this;
}

Picture::~Picture() {
    this->freePicture();
}

void Picture::copyFrom(const Picture& other) {
    if (other.picture == nullptr) {
        throw std::invalid_argument("Your picture cannot be null!");
    }

    this->width = other.width;
    this->length = other.length;

    this->picture = new Pixel*[other.length];
    for (size_t i = 0; i < other.length; ++i) {
        this->picture[i] = new Pixel[other.width];
    }

    for (size_t i = 0; i < other.length; ++i) {
        for (size_t j = 0; j < other.width; ++j) {
            this->picture[i][j] = other.picture[i][j];
        }
    }
}

void Picture::moveFrom(Picture&& other) noexcept {
    this->length = other.length;
    this->width = other.width;
    this->picture = other.picture;

    other.length = 0;
    other.width = 0;
    other.picture = nullptr;
}

void Picture::freePicture() {
    for (size_t i = 0; i < this->length; ++i) {
        if (this->picture[i] != nullptr) {
            delete[] this->picture[i];
        }
    }

    delete[] this->picture;
    this->picture = nullptr;
}


