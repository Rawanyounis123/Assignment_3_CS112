#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void loadImage(unsigned char image[SIZE][SIZE]);
void saveImage(unsigned char image[SIZE][SIZE]);
void darkenOrlighten();
void merge_images();
void black_and_white();
void flip();
void rotateImage();
void invertImage();

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
        loadImage();
        black_and_white();
        saveImage();
    }
    else if (choice == '2') {
        loadImage();
        invertImage();
        saveImage();
    }
    else if (choice == '3') {

        merge_images();

    }
    else if (choice == '4') {
        loadImage();
        flip();
        saveImage();
    }
    else if (choice == '5') {

        darkenOrlighten();

    }
    else if (choice == '6') {
        loadImage();
        rotateImage();
        saveImage();
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
    else {

        // break or exit

        cout << "Thank you for using our Filters App!";

    }
    return 0;

}


//to load the image from its new directory
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

//this function is to invert the image and produce the negative output of the picture.
void invertImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255 - image[i][j];
    }
  }
}

void flip() {

    string alignment;
    cout<<"Do you want to flip the image (v)ertically or (h)orozontally?";
    cin >> alignment;

    if (alignment == "h"){

        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i][j];
                image[SIZE-i][j]=temp;
        }
     }
   }

  else if (alignment == "v"){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
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
    cout<<"Enter the degree you want to rotate the image with \n 1.90 degrees \n 2.180 degrees \n 3.270 degrees";
    cin>>choice;
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

void black_and_white() {

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
