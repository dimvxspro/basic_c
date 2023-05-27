//
//  main.cpp
//  project
//
//  Created by Дима on 23.04.23.
//

#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;
#pragma region
#pragma endregion
//Создайте приложение «Склад». Приложение должно реализовывать такую функциональность:
//Добавление товара на склад
//Удаление товара со склада
//Замена товара
//Поиск товара
//По названию
//Производителю
//По цене
//Группе товара (Например, минеральная вода или консервы)
//Дате поступления на склад
//Сроку годности
//Сортировка товара
//По цене
//По группе товара




int main() {
    setlocale(LC_ALL, "");
    int choice;
    int size;
    int answer;
    cout << "введите количество товаров: ";
    cin >> size;
    Product* storage = new Product[size];
    for(int i = 0; i < size; i++){
        storage[i] = add_product();
    }
    
    ask_print(storage, size, choice);
    all_functions(storage, size, choice, answer);
    delete[] storage;
}

Product add_product(){//функция для добавления продукта
    Product product;
    cout << "введите наименование продукта: ";
    cin.ignore(1, '\n');
    cin.getline(product.name, 100);
    cout << "введите производителя: ";
    cin.getline(product.producer, 100);
    cout << "введите цену: ";
    cin >> product.price;
    cout << "введите дату поступления: ";
    cin >> product.arrival;
    cout << "введите срок годности: ";
    cin >> product.exp;
    cout << "введите категорию товара: ";
    cin.ignore(1, '\n');
    cin.getline(product.group, 100);
    cout << endl;
    return product;
}

void extra_product(Product* storage, int size){//добавляем дополнительно продукты, после того, как добавили основное количество
    int answer;//переменная для запроса количества продуктов
    int answer2;//переменная для вывода всех продуктов
    cout << "введите количество добавляемых продуктов: ";
    cin >> answer;
    int new_size = size + answer;
    Product* new_storage = new Product[new_size];//создаём массив на новое количество продуктов
    for(int i = 0; i < size; i++){//заполняем массив старым
        new_storage[i] = storage[i];
    }
    for(int i = size; i < new_size; i++){//добавляем новые продукты
        new_storage[i] = add_product();
    }
    cout << "хотите вывести все продукты? " << endl;
    cout << "1 - да" << endl;
    cout << "2 - нет" << endl;
    cin >> answer2;
    if(answer2 == 1){
    for(int i = 0; i < new_size; i++){
        cout << "товар " << i + 1 << endl;
        cout << "наименование: " << new_storage[i].name << endl;
        cout << "производитель: " << new_storage[i].producer << endl;
        cout << "цена: " << new_storage[i].price << endl;
        cout << "дата поступления: " << new_storage[i].arrival << endl;
        cout << "срок годности: " << new_storage[i].exp << endl;
        cout << "категория товара: " << new_storage[i].group << endl;
        cout << endl;
    }
    }
    delete[] new_storage;
}

void print_storage(Product* storage, int size){//функция для вывода всех продуктов
    for(int i = 0; i < size; i++){
        cout << "товар " << i + 1 << endl;
        cout << "наименование: " << storage[i].name << endl;
        cout << "производитель: " << storage[i].producer << endl;
        cout << "цена: " << storage[i].price << endl;
        cout << "дата поступления: " << storage[i].arrival << endl;
        cout << "срок годности: " << storage[i].exp << endl;
        cout << "категория товара: " << storage[i].group << endl;
        cout << endl;
    }
}


void delete_product(Product* storage, int size){//функция для удаления продуктов
    char answer[50];
    int index;
    cout << "введите продукт, который хотите удалить: ";
    cin >> answer;
    int new_size = size - 1;
    Product* new_storage = new Product[size - 1];
    for(int i = 0; i < size; i++){
        if(strcmp(storage[i].name, answer) == 0){
            index = i;
        }
    }
    int k = 0;
    for(int i = 0; i < size; i++){
        if(index != i){
            new_storage[k] = storage[i];
            k++;
        }
    }
    print_storage(new_storage, new_size);
    delete[] new_storage;
}
void change_product(Product* storage, int size){//функция для замены продукта или для замены его характеристик
    int index = 0;
    char answer[50];
    int asking;
    cout << "введите продукт, который хотите заменить: ";
    cin >> answer;
    for(int i = 0; i < size; i++){
        if(strcmp(storage[i].name, answer) == 0){
            index = i;
        }
    }
    cout << "выберите, что вы хотите сделать: " << endl;
    cout << "1 - заменить полностью товар" << endl;
    cout << "2 - заменить название" << endl;
    cout << "3 - заменить производителя" << endl;
    cout << "4 - заменить цену" << endl;
    cout << "5 - заменить дату поступления" << endl;
    cout << "6 - заменить срок годности" << endl;
    cout << "7 - заменить группу товара" << endl;
    cin >> asking;
    switch(asking){
        case 1:
            storage[index] = add_product();
            break;
            
        case 2:
            cout << "введите новое наименование продукта: ";
            cin.ignore(1, '\n');
            cin.getline(storage[index].name, 100);
            break;
            
        case 3:
            cout << "введите производителя: ";
            cin.getline(storage[index].producer, 100);
            break;
            
        case 4:
            cout << "введите цену: ";
            cin >> storage[index].price;
            break;
            
        case 5:
            cout << "введите дату поступления: ";
            cin >> storage[index].arrival;
            break;
            
        case 6:
            cout << "введите срок годности: ";
            cin >> storage[index].exp;
            break;
            
        case 7:
            cout << "введите группу товара: ";
            cin >> storage[index].group;
            break;

            default:
            cout << "вы ввели неверное значение" << endl;
            break;
    }

}

void help_category(Product* storage, int index){//функция, выводящая продукт найденный по характеристикам продукта
    cout << "наименование: " << storage[index].name << endl;
    cout << "производитель: " << storage[index].producer << endl;
    cout << "цена: " << storage[index].price << endl;
    cout << "дата поступления: " << storage[index].arrival << endl;
    cout << "срок годности: " << storage[index].exp << endl;
    cout << "категория товара: " << storage[index].group << endl;
    cout << endl;
}
void search_product(Product* storage, int size){//функция для поиска продукта
    char answer[100];//массив, запрашивающий характеристики продукта(кроме цены)
    double answer1;//массив запрашивающий цену продукта
    int category;
    int index;
    cout << "выберите категорию поиска: " << endl;
    cout << "1 - по названию " << endl;
    cout << "2 - по производителю " << endl;
    cout << "3 - по цене " << endl;
    cout << "4 - по дате поступления " << endl;
    cout << "5 - по сроку годности " << endl;
    cout << "6 - по группе товара " << endl;
    cin >> category;
    switch(category){
        case 1:
            cout << "введите название для поиска: ";
            cin >> answer;
            for(int i = 0; i < size; i++){
                if(strcmp(storage[i].name, answer) == 0){
                    index = i;
                }
            }

            help_category(storage, index);
            break;
        case 2:
            cout << "введите производителя для поиска: ";
            cin >> answer;
            for(int i = 0; i < size; i++){
                if(strcmp(storage[i].producer, answer) == 0){
                    index = i;
                }
            }

            help_category(storage, index);
            break;
        case 3:
            cout << "введите цену для поиска: ";
            cin >> answer1;
            for(int i = 0; i < size; i++){
                if(storage[i].price == answer1){
                    index = i;
                }
            }
            
            help_category(storage, index);
            break;
        case 4:
            cout << "введите дату поступления для поиска: ";
            cin >> answer1;
            for(int i = 0; i < size; i++){
                if(storage[i].arrival == answer){
                    index = i;
                }
            }
            help_category(storage, index);
            break;
        case 5:
            cout << "введите срок годности для поиска: ";
            cin >> answer1;
            for(int i = 0; i < size; i++){
                if(storage[i].price == answer1){
                    index = i;
                }
            }
            help_category(storage, index);
            break;
        case 6:
            cout << "введите название для поиска: ";
            cin >> answer;
            for(int i = 0; i < size; i++){
                if(strcmp(storage[i].group, answer) == 0){
                    index = i;
                }
            }
            
            help_category(storage, index);
            break;
      default:
            cout << "вы ввели неверное значение" << endl;
            break;
    }
}

void sort(Product* storage, int size){ //функция для сортировки массива
    bool answer;
    cout << "выберите сортировку: " << endl;
    cout << "1 - по цене" << endl;
    cout << "2 - по группе" << endl;
    cin >> answer;
    for (size_t i = 0; i < size - 1; i++){
         for (int j = 0; j < size - 1 - i; j++){
           if (answer){
             if (storage[j].price > storage[j + 1].price) {
               Product change = storage[j];
                 storage[j] = storage[j + 1];
                 storage[j + 1] = change;
             }
           }
           else{
             if (strcmp(storage[j].group, storage[j + 1].group) == 1) {
                 Product change = storage[j];
                 storage[j] = storage[j + 1];
                 storage[j + 1] = change;
             }
           }
         }
       }
    print_storage(storage, size);
}
void ask_print(Product* storage, int size, int choice){//функция, спрашивающая, нужно ли вывести продукты
    cout << "желаете вывести все продукты?" << endl;
    cout << "1 - да" << endl;
    cout << "2 - нет" << endl;
    cin >> choice;
    if(choice == 1){
        print_storage(storage, size);
    }
}
void all_functions(Product* storage, int size, int choice, int answer){//все функции
    cout << "выберите, что вы хотите сделать: " << endl;
    cout << "1 - добавить продукт" << endl;
    cout << "2 - удалить продукт" << endl;
    cout << "3 - заменить продукт" << endl;
    cout << "4 - найти продукт" << endl;
    cout << "5 - отсортировать продукты" << endl;
    cin >> answer;
    switch(answer){
        case 1 :
            extra_product(storage, size);
            break;
        case 2 :
            delete_product(storage, size);
            break;
        case 3 :
            change_product(storage, size);
            ask_print(storage, size, choice);
            break;
        case 4 :
            search_product(storage, size);
            break;
        case 5:
            sort(storage, size);
            break;
        default:
            cout << "вы ввели неверное значение" << endl;
            break;
    }

}
