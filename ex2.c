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
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			case 1:
				//IO
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
				// print first row
				printf("%c", eyesSymbol);
				for(int i = 0; i < faceSize; i++){
					printf(" ");
				}
				printf("%c\n", eyesSymbol);
				// print middle row
				for(int i = 0; i < (faceSize + 1) / 2; i++){
					printf(" ");
				}
				printf("%c\n", noseSymbol);
				// print last row
				printf("\\");
				for(int i = 0; i < faceSize; i++){
					printf("%c", mouseSymbol);
				}
				printf("/\n");
				break;

			/* Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			and the sum of all digits to the right of the middle digit(s) are equal*/
			case 2:
				//IO
				int num1;
				printf("Enter a number:\n");
				scanf("%d", &num1);
				while(!(num1 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				int copyOfNum1 = num1;
				// calc number of digits
				int numOfDisits = 0;
				while(copyOfNum1 != 0){
					copyOfNum1 /= 10;
					numOfDisits++;
				}
				// calc sum of digits to the left of the middle digits
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
				// print result
				if(leftSum == rightSum){
					printf("This number is balanced and brings harmony!\n");
				}
				else{
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			case 3:
				// IO
				int num2;
				printf("Enter a number:\n");
				scanf("%d", &num2);
				while(!(num2 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num2);
				}
				// calc sum of proper divisors
				int sum = 0;
				for(int i = 1; i < num2; i++){
					if(num2 % i == 0){
						sum += i;
					}
				}
				// print result
				if(sum > num2){
					printf("This number is generous!\n");
				}
				else{
					printf("This number does not share.\n");
				}
				break;
			
			//Case 4: determine wether a number and his reverse are prime.
			case 4:
				// IO
				int num3;
				printf("Enter a number:\n");
				scanf("%d", &num3);
				while(!(num3 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num3);
				}
				// calc reverse of num3
				int copyOfNum3 = num3;
				int num3Reverse = 0;
				while(copyOfNum3 != 0){
					num3Reverse = num3Reverse * 10 + copyOfNum3 % 10;
					copyOfNum3 /= 10;
				}
				// calc primality of num3 and num3Reverse
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
				// print result
				if(isNum3Prime && isNum3ReversePrime){
					printf("This number completes the circle of joy!\n");
				}
				else{
					printf("The circle remains incomplete.\n");
				}
				break;

			// Case 5: Print all the happy numbers between 1 to the given number.
			case 5:
				// IO
				int num4;
				printf("Enter a number:\n");
				scanf("%d", &num4);
				while(!(num4 > 0)){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num4);
				}
				// calc happy numbers
				printf("Between 1 and %d only these numbers bring happiness: ", num4);
				int newNum, copyOfNum4;
				for(int i = 1; i <= num4; i++){
					newNum = i;
					while(!(newNum == 1 || newNum == 4)){
						copyOfNum4 = newNum;
						newNum = 0;
						while(copyOfNum4 != 0){
							newNum += (copyOfNum4 % 10) * (copyOfNum4 % 10);
							copyOfNum4 /= 10;
						}
					}
					if(newNum == 1){
						printf("%d ", i);
					}
				}
				printf("\n");
				break;

			/* Case 6: prints all the numbers between 1 the given number:
			and replace with "Smile!" every number that divided by the given smile number
			and replace with "Cheer!" every number that divided by the given cheer number
			and replace with "Festival!" every number that divided by both of them */
			case 6:
				// IO
				int smileNumber, cheerNumber;
				printf("Enter a smile and cheer number:\n");
				int numberOfInputs = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber);
				if (numberOfInputs != 2){
					smileNumber = 0;
					cheerNumber = -1;
				}
				scanf("%*c");	
				while(numberOfInputs != 2 && smileNumber <= 0 && cheerNumber <= 0 && smileNumber != cheerNumber){
					scanf("%*[^\n]");
					scanf("%*c");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					numberOfInputs = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber);
					if (numberOfInputs != 2){
						smileNumber = 0;
						cheerNumber = -1;
					}
				}
				// calc result
				int max;
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while(max <= 0){
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &max);
				}
				for(int i = 1; i <= max; i++){
					if(i % smileNumber == 0 && i % cheerNumber == 0){
						printf("Festival!\n");
					}
					else if(i % smileNumber == 0){
						printf("Smile!\n");
					}
					else if(i % cheerNumber == 0){
						printf("Cheer!\n");
					}
					else{
						printf("%d\n", i);
					}
				}
				break;

			// Case 7: Exit
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
