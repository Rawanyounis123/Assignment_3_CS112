#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void loadImage(unsigned char image[SIZE][SIZE]);
void saveImage(unsigned char image[SIZE][SIZE]);
void darkenOrlighten();
void merge_images();

int main() {
    char choice;

    cout << "Welcome to our Filters App! \n"
        << "Please select a filter number to apply or 0 to exit: \n "
        << "1- Black & White Filter \n"
        << "2 - Invert Filter\n"
        << "3 - Merge Filter\n"
        << "4 - Flip Image\n"
        << "5 - Darken and Lighten Image\n"
        << "6 - Rotate Image\n"
        << "7 - Detect Image Edges\n"
        << "8 - Enlarge Image\n"
        << "9 - Shrink Image\n"
        << "a - Mirror 1 / 2 Image\n"
        << "b - Shuffle Image\n"
        << "c - Blur Image\n"
        //        << "s - Save the image to a file\n"
        << "0 - Exit\n";
    cin >> choice;
    if (choice == '1') {
        //TODO: blackWhite()
        continue;
    }
    else if (choice == '2') {
        //TODO: invert()
        continue;
    }
    else if (choice == '3') {
        merge_images();
    }
    else if (choice == '4') {
        //TODO: flip()
        continue;
    }
    else if (choice == '5') {
        darkenOrlighten();
    }
    else if (choice == '6') {
        //TODO: rotate()
        continue;
    }
    else if (choice == '7') {
        //TODO: detectEdges()
        continue;
    }
    else if (choice == '8') {
        //TODO: enlarge()
        continue;
    }
    else if (choice == '9') {
        //TODO: shrink()
        continue;
    }
    else if (choice == 'a') {
        //TODO: mirior()
        continue;
    }
    else if (choice == 'b') {
        //TODO: shuffle()
        continue;
    }
    else if (choice == 'c') {
        //TODO: blur()
        continue;
    }
    else {
        // break or exit 
        cout << "Thank you for using our Filters App!"
    }
    return 0;
}

void loadImage(unsigned char image[SIZE][SIZE]) {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage(unsigned char image[SIZE][SIZE]) {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void darkenOrlighten() {
    loadImage(image1);
    char choice;

    cout << "Do you want to (d)arken or (l)ighten?  \n"
        << "(enter d for darken and l for lighten) \n";
    cin >> choice;

    // darken image by 50%
    if (choice == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1[i][j] /= 2;
            }
        }
    } // lighten image by 50%
    else if (choice == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1[i][j] = image1[i][j] + 0.5 * (SIZE - image1[i][j]);
            }
        }
    }
    saveImage(image1);
}
void merge_images() {
    loadImage(image1);
    loadImage(image2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = ((image1[i][j]) + (image2[i][j])) / 2;
        }
    }
    saveImage(image3);
}
