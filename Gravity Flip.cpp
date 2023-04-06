#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //getting be (the biggest element of arr)
    int be = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > be) {
            be = arr[i];
        }

    }

    cout << "\n";
    cout << be;
    cout << "\n";
    //creating the box (array darr), storing cubes (1's) and void spaces (0's) in it
    int** darr = new int* [be];
    for (int i = 0; i < be; i++)
    {
        darr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i < arr[j]) {
                darr[i][j] = 1;
            }
            else {
                darr[i][j] = 0;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < be; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << darr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";


    //swapping vice-versa (vertically)
    int sbe = be;
    for (int i = 0; i < (be / 2); i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t = darr[i][j];
            darr[i][j] = darr[sbe - 1][j];
            darr[sbe - 1][j] = t;
        }
        sbe--;
    }
    for (int i = 0; i < be; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << darr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
    //changing gravity to the right
    int* oarr = new int[n];
    int ts;
    for (int darr_i = 0; darr_i < be; darr_i++)
    {
        for (int j = 0, oarr_i = 0; j < n; j++, oarr_i++)
        {
            //storing the current row to one-dimensional array oarr
            oarr[oarr_i] = darr[darr_i][j];
            //when it comes to the last element of the current row
            if (j == (n - 1))
            {
                //sort of one-dimensional array oarr
                for (int is = 0; is < (n - 1); is++)
                {
                    for (int js = 0; js < n - (is - 1); js++) {

                        if (((oarr[js + 1] == 0) && (oarr[js] == 1)) || ((oarr[js + 1] == 1) && (oarr[js] == 1)) || ((oarr[js + 1] == 0) && (oarr[js] == 0)))
                        {
                            ts = oarr[js];
                            oarr[js] = oarr[js + 1];
                            oarr[js + 1] = ts;
                        }
                    }
                }
                //putting one-dimensional array oarr to the current row
                for (int j = 0; j < n; j++)
                {
                    darr[darr_i][j] = oarr[j];
                }
            }
        }
    }

    for (int i = 0; i < be; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << darr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";

    //counting number of cubes in each column after gravity flip
    int* oarr1 = new int[be];
    int ones_in_col;
    for (int darr_j = 0; darr_j < n; darr_j++)
    {
        for (int i = 0, oarr1_j = 0; i < be; i++, oarr1_j++)
        {
            //storing the current column to one-dimensional array oarr1
            oarr1[oarr1_j] = darr[i][darr_j];
            //when it comes to the last element of the current column
            if (i == (be - 1))
            {
                //count 1's in the current column
                for (int i = 0, ones_in_col_counter = 0; i < be; i++)
                {
                    if (oarr1[i] == 1)
                    {
                        ones_in_col_counter++;
                    }
                    if (i == (be - 1))
                    {
                        ones_in_col = ones_in_col_counter;
                    }
                }
                cout << ones_in_col << " ";
            }
        }
    }

    cout << "\n";
    cout << "\n";
    return 0;
}