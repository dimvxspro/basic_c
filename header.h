//
//  header.h
//  project
//
//  Created by Дима on 22.05.23.
//

#ifndef header_h
#define header_h
struct Product{
    char name[100];//наименование
    char producer[100];//производитель
    double price;//цена
    char arrival[100];//дата поступления на склад
    char exp[100];//срок годности
    char group[100];//категория товара
};
Product add_product();//функция для добавления продукта
void extra_product(Product* storage, int size);//добавляем дополнительно продукты, после того, как добавили основное количество
void print_storage(Product* storage, int size);//функция для вывода всех продуктов
void delete_product(Product* storage, int size);//функция для удаления продуктов
void change_product(Product* storage, int size);//функция для замены продукта или для замены его характеристик
void help_category(Product* storage, int index);//функция, выводящая продукт найденный по характеристикам продукта
void search_product(Product* storage, int size);//функция для поиска продукта
void sort(Product* storage, int size);//функция для сортировки массива
void ask_print(Product* storage, int size, int choice);//функция, спрашивающая, нужно ли вывести продукты
void all_functions(Product* storage, int size, int choice, int answer);//все функции
#endif /* header_h */
