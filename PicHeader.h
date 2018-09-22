#pragma once
#include "stdafx.h"
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
class Picture
{
private:
	string message;
	string picLoc;
	int numberOfChars;
	char * arrayOfChars;
	Mat image;

public:
	Picture(string mes, string pic);//constructor
	void displayImage();//display current image
	void displayImageInfo();//print out number of row and cols
	int getNumberCols(); //return number of cols
	int getNumberRows();//return number of rows
	Vec4b getBGRAVector(int x, int y);//return vector containing character values for Mat rgba values for a pixel
	int getBlueVal(int x, int y);//return blue value between 0 and 255
	int getGreenVal(int x, int y);//return green value between 0 and 255
	int getRedVal(int x, int y);//return red value between 0 and 255
	int getAlphaVal(int x, int y);//return alpha value between 0 and 255
	string getMessage();//return the message to be encoded
	Mat getMat();//return cv::Mat, the matrix data type that contains pixels, their data, and allows for image display
	void encodeMessage(); //encode the whole message into the Mat pixels
	string decodeMessage(int numberOfChars); //retrieve message that has been encoded in Mat, with numberOfChars chars

};

////////////////////////Max's Stuff
// Format: vector<DataType> myVector(size);
// myVector.push_back(value) ==> adds an element to th END of the vector (also resizes it)
// myVector.at(index) ==> return element at specified index number
// myvector.size ==> returns an unsigned int equal to the number of elements
// for (unsigned int i = 0; i < myVector.size(); i++)
// myVector.begin() ==> reads vector from first element (index 0)
// myVector.insert(myVector.begin() + integer, new value) ==> adds element before specified index number
// myVector.erase(myVector.begin() + integer ==> removes element at specified index number
// myVector.clear() ==> removes all elements in vector
// myVector.empty() ==> returns boolean value if vector is empty

// Convert char to int
// char a = '6';
// int b = a-48;
// int ASCII, 48 = 0;

Vec4b encryptRGB(Vec4b rgbValues, char message);
char decryptRGB(Vec4b vec);
// I may make a method that converts the vector values to binary strings