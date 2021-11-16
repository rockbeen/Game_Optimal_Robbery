
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int maxElementID(vector<int> array)//возвращает id  самого большого числа в массиве
{
    int biggestElement = 0;
    int biggestElementID;
    for (int i = 0;i < array.size();++i)
    {
        if (biggestElement < array[i])//обновление самого большого
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

        while (sumRobbed > loadCapacity)//если после всех операции сумма награбленного > грузоподъемности (это может произойти из-за округления)
        {   
            int biggestElementID= maxElementID(arrayRobbed);//то находим самый большой элемент в массиве 
            arrayRobbed[biggestElementID] -= 1;//и уменьшаем его
            sumRobbed -= 1;
        }//повторяем пока sumRobbed = loadCapacity
        while (sumRobbed < loadCapacity)//аналогично если наоборот, после всех операции сумма награбленного < грузоподъемности 
        {
            int biggestElementID = maxElementID( arrayRobbed);
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
      

    }

