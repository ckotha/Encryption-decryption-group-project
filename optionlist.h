#ifndef OPTIONLIST_H_INCLUDED
#define OPTIONLIST_H_INCLUDED
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
#include "MbXor.h"
#include "encryption.h"
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <PicHeader.h>





void stringToBinary();

void binaryToString();
void encryptCaesar();
void decryptCaesar();
std::string XOR();
void XORMULTI(char holder);



using namespace std;




//CAESAR LOGIC FOR ENCRYPTION AND DECRYPTION
void encryptCaesar();
void decryptCaesar();


class XOR
{
public:
	XOR();
	virtual ~XOR();
protected:
private:
};

string XOR(string input, char key);
void XOR_ENCRYPT();

void XOR_DECRYPT();




void binaryToString();


void stringToBinary();

using namespace std;

MbXor::MbXor();

MbXor::MbXor(string nameOfFile);

void MbXor::determineKeyLength();

void MbXor::printOptions(int keyLength);


/*Program takes in a user inputted phrase and then checks for common words in the phrase. Returns true if any common phrases are found.*/
bool MbXor::dictionaryChecker(const string phrase);

encryption::encryption() {};


void encryption::encrypt(string ifile, string ofile);


void XORMULTI(char holder);




using namespace cv;
void encryptPic();
void decryptPic();

void encryptPic(string input, string fileLoc);
void decryptPic(int numberOfChars, string fileLoc);
//////////////////////////MaxsHeader implementation
Vec4b encryptRGB(Vec4b rgbValues, char message);

// Function decryptRGB
// @param  cv::Vec4b rgbValues - values from which the message will be decrypted
// @return char that is decrypted in the vector
char decryptRGB(Vec4b rgbValues);
void Picture::encodeMessage();
///////////////////////Decode emcode message
string Picture::decodeMessage(int numberOfChars);
Picture::Picture(string mes, string pic);
void Picture::displayImage();
void Picture::displayImageInfo();
int Picture::getNumberCols();
int Picture::getNumberRows();
Vec4b Picture::getBGRAVector(int x, int y);
int Picture::getBlueVal(int x, int y);
int Picture::getGreenVal(int x, int y);
int Picture::getRedVal(int x, int y);
int Picture::getAlphaVal(int x, int y);
string Picture::getMessage();
Mat Picture::getMat();




















#endif // OPTIONLIST_H_INCLUDED
