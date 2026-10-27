#include <string>
#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    int id;
    string name;
    string email;
    string passwordHash;
    string role;

public:
    User(int id, const string& name, const string& email,
         const string& passwordHash, const string& role) {
        this->id = id;
        this->name = name;
        this->email = email;
        this->passwordHash = passwordHash;
        this->role = role;
    }

    virtual ~User() = default;

    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getRole() const { return role; }
    void setName(const string& name) { this->name = name; }
    void setEmail(const string& email) { this->email = email; }

    virtual void printInfo() const = 0;
};

// Студент: ищет стажировки и подаёт заявки
class Student : public User {
private:
    string university;
    string course;

public:
    Student(int id, const string& name, const string& email,
            const string& passwordHash, const string& university,
            const string& course)
        : User(id, name, email, passwordHash, "student"),
          university(university), course(course) {}

    string getUniversity() const { return university; }
    string getCourse() const { return course; }
    void setCourse(const string& course) { this->course = course; }

    void printInfo() const override {
        cout << "[Студент] ID: " << id
             << " | Имя: " << name
             << " | Email: " << email
             << " | Вуз: " << university
             << " | Курс: " << course << endl;
    }
};

// Представитель организации: публикует стажировки и рассматривает заявки
class Recruiter : public User {
private:
    string organizationName;
    string position;

public:
    Recruiter(int id, const string& name, const string& email,
              const string& passwordHash, const string& organizationName,
              const string& position)
        : User(id, name, email, passwordHash, "recruiter"),
          organizationName(organizationName), position(position) {}

    string getOrganizationName() const { return organizationName; }
    string getPosition() const { return position; }
    void setPosition(const string& position) { this->position = position; }

    void printInfo() const override {
        cout << "[Представитель организации] ID: " << id
             << " | Имя: " << name
             << " | Email: " << email
             << " | Организация: " << organizationName
             << " | Должность: " << position << endl;
    }
};

int main() {
    vector<User*> users;

    users.push_back(new Student(1, "Иван Иванов", "ivanov@mail.ru", "hash1", "МГУ", "3"));
    users.push_back(new Recruiter(2, "Петр Петров", "petrov@company.ru", "hash2", "ООО Технологии", "HR-менеджер"));
    users.push_back(new Student(3, "Мария Сидорова", "sidorova@mail.ru", "hash3", "СПбГУ", "2"));
    users.push_back(new Recruiter(4, "Анна Смирнова", "smirnova@firm.ru", "hash4", "АО Разработка", "Руководитель практики"));

    cout << "\nИнформация о пользователях" << endl;
    for (size_t i = 0; i < users.size(); ++i) {
        users[i]->printInfo();
    }

    cout << "\nУдаление объектов" << endl;
    for (size_t i = 0; i < users.size(); ++i) {
        delete users[i];
    }

    cout << "Все объекты удалены. Программа завершена." << endl;
    return 0;
}
