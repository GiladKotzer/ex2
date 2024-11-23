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
				int num1;
				printf("Enter a number:\n");
				scanf("%d", &num1);
				while(!(num1 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				int copy1 = num1;
				int numOfDisits = 0;
				while(copy1 != 0){
					copy1 /= 10;
					numOfDisits++;
				}
				int rightSum = 0, leftSum = 0;
				for(int i = 0; i < numOfDisits; i++){
					if(i < numOfDisits / 2){
						rightSum += num1 % 10;
					}
					if(i > numOfDisits / 2 || (i == numOfDisits / 2 && numOfDisits % 2 == 0)){
						leftSum += num1 % 10;
					}
					num1 /= 10; 
				}
				if(leftSum == rightSum){
					printf("This number is balanced and brings harmony!\n");
				}
				else{
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			
			case 3:
				int num2;
				printf("Enter a number:\n");
				scanf("%d", &num2);
				while(!(num2 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num2);
				}
				int sum = 0;
				for(int i = 1; i < num2; i++){
					if(num2 % i == 0){
						sum += i;
					}
				}
				if(sum > num2){
					printf("This number is generous!\n");
				}
				else{
					printf("This number does not share.\n");
				}
				break;
			
			case 4:
				int num3;
				printf("Enter a number:\n");
				scanf("%d", &num3);
				while(!(num3 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num3);
				}
				int copy2 = num3;
				int num3Reverse = 0;
				while(copy2 != 0){
					num3Reverse = num3Reverse * 10 + copy2 % 10;
					copy2 /= 10;
				}
				int isNum3Prime = 1, isNum3ReversePrime = 1;
				if(num3 == 1){
					isNum3Prime = 0;
				}
				for(int i=2; i < num3; i++){
					if(num3 % i == 0){
						isNum3Prime = 0;
						break;
					}
				}
				for(int i=2; i < num3Reverse; i++){
					if(num3Reverse % i == 0){
						isNum3ReversePrime = 0;
						break;
					}
				}
				if(isNum3Prime && isNum3ReversePrime){
					printf("This number completes the circle of joy!\n");
				}
				else{
					printf("The circle remains incomplete.\n");
				}
				break;

			case 5:
			int num4;
			printf("Enter a number:\n");
			scanf("%d", &num4);
			while(!(num4 > 0)){
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num4);
			}
			printf("Between 1 and %d only these numbers bring happiness: ", num4);
			int newNum, copy3;
			for(int i = 1; i <= num4; i++){
				newNum = i;
				while(!(newNum == 1 || newNum == 4)){
					copy3 = newNum;
					newNum = 0;
					while(copy3 != 0){
						newNum += (copy3 % 10) * (copy3 % 10);
						copy3 /= 10;
					}
				}
				if(newNum == 1){
					printf("%d ", i);
				}
			}
			printf("\n");
			break;

			case 6:
				
				break;

			case 7:
				printf("Thank you for your journey through Numeria!\n");
				isFinish = 1;
				break;

			default:
				printf("This option is not available, please try again.\n");
				break;
		}
	} while(!isFinish);
	return 0;
}
