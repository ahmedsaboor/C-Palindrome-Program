#include <iostream>
using namespace std;

//String class
class String
{
public:
    String(int size) : capacity(size) { array = new char[capacity]; }

    //Default constructor
    String() : capacity(0)
    {
        array = nullptr;
    }

    //constructor
    String(char s[]) : capacity(100)
    {
        array = new char[capacity];
        array = s;

        for (int i = 0; s[i] != '\0'; i++)
        {
            length++;
        }
    }

    //returns length of the String
    int Length()
    {
        return length;
    }

    //returns element at index, indx
    char getElement(int indx)
    {
        int i = 0;
        for (; i < indx; i++)
        {
        }
        if (i < this->Length())
        {
            return this->array[i];
        }
        else
        {
            return '\0';
        }
    }

    //checks if the String s is equal to the String Object
    bool EqualTo(String s)
    {

        for (int i = 0; i < s.Length(); i++)
        {
            if (this->array[i] != s.getElement(i))
            {
                return false;
            }
        }
        return true;
    }

    //checks if the String s is greater that the String Object
    bool LessThan(String s)
    {
        if (this->EqualTo(s))
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.Length(); i++)
            {
                // cout << "comparing " << this->array[i] << " and " << s.getElement(i) << endl;
                if (this->array[i] > s.getElement(i))
                {
                    return false;
                }
                else if (this->array[i] < s.getElement(i))
                {
                    return true;
                }
            }
        }
        return true;
    }

    //checks if the String s is lesser that the String Object
    bool GreaterThan(String s)
    {

        if (this->EqualTo(s))
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.Length(); i++)
            {
                // cout << "comparing " << this->array[i] << " and " << s.getElement(i) << endl;
                if (this->array[i] < s.getElement(i))
                {
                    return false;
                }
                else if (this->array[i] > s.getElement(i))
                {
                    return true;
                }
            }
        }
        return true;
    }

    //replaces an element at index indx with a character ch
    void setElement(int indx, char ch)
    {
        this->array[indx] = ch;
    }
    void ToUpper()
    {
        for (int i = 0; i < Length(); i++)
        {
            if (isalpha(array[i]))
                array[i] = toupper(array[i]);
        }
    }
    void ToLower()
    {
        for (int i = 0; i < Length(); i++)
        {
            if (isalpha(array[i]))
                array[i] = tolower(array[i]);
        }
    }
    bool operator<(String s)
    {
        if (*this == s)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.Length(); i++)
            {
                // cout << "comparing " << this->array[i] << " and " << s.getElement(i) << endl;
                if (this->array[i] > s[i])
                {
                    return false;
                }
                else if (this->array[i] < s[i])
                {
                    return true;
                }
            }
        }
        return true;
    }
    bool operator>(String s)
    {
        if (*this == s)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.Length(); i++)
            {
                if (this->array[i] < s[i])
                {
                    return false;
                }
                else if (this->array[i] > s[i])
                {
                    return true;
                }
            }
        }
        return true;
    }
    bool operator==(String s)
    {
        for (int i = 0; i < s.Length(); i++)
        {
            if (this->array[i] != s[i])
            {
                return false;
            }
        }
        return true;
    }
    char operator[](int x)
    {
        return array[x];
    }
    //Gets user input
    friend istream& operator>>(istream& in, String& s)
    {
        String a_word(100);
        char b;
        int i = 0;
        while (in.get(b))
        {
            if (b == '\n')
            {
                break;
            }
            a_word.array[i] = b;
            i++;
        };

        s.array = a_word.array;
        s.length = i;
        return in;
    }

    //Writes the String object to the screen
    friend ostream& operator<<(ostream& out, String& s)
    {
        int i = 0;
        while (i < s.length)
        {
            out << s.array[i];
            i++;
        }
        return out;
    }

private:
    int capacity;
    int length;
    char* array;
};

//function to check if a String object is a palindrome
bool isPalindrome(String s)
{
    int length = s.Length();
    int bool_flag = 0;

    for (int i = 0; i < length; i++)
    {
        if (s.getElement(i) != s.getElement(length - i - 1))
        {
            bool_flag = 1;
            break;
        }
    }

    if (bool_flag)
    {

        return 0;
    }
    else
    {
        return 1;
    }
}

//Gets user input until "quit" is the input
void GetStrings(String sList[], int& count)
{
    cout << "Please input a sequence of values, or the word 'quit' to terminate" << endl;
    int i = 0;

    char quit_word[5] = { 'q', 'u', 'i', 't' };
    String quit(quit_word);

    char s[1] = { '\0' };

    sList[0] = String(s);
    while (true)
    {

        cin >> sList[i];

        if (quit.EqualTo(sList[i]))
        {
            break;
        }
        i++;
        count++;
    }
}

//sorts list in ascending order, the sequence of string values contained in its first parameter
//second parametr specifies teh number of string values contained in the first parameter
void Sort(String sList[], int count)
{
    String temp_array[count];
    int record = count;

    for (int i = 0; i < record; i++)
    {
        int ind = 0;
        String smallest_string = sList[0];
        // setting smallest string to sList[0]

        for (int j = 0; j < count; j++)
        {
            if (smallest_string.LessThan(sList[j]))
            {
                //new smallest_string found will be sList[j]
                smallest_string = sList[j];
                ind = j;
            }
        }
        temp_array[i] = smallest_string;
        // cout << "smallest atring is ";
        // smallest_string.Write();
        // copying the element to new array and moving everything one step up
        while (ind < count)
        {
            sList[ind] = sList[ind + 1];
            ind++;
        }
        count = count - 1;
    }

    // moving all data from temp array to original array

    for (int i = 0; i < record; i++)
    {
        sList[i] = temp_array[i];
    }
}

int main()
{
    int var1;
    //List to store all the user input
    String sList[100];
    int array_size = 0;

    GetStrings(sList, array_size);
    Sort(sList, array_size);

    cout << "\nSorted String List" << endl;
    for (int i = 0; i < array_size; i++)
    {
        cout << sList[i];
        if (isPalindrome(sList[i]))
        {
            cout << " *palindrome*";
        }
        cout << endl;
    }
    cout << "End of String List" << endl;

    return 0;
}
