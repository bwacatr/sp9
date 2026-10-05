// pract9_SP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct Product
{
    int id = 0;
    double price = 0;
    double markup = 0;
    double totalPrice = 0;

};

void Info(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    

    for (int i = 0; i < size; i++)
    {
        array = (array + i);
        cout << "\nПродукт номер: " << array->id << " цена: " << array->price << " фиксированная наценка: " << array->markup << " итоговая цена:" << array->totalPrice  << endl;
    }
}
   
void DiscountBy10(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    cout << "\n\nДо:\n" << endl;
    Info(array, size);


    for (int i = 0; i < size; i++)
    {
        array = (array + i);
        
        array->price = array->price - (array->price * 0.1);
    }

    cout << "\n\nПосле:\n" << endl;
    Info(array, size);
}

void RoundOffTotalPrices(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    cout << "\n\nДо:\n" << endl;
    Info(array, size);

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        array->totalPrice = ceil(array->totalPrice);
    }

    cout << "\n\nПосле:\n" << endl;
    Info(array, size);
}

void DiscountBy20(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    cout << "\n\nДо:\n" << endl;
    Info(array, size);

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        array->price = array->price - (array->price * 0.2);
    }

    cout << "\n\nПосле:\n" << endl;
    Info(array, size);
}

void RandomizeMarkup(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    double markupNum = rand() % 500;

    cout << "\n\nДо:\n" << endl;
    Info(array, size);

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        array->markup = markupNum;
        array->totalPrice = array->price + array->markup;
    }

    cout << "\n\nПосле:\n" << endl;
    Info(array, size);
}

    void RandomizePrices(Product* array, int size)
    {
        if (array == nullptr || size == 0)
        {
            cout << "\n\nНет данных\n" << endl;
            return;
        }

        int num;

        cout << "\n\nДо:\n" << endl;
        Info(array, size);

        for (int i = 0; i < size; i++)
        {
            num = rand() % 3001;

            array = (array + i);
            array->id = i;
            array->price = num;
            array->totalPrice = array->totalPrice + array->markup;
        }

        cout << "\n\nПосле:\n" << endl;

        Info(array, size);
    }



    void applyProcessing(
        Product* data,
        int size,
        void (*processor)(Product*, int)
    ) {
        if (processor != nullptr) {
            processor(data, size);
        }
    }


int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    void (*operation1)(Product*, int) = RandomizePrices;
    void (*operation2)(Product*, int) = Info;
    void (*operation3)(Product*, int) = DiscountBy10;
    void (*operation4)(Product*, int) = DiscountBy20;
    void (*operation5)(Product*, int) = RandomizeMarkup;
    void (*operation6)(Product*, int) = RoundOffTotalPrices;

    void (*processors[])(Product*, int) = 
    {
        operation1,
        operation2,
        operation3,
        operation4,
        operation5,
        operation6
    };

    int count;
    cout << "Введите количество продуктов: " << endl;
    cin >> count;

    Product* products = nullptr;

    if (count > 0)
    {
        products = new Product[count];
    }
    else
    {
        cout << "\nНет данных\n" << endl;
        return 0;
    }

    int choiceNum;

    do
    {
        cout << "1. Ввести продукты" << "\n" << "2. Показать продукты" << "\n" << "3. Применить скидку 10% " << "\n" << "4. Применить скидку 20%" << "\n" << "5. Применить скидку 20%" << "\n" <<
        switch (choiceNum)
        {
        default:
            break;
        }
    } while (true);

}


