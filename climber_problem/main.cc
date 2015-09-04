#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

//计算爬山的总路程，时间复杂度为O(n), 空间复杂度为O(1)
int resolve(const char* input)
{
    int rectangle[3] = {0, 0, 0};
    int num_rectangle = 0;
    int end_prerectangle = 0;
    int height_prerectangle = 0;
    int distance = 0;
    int num_comma = 0;
    int power_exponent = 0;
    for(int i = 0; *input != '\n' && *input != '\0'; i++)
    {
        num_rectangle = num_rectangle * pow(10, i) + (int)(*input - '0');
        input++;
    }
    while(*input != '\0')
    {
        height_prerectangle = rectangle[2];
        end_prerectangle = rectangle[1];
        num_comma = 0;
        rectangle[0] = 0;
        rectangle[1] = 0;
        rectangle[2] = 0;
        while(*input != '\n')
        {
            power_exponent = 0;
            while(*input != ',' && *input != '\n')
            {
                rectangle[num_comma] = rectangle[num_comma] * pow(10, power_exponent) + (int)(*input - '0');
                power_exponent++;
                input++;
            }
            num_comma++;
            if(*input == '\n') break;
            else input++;
        }
        if(rectangle[0] > end_prerectangle) distance += height_prerectangle + rectangle[2];
        else distance += abs(rectangle[2] - height_prerectangle);
        input++;
    }
    distance += rectangle[1] + rectangle[2];
    return distance;
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2\n",
        "3\n1,2,1\n2,3,2\n3,6,1\n",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1\n",
        "1\n0,1,1\n",
        "2\n0,1,1\n2,4,3\n",
        "3\n0,1,1\n2,4,3\n3,5,1\n",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n",
        //TODO please add more test case here
        //"11\n0,1,2\n2,5,10\n4,6,11\n7,8,4\n8,9,5\n11,12,1\n13,14,2\n14,15,3\n15,16,4\n16,17,5\n17,18,6\n"
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
