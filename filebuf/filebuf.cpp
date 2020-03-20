// filebuf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


int main() 
{
    std::cout << "FT service manipulation program\n";
	std::cout << "(type '?' to help, 'x' - to exit)\n";

	char ucCase = 0;
	while (ucCase != 'x')
	{
		std::cout << "enter case symbol: " << std::endl;
		
		std::cin >> ucCase;
		if (ucCase == '?')
		{
			// help
		}
		else if (ucCase == 'c')
		{
			// clear
		}
		else if (ucCase == '0')
		{
			// test0

			// i-streams, o-streams ops
			std::ifstream fin;
			fin.open("t0_input");

			std::ofstream fout;
			fout.open("t0_output");

			int a;
			int b;
			int c;

			fin >> a >> b >> c;

			std::cout << a << " " << b << " " << c << std::endl;

			fin.close();
			fout.close();

			// io filestream ops
			std::fstream fio("t0_iobuf", std::ios::out | std::ios::in);
			//fio.seekg(0, std::ios::beg);

			while (!fio.eof())
			{
				std::string str;

				fio >> str;
			}


			fio.close();
		}
		else if (ucCase == '1')
		{
			// test1

			std::ofstream outfile;
			outfile.open("t1.txt");

			outfile.write("This is an apple", 16);
			int pos = outfile.tellp();
			outfile.seekp(pos - 7);
			outfile.write(" sam", 4);

			outfile.close();
		}
		else if (ucCase == '2')
		{
			// test2

			std::ifstream is("t2.txt", std::ifstream::binary);
			if (is) {
				// get length of file:
				is.seekg(0, is.end);
				int length = is.tellg();
				is.seekg(0, is.beg);

				// allocate memory:
				char* buffer = new char[length];

				// read data as a block:
				is.read(buffer, length);

				is.close();

				// print content:
				std::cout.write(buffer, length);

				delete[] buffer;
			}
		}
		else if (ucCase == '3')
		{
			// test3

			std::ifstream infile("test.txt", std::ifstream::binary);
			std::ofstream outfile("new.txt", std::ofstream::binary);

			// get size of file
			infile.seekg(0, infile.end);
			long size = infile.tellg();
			infile.seekg(0);

			// allocate memory for file content
			char* buffer = new char[size];

			// read content of infile
			infile.read(buffer, size);

			// write to outfile
			outfile.write(buffer, size);

			// release dynamically-allocated memory
			delete[] buffer;

			outfile.close();
			infile.close();
		}
		else if (ucCase == '4')
		{
			// test4

			std::ofstream outfile;
			outfile.open("t4.txt");

			outfile.write("0123456789012345678\n", 20);
			outfile.write("0123456789012345678\n", 20);
			outfile.write("0123456789012345678\n", 20);
			outfile.write("0123456789012345678\n", 20);
			outfile.write("0123456789012345678\n", 20);

			int pos = outfile.tellp();

			// test exact replacement: Success
			outfile.seekp(pos - 10);
			outfile.write("555", 3);

			// test exact replacement: Success
			outfile.seekp(pos - 20);
			outfile.write("444", 3);

			// test different size replacement: Success
			// NOTE: file size is increased
			outfile.seekp(pos - 10);
			outfile.write("777777777777777777", 18);

			// test different size replacement: Success
			// NOTE: file size is increased
			outfile.seekp(pos - 28);
			outfile.write("\0", 1);


			outfile.close();
		}

	}

	std::cout << "exiting...\n";
}




//// HW
//	// 1
//buf_value.value_2BYTE[0] = m_unTableThreshold.structVal.TX_Power_High_Warning[1];
//buf_value.value_2BYTE[1] = m_unTableThreshold.structVal.TX_Power_High_Warning[0];
//
//// output User-format
//fValue = buf_value.value_WORD;
//fValue /= 10000;
//fValue = log10(fValue);
//fValue *= 10;
//
//// convert to str
//str.Format(L"%02.1f dBm", fValue);
//
//// output
//Item.col = 4;
//Item.strText = str;
//m_GridDDM.SetItem(&Item);
//
//
//// LA
//// 1
//buf_value.value_2BYTE[0] = m_unTableThreshold.structVal.TX_Power_Low_Warning[1];
//buf_value.value_2BYTE[1] = m_unTableThreshold.structVal.TX_Power_Low_Warning[0];
//
//// output User-format
//fValue = buf_value.value_WORD;
//fValue /= 10000;
//fValue = log10(fValue);
//fValue *= 10;
//
//// convert to str
//str.Format(L"%02.1f dBm", fValue);