#include <iostream>
#include <bitset>
#include <cmath>
#include <string>

// Find the first set bit
int firstSetBit(int n)
{
    // Below is the property that returns the binary number from rightmost one set bit only
    int y = n & (~(n - 1));

    // Convert binary to string then convert binary string to binary in the form of integer as in 00100 = 100
    int z = std::stoi(std::bitset<16>(y).to_string());

    int count = 0;
    while(z != 0)
    {
        count++;
        z /= 10;
    }

    return count;
}

// Check the rightmost different bit between two numbers
int rightMostDifferent(int a, int b)
{
    int y = a ^ b;
    return firstSetBit(y);
}

// Check kth bit is set or not
bool kth(int n, int k)
{
    // Leftshift 1 to kth position and do logical AND with number, eg : 1100 & (1<<2) => 1100 & 0100 = 100
    if(n & (1 << k) != 0)
        return true;
    
    return false;
}

// Count set bits in a number
int setBits(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = i;
        while(x)
        {
            x = x & (x-1);
            count++;
        }
    }

    return count;
}

// Count the number of bits needed to be flipped to equalize two numbers
int countBitsFlips(int a, int b)
{
    // Will return a number with all different bits set
    int y = a ^ b;
    int count = 0;

    // Count all set bits
    while(y)
    {
        y = y & (y - 1);
        count ++;
    }

    return count;
}

// Check if number is sparse or not - consecutive bits should not be set
bool isSparse(int n)
{
    if((n & (n << 1)) == 0)
        return true;

    return false;
}

// Find longest consecutive 1's
int consecutiveOnes(int n)
{
    int a = 0;

    while(n)
    {
        n = n & (n<<1);
        a++;
    }

    return a;
}

// Return if number is power of 2
bool power2(int z)
{
    if(z == 0)
        return false;

    if((z & (z - 1)) == 0)
        return true;
    return false;
}

// Swap even and odd bits in a number
int swapEvenOdd(int n)
{
    // 0xAAAAAAAA in hex is (A) - 1010 in binary meaning only even bits
    int x = n & 0xAAAAAAAA;
    x >>= 1;

    // 0x55555555 in hex is (5) - 0101 in binary meaning only odd bits
    int y = n & 0x55555555;
    y <<= 1;

    // x and y bitwise or operation
    return (x | y);
}

// Helper function for maxAnd
int checkBits(int pattern, int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if((pattern & arr[i]) == pattern)
            count++;
    }

    return count;
}

// Get the maximum AND(&) value in an array
int maxAnd(int arr[], int n)
{
    int res = 0, count;

    for(int i = 32; i > 0; i--)
    {
        count = checkBits((res | (1 << i)), arr, n);

        if(count >= 2)
            res |= (1 << i);
    }

    return res;
}

// Power set from bitwise operations
void printPowerSet(std::string str)
{
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                std::cout << str[j];
		}
		
		std::cout << "\n";
	}
}

int main()
{
    int arr[] = {4, 8, 6, 2, 16};

    std::cout << "First set bit : " << firstSetBit(32512) << "\n";
    std::cout << "Rightmost different bit : " << rightMostDifferent(11, 9) << "\n";
    std::cout << "Check kth bit is set or not : " << kth(30, 3) << "\n";
    std::cout << "Set bits in a number : " << setBits(4) << "\n";
    std::cout << "Count the number of bits to flip to equalize two numbers : " << countBitsFlips(20, 25) << "\n";
    std::cout << "Check if number is sparse or not : " << isSparse(2) << "\n";
    std::cout << "Count longest consecutive ones : " << consecutiveOnes(15) << "\n";
    std::cout << "Check if number is power of 2 : " << power2(15) << "\n";
    std::cout << "Swap even with odd bits : " << swapEvenOdd(23) << "\n";
    std::cout << "Maximum AND value in an array : " <<maxAnd(arr, 5) << "\n";
    printPowerSet("abc");
}