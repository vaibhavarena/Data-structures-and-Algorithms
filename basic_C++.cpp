#include <iostream>

using namespace std;

int columnWithMaxZeros(int arr[][5]){
    int maxCount = 0;
    int col;
    for(int j = 0; j < 5 ; j++)
    {
        int count = 0;
        for(int i = 0; i < 3; i++)
        {
            if(arr[i][j] == 0)
                count++;
        }
        if(maxCount <= count){
            maxCount = count;
            col = j;
        }
    }
    return col;
}

void interchange(int arr[][4], int r,int c)
{
    // Interchange last column elements with first column
    cout << "\nInterchange : \n";
    int temp;
    for(int i = 0;i < r; i++)
    {
        temp = arr[i][c-1];
        arr[i][c-1] = arr[i][0];
        arr[i][0] = temp;
    }

    //Printing the modified matrix
    for(int i=0;i<r;i++)
	   { 
	       for(int j=0;j<c;j++)
    	    {
    	        cout<<arr[i][j]<<" ";
    	        
    	    }
    	 cout<<endl;
	   }
}

void swapElements(int arr[], int sizeof_array){
    // Swap i with i+2 element
    int temp;
    for(int i = 0; i < sizeof_array - 2; i++)
    {
        temp = arr[(i+2)];
        arr[(i+2)] = arr[i];
        arr[i] = temp;
    }
    cout << "\nSwap Elements : ";
    for(int i = 0; i < sizeof_array; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}


void countOddEven(int arr[], int sizeof_array)
{
    // Count occurences of odd and even numbers in an array
    cout<< "\nOdd Even : ";
    int countOdd=0, countEven=0;
   for(int i = 0;i< sizeof_array;i++)
   {
    if(arr[i] % 2 == 0)
        countEven+=1;
    else
        countOdd+=1;
   }
   
   cout<<countOdd<<" "<<countEven << endl;
    
}

int digitalRoot(int n)
{
    // Digital root is sum of elements of number and if root is greater than 9 find digital root again
    int sum = 0;
    
    while(n)
    {
        sum += (n%10);
        n = n/10;
    }

    if(sum / 10 != 0)
    {
        return digitalRoot(sum);
    }
    return sum;
}

int main()
{
    cout << "Digital Root : " << digitalRoot(99999) << endl;
    int arr[] = {14102, 18038, 19167, 14538, 13689, 17753, 16528, 21413, 18874, 20988, 22232, 20605, 14179, 16590, 19943, 15808, 16376, 16438, 13208, 14590, 14072, 21623, 18868, 17389, 15890, 21155, 15030, 22108, 12474, 21966, 18990, 20023, 19019, 15188, 19738, 17867, 12943, 17469, 17026, 13674, 16781, 21679, 17186, 13840, 20931, 17477, 16158, 17911, 14629, 19472, 14000, 16408, 14244, 13899, 12358, 18659, 18353, 15571, 20474, 17185, 22068, 16454, 19714, 12664, 20073, 14875, 17721, 15583, 13002, 14563, 13245, 14131, 18931, 19134, 21691, 20601, 19505, 20161, 19655, 20148, 15901, 14870};
    countOddEven(arr, (sizeof(arr)/ sizeof(arr[0])));
    
    int arr2[] = {1,2,3,4,5};
    swapElements(arr2, 5);

    int arr3[][4] = {{1, 2, 3, 4}, {4, 3, 2, 1}, {6, 7, 8, 9}};
    interchange(arr3, 3, 4);

    int arr4[][5] = {{1, 1, 0, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 0}};
    cout << "Column with maximum zeros : " << columnWithMaxZeros(arr4) << endl;
}