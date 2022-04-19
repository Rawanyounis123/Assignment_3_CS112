/*  FCI - Programming 1 – 2022 - Assignment 3
    Program Name: CS112- 2022 – S25&26 -20210493-20210501-20210524-A3-Part1.cpp
    Last Modification Date: 17/04/2022
    Author1 and ID and Group: Salma Gamal
    Author2 and ID and Group: Laila Hesham
    Author3 and ID and Group: Rawan Younis
    Teaching Assistant: Eng. Mahmoud Fateaha
    Purpose:Purpose: A filters application that allows user to choose to apply
                     one of 9 filters to a colored image.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];

void loadImage (unsigned char image[SIZE][SIZE][RGB]);
void loadImage ();
void saveImage ();

void mergeImages();
void darkenLighten();
void shrinkImage();
void blurImage();

int main() {
    char choice;
    while (true){
        cout << "Welcome to our Filters App! \n"
        << "Please select a filter number to apply or 0 to exit: \n"
        << "1 - Black & White Filter \n"
        << "2 - Invert Filter\n"
        << "3 - Merge Filter\n"
        << "4 - Flip Image\n"
        << "5 - Rotate Image\n"
        << "6 - Darken and Lighten Image\n"
        << "7 - Detect Image Edges\n"
        << "8 - Enlarge Image\n"
        << "9 - Shrink Image\n"
        << "a - Mirror 1 / 2 Image\n"
        << "b - Shuffle Image\n"
        << "c - Blur Image\n"
        << "s - Save the image to a file\n"
        << "0 - Exit\n";

        cin >> choice;
        if (choice == '1') {
            //TO DO
        }
        else if (choice == '2') {
            //TO DO
        }
        else if (choice == '3') {
            mergeImages();
        }
        else if (choice == '4') {
            //TO DO
        }
        else if (choice == '5') {
            //TO DO
        }
        else if (choice == '6') {
            loadImage();
            darkenLighten();
        }
        else if (choice == '7') {
            //TODO: detectEdges()
        }
        else if (choice == '8') {
            //TODO: enlarge()
        }
        else if (choice == '9') {
            loadImage(image1);
            shrinkImage();
        }
        else if (choice == 'a') {
            //TODO: mirior()
        }
        else if (choice == 'b') {
            //TODO: shuffle()
        }
        else if (choice == 'c') {
            loadImage();
            blurImage();
        }
        else if (choice == 's'){
            saveImage();
        }
        else{
            cout << "Thank you for using our Filters App!";
            break;
        }
    }
    return 0;
}


//To load the image from its new directory
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout<<"Welcome user!";
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

//To save the new image
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//Loads image to specific 2d array
void loadImage(unsigned char image[SIZE][SIZE][RGB]) {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}


//Given user choice, this function lightens or darkens an image
void darkenLighten() {
    char c;

    cout << "Do you want to (d)arken or (l)ighten?  \n";
    cin >> c;

    // darken image by 50%
    if (c == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int n = 0; n < RGB; n++) {
                    image[i][j][n] /= 2;
                }
            }
        }
    } // lighten image by 50%
    else if (c == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int n = 0; n < RGB; n++) {
                    image[i][j][n] = image[i][j][n] + 0.5 * (SIZE - image[i][j][n]);
                }
            }
        }
    }
}
//this function merge two images
void mergeImages() {
    loadImage(image1);
    loadImage(image2);
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image[i][j][k]  = (image1[i][j][k] + image2[i][j][k] )/2;

            }
        }
    }

}


//this function is to shrink the image.
void shrinkImage() {
    int choice, scale;
    cout << "Shrink to \n"
         << "1.(1/2)\n"
         << "2.(1/3)\n"
         << "3.(1/4)\n";
    cin >> choice;

    if (choice == 1){
        scale = 2;
    }
    else  if (choice == 2){
        scale = 3;
    }
    else  if (choice == 3){
        scale = 4;
    }

    int row = -1 ;
    for (int i = 0; i < SIZE; i+=scale) {
        int column = 0;
        row ++;
        for (int j = 0; j < SIZE; j+=scale) {
            for (int r = 0; r < RGB; r++) {
                image[row][column][r] = image1[i][j][r];
            }
            column ++;
        }
    }

    // make blanks white
    for (int i = (SIZE/scale); i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = 255;
            }
        }
    }

    for (int i = 0; i < (SIZE / scale); i++) {
        for (int j = (SIZE / scale); j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = 255;
            }
        }
    }
}

//this function is to blur the image.
void blurImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                int ave = 0;
                for (int k = 0; k < 9; k++){
                    for (int m = 0; m < 9; m++){
                            ave += image[i+k][j+m][r];
                    }
                }
                image[i][j][r] = (ave / 81);
            }
        }
    }
}
