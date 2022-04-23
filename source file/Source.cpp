/*  FCI � Programming 1 � 2022 - Assignment 3
    Program Name: CS112- 2022 � S25&26 -20210493-20210501-20210524-A3-full.cpp
    Last Modification Date: 17/04/2022
    Author1 and ID and Group: Salma Gamal
    Author2 and ID and Group: Laila Hesham
    Author3 and ID and Group: Rawan Younis
    Teaching Assistant: Eng. Mahmoud Fateaha
    Purpose:Purpose: A filters application that allows user to choose to apply
                     one of 9 filters to a gray-scale image.
*/

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
void shrinkImage();
void blurImage();
void enlarge();
void shuffleImage();

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
             << "0 - Exit\n";

        cin >> choice;
        if (choice == '1') {
            loadImage();
            blackWhite();
            break;
        }
        else if (choice == '2') {
            loadImage();
            invertImage();
            break;
        }
        else if (choice == '3') {
            loadImage(image1);
            loadImage(image2);
            mergeImages();
            break;
        }
        else if (choice == '4') {
            loadImage();
            flipImage();
            break;
        }
        else if (choice == '5') {
            loadImage();
            rotateImage();
            break;
        }
        else if (choice == '6') {
            loadImage();
            darkenLighten();
            break;
        }
        else if (choice == '7') {
            //TODO: detectEdges()
            break;
        }
        else if (choice == '8') {
            loadImage();
            enlarge();
            break;
        }
        else if (choice == '9') {
            loadImage(image1);
            shrinkImage();
            break;
        }
        else if (choice == 'a') {
            //TODO: mirior()
            break;
        }
        else if (choice == 'b') {
            loadImage();
            shuffleImage();
            break;
        }
        else if (choice == 'c') {
            loadImage();
            blurImage();
            break;
        }else if (choice == '0'){
            cout << "Thank you for using our Filters App!";
            break;
        }
        else{
            cout << "Enter a valid input";
        }
    }
    saveImage();
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
                image[i][j] /= 2;
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

    cout << "Enter the degree you want to rotate the image with"
         <<"\n 1.90 degrees \n 2.180 degrees \n 3.270 degrees";
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
            int ave = 0;
            for (int k = 0; k < scale; k++){
                for (int m = 0; m < scale; m++){
                    ave += image1[i+k][j+m];
                }
            }
            image[row][column] = ave / (scale * scale);
            column ++;
        }
    }

    // make blanks white
    for (int i = (SIZE/scale); i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255;
        }
    }

    for (int i = 0; i < (SIZE / scale); i++) {
        for (int j = (SIZE / scale); j < SIZE; j++) {
            image[i][j] = 255;
        }
    }

}

//this function is to blur the image.
void blurImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int ave = 0;
            for (int k = 0; k < 9; k++){
                for (int m = 0; m < 9; m++){
                    ave += image[i+k][j+m];
                }
            }
            image[i][j] = (ave / 81);

        }
    }
}

void enlarge() {
    int choice;
    cout<<"Welcome. Enter which quadrant you would like to enlarge(1 to 4)";
    cin>>choice;
    unsigned char imageOriginal[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            imageOriginal[i][j] = image[i][j];
        }
    }
    if (choice==1){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                char c = imageOriginal[i][j];
                image[(i+1)*2-1][(j+1)*2-1] = c;
                image[(i+1)*2-1][(j+1)*2-2] = c;
                image[(i+1)*2-2][(j+1)*2-1] = c;
                image[(i+1)*2-2][(j+1)*2-2] = c;
            }
        }
    }
    if (choice==2){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = SIZE/2; j< SIZE; j++) {
                char c = imageOriginal[i][j];
                image[(i+1)*2-1][2*j - SIZE] = c;
                image[(i+1)*2-1][2*j - SIZE + 1] = c;
                image[(i+1)*2-2][2*j - SIZE] = c;
                image[(i+1)*2-2][2*j - SIZE + 1] = c;
            }
        }
    }
    if (choice==3){

        for (int i = SIZE/2; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                char c = imageOriginal[i][j];
                image[2*i - SIZE][(j+1)*2-1] = c;
                image[2*i -SIZE][(j+1)*2-2] = c;
                image[2*i -SIZE + 1][(j+1)*2-1] = c;
                image[2*i -SIZE + 1][(j+1)*2-2] = c;
            }
        }
    }
    if (choice==4){
        for (int i = SIZE/2; i < SIZE; i++) {
            for (int j = SIZE/2; j< SIZE; j++) {
                char c = imageOriginal[i][j];
                image[2*i - SIZE][2*j - SIZE] = c;
                image[2*i - SIZE][2*j - SIZE + 1] = c;
                image[2*i - SIZE + 1][2*j - SIZE] = c;
                image[2*i - SIZE + 1][2*j - SIZE + 1] = c;
            }
        }
    }
}

//Shuffles the image to order the quadrants the way the user wants it
void shuffleImage(){
    unsigned char imageOriginal[SIZE][SIZE];
    int quadrant1,quadrant2,quadrant3,quadrant4;
    cout<<"Welcome.Please enter which quadrant you want to place in the first quadrant ";
    cin>>quadrant1;
    cout<<"Please enter which quadrant you want to place in the second quadrant ";
    cin>>quadrant2;
    cout<<"Please enter which quadrant you want to place in the third quadrant ";
    cin>>quadrant3;
    cout<<"Please enter which quadrant you want to place in the fourth quadrant ";
    cin>>quadrant4;
    cout<<quadrant1<<quadrant2<<quadrant3<<quadrant4<<endl;

    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            imageOriginal[i][j] = image[i][j];
        }
    }
    //quadrant 1:
    if(quadrant1 != 1){
        int x = 0;
        int y = 0;
        if(quadrant1 == 2 || quadrant1 == 4)
            y = SIZE/2;
        if(quadrant1 == 3 || quadrant1 == 4)
            x = SIZE/2;
        int y1 = y;
        for(int i = 0; i < SIZE/2; i++, x++){
            y = y1;
            for(int j = 0; j< SIZE/2; j++, y++){
                image[i][j] = imageOriginal[x][y];
            }
        }
    }
    //quadrant 2:
    if (quadrant2 !=2){
        int x=0;
        int y=0;
        if(quadrant2 == 4)
            y = SIZE/2;
        if(quadrant2 == 3 || quadrant2 == 4)
            x = SIZE/2;
        int y1 = y;
        for (int i = 0; i < SIZE/2; i++, x++){
            y = y1;
            for (int j = SIZE/2; j< SIZE; j++, y++){
                image[i][j]=imageOriginal[x][y];
            }
        }
    }
    //quadrant 3:
    if(quadrant3 != 3){
        int x=0;
        int y=0;
        if(quadrant3 == 2 || quadrant3 == 4)
            y = SIZE/2;
        if(quadrant3 == 4)
            x = SIZE/2;
        int y1 = y;
        for (int i = SIZE/2; i < SIZE; i++, x++){
            y = y1;
            for (int j = 0; j< SIZE/2; j++, y++){
                image[i][j]=imageOriginal[x][y];
            }
        }
    }
    //quadrant 4:
    if(quadrant4 != 4){
        int x=0;
        int y=0;
        if(quadrant4 == 2)
            y = SIZE/2;
        if(quadrant4 == 3)
            x = SIZE/2;
        int y1 = y;
        for (int i = SIZE/2; i < SIZE; i++, x++){
            y = y1;
            for (int j = SIZE/2; j< SIZE; j++, y++){
                image[i][j]=imageOriginal[x][y];
            }
        }
    }
}
