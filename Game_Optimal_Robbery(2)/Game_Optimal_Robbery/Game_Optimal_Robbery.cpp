
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int maxElementID(vector<int> array)//возвращает id  самого большого числа в массиве
{
    int biggestElement = 0;
    int biggestElementID=0;
    for (int i = 0;i < array.size();++i)
    {
        if (biggestElement >= array[i])//обновление самого большого
        {
            biggestElement = array[i];
            biggestElementID = i;
        }
    }
    return biggestElementID;
}

vector<int> robbery(vector<int> arrayResources,const int loadCapacity)
{
    int sumResources = 0;//сумма ресурсов
    int sumRobbed = 0;//сумма награбленного
    
    vector<int> arrayRobbed;//масив награбленных ресурсов

    for (auto i: arrayResources)//находим общую сумму всех ресурсов
    {
        sumResources += i;
    }

    if (sumResources >= loadCapacity)//если общая сумма всех ресурсов >= грузоподъемности
    {
        for (auto i : arrayResources)//для каждого элемента массива
        {
            //делим количество одного определенного ресурса на сумму всех(находим какой процент от общаго числа занимает этот ресурс)
            //и умножаем на грузоподъемности, чтобы такой же  процент занимал он (все это мы перевили в double и округлили)
            double element = round(static_cast<double>(loadCapacity) * (static_cast<double>(i) / sumResources));
            static_cast<int>(element);
            arrayRobbed.push_back(element);
            sumRobbed += element;   
        }

        int  remains = loadCapacity- sumRobbed;// сколько осталось "свободной" грузоподъемности 

        if (sumRobbed < loadCapacity)//если после всех операции сумма награбленного < грузоподъемности 
        {
            vector<int> numberResourcesPerStep= arrayResources;
            for (int k = 0;k < numberResourcesPerStep.size();++k)
            {
                numberResourcesPerStep[k] = 0;
            }
            vector<int> arrayK= numberResourcesPerStep;//массив хранящий коэфиценты

            for (int k = 0;k < remains;++k)
            {
                vector<int> arrayValueK = numberResourcesPerStep;//массив значений коэфицентов
                for (int i = 0;i< arrayResources.size();++i)
                {
                    double ratio = static_cast<double>(arrayResources[i]) / (numberResourcesPerStep[i] + 1);//считаем по методу Д'Ондта 
                    static_cast<int>(ratio);
                 
                    if (ratio > arrayValueK[k])
                    {
                        arrayValueK[k]=ratio;
                        arrayK[k]=i;
                    }
                }
                numberResourcesPerStep[arrayK[k]]++;
            }

            for (int k = 0;k < remains;++k)
            {
                arrayRobbed[arrayK[k]] += 1;
                sumRobbed += 1;
            }
        }
        while (sumRobbed > loadCapacity)//если после всех операции сумма награбленного > грузоподъемности (это может произойти из-за округления)
        {
            int biggestElementID = maxElementID(arrayRobbed);//то находим самый большой элемент в массиве 
            arrayRobbed[biggestElementID] -= 1;//и уменьшаем его
            sumRobbed -= 1;
        }//повторяем пока sumRobbed = loadCapacity

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

        vector<int>  arrayResources;
        cout << "Fill the array with resources:" << endl;
        int value;
        for (int i = 0;i < sizeArray;++i)
        {
            cin >> value;
            arrayResources.push_back(value);

        }
        

        cout << "Enter the load capacity:" << endl;
        cin >> loadCapacity;

  
        arrayResources = robbery(arrayResources, loadCapacity);

        cout << "Stolen resources:" << endl;
        for (auto i : arrayResources)
        {
            cout << i << endl;
        }
   
    }

