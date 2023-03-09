// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(int customer, float bill, float tax, int tip);

int main(void)
{
    int customer = get_int("how many customer? ");
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(int customer, float bill, float tax, int tip)
{
    //calcule tax
    tax = bill * (tax / 100);

    //calcule bill + tax
    float sub_total = bill + tax;

    //calcule total de tip
    float total_tip = sub_total / 100 * tip;

    //calcul total / 2
    float total = (sub_total + total_tip) / customer;

    return total;
}
