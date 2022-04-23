/*  FCI - Programming 1 � 2022 - Assignment 3
    Program Name: CS112- 2022 � S25&26 -20210493-20210501-20210524-A3-Part1.cpp
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

void blackandwhite();
void mergeImages();
void darkenLighten();
void flip();
void shrinkImage();
void blurImage();
void invertImage();
void enlarge();
void Mirror();
void shuffle();
void rotateImage();

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
            blackandwhite()
            break;
        }
        else if (choice == '2') {
            loadImage();
            invertImage();
            break;
        }
        else if (choice == '3') {
            mergeImages();
            break;
        }
        else if (choice == '4') {
            flip()
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
            Mirror()
            break;
        }
        else if (choice == 'b') {
            loadImage();
            shuffle();
            break;
        }
        else if (choice == 'c') {
            loadImage();
            blurImage();
            break;
        }
        else if (choice == '0'){
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

//Shuffles the image to order the quadrants the way the user wants it
void shuffle(){
    unsigned char imageOriginal[SIZE][SIZE][RGB];
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
                for(int k =0; k<RGB ; k++){
                    imageOriginal[i][j][k] = image[i][j][k];
                }
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
                for(int k =0; k<RGB ; k++){
                    image[i][j][k] = imageOriginal[x][y][k];
                }
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
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
            }
        }
    }
    //quadrant 3:
    if(quadrant3 != 3){
        int x = 0;
        int y = 0;
        if(quadrant3 == 2 || quadrant3 == 4)
            y = SIZE/2;
        if(quadrant3 == 4)
            x = SIZE/2;
        int y1 = y;
        for (int i = SIZE/2; i < SIZE; i++, x++){
                y = y1;
            for (int j = 0; j< SIZE/2; j++, y++){
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
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
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
            }
        }
    }
}

//Enlarge a certain quadrant
void enlarge(){
    int choice;
    cout<<"Welcome. Enter which quadrant you would like to enlarge(1 to 4)";
    cin>>choice;
    unsigned char imageOriginal[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++){
            for (int k =0; k<RGB ; k++){
                imageOriginal[i][j][k] = image[i][j][k];
            }

        }
    }
    if (choice==1){
        for (int i = 0; i < SIZE/2; i++){
            for (int j = 0; j< SIZE/2; j++){
                 for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[(i+1)*2-1][(j+1)*2-1][k] = c;
                    image[(i+1)*2-1][(j+1)*2-2][k] = c;
                    image[(i+1)*2-2][(j+1)*2-1][k] = c;
                    image[(i+1)*2-2][(j+1)*2-2][k] = c;
                 }
                 }
                 }
                 }
    if (choice==2){
         for (int i = 0; i < SIZE/2; i++){
            for (int j = SIZE/2; j< SIZE; j++){
                 for(int k =0; k<RGB ; k++){
                     char c = imageOriginal[i][j][k];
                     image[(i+1)*2-1][2*j - SIZE][k] = c;
                     image[(i+1)*2-1][2*j - SIZE + 1][k] = c;
                     image[(i+1)*2-2][2*j - SIZE][k] = c;
                     image[(i+1)*2-2][2*j - SIZE + 1][k] = c;

            }
            }
            }
            }
    if (choice==3){
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j = 0; j< SIZE/2; j++){
                for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[2*i - SIZE][(j+1)*2-1][k] = c;
                    image[2*i -SIZE][(j+1)*2-2][k] = c;
                    image[2*i -SIZE + 1][(j+1)*2-1][k] = c;
                    image[2*i -SIZE + 1][(j+1)*2-2][k] = c;
                }
                }
                }
                }
    if (choice==4){
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j = SIZE/2; j< SIZE; j++){
                for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[2*i - SIZE][2*j - SIZE][k] = c;
                    image[2*i - SIZE][2*j - SIZE + 1][k] = c;
                    image[2*i - SIZE + 1][2*j - SIZE][k] = c;
                    image[2*i - SIZE + 1][2*j - SIZE + 1][k] = c;
                }
                }
                }
                }
}

//invert image using colours
void invertImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for(int k =0; k<RGB ; k++){
        image[i][j][k] = 255 - image[i][j][k];
    }
  }
 }
}

//this function is to rotate the image.
void rotateImage() {
    int choice;
    cout<<"Enter the degree you want to rotate the image with \n 1.90 degrees \n 2.180 degrees \n 3.270 degrees";
    cin>>choice;
    char tempArr[SIZE][SIZE][RGB];
    for (int countRotations = 0; countRotations < choice; countRotations++) {
        for (int i = 0; i < SIZE; i++){
            for (int j =0; j<SIZE; j++){
                for(int k =0; k<RGB ; k++){
                    tempArr[i][j][k] = image[i][j][k];
                }

            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for(int k =0; k<RGB ; k++){
                    image[j][SIZE-1-i][k] = tempArr[i][j][k];
                }



            }
        }
    }
}
//black and white filter
void blackandwhite() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j][0] +image[i][j][1]+image[i][j][2] > 382){

                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
                
            }
        }
    }
}
//mirror half an image filter
void Mirror()
{
    string order;
    cout << "Please choose which half to mirror : Left1/2, Right1/2, Upper1/2 and Lower1/2"<<endl;
    cin >> order;

    if (order == "upper1/2")
    {
        for (int i = 0 ; i <SIZE/2 ; i++)
        {
            for (int j = 0 ; j<SIZE ; j++)
            {
                for (int k = 0 ; k < RGB ; k++){

                    image[i][j][k] = image[i][j][k];

                }
            }

         for (int i = SIZE/2 ; i < SIZE ; i++)
            {
                for (int j =0; j < SIZE ; j++)
                {
                    for (int k = 0 ; k < RGB ; k++)
                    {
                        image[i][j][k]=image[SIZE-i][j][k];
                    }
                }
            }
        }
    }
    else if (order == "left1/2"){

    for (int i = 0 ; i <SIZE ; i++)
    {
        for (int j = 0 ; j<SIZE/2 ; j++)
        {
            for (int k = 0 ; k < RGB ; k++)
                {
                    image[i][j][k] = image[i][j][k];
                }
        }

     for (int i = 0 ; i < SIZE ; i++)
        {
            for (int j = SIZE/2; j < SIZE ; j++)
            {
                for (int k = 0 ; k < RGB ; k++)
                {

                image[i][j][k]=image[i][SIZE - j][k];

                }

            }
        }
    }
}
    else if (order == "lower1/2"){

    for (int i = 0; i < SIZE/2; i++){

        for (int j = 0; j < SIZE; j++){

            for (int k = 0 ; k < RGB ; k++)
            {
                int temp = image[i][j][k];
                image[i][j][k]=image[SIZE-i][j][k];
                image[SIZE-i][j][k]=temp;
            }
        }
    }

         for (int i = 0 ; i <SIZE/2 ; i++)
        {
            for (int j = 0 ; j<SIZE ; j++)
            {
                for (int k = 0 ; k < RGB ; k++)
                    {

                    image[i][j][k] = image[i][j][k];

                    }
            }

         for (int i = SIZE/2 ; i < SIZE ; i++)
            {
                for (int j =0; j < SIZE ; j++)
                {
                    for (int k = 0 ; k < RGB ; k++)
                    {

                    image[i][j][k]=image[SIZE-i][j][k];

                    }
                }
            }
        }
    }
    else if (order == "right1/2"){
        for (int i = 0; i < SIZE; i++){

            for (int j = 0; j < SIZE/2; j++){

                for (int k = 0 ; k < RGB ; k++)
                {

                int temp = image[i][j][k];
                image[i][j][k]=image[i][SIZE-j][k];
                image[i][SIZE-j][k]=temp;
                }
            }
        }

        for (int i = 0 ; i <SIZE ; i++)
        {
            for (int j = 0 ; j<SIZE/2 ; j++)
            {
                for (int k = 0 ; k < RGB ; k++)

                    {

                    image[i][j][k] = image[i][j][k];

                    }
            }

         for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = SIZE/2; j < SIZE ; j++)
                {
                    for (int k = 0 ; k < RGB ; k++)
                    {

                    image[i][j][k]=image[i][SIZE - j][k];

                    }
                }
            }
        }
    }
}
// flip filter
void flip() {
    char alignment;
    cout<<"Do you want to flip the image (v)ertically or (h)orozontally?";
    cin >> alignment;
    if (alignment == 'h'){
        for (int i = 0; i < SIZE/2; i++){
            for (int j = 0; j < SIZE; j++){
                for (int k = 0 ; k < RGB ; k++){

                int temp = image[i][j][k];
                image[i][j][k]=image[SIZE-i][j][k];
                image[SIZE-i][j][k]=temp;

                }
            }
        }
    }
    else if (alignment == 'v'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE/2; j++){
                for (int k = 0 ; k < RGB ; k++){

                int temp = image[i][j][k];
                image[i][j][k]=image[i][SIZE-j][k];
                image[i][SIZE-j][k]=temp;

                }
            }
        }
    }
}

