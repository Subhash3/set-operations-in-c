#include <stdio.h>
#include <stdlib.h>

/*All constant declarations*/
#define MAX    32

/*Function Declarations*/
void print_data(int set[], int nitems);

/*UNION function*/
int set_union(int setA[MAX], int NA, int setB[MAX], int NB, int NC)
{
/*Declaration of variables*/
  int i, j, match, setC[MAX];
  match = 1;/*I'm taking 1 for false and 0 for true.*/
  
/*Checking if the union set is exceeding MAX*/
  if ((NA + NB) > MAX)
  {
      printf("\x1b[31mInteger limit exceeded.\x1b[0m\n"); 
      exit (1);     
  }

/*Empty set checking*/
  if (NA == 0 && NB == 0)
  {
      printf("Both are empty sets. Union of them is also an empty set.\n");
      exit (2);
  }

  NC = NA;/*Assaignment*/
 
/*Copy all the elements of setA to setC*/
  for (i = 0; i < NA; i++)
  {
      setC[i] = setA[i];
  }

/*Copying the unmatched elements*/
  for (i = 0; i < NB; i++)
  {
      for (j = 0; j < NA; j++)
      {
          if (setC[j] == setB[i])
          {
              match = 0;
              break;
          }
      }
      if (match == 1)
      {
          setC[NC] = setB[i];
          NC++;
      }
      match = 1;
  }

  printf("Union of the given sets is: \n");
  print_data(setC, NC);
  printf("Number of elements is: %d\n", NC);
  exit (3);
}

/*INTERSECTION*/
int set_intersection(int setA[MAX], int NA, int setB[MAX], int NB, int NC)
{
/*Declaration of variables*/
    int i, j ,setC[MAX];
    NC = 0;/*Initialization*/

/*Empty set checking*/
    if (NA == 0 || NB == 0)
    {
        printf("One is Empty set. Intersection is an empty set\n");
        exit (1);
    }

/*Copying matched elements*/
    for (i = 0; i < NB; i++)
    {
        for (j = 0; j < NA; j++)
        {
            if (setB[i] == setA[j])
            {
                setC[NC] = setB[i];
                NC++;
            }
        }
    }

    printf("Cardinality of Intersection set is %d\n", NC);
    printf("Elements of the Intersection set are:\n");
    print_data(setC, NC);
    return 0;
}

/*DIFFERENCE*/
int set_diff(int setA[MAX], int NA, int setB[MAX], int NB, int NC)
{
/*Declaration of variables*/
  int i, j, setC[MAX], match;
  NC = 0;/*Initialization*/
  match = 1;

/*Copying elements those are not members of setB but of setA to setC*/
  for (i = 0; i < NA; i++)
  {
      for (j = 0; j < NB; j++)
      {
          if (setA[i] == setB[j])
          {
              match = 0;
              break;
          }

      }
      if (match == 1)
      {
          setC[NC] = setA[i];
          NC++;
      }
      match = 1;
  }

  printf("Cardinality of setA - SetB is %d\n", NC);
  print_data(setC, NC);
  exit (1);
}

/*MEMBERSHIP*/
int set_mem(int setA[MAX], int NA, int element)
{
/*Declaration of variables*/
  int member, i;
  member = 1;/*I'm taking 1 for false and 0 for true*/

/*Checking the membership of the element*/
  for (i = 0; i < NA; i++)
  {
      if (setA[i] == element)
      {
          member = 0;
          break;
      }
  }

  if (member == 0)
  {
      printf("Given element is a member of given set.\n");
      exit (0);
  }
  else if (member == 1)
  {
      printf("Given element is not a member of given set.\n");
      exit (1);
  } 
  exit (0);
}

/*SUBSET*/
int sub_set(int setA[MAX], int NA, int setB[MAX], int NB)
{
/*Declaration of variables*/
  int count, i, j;
  count = 0;/*Initializing count to 0*/

/*Checking if all the elements of setB are in setA*/
  for (i = 0; i < NA; i++)
  {
      for (j = 0; j < NB; j++)
      {
          if (setB[j] == setA[i])
          {
              count++;
              break;
          }
      }
  }

  if (count == NB && count != NA)
  {
      printf("setB is a proper subset of setA.\n");
  }
  else if (count == NB)
  {
      printf("setB is not a proper subset of setA but is a subset.\n");
  }
  else 
  {
      printf("Not a subset.\n");
  }
  exit (0);
}
