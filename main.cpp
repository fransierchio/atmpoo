#include "system.hpp"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "en_US.utf8");
    Users userDatabase;
    userDatabase.loadUsersFromFile();
    
    int accountNO;
    string password, question;
    int option = -1;

    while (option < 0) 
    {
        system("cls");
        cout << "Ingresa tu numero de cuenta: "; cin >> accountNO;
        cout << "Ingresa tu contrasena: "; cin >> password;
        cout << "Ingresa la respuesta a tu pregunta de seguridad: "; cin >> question;

        option = userDatabase.authy(accountNO, password, question);
        if (option == 1) 
        {
            // Admin user
            int choice;
            while (true) 
            {

                cout << "1. Crear nuevo usuario" << endl;
                cout << "2. Modificar usuario" << endl;
                cout << "3. Lista de usuarios" << endl;
                cout << "4. Borrar usuario" << endl;
                cout << "0. Salir" << endl;
                cout << "Selecciona una opcion: "; cin >> choice;

                switch (choice) 
                {
                    case 1:
                        userDatabase.newUser();
                        _getch();
                        system("cls");
                        break;
                    case 2:
                        userDatabase.modifyUser();
                        _getch();
                        system("cls");
                        break;
                    case 3:
                        userDatabase.listUser();
                        _getch();
                        system("cls");
                        break;
                    case 4:
                        userDatabase.deleteUser();
                        _getch();
                        system("cls");
                        break;
                    case 0:
                        return 0;
                    default:
                        cout << "Opción no válida, intenta de nuevo." << endl;
                        _getch();
                        system("cls");
                        break;
                }
            }
        } 
        /**else if (option == 2) 
        {
            int choice;
            while (true) 
            {
                system("cls");
                cout << "*****SISTEMA BANCARIO*****" << endl;
                cout << "1. Ver balance" << endl;
                cout << "2. Retirar dinero" << endl;
                cout << "3. Ingresar dinero" << endl;
                cout << "4. Modificar numero" << endl;
                cout << "5. Detalles de usuario" << endl;
                cout << "0. Salir" << endl;
                cout << "Selecciona una opción: "; cin >> choice;

                switch (choice) 
                {
                    case 0:
                        cout << "Adiós" << endl;
                        return 0;
                    case 1:
                        userInterface.userMenu.checkBalance();
                        break;
                    case 2:
                        userInterface.userMenu.withdrawMoney();
                        break;
                    case 3:
                        userInterface.userMenu.addMoney();
                        break;
                    case 4:
                        userInterface.userMenu.modifyNumber();
                        break;
                    case 5:
                        userInterface.userMenu.userDetails();
                        break;
                    default:
                        cout << "Opción inválida" << endl;
                        break;
                }
            }
        } **/
        else 
        {
            cout << "Datos incorrectos, vuelve a intentar" << endl;
            _getch();
            system("cls");
        }
    }

    return 0;
}
