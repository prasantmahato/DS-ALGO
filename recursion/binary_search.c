#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define ul unsigned long int 

ul binary_search(ul arr[],ul low,ul size, ul key)
{
    if(low<=size)
    {
        ul mid = low + (size-low)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key)
            return binary_search(arr,low,mid-1,key);
        return binary_search(arr,mid+1,size,key);
    }
    return -1;
}

void display(ul arr[], ul size){
	for(ul i=0; i<size; i++)
		printf("%lu\n",arr[i]);
	printf("\n");
}

int main()
{
	ul arr[] = {1,2,3,4,5,6,7,8,9,10};
	FILE *fp = fopen("random.txt","r");
	
	if(fp == NULL){
		printf("Error Opening file\n");
		exit(EXIT_FAILURE);
	}
	char num[10];
	
	// Read from the file
	ul data[1000000],i=0;
	while(fgets(num,10,fp) != NULL){
		//printf("%s",num);
		data[i] = atoi(num);
		i++;
	}

	fclose(fp);
	
    ul size = sizeof(data)/sizeof(ul);
    ul key = 1;
	display(data,size);
    printf("Enter key to search: ");
    scanf("%lu",&key);
    ul pos = binary_search(data,0,size,key);
    printf("Pos: %lu\n",pos+1);
    return 0;
}
