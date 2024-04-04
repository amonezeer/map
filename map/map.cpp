#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void loadDictionary(map<string, string>& dictionary, const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string word, definition;
        while (file >> word >> definition) {
            dictionary[word] = definition;
        }
        file.close();
        cout << "Словарь успешно загружен из файла" << endl;
    }
    else {
        cout << "Невозможно открыть файл для чтения" << endl;
    }
}

void saveDictionary(const map<string, string>& dictionary, const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const auto& entry : dictionary) {
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
        cout << "Словарь успешно сохранен в файле" << endl;
    }
    else {
        cout << "Невозможно открыть файл для записи" << endl;
    }
}

int main() {
    system("chcp 1251");

    map<string, string> dictionary;
    string fileName = "dictionary.txt";
    loadDictionary(dictionary, fileName);

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Поиск слова" << endl;
        cout << "2. Добавить слово" << endl;
        cout << "3. Удалить слово" << endl;
        cout << "4. Редактировать слово" << endl;
        cout << "5. Выйти и сохранить" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string word;
            cout << "Введите слово для поиска: ";
            cin >> word;
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << word << ": " << it->second << endl;
            }
            else {
                cout << "Слово не найдено в словаре " << endl;
            }
        }
        else if (choice == 2) {
            string word, definition;
            cout << "Введите слово для добавления : ";
            cin >> word;
            cout << "Введите определение слова: ";
            cin >> definition;
            dictionary[word] = definition;
            cout << "Слово '" << word << "' успешно добавлен в словарь" << endl;
        }
        else if (choice == 3) {
            string word;
            cout << "Введите слово для удаления: ";
            cin >> word;
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                dictionary.erase(it);
                cout << "Слово '" << word << "' успешно удален из словаря" << endl;
            }
            else {
                cout << "Слово не найдено в словаре" << endl;
            }
        }
        else if (choice == 4) {
            string word, definition;
            cout << "Введите слово для редактирования: ";
            cin >> word;
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << " Введите новое определение для слова'" << word << "': ";
                cin >> definition;
                it->second = definition;
                cout << "Определение слова '" << word << "' обновлено " << endl;
            }
            else {
                cout << "Слово не найдено в словаре" << endl;
            }
        }
        else if (choice == 5) {
            saveDictionary(dictionary, fileName);
            break;
        }
        else {
            cout << "Некоректный выбор , попробуйте еще раз" << endl;
        }
    }

    return 0;
}
