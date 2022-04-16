#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image[SIZE][SIZE];

void loadImage (unsigned char image[SIZE][SIZE]);
void loadImage ();
void saveImage ();

void blackWhite();
void invertImage();
void mergeImages();
void flipImage();
void rotateImage();
void darkenLighten();

int main() {
    char choice;
    while (true){
        cout << "Welcome to our Filters App! \n"
        << "Please select a filter number to apply or 0 to exit: \n"
        << "1- Black & White Filter \n"
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
            loadImage();
            blackWhite();
        }
        else if (choice == '2') {
            loadImage();
            invertImage();
        }
        else if (choice == '3') {
            loadImage(image1);
            loadImage(image2);
            mergeImages();
        }
        else if (choice == '4') {
            loadImage();
            flipImage();
        }
        else if (choice == '5') {
            loadImage();
            rotateImage();
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
            //TODO: shrink()
        }
        else if (choice == 'a') {
            //TODO: mirior()
        }
        else if (choice == 'b') {
            //TODO: shuffle()
        }
        else if (choice == 'c') {
            //blur();
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
   readGSBMP(imageFileName, image);
}

//To save the new image
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//Loads image to specific 2d array
void loadImage(unsigned char image[SIZE][SIZE]) {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//this function convert image to black and white only
void blackWhite() {

  long avrg = 0, avrg2 = 0, avrg3 =0  ;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image [i][j] < 127){
                avrg += image[i][j];
            }
        }
    }

    avrg/=(SIZE*SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image [i][j] > avrg){

                avrg2 += image[i][j];

            }
        }
    }

    avrg2/=(SIZE*SIZE);

     for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image [i][j] > avrg2){

                avrg3 += image[i][j];

            }
        }
     }

    avrg3/=(SIZE*SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image [i][j] > avrg3){

                image[i][j] = 255;
            }
            else {
                image[i][j] = 0;
            }
        }
    }
}

//this function is to invert the image and produce the negative output of the picture.
void invertImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255 - image[i][j];
    }
  }
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
                image1[i][j] /= 2;
            }
        }
    } // lighten image by 50%
    else if (c == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j] + 0.5 * (SIZE - image[i][j]);
            }
        }
    }
}

//this function merge two images
void mergeImages() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = ((image1[i][j]) + (image2[i][j])) / 2;
        }
    }

}

//this function flips image
void flipImage() {
    char alignment;
    cout<<"Do you want to flip the image (v)ertically or (h)orozontally?";
    cin >> alignment;

    if (alignment == 'h'){
        for (int i = 0; i < SIZE/2; i++){
            for (int j = 0; j < SIZE; j++){
                int temp = image[i][j];
                image[i][j]=image[SIZE-i][j];
                image[SIZE-i][j]=temp;
            }
        }
    }
    else if (alignment == 'v'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE/2; j++){
                int temp = image[i][j];
                image[i][j]=image[i][SIZE-j];
                image[i][SIZE-j]=temp;
            }
        }
    }
}

//this function is to rotate the image.
void rotateImage() {
    int choice;

    cout << "Enter the degree you want to rotate the image with
         <<\n 1.90 degrees \n 2.180 degrees \n 3.270 degrees";
    cin >> choice;

    char tempArr[SIZE][SIZE];

    for (int countRotations = 0; countRotations < choice; countRotations++) {
        for (int i = 0; i < SIZE; i++){
            for (int j =0; j<SIZE; j++){
                tempArr[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[j][SIZE-1-i] = tempArr[i][j];
            }
        }
    }
}

