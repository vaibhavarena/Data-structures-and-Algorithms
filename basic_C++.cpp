#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>

using namespace std;

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

int columnWithMaxZeros(int arr[][5]){
    // Find the column with maximum number of zeros
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

void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{
    //Insert an element in an array at specific index and shift forward other elements
    int temp;
    int count = sizeOfArray;
    
    while(count != index)
    {
        count--;
        arr[count+1] = arr[count];
    }
    arr[index] = element;
}

vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT8_MIN, max2= INT8_MIN;
    vector<int> result;

     for(int i = 0; i < sizeOfArray; i++)
     {
         // If max is updated max2 takes its place
         if(arr[i] > max)
         {
            max2 = max;
            max = arr[i];
         }
        if(arr[i] > max2 && arr[i] < max)
            max2 = arr[i];
     }
     
     if(max2 == INT8_MIN)
        max2 = -1;
        
     result.push_back(max);
     result.push_back(max2);
     
     return result;
}

int findSum(string s)
{
    // Find the sum of digits in an alphanumeric string
    int sum = 0;
    string str = "";
    s = s + " ";

    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            str += s[i];
        }
        else if(str.length() > 0)
        {
            sum += stoi(str);
            str = "";
        }
    }

    return sum;
}

int strstr(string s, string x)
{
    // Find the second string in first as a substring
    int m = s.length();
    int n = x.length();

    for(int i = 0; i < m-n+1; i++)
    {
        int a = 1;
        int index = 0;
        for(int j = i; j < i + n; j++)
        {
            cout << "S : "<< s[j] << "     I : "<< x[index] << endl;
            if(s[j] == x[index])
            {
                index++;
            }
            else{
                a = 0;
                break;
            }                
        }
        if(a)
            return i;
    }
    return -1;
}

char *encode(char *src)
{     
    // Return occurence of each alphabet in a string
    int count = 0;
    int index = 0;
    char *ch = new char[strlen(src) + 1000];

    for(int i = 0; src[i] != '\0'; i++)
    {
        if(count == 0)
        {
            ch[index] = src[i];
            index++;
            count++;
        }

        else if(src[i] == src[i-1])
        {
            count++;
        }

        else
        {
            while(count)
            {
                 ch[index] = to_string(count % 10)[0];
                 index++;
                 count = count/10;
            }

            ch[index] = src[i];
            index++;
            count = 1;
        }
    }

    if(count > 0)
    {
        while(count)
            {
                 ch[index] = to_string(count % 10)[0];
                 index++;
                 count = count/10;
            }
    }
    
    return ch;
}    


string reverseWords(string s) 
{ 
    string delimiter = ".";
    vector<string> v;

    size_t last = 0, pos = 0;

    while((pos = s.find(delimiter, last)) != string::npos)
    {
        v.push_back(s.substr(last, pos - last));
        last = pos + delimiter.length();
    }

    v.push_back(s.substr(last, string::npos));
    reverse(v.begin(), v.end());

    string z = accumulate(v.begin(), v.end(), string(), [](string &ss, string &s){
        return ss.empty() ? s : ss + "." + s;
    });

    return z;
} 

void reverse_dig(int &a,int &b)
{
    //Add your code here.
    int n1 = 0, n2 = 0;
    while(a)
    {
        n1 = (n1*10) + a%10;
        a = a / 10;
    }
    
    while(b)
    {
        n2 = (n2*10) + b%10;
        b = b / 10;
    }
    a = n1;
    b = n2;
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

    // Insert at index
    // Largest and second largest    

    cout << "Sum of numbers in a string : " << findSum("va23ibh9av20") << endl;

    cout << "Substring in a string : " << strstr("geegsforgeeks", "gsforgeeks") << endl;

    char ch[] = {'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'd', 'e' , 'z' ,'a', 'a', 'a'};
    char *a = encode(ch);
    for(int i = 0; a[i] != '\0'; i++)
        cout << a[i] << " ";
    cout << endl;

    string s = "i.like.this.program.very.much";
    cout << reverseWords(s) << endl;

    int n1 = 2332, n2= 92920;
    reverse_dig(n1, n2);
    cout << n1 << " " << n2 << endl;
}