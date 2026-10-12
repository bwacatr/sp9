// pract9_SP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct Product
{
    int id{ 0 };
    double price{ 0 };
    double markup{ 0 };
    double totalPrice{0};

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

    


    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        if (!(array->totalPrice < 10.0))
        {



            double difference = array->totalPrice;

            array->totalPrice = array->totalPrice - (array->totalPrice * 0.1);

            difference -= array->totalPrice;

            array->price -= difference;
        }
        else
        {
            cout << "\n\nСлишком низкая цена для скидки у номера " << array->id << "\n" << endl;
            
        }
    }

    
}

void RoundOffTotalPrices(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        array->price = round(array->price);
        array->totalPrice = array->price + array->markup;
    }

    
}

void DiscountBy20(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        if (!(array->totalPrice < 10.0))
        {
            

            double difference = array->totalPrice;

            array->totalPrice = array->totalPrice - (array->totalPrice * 0.2);

            difference -= array->totalPrice;

            array->price -= difference;
        }
        else
        {
            cout << "\n\nСлишком низкая цена для скидки у номера " << array->id << "\n" << endl;
            
        }
    }

    
}

void RandomizeMarkup(Product* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "\n\nНет данных\n" << endl;
        return;
    }

    
    double markupNum;
    

    for (int i = 0; i < size; i++)
    {
        array = (array + i);

        markupNum = rand() % 500;

        array->markup = markupNum;
        array->totalPrice = array->price + array->markup;
    }

    
}

    void RandomizePrices(Product* array, int size)
    {
        if (array == nullptr || size == 0)
        {
            cout << "\n\nНет данных\n" << endl;
            return;
        }

        int num;

        

        for (int i = 0; i < size; i++)
        {
            num = rand() % 3001;

            array = (array + i);
            array->id = i;
            array->price = num;
            array->markup = 0;
            array->totalPrice = array->price + array->markup;
        }

        
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

    void (*randomizePrices)(Product*, int) = RandomizePrices;
    void (*info)(Product*, int) = Info;
    void (*discountBy10)(Product*, int) = DiscountBy10;
    void (*discountBy20)(Product*, int) = DiscountBy20;
    void (*randomizeMarkup)(Product*, int) = RandomizeMarkup;
    void (*roundOffTotalPrices)(Product*, int) = RoundOffTotalPrices;

    void (*processors[])(Product*, int) = 
    {
        randomizePrices,
        info,
        discountBy10,
        discountBy20,
        randomizeMarkup,
        roundOffTotalPrices
    };

    try
    {

       
        
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
        bool continueLoop = true;



        do
        {
            cout << "1. Ввести продукты" << "\n" << "2. Показать продукты" << "\n" << "3. Применить скидку 10% " << "\n" << "4. Применить скидку 20%" << "\n" << "5. Добавить фиксированную наценку" << "\n" << "6. Округлить цены до целого" << "\n" << "6. Выйти" << endl;
            
            cin >> choiceNum;
            
            if (choiceNum == 1)
            {


                cout << "\n\nДо:\n" << endl;
                applyProcessing(products, count, processors[1]);


                applyProcessing(products, count, processors[0]);


                cout << "\n\nПосле:\n" << endl;
                applyProcessing(products, count, processors[1]);
            }
            else if (choiceNum == 2)
            {
                processors[1](products, count);
                
                    
            }
            else if (choiceNum == 3)
            {
                cout << "\n\nДо:\n" << endl;
                applyProcessing(products, count, processors[1]);


                applyProcessing(products, count, processors[2]);


                cout << "\n\nПосле:\n" << endl;
                applyProcessing(products, count, processors[1]);
                
            }
            else if (choiceNum == 4)
            {
                cout << "\n\nДо:\n" << endl;
                applyProcessing(products, count, processors[1]);


                applyProcessing(products, count, processors[3]);


                cout << "\n\nПосле:\n" << endl;
                applyProcessing(products, count, processors[1]);
            }
            else if (choiceNum == 5)
            {
                cout << "\n\nДо:\n" << endl;
                applyProcessing(products, count, processors[1]);


                applyProcessing(products, count, processors[4]);


                cout << "\n\nПосле:\n" << endl;
                applyProcessing(products, count, processors[1]);
            }
            else if (choiceNum == 6)
            {
                cout << "\n\nДо:\n" << endl;
                applyProcessing(products, count, processors[1]);


                applyProcessing(products, count, processors[5]);


                cout << "\n\nПосле:\n" << endl;
                applyProcessing(products, count, processors[1]);
            }
            else
            {
                continueLoop = false;
            }
            
        } while (continueLoop);
    }
    catch (std::invalid_argument& e)
    {
        e.what();
    }

}


