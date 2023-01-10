/*
FCI ? Programming 1 ? 2022 - Assignment 3
Program Name: CS112-2022-2nd-S11S12-20210044-20210552-20210497-A3-FULL.cpp
Last Modification Date: 19/04/2022
Author1 and ID and Group: Ahmed Hany Gamal El-din Helmy    20210044    group A
Author2 and ID and Group: Michael Youssry Saeed Wasfi      20210497    group A
Author3 and ID and Group: Nouran Khaled Badri Gadallah     20210552    group A
Teaching Assistant: Afaf abdel monem
Purpose: to do various filters on the chosen gray scale image
*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"
#include <string>

using namespace std;



//making arrays of char so that we can store the image inside
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
//to abbreviate unsigned char [SIZE][SIZE] to image_gs_t
using pixel_gs_t = unsigned char;
using image_gs_t = pixel_gs_t[SIZE][SIZE];
//making arrays of char so that we can store the RGB image inside
unsigned char imageRGB[SIZE][SIZE][RGB];
unsigned char imageRGB2[SIZE][SIZE][RGB];
//to abbreviate unsigned char [SIZE][SIZE][RGB] to image_RGB_t
using pixel_RGB_t = unsigned char;
using image_RGB_t = pixel_RGB_t[SIZE][SIZE][RGB];





int loadImage ();
void saveImage ();
string get_image_file_name ();

void black_and_white_image ();
void invert_image ();
void merge_images ();
void flip_image ();
void lighten_image ();
void darken_image ();
void rotate_image ();
void detect_image_edges ();
void enlarge_image ();
void shrink_image (size_t factor);
void mirror_image ();
void shuffle_image ();
void blur_image (int kernel_size);






int loadImageRGB ();
void saveImageRGB ();
void invert_imageRGB ();
void rotate_imageRGB ();
void enlarge_imageRGB ();
void shuffle_imageRGB ();
void merge_imageRGB ();
void black_and_white_filterRGB ();
void mirror_imageRGB ();
void lighten_imageRGB ();
void darken_imageRGB ();
void blur_imageRGB (int kernel_size);
void flip_imageRGB ();
void detect_image_edgesRGB ();


int main () {
	char GS_or_RGB;
	cout << "Will you be working on a (G)rey scale image or a (C)olored/RGB image or do you want to (E)xit the program my good Sir/Mam: ";
	cin >> GS_or_RGB;
	cin.ignore ();

	while (true) {

		if (GS_or_RGB == 'G' || GS_or_RGB == 'g') {
			loadImage();

			while (true) {
				cout << "please select a filter to apply or 0 to finish the image\n";
				cout << "1 - invert\n";
				cout << "2 - rotate\n";
				cout << "3 - enlarge\n";
				cout << "4 - shuffle\n";
				cout << "5 - merge\n";
				cout << "6 - black and white\n";
				cout << "7 - mirror\n";
				cout << "8 - lighten\n";
				cout << "9 - darken\n";
				cout << "a - blur\n";
				cout << "b - flip\n";
				cout << "c - edge detection\n";
				cout << "d - shrink\n";
				cout << "0 - finish\n";

				char command;
				cin >> command;
				cin.ignore ();
				if (command == '1') {
					invert_image ();
				}
				else if (command == '2') {
					rotate_image ();
				}
				else if (command == '3') {
					enlarge_image ();
				}
				else if (command == '4') {
					shuffle_image ();
				}
				else if (command == '5') {
					cout << "please enter another image's path\n";

					// Get gray scale image file name
					string imageFileName = get_image_file_name ();

					// Add to it .bmp extension and load image
					readGSBMP (imageFileName.c_str (), image2);

					merge_images ();
				}
				else if (command == '6') {
					black_and_white_image ();
				}
				else if (command == '7') {
					mirror_image ();
				}
				else if (command == '8') {
					lighten_image ();
				}
				else if (command == '9') {
					darken_image ();
				}
				else if (command == 'a') {
					int kernel;
					cout << "enter kernel size (degree of blur):";
					cin >> kernel;
					cin.ignore ();

					blur_image (kernel);
				}
				else if (command == 'b') {
					flip_image ();
				}
				else if (command == 'c') {
					detect_image_edges ();
				}
				else if (command == 'd') {
					int shrinkageDeg;
					cout << "enter the degree of shrinkage (2 for 1/2, 3 for 1/3, 4 for 1/4):";
					cin >> shrinkageDeg;
					cin.ignore ();

					shrink_image (shrinkageDeg);
				}
				else if (command == '0') {
					cout << "the image has been saved ;)\n";
					break;
				}
			}
			saveImage ();
		}
		else if (GS_or_RGB == 'C' || GS_or_RGB == 'c'){
			loadImageRGB ();

			while (true) {
				cout << "please select a filter to apply or 0 to finish the image\n";
				cout << "1 - invert\n";
				cout << "2 - rotate\n";
				cout << "3 - enlarge\n";
				cout << "4 - shuffle\n";
				cout << "5 - merge\n";
				cout << "6 - black and white\n";
				cout << "7 - mirror\n";
				cout << "8 - lighten\n";
				cout << "9 - darken\n";
				cout << "a - blur\n";
				cout << "b - flip\n";
				cout << "c - edge detection\n";
				cout << "0 - finish\n";

				char command;
				cin >> command;
				cin.ignore ();
				if (command == '1') {
					invert_imageRGB ();
				}
				else if (command == '2') {
					rotate_imageRGB ();
				}
				else if (command == '3') {
					enlarge_imageRGB ();
				}
				else if (command == '4') {
					shuffle_imageRGB ();
				}
				else if (command == '5') {
					cout << "please enter another image's path\n";

					// Get gray scale image file name
					string imageFileName = get_image_file_name ();

					// Add to it .bmp extension and load image
					readRGBBMP (imageFileName.c_str (), imageRGB2);

					merge_imageRGB ();
				}
				else if (command == '6') {
					black_and_white_filterRGB ();
				}
				else if (command == '7') {
					mirror_imageRGB ();
				}
				else if (command == '8') {
					lighten_imageRGB ();
				}
				else if (command == '9') {
					darken_imageRGB ();
				}
				else if (command == 'a') {
					int kernel;
					cout << "enter kernel size (degree of blur):";
					cin >> kernel;
					cin.ignore ();

					blur_imageRGB (kernel);
				}
				else if (command == 'b') {
					flip_imageRGB ();
				}
				else if (command == 'c') {
					detect_image_edgesRGB ();
				}
				else if (command == '0') {
					cout << "the image has been saved ;)\n";
					break;
				}
			}
			saveImageRGB ();

		}
		else if (GS_or_RGB == 'E' || GS_or_RGB == 'e') {
			cout << "it was a pleasure working for you :)\n";
			break;
		}
		else {
			cout << "invalid command\n";
		}

		cout << "Will you be working on a (G)rey scale image or a (C)olored/RGB image or do you want to (E)xit the program my good Sir/Mam: ";
		cin >> GS_or_RGB;
		cin.ignore ();
	}
	return 0;
}

//loads the image so that we can use it in the filters
int loadImage () {
	// Get gray scale image file name
	cout << "Enter the source image's path: ";
	string imageFileName = get_image_file_name ();

	// Add to it .bmp extension and load image
	return (readGSBMP (imageFileName.c_str (), image));
}

void saveImage () {
	// Get gray scale image target file name
	cout << "what do you wish to call your new image? : ";
	string imageFileName = get_image_file_name ();

	// Add to it .bmp extension and load image
	writeGSBMP (imageFileName.c_str (), image);
}



void black_and_white_image () {
	int sum = 0;

	//calculate the sum of the pixelse to calculate the average
	for (auto& row : image) {
		for (auto pixel : row) {
			sum += pixel;
		}
	}

	// calculating the average
	int average = sum / (SIZE * SIZE);

	// converting all pixels that have values greater than the average to 255(white)
	for (auto& row : image) {
		for (auto& pixel : row) {
			if (pixel > average) {
				pixel = 255;
			}
			else {  //converting all pixels that have values smaller than the average to 0(black)
				pixel = 0;
			}
		}
	}
}

//inverts the image
void invert_image () {
	for (auto& row : image) {
		for (auto& pixel : row) {
			pixel = 255 - pixel;
		}
	}
}

void merge_images () {
	for (size_t i = 0; i < SIZE; ++i) {
		for (size_t j = 0; j < SIZE; ++j) {
			image[i][j] = (image[i][j] + image2[i][j]) / 2;
		}
	}
}

void flip_image () {
	char orientation;
	unsigned char flipped_image[SIZE][SIZE];
	// asks the user how to flip the image
	cout << "Flip (h)orizontally or (v)ertically ?" << endl;
	cin >> orientation;
	// validate the input
	while (orientation != 'h' && orientation != 'v') {
		cout << "invalid option! please enter (h) for horizontally or (v) for vertically" << endl;
		cin >> orientation;
	}
	//Flip the image horizontally
	if (orientation == 'h') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				// flipping the rows of the 2d array
				flipped_image[i][j] = image[255 - i][j];
			}
		}
	}
	else if (orientation == 'v') { //Flip the image v
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				// flipping the columns of the 2d array
				flipped_image[i][j] = image[i][255 - j];
			}
		}
	}
	// saving the flipped image
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			image[i][j] = flipped_image[i][j];
		}
	}
}

//rotates the image in the degree that the user enters. either 90, 180, or 270 degrees
void rotate_image () {

	unsigned char imageCopy[SIZE][SIZE];

	//makes a copy of the image called imageCopy
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			imageCopy[i][j] = image[i][j];
		}
	}

	short int degreeOfRotation;
	cout << "enter the degree that you wish to rotate with (90, 180 ,270 or 360): ";
	cin >> degreeOfRotation;
	cin.ignore ();

	while (true) {
		//rotates the image 90 degrees if the degree of rotation is 90
		if ((degreeOfRotation % 90 == 0) && (degreeOfRotation % 360 != 0) && (degreeOfRotation % 180 != 0) && (degreeOfRotation % 270 != 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					image[j][SIZE - i - 1] = imageCopy[i][j];
				}
			}
			break;
		}
		//rotates the image 180 degrees if the degree of rotation is 180
		else if ((degreeOfRotation % 180 == 0) && (degreeOfRotation % 360 != 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					image[SIZE - i - 1][SIZE - j - 1] = imageCopy[i][j];
				}
			}
			break;
		}
		//rotates the image 270 degrees if the degree of rotation is 270
		else if ((degreeOfRotation == 270) || ((degreeOfRotation - 270) % 360 == 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					image[i][j] = imageCopy[j][SIZE - i - 1];
				}
			}
			break;
		}
		//checks if the degree is valid or not
		else if (degreeOfRotation % 90 != 0) {
			cout << "invalid degree, please enter a valid one as stated previously\n";
			cin >> degreeOfRotation;
			cin.ignore ();
			continue;
		}
		else {
			cout << "you do know that you didn't do anything to the image right? well, as you wish\n";
			break;
		}
	}
}

void lighten_image () {
	for (auto& row : image) {
		for (auto& pixel : row) {
			pixel = 255 - (255 - pixel) / 2;
		}
	}
}

void darken_image () {
	for (auto& row : image) {
		for (auto& pixel : row) {
			pixel /= 2;
		}
	}
}

void detect_image_edges () {
	// make the image black and white
	int sum = 0;
	int average;
	//finding the sum of all the numerical value of the pixels in the image to calculate the average
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sum = sum + int (j);
		}
	}
	// calculating the average of pixel values by dividing the sum of all values / number of pixels in 256x256 image
	average = sum / 65536;
	// converting all pixels that have values greater than the average to 255(white) and the smaller to (black)
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (image[i][j] > average) {
				image[i][j] = 255;
			}
			else {
				image[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 1; j < SIZE - 1; j++) {
			image2[i][j] = image[i + 1][j] + image[i - 1][j] + image[i][j + 1] + image[i][j - 1] - 4 * image[i][j];
		}
	}
	// inverting the new image
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			image[i][j] = 255 - image2[i][j];
		}
	}
}

//enlarges the chosen quarter of the image
void enlarge_image () {
	//makes four arrays quarter the size of the image to save the four quarters of the image in
	unsigned char quarter1[SIZE / 2][SIZE / 2], quarter2[SIZE / 2][SIZE / 2], quarter3[SIZE / 2][SIZE / 2], quarter4[SIZE / 2][SIZE / 2];
	//saves the first quarter of the image in one of the new arrays
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			quarter1[i][j] = image[i][j];
		}
	}
	//saves the second quarter of the image in one of the new arrays
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			quarter2[i][j] = image[i][(SIZE / 2) + j];
		}
	}
	//saves the third quarter of the image in one of the new arrays
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			quarter3[i][j] = image[(SIZE / 2) + i][j];
		}
	}
	//saves the fourth quarter of the image in one of the new arrays
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			quarter4[i][j] = image[(SIZE / 2) + i][(SIZE / 2) + j];
		}
	}
	//takes the quarter that the user wants to enlarge
	int quarterNum;
	cout << "(1) is the top left quarter, (2) is the top right quarter, (3) is the bottom left quarter,\nand (4) is the bottom right quarter\n";
	cout << "enter the number of the quarter that you wish to enlarge: ";
	cin >> quarterNum;
	cin.ignore ();
	//enlarges the first quarter of the image it is chosen
	if (quarterNum == 1) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				image[i][j] = quarter1[i / 2][j / 2];
				image[i][j + 1] = quarter1[i / 2][j / 2];
				image[i + 1][j] = quarter1[i / 2][j / 2];
				image[i + 1][j + 1] = quarter1[i / 2][j / 2];
			}
		}
	}
	//enlarges the second quarter of the image it is chosen
	else if (quarterNum == 2) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				image[i][j] = quarter2[i / 2][j / 2];
				image[i][j + 1] = quarter2[i / 2][j / 2];
				image[i + 1][j] = quarter2[i / 2][j / 2];
				image[i + 1][j + 1] = quarter2[i / 2][j / 2];
			}
		}
	}
	//enlarges the third quarter of the image it is chosen
	else if (quarterNum == 3) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				image[i][j] = quarter3[i / 2][j / 2];
				image[i][j + 1] = quarter3[i / 2][j / 2];
				image[i + 1][j] = quarter3[i / 2][j / 2];
				image[i + 1][j + 1] = quarter3[i / 2][j / 2];
			}
		}
	}
	//enlarges the fourth quarter of the image it is chosen
	else if (quarterNum == 4) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				image[i][j] = quarter4[i / 2][j / 2];
				image[i][j + 1] = quarter4[i / 2][j / 2];
				image[i + 1][j] = quarter4[i / 2][j / 2];
				image[i + 1][j + 1] = quarter4[i / 2][j / 2];
			}
		}
	}
	else {
		cout << "not a valid quarter";
	}
}

void shrink_image (size_t factor) {
	static constexpr pixel_gs_t WHITE = 255;

	const auto new_size = SIZE / factor;
	for (size_t i = 0; i < new_size; ++i) {
		for (size_t j = 0; j < new_size; ++j) {
			image[i][j] = image[i * factor][j * factor];
		}

		fill (next (begin (image[i]), new_size), end (image[i]), WHITE);
	}

	for (size_t i = new_size; i < SIZE; ++i) {
		fill (begin (image[i]), end (image[i]), WHITE);
	}
}


void mirror_image () {
	char operation;
	//ask the user how to mirror the image
	cout << "mirror (l)eft or (r)ight or (t)op or (b)ottom ?" << endl;
	cin >> operation;
	//validate input
	while (operation != 'l' && operation != 'r' && operation != 't' && operation != 'b') {
		cout << "invalid input !! please enter (l) for left or (r) for right or (t) for top or (b) for bottom" << endl;
		cin >> operation;
	}
	//mirror  the left section
	if (operation == 'l') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = SIZE / 2; j < SIZE; j++) {
				image[i][j] = image[i][255 - j];
				//make the first left pixel the first right one
			}
		}
	}
	//mirror the right section
	if (operation == 'r') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE / 2; j++) {
				image[i][j] = image[i][255 - j];
			}
			//make the first right pixel the first left one
		}
	}
	//mirror the upper section
	if (operation == 't') {
		for (int i = SIZE / 2; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image[255 - i][j];
			}
			//make the last right pixel the first right one
		}
	}
	//mirror the lower section
	if (operation == 'b') {
		for (int i = 0; i < SIZE / 2; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image[255 - i][j];
				//make the first right pixel the last right one
			}
		}
	}
}

//shuffles the image depending on the input
void shuffle_image () {
	//makes an array to put the four quarter in seperately
	unsigned char imageWithQuarters[4][SIZE / 2][SIZE / 2];
	//puts the first quarter of the image in the first index
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			imageWithQuarters[0][i][j] = image[i][j];
		}
	}
	//puts the second quarter of the image in the second index
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			imageWithQuarters[1][i][j] = image[i][(SIZE / 2) + j];
		}
	}
	//puts the third quarter of the image in the third index
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			imageWithQuarters[2][i][j] = image[(SIZE / 2) + i][j];
		}
	}
	//puts the fourth quarter of the image in the fourth index
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			imageWithQuarters[3][i][j] = image[(SIZE / 2) + i][(SIZE / 2) + j];
		}
	}

	unsigned int shuffleOrder1, shuffleOrder2, shuffleOrder3, shuffleOrder4;
	cout << "(1) is the top left quarter, (2) is the top right quarter, (3) is the bottom left quarter, \nand (4) is the bottom right quarter\n";
	cout << "enter the order of the shuffled image:";
	cin >> shuffleOrder1 >> shuffleOrder2 >> shuffleOrder3 >> shuffleOrder4;
	cin.ignore ();
	while (shuffleOrder1 > 4 || shuffleOrder2 > 4 || shuffleOrder3 > 4 || shuffleOrder4 > 4) {
		cout << "invalid inputs, please enter valid inputs as stated previously : ";
		cin >> shuffleOrder1 >> shuffleOrder2 >> shuffleOrder3 >> shuffleOrder4;
		cin.ignore ();
	}

	//decrements the inputs
	shuffleOrder1--;
	shuffleOrder2--;
	shuffleOrder3--;
	shuffleOrder4--;
	//puts the quarter with the given number in shuffleOrder1 in the first quarter
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			image[i][j] = imageWithQuarters[shuffleOrder1][i][j];
		}
	}
	//puts the quarter with the given number in shuffleOrder2 in the second quarter
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			image[i][(SIZE / 2) + j] = imageWithQuarters[shuffleOrder2][i][j];
		}
	}
	//puts the quarter with the given number in shuffleOrder3 in the third quarter
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			image[(SIZE / 2) + i][j] = imageWithQuarters[shuffleOrder3][i][j];
		}
	}
	//puts the quarter with the given number in shuffleOrder4 in the fourth quarter
	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			image[(SIZE / 2) + i][(SIZE / 2) + j] = imageWithQuarters[shuffleOrder4][i][j];
		}
	}
}

void blur_image (int kernel_size) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			int sum = 0, counter = 0;
			for (int x = max (i - kernel_size, 0); x <= min (i + kernel_size, SIZE - 1); ++x) {
				for (int y = max (j - kernel_size, 0); y <= min (j + kernel_size, SIZE - 1); ++y) {
					sum += image[x][y];
					++counter;
				}
			}
			image2[i][j] = sum / counter;
		}
	}

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			image[i][j] = image2[i][j];
		}
	}
}



void copy_image2_to_imageRGB () {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			for (int k = 0; k < RGB; ++k) {
				imageRGB[i][j][k] = imageRGB2[i][j][k];
			}
		}
	}
}

void black_and_white_filterRGB () {
	//converting RGB into black and white
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int gray = (imageRGB[i][j][0] * 0.299) + (imageRGB[i][j][1] * 0.587) + (imageRGB[i][j][2] * 0.114);

			//converting to white if it is greater than the avg
			if (gray > 127) {
				imageRGB[i][j][0] = 255;
				imageRGB[i][j][1] = 255;
				imageRGB[i][j][2] = 255;

			}//converting to black if it is less than the avg
			else {
				imageRGB[i][j][0] = 0;
				imageRGB[i][j][1] = 0;
				imageRGB[i][j][2] = 0;
			}
		}
	}
}

void mirror_imageRGB () {
	char operation;
	unsigned char mirror[SIZE][SIZE][RGB];
	//ask the user how to mirror the image
	cout << "mirror (l)eft or (r)ight or (t)op or (b)ottom ?" << endl;
	cin >> operation;
	//validate input
	while (operation != 'l' && operation != 'r' && operation != 't' && operation != 'b') {
		cout << "invalid input !! please enter (l) for left or (r) for right or (t) for top or (b) for bottom" << endl;
		cin >> operation;
	}
	//mirror  the left section
	if (operation == 'l') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = SIZE / 2; j < SIZE; j++) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = imageRGB[i][255 - j][k];
				}
				//make the first left pixel the first right one
			}
		}
	}
	//mirror the right section
	if (operation == 'r') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE / 2; j++) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = imageRGB[i][255 - j][k];
				}
			}
			//make the first right pixel the first left one
		}
	}
	//mirror the upper section
	if (operation == 't') {
		for (int i = SIZE / 2; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = imageRGB[255 - i][j][k];
				}
			}
			//make the last right pixel the first right one
		}
	}
	//mirror the lower section
	if (operation == 'b') {
		for (int i = 0; i < SIZE / 2; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = imageRGB[255 - i][j][k];
				}
				//make the first right pixel the last right one
			}
		}
	}
}

int loadImageRGB () {
	// Get gray scale image file name
	cout << "Enter the source image's path: ";
	string imageFileName = get_image_file_name ();

	// Add to it .bmp extension and load image
	return (readRGBBMP (imageFileName.c_str (), imageRGB));
}

void saveImageRGB () {
	// Get gray scale image target file name
	cout << "what do you wish to call your new image? : ";
	string imageFileName = get_image_file_name ();

	// Add to it .bmp extension and load image
	writeRGBBMP (imageFileName.c_str (), imageRGB);
}

void invert_imageRGB () {
	for (auto& row : imageRGB) {
		for (auto& pixel : row) {
			for (auto& color : pixel) {
				color = 255 - color;
			}
		}
	}
}

void lighten_imageRGB () {
	for (auto& row : imageRGB) {
		for (auto& pixel : row) {
			for (auto& channel : pixel) {
				channel = min (channel * 3 / 2, 255);
			}
		}
	}
}

void darken_imageRGB () {
	for (auto& row : imageRGB) {
		for (auto& pixel : row) {
			for (auto& channel : pixel) {
				channel /= 2;
			}
		}
	}
}

void blur_imageRGB (int kernel_size) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			for (int k = 0; k < RGB; ++k) {
				int sum = 0, count = 0;
				for (int x = max (i - kernel_size, 0); x <= min (i + kernel_size, SIZE - 1); ++x) {
					for (int y = max (j - kernel_size, 0); y <= min (j + kernel_size, SIZE - 1); ++y) {
						sum += imageRGB[x][y][k];
						++count;
					}
				}
				imageRGB2[i][j][k] = sum / count;
			}
		}
	}
	copy_image2_to_imageRGB ();
}

void rotate_imageRGB () {
	//makes a copy of the image called imageCopy
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < RGB; k++) {
				imageRGB2[i][j][k] = imageRGB[i][j][k];
			}
		}
	}

	short int degreeOfRotation;
	cout << "enter the degree that you wish to rotate with (90, 180 ,270 or 360): ";
	cin >> degreeOfRotation;
	cin.ignore ();

	if (!((degreeOfRotation % 90 == 0) || ((degreeOfRotation - 270) % 360 == 0))) {
		cout << "invalid degree of rotation!\n";
	}

	while (true) {
		if ((degreeOfRotation % 90 == 0) && (degreeOfRotation % 360 != 0) && (degreeOfRotation % 180 != 0) && (degreeOfRotation % 270 != 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					for (int k = 0; k < RGB; k++) {
						imageRGB[j][SIZE - i - 1][k] = imageRGB2[i][j][k];
					}
				}
			}
			break;
		}

		else if ((degreeOfRotation % 180 == 0) && (degreeOfRotation % 360 != 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					for (int k = 0; k < RGB; k++) {
						imageRGB[SIZE - i - 1][SIZE - j - 1][k] = imageRGB2[i][j][k];
					}
				}
			}
			break;
		}

		else if ((degreeOfRotation == 270) || ((degreeOfRotation - 270) % 360 == 0)) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					for (int k = 0; k < RGB; k++) {
						imageRGB[i][j][k] = imageRGB2[j][SIZE - i - 1][k];
					}
				}
			}
			break;
		}

		else if (degreeOfRotation % 90 != 0) {
			cout << "invalid degree, please enter a valid one as stated previously\n";
			cin >> degreeOfRotation;
			cin.ignore ();
			continue;
		}

		else {
			cout << "you do know that you didn't do anything to the image right? well, as you wish\n";
			break;
		}
	}
}

void flip_imageRGB () {
	char orientation;
	// asks the user how to flip the image
	cout << "Flip (h)orizontally or (v)ertically ?" << endl;
	cin >> orientation;
	// validate the input
	while (orientation != 'h' && orientation != 'v') {
		cout << "invalid option! please enter (h) for horizontally or (v) for vertically" << endl;
		cin >> orientation;
	}

	if (orientation == 'h') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int k = 0; k < RGB; k++) {
					// flipping the rows of the 2d array while keeping the columns constant to flip the image horizontally
					imageRGB2[i][j][k] = imageRGB[255 - i][j][k];
				}
			}
		}
	}
	else if (orientation == 'v') {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int k = 0; k < RGB; k++) {
					// flipping the columns of the 2d array while keeping the rows constant to flip the image vertically
					imageRGB2[i][j][k] = imageRGB[i][255 - j][k];
				}
			}
		}
	}

	copy_image2_to_imageRGB ();
}

void detect_image_edgesRGB () {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < RGB; k++) {
				//We make Matrix X and we multiply each element in it by the number specified for it and we add the elements of this Matrix
				int x = (imageRGB[i][j][k] * -1 +
					imageRGB[i][j + 1][k] * 0 +
					imageRGB[i][j + 2][k] * 1 +
					imageRGB[i + 1][j][k] * -2 +
					imageRGB[i + 1][j + 1][k] * 0 +
					imageRGB[i + 1][j + 2][k] * 2 +
					imageRGB[i + 2][j][k] * -1 +
					imageRGB[i + 2][j + 1][k] * 0 +
					imageRGB[i + 2][j + 2][k] * 1);
				// We make Matrix y and we multiply each element in it by the number specified for it and we add the elements of this Matrix
				int y = (imageRGB[i][j][k] * -1 +
					imageRGB[i][j + 1][k] * -2 +
					imageRGB[i][j + 2][k] * -1 +
					imageRGB[i + 1][j][k] * 0 +
					imageRGB[i + 1][j + 1][k] * 0 +
					imageRGB[i + 1][j + 2][k] * 0 +
					imageRGB[i + 2][j][k] * 1 +
					imageRGB[i + 2][j + 1][k] * 2 +
					imageRGB[i + 2][j + 2][k] * 1);
				//We square the sum of each of the 2 Matrix and then add them and take the root of them
				int res = sqrt (x * x + y * y);
				if (res <= 255 / 5) {
					imageRGB2[i][j][k] = 255;
				}
				else {
					imageRGB2[i][j][k] = 0;
				}
			}
		}
	}

	copy_image2_to_imageRGB ();
}

void enlarge_imageRGB () {
	unsigned char quarter1[SIZE / 2][SIZE / 2][RGB], quarter2[SIZE / 2][SIZE / 2][RGB], quarter3[SIZE / 2][SIZE / 2][RGB], quarter4[SIZE / 2][SIZE / 2][RGB];

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				quarter1[i][j][k] = imageRGB[i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				quarter2[i][j][k] = imageRGB[i][(SIZE / 2) + j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				quarter3[i][j][k] = imageRGB[(SIZE / 2) + i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				quarter4[i][j][k] = imageRGB[(SIZE / 2) + i][(SIZE / 2) + j][k];
			}
		}
	}

	int quarterNum;
	cout << "(1) is the top left quarter, (2) is the top right quarter, (3) is the bottom left quarter,\nand (4) is the bottom right quarter\n";
	cout << "enter the number of the quarter that you wish to enlarge: ";
	cin >> quarterNum;
	cin.ignore ();

	if (quarterNum == 1) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = quarter1[i / 2][j / 2][k];
					imageRGB[i][j + 1][k] = quarter1[i / 2][j / 2][k];
					imageRGB[i + 1][j][k] = quarter1[i / 2][j / 2][k];
					imageRGB[i + 1][j + 1][k] = quarter1[i / 2][j / 2][k];
				}
			}
		}
	}
	else if (quarterNum == 2) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = quarter2[i / 2][j / 2][k];
					imageRGB[i][j + 1][k] = quarter2[i / 2][j / 2][k];
					imageRGB[i + 1][j][k] = quarter2[i / 2][j / 2][k];
					imageRGB[i + 1][j + 1][k] = quarter2[i / 2][j / 2][k];
				}
			}
		}
	}
	else if (quarterNum == 3) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = quarter3[i / 2][j / 2][k];
					imageRGB[i][j + 1][k] = quarter3[i / 2][j / 2][k];
					imageRGB[i + 1][j][k] = quarter3[i / 2][j / 2][k];
					imageRGB[i + 1][j + 1][k] = quarter3[i / 2][j / 2][k];
				}
			}
		}
	}
	else if (quarterNum == 4) {
		for (int i = 0; i < SIZE; i += 2) {
			for (int j = 0; j < SIZE; j += 2) {
				for (int k = 0; k < RGB; k++) {
					imageRGB[i][j][k] = quarter4[i / 2][j / 2][k];
					imageRGB[i][j + 1][k] = quarter4[i / 2][j / 2][k];
					imageRGB[i + 1][j][k] = quarter4[i / 2][j / 2][k];
					imageRGB[i + 1][j + 1][k] = quarter4[i / 2][j / 2][k];
				}
			}
		}
	}
	else {
		cout << "not a valid quarter";
	}

}

void shuffle_imageRGB () {
	unsigned char imageWithQuarters[4][SIZE / 2][SIZE / 2][RGB];

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageWithQuarters[0][i][j][k] = imageRGB[i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageWithQuarters[1][i][j][k] = imageRGB[i][(SIZE / 2) + j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageWithQuarters[2][i][j][k] = imageRGB[(SIZE / 2) + i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageWithQuarters[3][i][j][k] = imageRGB[(SIZE / 2) + i][(SIZE / 2) + j][k];
			}
		}
	}

	unsigned int shuffleOrder1, shuffleOrder2, shuffleOrder3, shuffleOrder4;
	cout << "(1) is the top left quarter, (2) is the top right quarter, (3) is the bottom left quarter, \nand (4) is the bottom right quarter\n";
	cout << "enter the order of the shuffled image:";
	cin >> shuffleOrder1 >> shuffleOrder2 >> shuffleOrder3 >> shuffleOrder4;
	cin.ignore ();

	while (shuffleOrder1 > 4 || shuffleOrder2 > 4 || shuffleOrder3 > 4 || shuffleOrder4 > 4) {
		cout << "invalid inputs, please enter valid inputs as stated previously : ";
		cin >> shuffleOrder1 >> shuffleOrder2 >> shuffleOrder3 >> shuffleOrder4;
		cin.ignore ();
	}

	shuffleOrder1--;
	shuffleOrder2--;
	shuffleOrder3--;
	shuffleOrder4--;

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageRGB[i][j][k] = imageWithQuarters[shuffleOrder1][i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageRGB[i][(SIZE / 2) + j][k] = imageWithQuarters[shuffleOrder2][i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageRGB[(SIZE / 2) + i][j][k] = imageWithQuarters[shuffleOrder3][i][j][k];
			}
		}
	}

	for (int i = 0; i < SIZE / 2; i++) {
		for (int j = 0; j < SIZE / 2; j++) {
			for (int k = 0; k < RGB; k++) {
				imageRGB[(SIZE / 2) + i][(SIZE / 2) + j][k] = imageWithQuarters[shuffleOrder4][i][j][k];
			}
		}
	}

}

void merge_imageRGB () {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			for (int k = 0; k < RGB; ++k) {
				imageRGB[i][j][k] = (imageRGB[i][j][k] + imageRGB2[i][j][k]) / 2;
			}
		}
	}
}

string get_image_file_name () {
	string imageFileName;
	getline (cin, imageFileName);
	if (imageFileName.size () < 4 || imageFileName.substr (imageFileName.size () - 4) != ".bmp") {
		imageFileName += ".bmp";
	}
	return imageFileName;
}