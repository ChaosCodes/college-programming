 #include <stdio.h>

int book[9];
int cases;
int num1[9];
void print_num();
void out_sort(int num, int count);

int main (){
	scanf("%d", &cases);
	for(int i = 1; i <= cases; ++i){
		book[i] = 1;
		out_sort(i,1);
		book[i] = 0;
    }
}


void out_sort(int num,int count){
	num1[count] = num;
	for(int m = 1; m <= cases; ++m){
		if(book[m] == 0){
			book[m] = 1;
			out_sort(m,count + 1);
			book[m] = 0;
		}
	}
	if(count == cases)
      print_num();
}


void print_num(){
	printf("%d", num1[1]);
	for(int i = 2; i <= cases; ++i)
		printf(" %d", num1[i]);
	printf("\n");
}
