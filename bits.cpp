#include <iostream>
#include <bitset>

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

int main()
{
    std::cout << "First set bit : " << firstSetBit(32512) << "\n";
    std::cout << "Rightmost different bit : " << rightMostDifferent(11, 9) << "\n";
    std::cout << "Check kth bit is set or not : " << kth(30, 3) << "\n";
    std::cout << "Set bits in a number : " << setBits(4) << "\n";
}