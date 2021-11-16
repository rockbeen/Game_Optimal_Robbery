
#include <iostream>
#include <cmath>
using namespace std;

int maxElementID(const int sizeArray, int array[])//возвращает id  самого большого числа в массиве
{
    int biggestElement = 0;
    int biggestElementID;
    for (int i = 0;i < sizeArray;++i)
    {
        if (biggestElement < array[i])//обновление самого большого
        {
            biggestElement = array[i];
            biggestElementID = i;
        }
    }
    return biggestElementID;
}

int* robbery(const int sizeArray, int arrayResources[],const int loadCapacity)
{
    int sumResources = 0;//сумма ресурсов
    int sumRobbed = 0;//сумма награбленного
    
    int* arrayRobbed = new int[sizeArray];//масив награбленных ресурсов

    for (int i = 0;i < sizeArray;++i)//находим общую сумму всех ресурсов
    {
        sumResources += arrayResources[i];
    }

    if (sumResources >= loadCapacity)//если общая сумма всех ресурсов >= грузоподъемности
    {
        for (int i = 0;i < sizeArray;++i)//для каждого элемента массива
        {
            //делим количество одного определенного ресурса на сумму всех(находим какой процент от общаго числа занимает этот ресурс)
            //и умножаем на грузоподъемности, чтобы такой же  процент занимал он (все это мы перевили в double и округлили)
            double element = round(static_cast<double>(loadCapacity) * (static_cast<double>(arrayResources[i]) / sumResources));
            static_cast<int>(element);
            arrayRobbed[i] = element;
            sumRobbed += element;   
        }

        while (sumRobbed > loadCapacity)//если после всех операции сумма награбленного > грузоподъемности (это может произойти из-за округления)
        {   
            int biggestElementID= maxElementID(sizeArray,arrayRobbed);//то находим самый большой элемент в массиве 
            arrayRobbed[biggestElementID] -= 1;//и уменьшаем его
            sumRobbed -= 1;
        }//повторяем пока sumRobbed = loadCapacity
        while (sumRobbed < loadCapacity)//аналогично если наоборот, после всех операции сумма награбленного < грузоподъемности 
        {
            int biggestElementID = maxElementID(sizeArray, arrayRobbed);
            arrayRobbed[biggestElementID] += 1;
            sumRobbed += 1;
        }
    }
    else//если общая сумма всех ресурсов < грузоподъемности
    {
         return arrayResources;//то просто разбойники уносят все ресурсы (возвращаем массив ресурсов)
        
    }
    return arrayRobbed;
    }



    int main()
    {
        int loadCapacity;
        int sizeArray;

        cout << "Enter the length of the array:" << endl;
        cin >> sizeArray;

        int* arrayResources = new int[sizeArray];
        cout << "Fill the array with resources:" << endl;

        for (int i = 0;i < sizeArray;++i)
            cin >> arrayResources[i];

        cout << "Enter the load capacity:" << endl;
        cin >> loadCapacity;

        int* resultRobbery;
        resultRobbery = robbery(sizeArray, arrayResources, loadCapacity);

        cout << "Stolen resources:" << endl;
        for (int i = 0;i < sizeArray;++i)
            cout << resultRobbery[i] << endl;



    }

