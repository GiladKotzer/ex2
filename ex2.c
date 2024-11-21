/******************
Name: Gilad Kotzer
ID: 331753509
Assignment: ex2
*******************/

#include <stdio.h>
int main(){
	int isFinish = 0;
	do{
		printf("Choose an option:\
			\n\t1. Happy Face\
			\n\t2. Balanced Number\
			\n\t3. Generous Number\
			\n\t4. Circle Of Joy\
			\n\t5. Happy Numbers\
			\n\t6. Festival Of Laughter\
			\n\t7. Exit\n");

		int option;
		scanf("%d", &option);

		switch(option){
			case 1:
				char eyesSymbol, noseSymbol, mouseSymbol;
				printf("Enter symbols for the eyes, nose, and mouse:\n");
				scanf(" %c %c %c", &eyesSymbol, &noseSymbol, &mouseSymbol);
				int faceSize;
				printf("Enter the size of the face:\n");
				scanf("%d", &faceSize);
				while(!(faceSize > 0 && faceSize % 2 == 1)){
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				printf("%c", eyesSymbol);
				for(int i = 0; i < faceSize; i++){
					printf(" ");
				}
				printf("%c\n", eyesSymbol);

				for(int i = 0; i < (faceSize + 1) / 2; i++){
					printf(" ");
				}
				printf("%c\n", noseSymbol);

				printf("\\");
				for(int i = 0; i < faceSize; i++){
					printf("%c", mouseSymbol);
				}
				printf("/\n");
				break;

			case 2:
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(!(num > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int cupy = num;
				int numOfDisits = 0;
				while(cupy != 0){
					cupy /= 10;
					numOfDisits++;
				}
				int rightSum = 0, leftSum = 0;
				for(int i = 0; i < numOfDisits; i++){
					if(i < numOfDisits / 2){
						rightSum += num % 10;
					}
					if(i > numOfDisits / 2 || (i == numOfDisits / 2 && numOfDisits % 2 == 0)){
						leftSum += num % 10;
					}
					num /= 10; 
				}
				if(leftSum == rightSum){
					printf("This number is balanced and brings harmony!\n");
				}
				else{
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;

			case 7:
				printf("Thank you for your journey through Numeria!\n");
				isFinish = 1;
				break;;

			default:
				printf("This option is not available, please try again.\n");
				break;
		}
	} while(!isFinish);
	return 0;
}
