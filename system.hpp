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
        string password;
        string mobileNumber;
        string securityQa;
        string cedula;
        string rol;
        vector<ATM> users;
        int currentUserIndex;

    public:   

    //Constructor
        ATM(int accountNo_set = 0, double balance_set = 0, string name_set = "NULL", string password_set = "NULL", string mobileNumber_set = "NULL", 
          string securityQa_set = "NULL", string cedula_set = "NULL", string rol_set="NULL") 
        {
            accountNO = accountNo_set; balance = balance_set; name = name_set; password = password_set; mobileNumber = mobileNumber_set;
            securityQa = securityQa_set; cedula = cedula_set; rol = rol_set; currentUserIndex = -1;
        }

    //GetData
        int getAccountNO(){return accountNO;}
        double getBalance (){return balance;}
        string getName (){return name;}
        string getPassword (){return password;}
        string getMobileNumber (){return mobileNumber;}
        string getSecurityQa(){return securityQa;}
        string getCedula(){return cedula;}
        string getRol(){return rol;}

    //Setters
        void setName(const string& newName) { name = newName; }
        void setMobileNumber(const string& newMobileNumber) { mobileNumber = newMobileNumber; }
        void setCedula(const string& newCedula) { cedula = newCedula; }
        void setRol(const string& newRol) { rol = newRol; }
        void setPassword(string newPassword) { password = newPassword; }
        void setSecurityQ(string newSecurityQ) { securityQa = newSecurityQ; }
        void setBalance(double newbalance) { balance = newbalance; }

    //check balance, withdraw money, modify mobile number, add money, user details
        void checkBalance() {
        if (currentUserIndex != -1) { // Verificar si hay un usuario autenticado
            cout << "Tu balance es: " << users[currentUserIndex].getBalance();
            _getch();
        } else {
            cout << "Debes autenticarte primero." << endl;
        }
    }

    void withdrawMoney() {
        if (currentUserIndex != -1) { // Verificar si hay un usuario autenticado
            double money_withdraw;
            cout << "Cuánto dinero deseas retirar?: "; cin >> money_withdraw;
            if (money_withdraw > 0 && users[currentUserIndex].getBalance() >= money_withdraw) {
                users[currentUserIndex].setBalance(users[currentUserIndex].getBalance() - money_withdraw);
                cout << "Retiro exitoso" << endl;
                cout << "Tu nuevo balance es: " << users[currentUserIndex].getBalance() << endl;
            } else {
                cout<< "Monto incorrecto o saldo insuficiente, vuelve a intentar" << endl;
            }
        } else {
            cout << "Debes autenticarte primero." << endl;
        }
        fstream saveuser("database.txt", ios::out | ios::trunc);
        if (saveuser.is_open()) {
            for (auto user : users) 
            {
                saveuser << user.getAccountNO() << " " << user.getName() << " " << user.getCedula() << " " << user.getRol() << " "
                << user.getBalance() << " " << user.getPassword() << " " << user.getMobileNumber() << " " << user.getSecurityQa() << endl;
            }
            saveuser.close();
            } else 
            {
                cout << "Error al abrir el archivo" << endl;
            }
    }

        void modifyNumber() {
        if (currentUserIndex != -1) { // Verificar si hay un usuario autenticado
            string prevNumber, newNumber;
            cout << "Ingrese el número antiguo: "; cin >> prevNumber;
            if (users[currentUserIndex].getMobileNumber() == prevNumber) {
                cout << "Ingrese el número nuevo: ";
                cin >> newNumber;
                users[currentUserIndex].setMobileNumber(newNumber);
                cout << "Actualización de número exitosa" << endl;
            } else {
                cout << "El número antiguo es incorrecto" << endl;
            }
        } else {
            cout << "Debes autenticarte primero." << endl;
        }
        fstream saveuser("database.txt", ios::out | ios::trunc);
        if (saveuser.is_open()) {
            for (auto user : users) 
            {
                saveuser << user.getAccountNO() << " " << user.getName() << " " << user.getCedula() << " " << user.getRol() << " "
                << user.getBalance() << " " << user.getPassword() << " " << user.getMobileNumber() << " " << user.getSecurityQa() << endl;
            }
            saveuser.close();
            } else 
            {
                cout << "Error al abrir el archivo" << endl;
            }
    }

    void addMoney() {
        if (currentUserIndex != -1) { // Verificar si hay un usuario autenticado
            double addMoney;
            cout << "Cuánto dinero deseas depositar?: "; cin >> addMoney;
            if (addMoney > 0) {
                users[currentUserIndex].setBalance(users[currentUserIndex].getBalance() + addMoney);
                cout << "Depósito exitoso" << endl;
                cout << "Tu nuevo balance es: " << users[currentUserIndex].getBalance() << endl;
            } else {
                cout << "Monto incorrecto, vuelve a intentar" << endl;
            }
        } else {
            cout << "Debes autenticarte primero." << endl;
        }
        fstream saveuser("database.txt", ios::out | ios::trunc);
        if (saveuser.is_open()) {
            for (auto user : users) 
            {
                saveuser << user.getAccountNO() << " " << user.getName() << " " << user.getCedula() << " " << user.getRol() << " "
                << user.getBalance() << " " << user.getPassword() << " " << user.getMobileNumber() << " " << user.getSecurityQa() << endl;
            }
            saveuser.close();
            } else 
            {
                cout << "Error al abrir el archivo" << endl;
            }
    }

    void userDetails() {
        if (currentUserIndex != -1) { // Verificar si hay un usuario autenticado
            cout << "Nombre: " << users[currentUserIndex].getName() << endl;
            cout << "Número de Teléfono: " << users[currentUserIndex].getMobileNumber() << endl;
            cout << "Cédula: " << users[currentUserIndex].getCedula() << endl;
            cout << "Rol: " << users[currentUserIndex].getRol() << endl;
            cout << "Número de cuenta: " << users[currentUserIndex].getAccountNO() << endl;
            // No mostrar la contraseña por razones de seguridad
        } else {
            cout << "Debes autenticarte primero." << endl;
        }
    }

    void newUser()
    {
        srand(time(0));
            int accountNo_set = 900000 + rand() % 100000; // Genera un número de cuenta aleatorio de 6 dígitos
            double balance_set;
            string name_set, mobileNumber_set, securityQa_set, cedula_set, rol_set;
            string password_set;

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

            ATM usernames(accountNo_set, balance_set, name_set, password_set, mobileNumber_set, securityQa_set, cedula_set, rol_set);
            users.push_back(usernames);
            cout << "Usuario creado con éxito. Numero de Cuenta: " << accountNo_set << endl;
            fstream saveuser("database.txt", ios::out | ios::app);
            if (saveuser.is_open())
            {
                saveuser<<accountNo_set<<" "<<name_set<<" "<<cedula_set<<" "<<rol_set<<" "<<balance_set<<" "<<password_set<<" "<<mobileNumber_set<<" "<<securityQa_set<<" "<<endl;
                saveuser.close();
            } else 
            {
                cout<<"error al abrir el archivo";
            }
    }
    void modifyUser()
    {
        int accountNO_search;
        cout << "Ingresa el Numero de Cuenta: "<<endl;
        cin >> accountNO_search;
        
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getAccountNO()==accountNO_search)
            {
                cout << "Usuario encontrado"<<endl;
                cout << endl << "nombre: " << users[i].getName();
                cout << endl << "Numero de Telefono: " << users[i].getMobileNumber();
                cout << endl << "Cedula: " << users[i].getCedula();
                cout << endl << "Rol: " << users[i].getRol();
                cout << endl << "Numero de cuenta: " << users[i].getAccountNO();
                cout << endl << "Contrasena: " << users[i].getPassword()<<endl;

                cout << "*********************"<<endl;
                cout << "Nuevos Datos"<<endl;
                double balance_set;
                string name_set, mobileNumber_set, securityQa_set, cedula_set, rol_set;
                string password_set;

                cout << "Nombre: ";
                cin >> name_set; users[i].setName(name_set);
                cout << "Cedula: ";
                cin >> cedula_set; users[i].setCedula(cedula_set);
                cout << "Rol: ";
                cin >> rol_set; users[i].setRol(rol_set);
                cout << "Contrasena: ";
                cin >> password_set; users[i].setPassword(password_set);
                cout << "Numero de Telefono: ";
                cin >> mobileNumber_set; users[i].setMobileNumber(mobileNumber_set);
                cout << "Pregunta de seguridad: ";
                cin >> securityQa_set; users[i].setSecurityQ(securityQa_set);

            fstream saveuser("database.txt", ios::out | ios::trunc);
            if (saveuser.is_open()) {
                for (auto user : users) {
                    saveuser << user.getAccountNO() << " " << user.getName() << " " << user.getCedula() << " " << user.getRol() << " "
                             << user.getBalance() << " " << user.getPassword() << " " << user.getMobileNumber() << " " << user.getSecurityQa() << endl;
                }
                saveuser.close();
            } else {
                cout << "Error al abrir el archivo" << endl;
            }
            }
        } 
    }
    void loadUsersFromFile() {
        ifstream infile("database.txt");
        if (infile.is_open()) {
            int accountNO;
            double balance;
            string name, mobileNumber, securityQa, cedula, rol;
            string password;

            while (infile >> accountNO >> name >> cedula >> rol >> balance >> password >> mobileNumber >> securityQa) {
                ATM user(accountNO, balance, name, password, mobileNumber, securityQa, cedula, rol);
                users.push_back(user);
            }
            infile.close();
        } else {
            cout << "Error al abrir el archivo" << endl;
        }
    }
    void deleteUser()
    {
        int account_delete;
        bool userfound = false;
        cout<<"Ingrese el numero de cuenta a borrar: ";
        cin >> account_delete;

        for (int i = 0; i < users.size(); i++)
        {
            if (account_delete==users[i].getAccountNO())
            {
                userfound = true;
                users.erase(users.begin()+i);
                cout<< "Usuario borrado exitosamente";
            }

        }
        if (!userfound)
        {
            cout<<"Usuario no encontrado";
        }
        
        fstream saveuser("database.txt", ios::out | ios::trunc);
        if (saveuser.is_open()) {
            for (auto user : users) 
            {
                saveuser << user.getAccountNO() << " " << user.getName() << " " << user.getCedula() << " " << user.getRol() << " "
                << user.getBalance() << " " << user.getPassword() << " " << user.getMobileNumber() << " " << user.getSecurityQa() << endl;
            }
            saveuser.close();
            } else 
            {
                cout << "Error al abrir el archivo" << endl;
            }
        
    }
    void listUser()
    {
        for (int i = 0; i < users.size(); i++)
        {
            cout << users[i].getName();
        }
        
    }

      int authy(int accountNO, string password, string securityQa) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getAccountNO() == accountNO && users[i].getPassword() == password && users[i].getSecurityQa() == securityQa) {
                if (users[i].getRol() == "admin") {
                    currentUserIndex = i; // Establecer currentUserIndex para el usuario autenticado
                    return 1; // Usuario administrador
                } else {
                    currentUserIndex = i; // Establecer currentUserIndex para el usuario autenticado
                    return 2; // Usuario regular
                }
            }
        }
        currentUserIndex = -1; // Restablecer currentUserIndex si la autenticación falla
        return -1; // Autenticación fallida
    }


     
};
