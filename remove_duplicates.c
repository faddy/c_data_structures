#include <stdio.h>
#include <malloc.h>

/*Remove duplicate characters from a character array
*/

void print_arr(char arr[]){
    int i = 0;
    for (i=0; i<10; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void remove_nulls(char arr[]){
   int to = 0, from = 0; 
}

int main(){
    char arr[] = {'a','b','c','a','e','f','b','b','d','g'};
    int i = 0;

    print_arr(arr);

    for (i=0; i<9; i++){
        printf("%c\n", arr[i]);
        int j=0;
        if (arr[i] == '\0') continue;
        for (j=i+1; j<10; j++){
            if (arr[i] == arr[j]) {
		arr[j]='\0';
            }
        }
    }

    print_arr(arr);

    remove_nulls(arr);

    print_arr(arr);

    printf("\n");
}
