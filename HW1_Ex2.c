/*
Author:		Joel Johnson
Course:		CS1325.001
Date:			1/31/2020
Assignment:	Homework 1, Assignment 2
Compiler:	Microsoft Visual Studio 2019

Description:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_triangle1(int);
void print_triangle2(int);
void print_triangle3(int);
void print_triangle4(int);
void print_triangle5(int);
void endl();

void main()
{
	int input = 0;
	printf("Enter any integer between 1 and 15 (inclusive): ");
	scanf("%i", &input);

	while (input < 1 || input > 15)
	{
		printf("Error! Input must be between 1 and 15 (inclusive)\n"
			   "Reenter the number: ");
		scanf("%i", &input);
	}

	print_triangle1(input);
	endl();
	print_triangle2(input);
	endl();
	print_triangle3(input);
	endl();
	print_triangle4(input);
	endl();

	printf("Enter any odd integer between 1 and 15 (inclusive): ");
	scanf("%i", &input);

	while (input < 1 || input > 15 || input % 2 == 0)
	{
		printf("Error! Input must be an odd integer between 1 and 15 (inclusive)\n"
			"Reenter the number: ");
		scanf("%i", &input);
	}
	print_triangle5(input);

}//end of main

void print_triangle1(int size)
{
	for (; size > 0; size--)
	{
		for (int i = size; i > 0; i--)
			printf("*");
		printf("\n");
	}
}

void print_triangle2(int size)
{
	for (int j = size; j > 0; j--)
	{
		for (int i = j; i > 1; i--)
			printf(" ");
		for (int i = size + 1 - j; i > 0; i--)
			printf("*");
		printf("\n");
	}
}

void print_triangle3(int size)
{
	for (int j = size; j > 0; j--)
	{
		for (int i = j - 1; i > 0; i--)
			printf(" ");
		for (int i = size + 1 - j; i > j - size; i--)
			printf("*");
		for (int i = j - 1; i > 0; i--)
			printf(" ");
		printf("\n");
	}
}

void print_triangle4(int size)
{
	for (int j = size; j > 0; j--)
	{
		for (int i = j - 1; i > 0; i--)
			printf(" ");
		for (int i = size + 1 - j; i > j - size; i--)
			if (i == size + 1 - j || i == j - size + 1 || j == 1)
				printf("*");
			else
				printf(" ");
		for (int i = j - 1; i > 0; i--)
			printf(" ");
		printf("\n");
	}
}

void print_triangle5(int size)
{
	for (int j = size; j > 0; j--)
	{
		for (int i = size; i > 0; i--)
			if (i == j || i == size - j + 1 || j == 1 || j == size)
			{
				if (i == 1)
					printf("*");
				else
					printf("* ");
			}
			else
				printf("  ");
		printf("\n");
	}
}

void endl()
{
	printf("\n");
}