#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


char* Decrypter(const char*, const char*);

int main(void)
{
	string word;
	string xorKey;

	
	cout << "Please enter a key: ";
	cin >> xorKey;

	ifstream infile;
	infile.open("hello.txt", ios::binary);
	string encrypt, write;
	
	while (getline(infile, write))
	{
		encrypt = write;
	}
	infile.close();

	char* decrypt = Decrypter(encrypt.c_str(), xorKey.c_str());
	cout << "Decrypted String: " << decrypt << endl;

	system("PAUSE");
	return 0;
}

void WriteFile(string text)
{
	string filename;
	cout << "Enter a file name: ";
	cin >> filename;
	
	ofstream file;
	file.open(filename + ".txt", ios::binary | ios::app);
	file << text << endl;
	file.close();
}

char * Decrypter(const char* inpString, const char* key)
{
	char* output = new char[strlen(inpString) + 1];
	memset(output, (int)'\0', strlen(inpString) + 1);

	int len = strlen(inpString);
	int keyLen = strlen(key);
	int x = 0;

	for (int i = 0; i < len; i++)
	{

		output[i] = inpString[i] ^ key[x];
		x++;
		if (x >= keyLen)
		{
			x = 0;
		}

	}
	//WriteFile(output);
	return output;
}