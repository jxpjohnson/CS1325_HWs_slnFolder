/*
Author:		Joel Johnson
Course:		CS1325.001
Date:			1/30/2020
Assignment:	Homework 1, Assignment 1
Compiler:	Microsoft Visual Studio 2019

Description:
This program converts decimal numbers ranging from 32 to 126, into hex, oct, binary form and also prints the ASCII code for that number.
These numbers are displayed in two columns, with left column having one extra entry as 32 to 126 results in odd entries.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void header();
void fill_entries(char);
void convert_hex_to_binary(char[], char[]);
void print_formatted(char[], int);

void main()
{
	const int STARTING_POINT = 32;						//Starting point where the process starts
	const int END_POINT = 126;								//Starting point where the process ends

	header();

	for (int i = 32, j = (STARTING_POINT + END_POINT + (2 * ((END_POINT + 1 - STARTING_POINT) % 2))) / 2; i < (STARTING_POINT + END_POINT + (2 * ((END_POINT + 1 - STARTING_POINT) % 2))) / 2; i = i++, j++)
	{
		fill_entries((char)i);								//prints all left hand entries
		printf("\t\t\t\t\t");								//gap between columns
		if(j <= END_POINT)									//in the case left hand column is bigger than right hand column
			fill_entries((char)j);
		printf("\n");											//next line
	}//end of for loop

}//end of main

void header()
{
	//printing all the heading with proper spacing and cell width
	printf("%7s    %4s %4s %4s %5s ", "Bin", "Oct", "Dec", "Hex", "Char");
	printf("\t\t\t\t %7s   %4s %4s %4s %5s \n", "Bin", "Oct", "Dec", "Hex", "Char");

	for (int i = 0; i < 31; i++)
		printf("-");											//printing left column border
	
	printf("\t\t\t\t \t");
	
	for (int i = 0; i < 31; i++)
		printf("-");											//printing left column border
	
	printf("\n");

}//end of function header

void fill_entries(char input)
{
	char hex[3];												//this variable store the hex value of the number as a string
	char bin[10];												//this variable store the binary value of the number as a string

	sprintf(hex, "%X", (int)input);						//uses sprintf to print the number into hexadecimal into a string
	convert_hex_to_binary(hex, bin);						//call a function to convert hex to bin
	print_formatted(bin, input);							//print all of the result by calling the function
	
}//end of functin fill_entries

void convert_hex_to_binary(char hex[], char bin[])
{
	char temp_bin[2][5];

	for (int i = 1; i >= 0; i--)
		switch (hex[i])
		{
		case '0':
			strcpy(temp_bin[i], "0000");
			break;
		case '1':
			strcpy(temp_bin[i], "0001");
			break;
		case '2':
			strcpy(temp_bin[i], "0010");
			break;
		case '3':
			strcpy(temp_bin[i], "0011");
			break;
		case '4':
			strcpy(temp_bin[i], "0100");
			break;
		case '5':
			strcpy(temp_bin[i], "0101");
			break;
		case '6':
			strcpy(temp_bin[i], "0110");
			break;
		case '7':
			strcpy(temp_bin[i], "0111");
			break;
		case '8':
			strcpy(temp_bin[i], "1000");
			break;
		case '9':
			strcpy(temp_bin[i], "1001");
			break;
		case 'A':
			strcpy(temp_bin[i], "1010");
			break;
		case 'B':
			strcpy(temp_bin[i], "1011");
			break;
		case 'C':
			strcpy(temp_bin[i], "1100");
			break;
		case 'D':
			strcpy(temp_bin[i], "1101");
			break;
		case 'E':
			strcpy(temp_bin[i], "1110");
			break;
		case 'F':
			strcpy(temp_bin[i], "1111");
			break;
		}//end of switch

	sprintf(bin, "%s %s", temp_bin[0], temp_bin[1]);
}//end of function convert_hex_to_binary

void print_formatted(char bin[], int number)
{
	printf("%10s %4o %4d %4X %3c  ", bin, (int)number, (int)number, (int)number, number);
}
