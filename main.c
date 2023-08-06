#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *login;
    FILE *password;
    FILE *bank_balance;


    char r;
    char nowy_login[20];
    char nowe_haslo[20];
    float kwota_do_wyplaty;
    float kwota_do_wplaty;
    char haslo_z_klawiatury[20];
    char haslo_z_pliku[20];
    char login_z_klawiatury[20];
    char login_z_pliku[20];
    char saldo_aktulane_z_pliku[20];
    float saldo_aktulane_z_pliku_float;
    float saldo_zaktulizowane;
    char saldo_po_konwersji[20];
    char aktualne_saldo[20];

    login = fopen("login.txt", "r");
    fgets(login_z_pliku,20,login);

    password = fopen("password.txt", "r");
    fgets(haslo_z_pliku,20,password);


    printf("Enter login\n");
    scanf("%s",&login_z_klawiatury);


    printf("Enter your password\n");
    scanf("%s",&haslo_z_klawiatury);



    if( strcmp (login_z_pliku,login_z_klawiatury) == 0 && strcmp (haslo_z_pliku,haslo_z_klawiatury) == 0)
    {
        printf("Logged in\n\n");
    }
    else
    {
        printf("Wrong password or login\n\n");
        return;
    }

    fclose(login);
    fclose(password);

    printf("|----------------------------------|\n");
    printf("|1.Deposit money                 |\n");
    printf("|2.Withdraw money                |\n");
    printf("|3.Current balance                  |\n");
    printf("|4.Change login                     |\n");
    printf("|5.Change password                     |\n");
    printf("|6.Log out                     |\n");
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

        break;

        case'3':

        bank_balance = fopen("bank_balance.txt", "r");

        fgets(aktualne_saldo,20,bank_balance);

        printf("Current balance %s\n",aktualne_saldo);

        fclose(bank_balance);

        break;

        case'4':

        login = fopen("login.txt", "w");

        printf("Enter a new login\n");
        scanf("%s",&nowy_login);

        fprintf(login,"%s",nowy_login);

        puts("");

        printf("Login has been changed\n");

        fclose(login);

        break;

        case'5':

        password = fopen("password.txt", "w");

        printf("Enter a new password\n");
        scanf("%s",&nowe_haslo);

        fprintf(password,"%s",nowe_haslo);

        puts("");

        printf("Password has been changed\n");

        fclose(password);

        break;

        case'6':

        puts("");

        printf("You have been logged out\n");

        return;

        break;
    }



    return 0;
}
