#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

class ATM 
{
    private:
        int accountNO;
        double balance;
        string name;
        int password;
        string mobileNumber;

    public:   
    //Constructor
        ATM(int accountNo_set = 0, double balance_set=0, string name_set="NULL", int password_set=0, string mobileNumber_set="NULL") 
        {
            accountNO = accountNo_set; balance = balance_set; name = name_set; password = password_set; mobileNumber = mobileNumber_set;
        }

    //GetData
        int getAccountNO(){return accountNO;}
        double getBalance (){return balance;}
        string getName (){return name;}
        int getPassword (){return password;}
        string getMobileNumber (){return mobileNumber;}

    //check balance, withdraw money, modify mobile number, add money, user details
        void checkBalance ()
        {
            cout << "tu balance es: " << balance;
            _getch();
        }

        void withdrawMoney ()
        {
            double money_withdraw;
            cout << "Cuanto dinero deseas retirar?: "; cin >> money_withdraw;
            if (money_withdraw>0 && balance >= money_withdraw)
            {
                balance -= money_withdraw;
                cout << "Retiro exitoso" << endl;
                cout << "Tu nuevo balance es: " << balance << endl;
            } else 
            {
                cout<< "Monto erroneo, vuelve a intentar" << endl;
            }
            
        }

        void modifyNumber ()
        {
            string prevNumber,newNumber;
            cout << "Ingrese el numero antiguo: "; cin >> prevNumber;
            if (mobileNumber == prevNumber) 
            { 
                cout << "Ingrese el numero nuevo: ";
                cin>> newNumber;
                mobileNumber=newNumber;
                cout << "Actualizacion de datos exitosa" << endl;
            } else 
            {
                cout << "El numero antiguo es incorrecto";
            }
        }
        void admin ();
        void addMoney ()
        {
            double addmoney;
            cout << "Cuanto dinero deseas depositar?: "; cin >> addmoney;
             if (addmoney>0)
            {
                balance += addmoney; 
                cout << "deposito exitoso" << endl;
                cout << "Tu nuevo balance es: " << balance << endl;
            } else 
            {
                cout<< "Monto erroneo, vuelve a intentar" << endl;
            }
            
        }

        virtual void userDetails() 
        {
            cout << endl << "nombre: " << name;
            cout << endl << "Numero de Telefono: " << mobileNumber;
            cout << endl << "Numero de cuenta: " << accountNO;
            cout << endl << "Contrasena: " << password;
            _getch();
            system("cls");
        }

    void interface()
    {
        int opcion;
        bool pass=0;
        while (pass != 1)
        {
        cout << "*****SISTEMA BANCARIO*****" << endl;
        cout << "1. Ver balance" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Ingresar dinero" << endl;
        cout << "4. Modificar numero" << endl;
        cout << "5. Detalles de usuario" << endl;
        cout << "6. Opciones de Administrador" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        
        switch (opcion)
        {
        case 0:
            cout << "chao we";
            pass = 1;
            break;
        case 1:
            checkBalance ();
            _getch();
            system("cls");
            break;
        case 2:
            withdrawMoney();
            _getch();
            system("cls");
            break;
        case 3:
            addMoney ();
            _getch();
            system("cls");
            break;
        case 4:
            modifyNumber ();
            _getch();
            system("cls");
            break;
        case 5:
            userDetails();
            _getch();
            system("cls");
            break;
        case 6:
            admin();
            _getch();
            system("cls");
        default:
            cout << "Opcion invalida";
            _getch();
            system("cls");
            break;
            }
        }
    }
        
};

class banesco: public ATM
{
    private:
        string securityQa;
        string cedula;
        string rol;
    public:
          banesco(int accountNo_set = 0, double balance_set = 0, string name_set = "NULL", int password_set = 0, string mobileNumber_set = "NULL", 
          string securityQa_set = "NULL", string cedula_set = "NULL", string rol_set="NULL"):
          ATM(accountNo_set, balance_set, name_set, password_set, mobileNumber_set), securityQa(securityQa_set), cedula(cedula_set), rol(rol_set) {}

        void userDetails() override
        {
            cout << endl << "nombre: " << getName();
            cout << endl << "Numero de Telefono: " << getMobileNumber();
            cout << endl << "Cedula: " << cedula;
            cout << endl << "Rol: " << rol;
            cout << endl << "Numero de cuenta: " << getAccountNO();
            cout << endl << "Contrasena: " << getPassword();
            
        }

        void admin ()
        {
        int opcion;
        bool pass=0;
        while (pass != 1)
        {
        cout << "*****Panel de Administrador*****" << endl;
        cout << "1. Crear Usuario" << endl;
        cout << "2. Buscar Usuario" << endl;
        cout << "3. Borrar Usuario" << endl;
        cout << "4. Lista de Usuarios" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        
        switch (opcion)
        {
        case 0:
            cout << "chao we";
            pass = 1;
            break;
        case 1:
            checkBalance ();
            _getch();
            system("cls");
            break;
        case 2:
            withdrawMoney();
            _getch();
            system("cls");
            break;
        case 3:
            addMoney ();
            _getch();
            system("cls");
            break;
        case 4:
            modifyNumber ();
            _getch();
            system("cls");
            break;
        case 5:
            userDetails();
            _getch();
            system("cls");
            break;
        case 6:
            admin();
            _getch();
            system("cls");
        default:
            cout << "Opcion invalida";
            _getch();
            system("cls");
            break;
            }
        }
        }
        string getSecurityQa(){return securityQa;}
};

class userManagment : public banesco
{
    //datos
    private:
        vector<banesco> Usuarios;
    //metodos
    //crear usuario en vector, buscar, borrar y lista
    public:
        
        void newUser()
        {
            srand(time(0));
            int accountNo_set = 900000 + rand() % 100000; // Genera un número de cuenta aleatorio de 6 dígitos
            double balance_set;
            string name_set, mobileNumber_set, securityQa_set, cedula_set, rol_set;
            int password_set;

            cout << "Nombre: ";
            cin >> name_set;
            cout << "Cedula: ";
            cin >> cedula_set;
            cout << "Rol: ";
            cin >> rol_set;
            cout << "Balance: ";
            cin >> balance_set;
            cout << "Contrasena: ";
            cin >> password_set;
            cout << "Numero de Telefono: ";
            cin >> mobileNumber_set;
            cout << "Pregunta de seguridad: ";
            cin >> securityQa_set;

            banesco usernames(accountNo_set, balance_set, name_set, password_set, mobileNumber_set, securityQa_set, cedula_set, rol_set);
            Usuarios.push_back(usernames);
            cout << "Usuario creado con éxito. Numero de Cuenta: " << accountNo_set << endl;
            
        } 

        void listUsers()
        {
            for (int i = 0; i < Usuarios.size(); i++)
            {
                cout << Usuarios[i].getName() << endl;
            }
            
        }

        void loginUsers()
        {
            bool pass=0;
            int account_log, pass_log;
            string security_log;
            while (pass==0) 
            {
                cout << "Ingresa tu numero de cuenta: "<<endl;
                cin >> account_log;
                cout << "Ingresa tu contrasena: " << endl;
                cin >> pass_log;
                cout << "Ingresa la pregunta de seguridad: " << endl;
                cin >> security_log;
                cin.clear(); cin.ignore();

                for (int i = 0; i < Usuarios.size(); i++)
                {
                if (account_log==Usuarios[i].getAccountNO() && pass_log==Usuarios[i].getPassword() && security_log==Usuarios[i].getSecurityQa())
                {
                    pass = 1;
                    system("cls");
                    interface();
                } else 
                {
                    pass = 0;
                    cout << "Numero de cuenta y/o contrasena incorrectas"<< endl;
                    _getch();
                    system("cls");
                }
                }  
            }
        }


}; 