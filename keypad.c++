#include <iostream>
using namespace std;
 
// Function to convert mobile numeric
// keypad sequence into its equivalent
// string
void printSentence(string str)
{
    // Store the mobile keypad mappings
    char nums[][6]
        = { "", "", "ABC2", "DEF3", "GHI4",
            "JKL5", "MNO6", "PQRS7", "TUV8",
            "WXYZ9" };
 
    // Traverse the string str
    int i = 0;
    while (str[i] != '\0') {
 
        // If the current character is
        // '.', then continue to the
        // next iteration
        if (str[i] == '.') {
            i++;
            continue;
        }
 
        // Stores the number of
        // continuous clicks
        int count = 0;
 
        // Iterate a loop to find the
        // count of same characters
        while (str[i + 1]
               && str[i] == str[i + 1]) {
 
            // 2, 3, 4, 5, 6 and 8 keys will
            // have maximum of 3 letters
            if (count == 3
                && ((str[i] >= '2'
                     && str[i] <= '6')
                    || (str[i] == '8')))
                break;
 
            // 7 and 9 keys will have
            // maximum of 4 keys
            else if (count == 4
                     && (str[i] == '7'
                         || str[i] == '9'))
                break;
            count++;
            i++;
 
            // Handle the end condition
            if (str[i] == '\0')
                break;
        }
 
        // Check if the current pressed
        // key is 7 or 9
        if (str[i] == '7' || str[i] == '9') {
            cout << nums[str[i] - 48][count % 5];
        }
 
        // Else, the key pressed is
        // either 2, 3, 4, 5, 6 or 8
        else {
            cout << nums[str[i] - 48][count % 4];
        }
        i++;
    }
}
 
// Driver Code
int main()
{
    string str = "7.7772777744266.662";
    printSentence(str);
    return 0;
}