////////////////////////////////////////////////////////////////////
//                   
// Author:           (Seth Allen)
// Email:            (sballen085@gmail.com)
// Label:            (A08)
// Title:            (Multi Color Storage)
// Course:           (2143)
// Semester:         (Spring 2021)
//
// Description:
//       Stores multiple colors in a vector to have a color pallet
//
// Usage:
//       Run the program it will ask you how many colors you want 
//       enter the number it will than be multiplied by 3 to have
//       an Red Green Blue or RGB
//
// Files:
//      main.cpp    :driver program
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

/**
 * RgbColor
 * 
 * Description:
 *      This class implements a vector to store an Red Green Blue
 *      in a vector which will
 *      than be printed out in a format as [r,g,b]
 * 
 * Public Methods:
 *                              RgbColor();
 *                              RgbColor(vector<int> num, int);
 *      void                    SetR(int);
 *      void                    SetG(int);
 *      void                    SetB(int);
 *      int                     GetR();
 *      int                     GetG();
 *      int                     GetB();
 *      friend ostream& operator<<(ostream&, const RgbColor&);
 *      
 * 
 * Private Methods:
 *      int             r;
 *      int             g;
 *      int             b;
 *      vector<int> RGBvec;
 * 
 * Usage: 
 * 
 *      RgbColor(vector<int> num, int) //builds the vector with 
 *                                     //the colors from user input
 *      
 */
class RgbColor
{
    int r;                           //int 0-255 red
    int g;                           //int 0-255 green
    int b;                           //int 0-255 blue
    vector<int> RGBvec;
public:
    RgbColor();                      // default constructor
    RgbColor(vector<int> num, int);  // overloaded 2

    void SetR(int);                  // setter red
    void SetG(int);                  // setter green
    void SetB(int);                  // setter blue

    int GetR();                      // getter red
    int GetG();                      // getter green
    int GetB();                      // getter blue

    // add (mix) two colors
    RgbColor operator+(const RgbColor&);
    void print();

};


    /**
     * Public: RgbColor
     * 
     * Description:
     *      overides the + operator to print out the average of red
     *      green and blue
     * 
     * Params:
     *      - private data members
     *      - sends in the plus data member for overridding 
     * 
     * Returns:
     *      - none
     */
RgbColor RgbColor::operator+(const RgbColor& rhs)
{
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

    /**
     * Public: RgbColor
     * 
     * Description:
     *      default operator that sets all int to 0
     * 
     * Params:
     *      - none it grabs the private data members
     * 
     * Returns:
     *      - none
     */
RgbColor::RgbColor()
{
    r = g = b = 0;
}

    /**
     * Public: function_name
     * 
     * Description:
     *      fills the vector with Red Green and Blue Values
     * 
     * Params:
     *      int     Vector<int> num
     *      int     Color
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
RgbColor::RgbColor(vector<int> num, int Color)
{
    int i = 0;
    RGBvec = num;
    while(i < Color)
    {
        cout << "How much red do you want enter a number"
             << " between 0 and 255" << endl;
        cin >> r;
        RGBvec.push_back(r);
        cout << "How much green do you want enter a number"
             << " between 0 and 255" << endl;
        cin >> g;
        RGBvec.push_back(g);
        cout << "How much blue do you want enter a number" 
             <<" between 0 and 255" << endl;
        cin >> b;
        RGBvec.push_back(b);
        i += 3;
    }
}

    /**
     * Public: print
     * 
     * Description:
     *      prints the array to cout
     * 
     * Params:
     *      nothing
     * 
     * Returns:
     *      - nothing
     */
void RgbColor::print()
{
    int i = 0;
    while(i < RGBvec.size())
    {
        cout << '[' << RGBvec[i] << ',' << RGBvec[i+1] << ',' << RGBvec[i+2] << ']' << endl;
        i += 3;
    }
}

int main()
{
    int ColorNum;
    vector<int> colorPallet;

    cout << "How many colors will you have " << endl;
    cin >> ColorNum;
    ColorNum *= 3;                             //so their is always an RGB
    RgbColor Color1(colorPallet, ColorNum);    //Pushes the vector to the class
    Color1.print();
    system("pause");
    return 0;
}