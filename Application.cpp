#include <iostream>
#include <string>

using namespace std;

class User {
private:
    int id;
    string name;
    string email;

public:
    User(int userId, string userName, string userEmail) {
        id = userId;
        name = userName;
        email = userEmail;
    }

    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Имя: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

class Application {
private:
    int id;
    User* applicant;

public:
    Application(int applicationId, User* user) {
        id = applicationId;
        applicant = user;
    }

    void displayInfo() {
        cout << "ID заявки: " << id << endl;

        if (applicant != nullptr) {
            cout << "Информация о пользователе:" << endl;
            applicant->displayInfo();
        }
    }
};

int main() {
    User user(1, "Иван", "ivan@example.com");

    Application application(101, &user);

    application.displayInfo();

    return 0;
}