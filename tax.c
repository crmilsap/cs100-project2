/* Cory Milsap
 * First the program asks for the user to enter a proper filing statement.
 * Then using a multitude of if statements, the program corectly chooses the formula that results in the correct tax amount.
 * The program then prints the estimated tax and loops again until 0 is entered as a filing status.
*/
#include <stdio.h>

int main(void) {

    int filingStatus = 10;
    double taxableIncome = 0;
    double estimatedTax = 0;

    while (filingStatus != 0) {

        do {
            printf("Enter an integer that responds to your proper filing status.\n");
            printf("1). Single\n2). Married filing jointly\n3). Married filing separately\n4). Head of household\n5). Qualifying window(er)\n");
            printf("Enter an integer 1-5 or 0 to end: ");
            scanf("%d", &filingStatus);
            if (filingStatus == 0)
                break;
        } while (filingStatus < 1 || filingStatus > 5); 

        if (filingStatus != 0) {
            printf("What is your estimated taxable income? \n");
            scanf("%lf", &taxableIncome);
        }
        if (taxableIncome < 0) {
            printf("Error: Changing taxable income to 0\n");
            taxableIncome = 0;
        }

        if (filingStatus == 1) {
            if (taxableIncome < 9525)
                estimatedTax = taxableIncome * 0.10;
            else if (taxableIncome < 38700)
                estimatedTax = ((taxableIncome - 9525) * 0.12) + 952.5;
            else if (taxableIncome < 82500)
                estimatedTax = ((taxableIncome - 38700) * 0.22) + 4453.5;
            else if (taxableIncome < 157500)
                estimatedTax = ((taxableIncome - 82500) * 0.24) + 14089.5;
            else if (taxableIncome < 200000)
                estimatedTax = ((taxableIncome - 157500) * 0.32) + 32089.5;
            else if (taxableIncome < 500000)
                estimatedTax = ((taxableIncome - 200000) * 0.35) + 45689.5;
            else if (taxableIncome >= 500000)
                estimatedTax = ((taxableIncome - 500000) * 0.37) + 150689;
        }
        else if (filingStatus == 2 || filingStatus == 5) {
            if (taxableIncome < 19050)
                estimatedTax = taxableIncome * 0.10;
            else if (taxableIncome < 77400)
                estimatedTax = 1905 + ((taxableIncome - 19050) * 0.12);
            else if (taxableIncome < 165000)
                estimatedTax = 8907 + ((taxableIncome - 77400) * 0.22);
            else if (taxableIncome < 315000)
                estimatedTax = 28179 + ((taxableIncome - 165000) * 0.24);
            else if (taxableIncome < 400000)
                estimatedTax = 64179 + ((taxableIncome - 315000) * 0.32);
            else if (taxableIncome < 600000)
                estimatedTax = 91379 + ((taxableIncome - 400000) * 0.35);
            else if (taxableIncome >= 600000)
                estimatedTax = 161379 + ((taxableIncome - 600000) * 0.37);
        }
        else if (filingStatus == 3) {
            if (taxableIncome < 9525)
                estimatedTax = taxableIncome * 0.10;
            else if (taxableIncome < 38700)
                estimatedTax = 952.5 + ((taxableIncome - 9525) * 0.12);
            else if (taxableIncome < 82500)
                estimatedTax = 4453.5 + ((taxableIncome - 38700) * 0.22);
            else if (taxableIncome < 157500)
                estimatedTax = 14089.5 + ((taxableIncome - 82500) * 0.24);
            else if (taxableIncome < 200000)
                estimatedTax = 32089.5 + ((taxableIncome - 157500) * 0.32);
            else if (taxableIncome < 300000)
                estimatedTax = 45689.5 + ((taxableIncome - 200000) * 0.35);
            else if (taxableIncome >= 300000)
                estimatedTax = 80689.5 + ((taxableIncome - 300000) * 0.37);
        }
        else if (filingStatus == 4) {
            if (taxableIncome < 13600)
                estimatedTax = taxableIncome * 0.10;
            else if (taxableIncome < 51800)
                estimatedTax = 1360 + ((taxableIncome - 13600) * 0.12);
            else if (taxableIncome < 82500)
                estimatedTax = 5944 + ((taxableIncome - 51800) * 0.22);
            else if (taxableIncome < 157500)
                estimatedTax = 12698 + ((taxableIncome - 82500) * 0.24);
            else if (taxableIncome < 200000)
                estimatedTax = 30698 + ((taxableIncome - 157500) * 0.32);
            else if (taxableIncome < 500000)
                estimatedTax = 44298 + ((taxableIncome - 200000) * 0.35);
            else if (taxableIncome >= 500000)
                estimatedTax = 149298 + ((taxableIncome - 500000) * 0.37);
        }
        if (filingStatus != 0)
            printf("Estimated tax: $%.2f\n", estimatedTax);
        else if (filingStatus == 0)
            printf("Goodbye.\n");

    }
    return 0;
}
