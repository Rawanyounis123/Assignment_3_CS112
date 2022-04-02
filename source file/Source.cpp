#include "bitmap_test.cpp"
#include<iostream>

using namespace std;

int main() {
	cout << "Please enter file name of the image to process: \n";
	//TODO: cin image path
	cout << "Welcome to our Filters App! \n"
		 << "Please select a filter to apply or 0 to exit: "
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
		 << "s - Save the image to a file\n"
		 << "0 - Exit";
	return 0;
}