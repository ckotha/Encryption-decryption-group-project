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
void encryptCaesar() {
	cout << "Please enter what you would like to encrypt: ";
	string userInfo;
	cin.ignore();
	getline(cin, userInfo);

	cout << "\nPlease enter your key value: ";
	int key = 0;
	cin >> key;

	//input validation for encryption key
	while (key < 1) {
		cin >> key;
		if (key < 1) {
			cout << "\nInvalid encryption input. Try again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	int i = 0;
	int newLetter = 0;
	long length = userInfo.length();
	while (i < length) {
		if (isalpha(userInfo[i])) {
			int start = 0;
			if (userInfo[i] < 97) {
				start = 65;
				newLetter = (((int)userInfo[i] + key - start) % 26) + start;
				userInfo[i] = (char)newLetter;
			}
			else {
				start = 97;
				int newLetter = (((int)userInfo[i] + key - start) % 26) + start;
				userInfo[i] = (char)newLetter;

			}
		}
		i++;
	}
	cout << "Encrypted information: " << userInfo << "\n";
}
void decryptCaesar() {
	cout << "Please enter what you would like to decrypt: ";
	string userInfo;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, userInfo);

	cout << "Do you know the key? yes or no. ";

	bool optionBool = false;
	string option = " ";
	string y = "yes";
	string n = "no";

	while (optionBool == false) {
		getline(cin, option);
		if (option == "yes" || option == "no") {
			optionBool = true;
		}

		else {
			cout << "Invalid input. Please type either yes or no. \n";
		}
	}
	if (option == "yes") {
		cout << "\nPlease enter your key value (1-26): ";
		int key = 0;

		//input validation for encryption key
		while (key < 1) {
			cin >> key;
			if (key < 1 || key > 26) {
				cout << "\nInvalid encryption input. Try again.\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		int i = 0;
		int newLetter = 0;
		long length = userInfo.length();
		while (i < length) {
			if (isalpha(userInfo[i])) {
				int start = 0;
				if (userInfo[i] < 97) {
					start = 65;
					newLetter = (((int)userInfo[i] - start - key + 26) % 26) + start;
					userInfo[i] = (char)newLetter;
				}
				else {
					start = 97;
					int newLetter = (((int)userInfo[i] - start - key + 26) % 26) + start;
					userInfo[i] = (char)newLetter;

				}
			}
			i++;
		}
		cout << "Decrypted information: " << userInfo << "\n";
	}
	if (option == "no") {
		for (int j = 1; j < 27; j++) {
			string helper = userInfo;
			int i = 0;
			int newLetter = 0;
			int key = j;
			long length = helper.length();
			while (i < length) {
				if (isalpha(helper[i])) {
					int start = 0;
					if (helper[i] < 97) {
						start = 65;
						newLetter = (((int)helper[i] - start - key + 26) % 26) + start;
						helper[i] = (char)newLetter;
					}
					else {
						start = 97;
						int newLetter = (((int)helper[i] - start - key + 26) % 26) + start;
						helper[i] = (char)newLetter;

					}
				}
				i++;
			}
			cout << "Key option: " << key << "\nDecrypted information: " << helper << "\n";
		}
	}
}


class XOR
{
public:
	XOR();
	virtual ~XOR();
protected:
private:
};

string XOR(string input, char key) {
	string XORString = input;
	string newXOR = "";
	for (int i = 0; i < input.size(); i++) {// takes in a string and then xor's that string by its length so all characters are encrypted
		newXOR += XORString[i] ^ ((int(key + i)) % 255);
	}
	return newXOR;
}
void XOR_ENCRYPT() {
	char key;
	string copied = "";
	string other = "";
	string readfile;
	cout << "What is the name of the file you want to open? (Do not include the extension)" << endl;
	cin >> readfile;
	readfile += ".txt";

	ifstream infile(readfile.c_str());// takes in the inputted filename into an ifstream
	while (!infile.good()) {
		infile.close();
		cout << "That file does not exist.  Please enter a correct file name: " << endl;
		cin >> readfile;
		readfile += ".txt";
		infile.open(readfile.c_str());
	}
	system(readfile.c_str());
	for (int i = 0; infile.eof() != true; i++) {// runs through the text file and copies contents into a string
		copied += infile.get();
	}
	string writefile;
	cout << "What is the name of the file you want to write to? (Do not include the extension)" << endl;
	cin >> writefile;
	cout << "Enter key to encrypt with: ";
	cin >> key;
	other = XOR(copied, key);// runs the decryption program with the string
	writefile += ".txt";
	ofstream outfile(writefile.c_str());
	outfile << other;// saves the contents of the string into an output textfile
	outfile.close();
	cout << "The new string has been stored in the file." << writefile << endl;
}


void XOR_DECRYPT() {

	//cout<< "Do you have a key to decrypt. Enter y for yes and n for no";
	// if()
	cout << "What file is it stored in? (Do not include the extension) " << endl;
	string line;
	std::string display = "";
	std::string fDisplay = "";
	string fileholder;
	cin >> fileholder;// takes in a file that needs to be decrypted
	fileholder += ".txt";
	cout << "Enter the key to decrypt: ";
	char key2;
	cin >> key2;
	ifstream infile2(fileholder.c_str());
	if (!infile2) {
		cout << "The file does not exist. " << endl;
	}

	else if (infile2.good()) {// if the file exists and is open, program will run through the text file and copy contents of text file into a string character by character
		string in = "";
		while (!infile2.eof())
		{
			//if (infile2.get() == 26)
			//line += (char)58;
			line += (char)infile2.get();
		}
		// cout << in << endl;
		infile2.close();
	}
	fDisplay = XOR(line, key2);
	fDisplay.erase(fDisplay.end() - 1);// displays the newly decrypted
	cout << fDisplay;
}




void binaryToString()
{
	string binary = "";
	cout << "Enter the binary you wish to be decrypted: " << endl;
	cin.ignore();
	getline(cin, binary);

	string output = ""; //what the binary will be converted to

						//removes spaces from binary input
	string::iterator end_pos = remove(binary.begin(), binary.end(), ' ');
	binary.erase(end_pos, binary.end());

	if (binary.length() % 8 != 0)
	{
		cout << "\ninvalid input. NOTE: binary must be in 8-bit form. " << endl;
		return;
	}

	for (int i = 0; i < binary.length() / 8; i++)
	{
		int chunkTotal = 0; //the base-10 representation of the 8-bit binary value

		for (int k = 0; k < 8; k++)
		{
			int a = (binary[k + (8 * i)]) - 48; //either a 1 or 0
			chunkTotal += a * (pow(2, (7 - k)));

			if (a != 0 && a != 1)
			{
				cout << "\ninvalid input. Only the '0', '1', and ' ' characters may be used for binary input." << endl;
				return;
			}
		}
		output += char(chunkTotal);
	}

	cout << "\nDecrypted message:" << "\n'" << output << "'" << endl;

	return;
}


void stringToBinary()
{
	string str = "";

	cout << "Enter the string you wish to be encrypted: " << endl;
	cin.ignore();
	getline(cin, str);
	cout << "\nEncrypted message: '";

	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		cout << bitset<8>(str.c_str()[i]);

		if (i != size - 1)
		{
			cout << " ";
		}
		else
		{
			cout << "'";
		}
	}

	return;
}







using namespace std;

MbXor::MbXor() {
	system("input.txt");
	ifstream inpt;
	inpt.open("input.txt");
	string line;

	if (inpt.is_open()) {
		while (getline(inpt, line)) {
			ctext += line;

			if (!inpt.eof()) {
				ctext += 10;
			}
		}
		inpt.close();
	}
}

MbXor::MbXor(string nameOfFile) {
	ifstream inpt;
	inpt.open(nameOfFile.c_str());
	string line;
	while (!inpt) {
		inpt.close();
		cout << "The file does not exist.  Enter a correct filename: (Do not include the extension)" << endl;
		cin >> nameOfFile;
		nameOfFile += ".txt";
		inpt.open(nameOfFile.c_str());
	}
	while (getline(inpt, line)) {
		ctext += line;

		if (!inpt.eof()) {
			ctext += 10;
		}
	}
	inpt.close();
}

void MbXor::determineKeyLength() {
	double hammingWeightArray[40];
	int minPosition = 0;

	//This loop tests key lengths from 1 to 40
	for (int i = 1; i <= 40; ++i) {
		string holder = ctext;
		string toBeDestroyed = ctext;
		string sub = ctext.substr(0, i);
		toBeDestroyed.erase(0, i);
		toBeDestroyed += sub;
		int hammingWeight = 0;

		//Adds up the ones in each character for each key length.  The hammingWeight that comes out of it
		//represents the hamming weight for that key length.
		int temp = ctext.size();
		for (int j = 0; j < temp; j++) {
			char temp = holder[j] ^ toBeDestroyed[j];

			while (temp != 0) {
				if (temp % 2 != 0) {
					hammingWeight++;
				}
				temp = (temp / 2);
			}
		}

		//Adds to the HW array and calculates the minimum key length.
		//Need to check Math
		for (int k = 1; k <= i; k++) {
			if ((i % k) == 0) {
				hammingWeightArray[k - 1] += hammingWeight / (40 / k);
				if (hammingWeightArray[k - 1] < hammingWeightArray[minPosition]) {
					minPosition = k - 1;
				}
			}
		}

		cout << "The Hamming weight of Key Length " << i << " is: ";
		if (i < 10)
			cout << "   " << hammingWeight << endl;
		else
			cout << "  " << hammingWeight << endl;
	}
	for (int z = 0; z < 41; z++) {
		cout << "Hamming weight in the array is: " << hammingWeightArray[z] << endl;
	}
	cout << "\n\nThe most likely key length is: " << (minPosition + 1) << endl;
}



void MbXor::printOptions(int keyLength) {
	/*Two if blocks:
	(1) check to see if the result of xor-ing two character is in the normal ascii range,
	if not, ++ the key's ascii value at that spot.
	(2) check if the key character is the last normal ascii value. if it is, then make the next chacter in the string ++ and
	the current character the min ascii value.  Should probably do this part in the outside loop. */
	string key;
	string maxKeyValue;
	for (int z = 0; z < keyLength; z++) {
		key += "!";
		maxKeyValue += "~";
	}

	string plainText(ctext.size(), 'a');
	while (key < maxKeyValue) {

		int staticReplacement = ctext.size();
		int d = 0;
		bool range = false;
		while (d < staticReplacement) {
			plainText[d] = ctext[d] ^ key[d % keyLength];

			if ((plainText[d] > 126 || plainText[d] < 14) && plainText[d] != 10) {
				range = true;
				key[d % keyLength] += 1;
				break;
			}
			d++;
		}

		bool temp = false;
		for (int z = keyLength - 1; z > 0; z--) {
			if (key[z] >= '~') {
				temp = true;
				key[z] = ' ';
				key[z - 1] += 1;
			}
		}

		if (!range && !temp) {
			if (dictionaryChecker(plainText)) {
				cout << "\n\nThe key was: " << key << "\nThe decrypted string is: \n\n" << endl;
				cout << plainText;
			}
			key[keyLength - 1] += 1;
		}
	}
	cout << "\n\nFinished!" << endl;
}


/*Program takes in a user inputted phrase and then checks for common words in the phrase. Returns true if any common phrases are found.*/
bool MbXor::dictionaryChecker(const string phrase) {
	int count = 0;
	string s = "";
	string dictionary[] = { "the","and","you","that","was","for","are","with","his","they","this","have","from","one",
		"had","word","but","not","what","all","were","when","your","can","said","there","use","each","which","she","how","their",
		"will","other","about","out","many","then","them","these" };// list of most common words
	size_t pos;
	int temp1 = sizeof(dictionary);
	int temp2 = sizeof(dictionary[0]);
	for (int i = 0; i < temp1 / temp2; i++) {
		pos = phrase.find(dictionary[i]);// foor loop to find the most common words
		if (count == 7) {// after 2 instances of finding words, program returns true
			return true;
		}
		else if (pos != string::npos) {
			count++;
			s = dictionary[i];
		}
	}
	return false;
}

encryption::encryption() {};


void encryption::encrypt(string ifile, string ofile) {
	//This section reads in all the lines from the input file.
	string line;
	string plaintext;
	ifstream inpt;
	inpt.open(ifile.c_str());

	while (getline(inpt, line)) {
		plaintext += line;
		if (!inpt.eof()) {
			plaintext += 10;
		}
	}
	inpt.close();

	//This block performs the encryption on the input string
	cout << "Enter the encryption key: ";
	string key;
	cin >> key;
	string ciphertext;
	int i = 0;
	int temp = plaintext.size();
	while (i != temp) {
		ciphertext += plaintext[i] ^ key[i % key.size()];
		if (ciphertext[i] == 26)
			//the ascii value 26 causes the program to crash, so instead I assigned that ascii value to something 32 bits higher.
			ciphertext[i] = 58;
		i++;
	}

	//This block assigns the xor-ed string to the txt file.
	ofstream outpt;
	outpt.open(ofile.c_str(), ofstream::out | ofstream::trunc);
	outpt << ciphertext;
	outpt.close();
	cout << ciphertext << "\n" << endl;
}


void XORMULTI(char holder) {

	if (holder == 'e') {
		string readfile;
		cout << "What is the name of the file you want to open? (Do not include the extension)" << endl;
		cin >> readfile;
		readfile += ".txt";

		ifstream infile(readfile.c_str());
		while (!infile.good()) {
			infile.close();
			cout << "That file does not exist.  Please enter a correct file name: " << endl;
			cin >> readfile;
			readfile += ".txt";
			infile.open(readfile.c_str());
		}
		system(readfile.c_str());
		string writefile;
		cout << "What is the name of the file you want to write to? (Do not include the extension)" << endl;
		cin >> writefile;
		writefile += ".txt";

		ifstream outfile(writefile.c_str());
		while (!outfile.good()) {
			outfile.close();
			cout << "That file does not exist.  Please enter a correct file name: " << endl;
			cin >> writefile;
			writefile += ".txt";
			outfile.open(writefile.c_str());
		}

		encryption* pleasework = new encryption();
		pleasework->encrypt(readfile, writefile);
		cout << "The new string has been stored in the file " << writefile << endl;
	}

	else if (holder == 'd') {
		cout << "Do you already have the string saved in a text file (y/n)?" << endl;
		char decision = 't';
		do {
			cin >> decision;
			if (decision == 'n') {
				MbXor decryption;
				cout << "Enter the key length: ";
				int keysize;
				cin >> keysize;
				decryption.printOptions(keysize);
				break;
			}
			else if (decision == 'y') {
				cout << "What file is it stored in? (Do not include the extension) " << endl;
				string fileholder;
				cin >> fileholder;
				fileholder += ".txt";
				MbXor decryption(fileholder);
				cout << "Enter the key length: ";
				int keysize;
				cin >> keysize;
				decryption.printOptions(keysize);
				break;
			}
			else
				cout << "Incorrect input, please enter a 'n' or a 'y'. " << endl;
		} while (holder != 'n' && holder != 'y');
	}
}




using namespace cv;
void encryptPic();
void decryptPic();

void encryptPic(string input, string fileLoc)
{
	Picture image = Picture(input, fileLoc);

	if (imread(fileLoc, IMREAD_UNCHANGED).data)
	{
		image.encodeMessage();
		cout << "Please enter the name you want to save your file as, in the project directory." << endl;
		string str = "";
		cin >> str;
		const vector<int>& params = vector<int>(101);
		imwrite(str, image.getMat(), params);
	}

}
void decryptPic(int numberOfChars, string fileLoc)
{
	Picture image = Picture("", fileLoc);
	string str = image.decodeMessage(numberOfChars);
	cout << "Message: " << str << endl;

}
//////////////////////////MaxsHeader implementation
Vec4b encryptRGB(Vec4b rgbValues, char message) {

	// store bgra values into variables as ints
	int blueInt = (int)rgbValues[0];
	int greenInt = (int)rgbValues[1];
	int redInt = (int)rgbValues[2];
	int alphaInt = (int)rgbValues[3];


	// convert ints into binary strings
	std::string blueBinary = bitset<8>(blueInt).to_string();
	std::string greenBinary = bitset<8>(greenInt).to_string();
	std::string redBinary = bitset<8>(redInt).to_string();
	std::string alphaBinary = bitset<8>(alphaInt).to_string();

	// convert message char into an int
	int messageInt = (int)message;

	// convert message int into a binary string
	std::string messageBinary = bitset<8>(messageInt).to_string();;

	// place two binary values from the message string
	// into the two least significant place holders
	// of the four bgra binary representations
	blueBinary[6] = messageBinary[0];
	blueBinary[7] = messageBinary[1];
	greenBinary[6] = messageBinary[2];
	greenBinary[7] = messageBinary[3];
	redBinary[6] = messageBinary[4];
	redBinary[7] = messageBinary[5];
	alphaBinary[6] = messageBinary[6];
	alphaBinary[7] = messageBinary[7];

	// convert the binary string representations back to ints
	blueInt = stoi(blueBinary, nullptr, 2);
	greenInt = stoi(greenBinary, nullptr, 2);
	redInt = stoi(redBinary, nullptr, 2);
	alphaInt = stoi(alphaBinary, nullptr, 2);

	//convert the ints back to char values and store them in the new array;

	rgbValues[0] = (char)(blueInt);
	rgbValues[1] = (char)(greenInt);
	rgbValues[2] = (char)(redInt);
	rgbValues[3] = (char)(alphaInt);

	return rgbValues;
}

// Function decryptRGB
// @param  cv::Vec4b rgbValues - values from which the message will be decrypted
// @return char that is decrypted in the vector
char decryptRGB(Vec4b rgbValues) {
	int messageInt;
	char message;

	// store bgra values into variables as ints
	int blueInt = (int)rgbValues[0];
	int greenInt = (int)rgbValues[1];
	int redInt = (int)rgbValues[2];
	int alphaInt = (int)rgbValues[3];

	// convert ints into binary strings
	std::string blueBinary = bitset<8>(blueInt).to_string();
	std::string greenBinary = bitset<8>(greenInt).to_string();
	std::string redBinary = bitset<8>(redInt).to_string();
	std::string alphaBinary = bitset<8>(alphaInt).to_string();

	// take the values from the two least significant placeholders
	// of each vector value and stor them into the binary string
	// representation of the message
	std::string messageBinary = "00000000";
	messageBinary[0] = blueBinary[6];
	messageBinary[1] = blueBinary[7];
	messageBinary[2] = greenBinary[6];
	messageBinary[3] = greenBinary[7];
	messageBinary[4] = redBinary[6];
	messageBinary[5] = redBinary[7];
	messageBinary[6] = alphaBinary[6];
	messageBinary[7] = alphaBinary[7];

	const char* str = &(messageBinary[0]);
	// convert binary string representation back to int
	messageInt = stoi(str, nullptr, 2);

	// convert int to char and return value
	message = (char)(messageInt);

	return message;
}
void Picture::encodeMessage() {
	int charIndex = 0;
	for (int r = 0; r < getNumberRows(); r++)
	{
		for (int c = 0; c < getNumberCols(); c++)
		{
			if (charIndex < message.length())
			{
				Vec4b tempVec = getBGRAVector(r, c);
				tempVec = encryptRGB(tempVec, message[charIndex]);//create the vector containing RGBA values
				image.at<Vec4b>(Point(r, c)) = tempVec;  //change the current color values to values with encrypted data
			}
			charIndex++;
		}
	}
}
///////////////////////Decode emcode message
string Picture::decodeMessage(int numberOfChars)
{
	string temp = "";
	int charIndex = 0;
	for (int r = 0; r < getNumberRows(); r++)
	{
		for (int c = 0; c < getNumberCols(); c++)
		{
			if (charIndex < numberOfChars)
			{
				Vec4b tempVec = getBGRAVector(r, c);
				temp += decryptRGB(tempVec);  //create the vector containing color values with encrypted data
			}
			charIndex++;
		}
	}
	return temp;
}
Picture::Picture(string mes, string pic) { // mes is the message to be encoded, pic is the pictures file location
	message = mes;
	picLoc = pic;
	numberOfChars = message.length();
	arrayOfChars = new char[numberOfChars];
	for (int i = 0; i < numberOfChars; i++)
	{
		arrayOfChars[i] = (char)mes[i];
		cout << mes[i] << " " << endl;
	}
	image = imread(picLoc, IMREAD_UNCHANGED);   // Read the file

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}
}
void Picture::displayImage() {
	namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display.
	imshow("Display window", image);                   // Show our image inside it.
}

void Picture::displayImageInfo() {
	cout << "Bytes Per Element: " << image.elemSize() << endl;
	cout << "Type of data (8 bit unsigned normally): " << image.depth() << endl;    //return a code to the type of info at each
	cout << "Rows: " << image.rows << endl;
	cout << "Cols: " << image.cols << endl;
}
int Picture::getNumberCols() {// number of cols in Mat
	return image.cols;
}
int Picture::getNumberRows() {//number of rows in Mat
	return image.rows;
}
Vec4b Picture::getBGRAVector(int x, int y) {
	Vec4b color = image.at<Vec4b>(Point(x, y));
	return color;
}
int Picture::getBlueVal(int x, int y) {
	Vec4b color = image.at<Vec4b>(Point(x, y)); //Create cv::vec containing 4 elements: Blue, Green, Red, Alpha, in that order
	cout << "Blue: " << (int)color.val[0] << endl;
	return  (int)color.val[0];
}
int Picture::getGreenVal(int x, int y) {
	Vec4b color = image.at<Vec4b>(Point(x, y)); //Create cv::vec containing 4 elements: Blue, Green, Red, Alpha, in that order
	cout << "Green: " << (int)color.val[1] << endl;
	return  (int)color.val[1];
}
int Picture::getRedVal(int x, int y) {
	Vec4b color = image.at<Vec4b>(Point(x, y)); //Create cv::vec containing 4 elements: Blue, Green, Red, Alpha, in that order
	cout << "Red: " << (int)color.val[2] << endl;
	return  (int)color.val[2];
}
int Picture::getAlphaVal(int x, int y) {
	Vec4b color = image.at<Vec4b>(Point(x, y));  //Create cv::vec containing 4 elements: Blue, Green, Red, Alpha, in that order
	cout << "Alpha: " << (int)color.val[3] << endl;
	return  (int)color.val[3];
}
string Picture::getMessage() {
	return message;
}
Mat Picture::getMat() {
	return image;
}




















#endif // OPTIONLIST_H_INCLUDED
