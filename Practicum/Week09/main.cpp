#include <iostream>
#include "Picture.h"
#include "Pixel.h"
#include "Gallery.h"

int main() {
    try {
        Pixel** img = new Pixel * [2];
        for (int i = 0; i < 2; ++i) {
            img[i] = new Pixel[2];
        }

        img[0][0] = Pixel(100, 150, 200);
        img[0][1] = Pixel(50, 80, 90);
        img[1][0] = Pixel(200, 20, 50);
        img[1][1] = Pixel(90, 170, 40);

        Picture picture((const Pixel**)img, 2, 2);

        Gallery gallery;
        gallery.addNewPicture(picture, false);

        std::cout << "Gallery information:" << std::endl;
        gallery.printGalleryInfo();

        std::cout << "Original picture:" << std::endl;
        picture.printPicture();

        if (picture.isColourful()) {
            std::cout << "The picture is colorful!" << std::endl;
        }

        Pixel** grayscaleImg = picture.grayscale();
        std::cout << "Grayscale picture:" << std::endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << "(" << (int)grayscaleImg[i][j].getRedColourValue() << ", " << (int)grayscaleImg[i][j].getGreenColourValue() << ", " << (int)grayscaleImg[i][j].getBlueColourValue() << ") ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        Pixel** monochromeImg = picture.monochrome();
        std::cout << "Monochrome picture:" << std::endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << "(" << (int)monochromeImg[i][j].getRedColourValue() << ", " << (int)monochromeImg[i][j].getGreenColourValue() << ", " << (int)monochromeImg[i][j].getBlueColourValue() << ") ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        Pixel** negativeImg = picture.negative();
        std::cout << "Negative picture:" << std::endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << "(" << (int)negativeImg[i][j].getRedColourValue() << ", " << (int)negativeImg[i][j].getGreenColourValue() << ", " << (int)negativeImg[i][j].getBlueColourValue() << ") ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (int i = 0; i < 2; ++i) {
            delete[] img[i];
            delete[] grayscaleImg[i];
            delete[] monochromeImg[i];
            delete[] negativeImg[i];
        }
        delete[] img;
        delete[] grayscaleImg;
        delete[] monochromeImg;
        delete[] negativeImg;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown error occurred!" << std::endl;
    }

    return 0;
}

