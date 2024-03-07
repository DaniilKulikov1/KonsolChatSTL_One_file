#include<iostream>
#include<string>

#include<vector>
using namespace std;

void hello()
{

    cout << R"(

                 ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv)

 )";
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "ПРИВЕТСТУЮ ВАС ПОЛЬЗОВАТЕЛЬ ВЫ ВОШЛИ В ЧАТ!" << endl;
    cout << "Над чатом трудились:" << endl;
    cout << "Даниил Куликов - старший стажёр, разработчик механизма чата, классов месседж, и 2 мемори" << endl;
    cout << "Николай Леванов - стажёр, разработчик класса юзер, и блока регистрации" << endl;
    cout << "Владислав Колесниченко  -  разработчик аскей дизайна и работа с циклами для функционирования чата" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
}


class Message
{
private:
    string recepient_p; /*кому*/
    string send_p;/* кто*/
    string text_p; /*текст смс*/
public:

    Message()
    {
        recepient_p = " ";
        send_p = " ";
        text_p = " ";
    }

    Message(const string& recepient, const string& send, const string& text) :recepient_p(recepient), send_p(send), text_p(text)
    {};
    string& getRecepient()
    {
        return recepient_p;//кто
    };

    string& getSend()//кому
    {
        return send_p;
    };

    string& getText()//что
    {
        return text_p;
    };
};

class User
{
private:
    string name_p; //имя
    string password_p;//пароль

public:

    User()//
    {
        name_p = " ";
        password_p = " ";
    };

    //Конструктор быстрого заполнения
    User(const string& name, const string& password) :name_p(name), password_p(password)
    {};

    //геттеры
    string& getName()
    {
        return name_p;
    };

    string& getPassword()
    {
        return password_p;
    };
};

//массив сообщений 
template<typename T>
class Memory {
private:
    int size;
    T* data;
    int i;
public:
    Memory()
    {
        size = 1;
        data = new T[size];
        i = 0;
    };
    ~Memory()
    {
        delete[] data;
    };

    void AddSms(const T& value)
    {
        if (i < size)
        {
            data[i] = value;
            ++i;
        }
        else
        {
            int newSize = size * 2;
            T* newData = new T[newSize];
            for (int j = 0; j < size; j++)
            {
                newData[j] = data[j];
            }

            newData[i] = value;
            ++i;
            delete[] data;
            data = newData;
            size = newSize;
        };
    };

    void Display()
    {
        for (int f = 0; f < i; f++)
        {
            cout << "В чате есть сообщение!!! Кому:  " << data[f].getRecepient() << ". От кого: " << data[f].getSend() << endl;
            cout << "cообщение: " << "'" << data[f].getText() << "'" << endl;
        };

    };


};




//Я закоментировал класс создающий массив, который хранит пользователей и сделал всё через стл. Чтобы можно было сравнить как было, \
//я не стал стиравть закоментированый код

////массив юзеров
//template<typename U>
//class MemoryUser
//{
//private:
//    int size1;
//    U* data1;
//    int j;
//public:
//    MemoryUser()
//    {
//        size1 = 1;
//        j = 0;
//        data1 = new U[size1];
//    };
//
//    ~MemoryUser()
//    {
//        delete[] data1;
//    };
//
//    int getSize1()
//    {
//        return j; // Количество добавленных пользователей,
//    };
//
//    U* getUser(int index) {
//        // Изменено на возвращение указателя и добавлена проверка границ
//        if (index < 0 || index >= j) {
//            return nullptr;
//        }
//        return &data1[index];
//    }
//
//    void AddUsers(const U& value)
//    {
//        if (j >= size1)
//        {
//            // Увеличиваем размер массива
//            int newSize1 = size1 * 2;
//            U* newData1 = new U[newSize1];
//            for (int t = 0; t < size1; t++)
//            {
//                newData1[t] = data1[t];
//            }
//
//            delete[] data1; // Удаляем старые данные
//            data1 = newData1;
//            size1 = newSize1;
//        }
//
//        // Теперь, когда у нас есть наверняка место, добавляем новый элемент
//        data1[j++] = value;
//
//    };
//};
//


class Chat
{
    Memory<Message>messages;
public:
    //функцией берём данные
    void sendMessage(const string& recepient, const string& send, const string& text)
    {
        //создаём обьект другого класса и наполняем
        Message message1(recepient, send, text);

        messages.AddSms(message1);//помещаем в массив

    };

    void DisplayMessages()
    {
        messages.Display();
    };
};





int main()
{
    system("chcp 1251");
    hello();


    vector<User>Tolpa;
    //User Noubody;
    User* currentUser = nullptr;


    cout << "Регистрация\n";
    string username, password;
    cout << "Введите логин: " << endl;
    cin >> username;
    cout << "Введите пароль: " << endl;
    cin >> password;
    User First(username, password);
    Tolpa.push_back(First);
    cout << "Вы успешно зарегистрировались!Теперь войдите в аккаунт." << endl;

    cout << " \n";
    cout << "Выберите действие:\n ";

    cout << "1. Послать сообщение\n";

    cout << "2. Войти в существующий аккаунт\n";

    cout << "3. Создать новый аккаунт\n";

    cout << "4. Выход из аккаунта\n";

    cout << "5. Завершить\n";

    cout << " \n";

    cout << "В дальнейшем пользуйтесь этими кнопками" << endl;
    int choice;

    Chat chat;
    do {
        cin >> choice;
        switch (choice)
        {///////////
            {case 1:
                if (currentUser != nullptr) { // только если пользователь вошел
                    string recipient, text;
                    cout << "Введите получателя: ";
                    cin >> recipient;
                    cout << "Введите текст сообщения: ";
                    cin.ignore();
                    getline(cin, text);

                    chat.sendMessage(recipient, currentUser->getName(), text);
                    cout << "Сообщение отправлено!\n";
                    cout << " \n";
                    cout << " \n";
                }
                else {
                    cout << "Вы не вошли в систему. Сначала войдите в свой аккаунт нажав 2.\n";
                }
                break;
            }


            {case 2:
                cout << "Вход в существующий аккаунт\n" << endl;
                string username1, password1;
                cout << "Введите логин: " << endl;
                cin >> username1;
                cout << "Введите пароль: " << endl;
                cin >> password1;

                for (int k = 0; k < Tolpa.size(); k++) {
                    User* user = &Tolpa[k]; // Получаем указатель на пользователя
                    if (user != nullptr && user->getName() == username1 && user->getPassword() == password1) {
                        currentUser = user; // Устанавливаем currentUser напрямую
                        cout << "Вы успешно вошли в аккаунт!" << endl;
                        chat.DisplayMessages();
                        break;
                    }
                }
                if (currentUser == nullptr) {
                    cout << "Неправильный логин или пароль." << endl;
                }
                break;
            }



            {case 3:
                cout << "Регистрация\n";
                cout << "Введите логин: " << endl;
                cin >> username;
                cout << "Введите пароль: " << endl;
                cin >> password;
                User newUser(username, password);
                Tolpa.push_back(newUser);  //тут использован стл

                int lastuser = Tolpa.size() - 1;
           

                currentUser = &Tolpa.at(lastuser); //изменено с использованием стл
                cout << "Вы успешно зарегистрировались!" << endl;
                cout << "  " << endl;
                //if (currentUser != nullptr) { // Проверка на nullptr
                //    chat.DisplayMessages();
                //}
                break;
            }

            {case 4:
                currentUser = nullptr; // Устанавливаем currentUser в nullptr при выходе
                cout << "Выход выполнен. Войдите в существующий аккаунт нажав 2 или зарегестрируйтесь нажав 3\n";
                cout << " \n";
                cout << " \n";
                break;
            }

            {case 5:

                cout << "Вы выполнили учебный выход из чата\n";
                cout << "В будущем эта кнопка будет закрывть всю консоль\n";
                cout << "А пока - это только учебный проект" << endl;
                break;
            }



        default:
            cout << "Вы ввели неправильное значение" << endl;
            break;

        };//////

    } while (choice != 5);

    return 0;
}









