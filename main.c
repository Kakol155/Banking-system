#include <stdio.h>
#include <stdlib.h>

int main()
{


    FILE *bank_balance;


    char r;

    float kwota_do_wyplaty;
    float kwota_do_wplaty;
    char saldo_aktulane_z_pliku[20];
    float saldo_aktulane_z_pliku_float;
    float saldo_zaktulizowane;
    char saldo_po_konwersji[20];
    char aktualne_saldo[20];
    char informacje_z_pliku[20];

    bank_balance = fopen("bank_balance.txt","r");

    fgets(informacje_z_pliku,20,bank_balance);

    fclose(bank_balance);

    bank_balance = fopen("bank_balance.txt","w");

    fprintf(bank_balance,"%s",informacje_z_pliku);

    fclose(bank_balance);

    printf("|----------------------------------|\n");
    printf("|1.Top up your account             |\n");
    printf("|2.Withdraw money                  |\n");
    printf("|3.Current balance                 |\n");
    printf("|4.Exit                            |\n");
    printf("|----------------------------------|\n");

    printf("Give me the number \n");
    scanf("%s",&r);

    switch(r)
    {
        case '1':

        bank_balance = fopen("bank_balance.txt", "r");

        printf("Enter the amount you want to top up your account with \n");
        scanf("%f",&kwota_do_wplaty);

        printf("You recharged %f \n",kwota_do_wplaty);

        fgets(saldo_aktulane_z_pliku,20,bank_balance);

        sscanf(saldo_aktulane_z_pliku,"%f", &saldo_aktulane_z_pliku_float);

        saldo_zaktulizowane = saldo_aktulane_z_pliku_float + kwota_do_wplaty;

        gcvt(saldo_zaktulizowane,6,saldo_po_konwersji);
        fclose(bank_balance);

        bank_balance = fopen("bank_balance.txt", "w");

        fprintf(bank_balance,"%s",saldo_po_konwersji);

        fclose(bank_balance);

        bank_balance = fopen("bank_balance.txt","r");

        fgets(aktualne_saldo,20,bank_balance);

        printf("Current balance %s\n\n",aktualne_saldo);

        fclose(bank_balance);

        break;

        case '2':

        bank_balance = fopen("bank_balance.txt", "r");

        printf("Enter the amount you want to withdraw \n");
        scanf("%f",&kwota_do_wyplaty);

        printf("You have withdrawn the amount %f \n",kwota_do_wyplaty);

        fgets(saldo_aktulane_z_pliku,20,bank_balance);

        sscanf(saldo_aktulane_z_pliku,"%f", &saldo_aktulane_z_pliku_float);

        saldo_zaktulizowane =  saldo_aktulane_z_pliku_float - kwota_do_wyplaty;

        gcvt(saldo_zaktulizowane,6,saldo_po_konwersji);
        fclose(bank_balance);

        bank_balance = fopen("bank_balance.txt", "w");

        fprintf(bank_balance,"%s",saldo_po_konwersji);

        fclose(bank_balance);

        bank_balance = fopen("bank_balance.txt","r");

        fgets(aktualne_saldo,20,bank_balance);

        printf("Current balance %s\n\n",aktualne_saldo);

        fclose(bank_balance);

        break;

        case'3':

        bank_balance = fopen("bank_balance.txt", "r");

        fgets(aktualne_saldo,20,bank_balance);

        printf("Current balance %s\n",aktualne_saldo);

        fclose(bank_balance);

        break;


        case'4':

        puts("");

        printf("You have been logged out\n");

        return;

        break;
    }



    return 0;
}
