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
            //TO DO
        }
        else if (choice == '4') {
            //TO DO
        }
        else if (choice == '5') {
            //TO DO
        }
        else if (choice == '6') {
            //TO DO
        }
        else if (choice == '7') {
            //TODO: detectEdges()
        }
        else if (choice == '8') {
            //TODO: enlarge()
        }
        else if (choice == '9') {
            //TO DO
        }
        else if (choice == 'a') {
            //TODO: mirior()
        }
        else if (choice == 'b') {
            //TODO: shuffle()
        }
        else if (choice == 'c') {
            //TO DO
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


