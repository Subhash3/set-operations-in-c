#include <stdio.h>
#include <stdlib.h>

/*All Constant Declarations*/
#define MAX    32

#include "set_op.h"/*Set operations' functions declarations are in it*/

/*Declaration of functions*/

int read_data(FILE *fp, int set[MAX]);/*Reads the data from file to a set*/
void print_data(int set[MAX], int nitems);/*Prints the data stored in the set.*/
int read_files(int set[MAX]);/*Opens the files & uses the above two functions*/

FILE *fp = NULL; /*File pointer*/

/*Main function starts here*/
int main()
{
/*Declaration of vriables*/
  int choice, element; 
  int setA[MAX], NA;
  int setB[MAX], NB;
  int NC;
  
  /*Initialization*/
  NA = 0;
  NB = 0;
  NC = 0;

  /*MENU*/
  printf("What operation you want to do: \n");
  printf("\x1b[33m 1.Union\x1b[0m of two sets.\n");
  printf("\x1b[33m 2.Intersection\x1b[0m of two sets.\n");
  printf("\x1b[33m 3.Difference\x1b[0m of two sets.\n");
  printf("\x1b[33m 4.Membership\x1b[0m of an element in a set\n");
  printf("\x1b[33m 5.Work with subsets.\x1b[0m\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  printf("\n");

  switch (choice)
  {
      case 1  : printf("---UNION---\n");
                NA = read_files(setA); 
                NB = read_files(setB);
                set_union(setA, NA, setB, NB, NC);/*Calling union function*/
                break;

      case 2  : printf("---INTERSECTION---\n");
                NA = read_files(setA);
                NB = read_files(setB);
                set_intersection(setA, NA, setB, NB, NC);/*Calling Intersection function*/
                break;

      case 3  : printf("---DIFFERENCE\n---");
                NA = read_files(setA);
                NB = read_files(setB);
                set_diff(setA, NA, setB, NB, NC);/*Calling diffence function*/
                break;

      case 4  : printf("---MEMBERSHIP---\n");
                NA = read_files(setA);
                printf("Enter an element to search: ");
                scanf("%d", &element);
                set_mem(setA, NA, element);/*Calling membership function*/
                break;

      case 5  : printf("---SUBSET---\n");
                NA = read_files(setA);
                NB = read_files(setB);
                sub_set(setA, NA, setB, NB);/*Calling subset function*/
                break;

      default : printf("\x1b[31mINVALID CHOICE\x1b[0m\n");
                break;
  }
  exit (0);
}

/*Read_data function*/
int read_data(FILE *fp, int set[MAX])
{
/*Declaration of variables*/
  int i;
  i = 0;/*Initialization*/

  while (fscanf(fp, "%d", &set[i]) != EOF)
  {
      i++;
  }
  return i;

}

/*Print data function starts here*/
void print_data(int set[MAX], int nitems)
{
/*Declaration of variables*/
  int i;
  
  if (nitems == 0)
  {
      printf("{ }\n");
      return;
  }

  printf("{");
  for (i = 0; i < nitems; i++)
  {
      printf("%d, ", set[i]);
  }
  printf("\b\b}\n");
  return;
}

/*Read_files function starts here*/
int read_files(int set[MAX])
{
/*Declaration of variables*/
  char filename[MAX];
  int N;
 
  printf("Enter a filename: ");
  scanf("%s", filename);
  printf("\n");

  fp = fopen(filename, "r");/*Opening file*/

  if (fp == NULL)
  {
      printf("\a\x1b[31mError opening file %s\x1b[0m\n", filename);
      exit (0);
  }

  N = read_data(fp, set);/*Calling read_data function*/

  if (N > MAX)
  {
      printf("Integer limit exceeded.\n");
      exit (0);
  }

  printf("It contains the set: \n");
  print_data(set, N);

  printf("Number of elements: %d\n", N);
  printf("\n");
  fclose (fp);

  return N;
 
 }


