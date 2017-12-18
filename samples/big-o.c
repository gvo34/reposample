/**
Find the big-O running time of a sorting program that does the following:

It takes in a list of integers

It iterates once through the list to find the largest element, and moves that element to the end

It repeatedly finds the largest element in the unsorted portion by iterating once through, and moves that element to the end of the unsorted portion

At the end, the list is sorted low to high.

(Also, try implementing this program in your language of choice)

O(n^2)
O(nlogn)
O(n)
O(1)
 **/


#include <stdio.h>
#include <stdlib.h>

const int mylimit=10;

int mylargestindex(int *a, int end_x);
int pushtotheback(int *a, int l, int end_x);
void print_array(char *header, int *array, int end);
void sort(int *array, int e_last);

int main(int argc, char** argv){

  if(argc==1){
    printf("Need a number, repeat\n");
  }
  else {
    int k=1;
    int array[mylimit]={-1,-1,-1}; // ,-1,-1,-1,-1,-1,-1,-1};

    while (argv[k]!=NULL && k<=mylimit) {
       array[k-1] = atoi(argv[k]);
       k++;
    }

    if (k>=mylimit+1) {
      printf("overflowed array at my limit (%d) with %d\n", mylimit, k);
	}
    else {
      int last = k-1;
      print_array("My original array is ", array,last);
      sort(array, last);
    }
  }

  return 0;
}

int mylargestindex(int *arrayin, int end_x){
  /* get the index for the largest integer of teh array */
  int largest=0;
  int i=1;
  while (i<end_x){
    if (arrayin[i]>arrayin[largest]) {
      /* got a new largest*/
      largest = i;
    }
    i++;
  }
  return largest;
}


int pushtotheback(int *a, int l, int end_x){
  /* swap element l and element from the end of the array */
  int temp = a[end_x-1];

  /*printf("swap index %d=array(%d) and %d=array (%d)\n", a[l], l, a[end_x-1], end_x-1);
   */

  a[end_x-1] = a[l];
  a[l] = temp;

  return end_x-1; // new end
}

void sort(int *array, int e_last) {

  int largest;
  int last = e_last;

  while (last >0) {
    largest = mylargestindex(array, last);
    /*printf(" My largest value is %d, at index %d\n", array[largest],largest);*/
    last = pushtotheback(array, largest, last);
    /* print_array("new array is ", array, last);*/
  }
  print_array("Sorted array is ", array, e_last);


}

void print_array(char *header, int *array, int end) {
  printf("%s<", header);
      for (int j=0;j<end;j++) printf("%d ",array[j]);
      printf(">\n");
}



