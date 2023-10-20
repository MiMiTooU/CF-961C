#include <bits/stdc++.h>
using namespace std;
struct chess
{
    vector <vector<bool>> node;
};

int main(void)
{
    map<int, chess> a;
    int odd_n;
    int operation=0;
    cin >> odd_n;
    for (int i = 0; i < 4; i++)
    {
        chess temp;
        vector <vector<bool>> temp_a;
        for (int a = 0; a < odd_n;a++)
        {
            string temp_input;
            vector<bool> temp_b;
            cin >> temp_input;
            for (int b = 0; b < odd_n; b++)
            {
                if (temp_input[b] == '1')
                {
                    temp_b.push_back(1);
                }
                else
                {
                    temp_b.push_back(0);
                }
            }
            temp_a.push_back(temp_b);
        }
        temp.node = temp_a;
        a.insert(make_pair(i, temp));
    }
    auto it_o1 = a.begin(), it_o2 = a.begin(), it_e1 = a.begin(), it_e2= a.begin();
    int operation_temp;
    for (; it_o1 != a.end(); it_o1++)
    {
        if (it_o1->first != 3)
        {
            it_o2 = it_o1;
            for (it_o2++; it_o2 != a.end(); it_o2++)
            {
                operation = 0;
                for (it_e1=a.begin(); it_e1 != a.end(); it_e1++)
                {
                    if (it_e1 != it_o1 && it_e1 != it_o2)
                    {
                        break;
                    }
                }
                for (it_e2=a.begin(); it_e2 != a.end(); it_e2++)
                {
                    if (it_e2 != it_o1 && it_e2 != it_o2&&it_e2!=it_e1)
                    {
                        break;
                    }
                }
                for (int x = 0; x < odd_n; x++)
                {
                    for (int y = 0; y < odd_n; y++)
                    {
                        if ((x + 1) % 2 != 0)
                        {
                            if (y % 2 == 0)
                            {
                                if (it_o1->second.node[x][y]==0)
                                {
                                    operation++;
                                }
                                if (it_o2->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                                if (it_e1->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_e2->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                            }
                            else
                            {
                                if (it_o1->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_o2->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_e1->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                                if (it_e2->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                            }
                        }
                        else
                        {
                            if (y % 2 == 0)
                            {
                                if (it_o1->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_o2->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_e1->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                                if (it_e2->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                            }
                            else
                            {
                                if (it_o1->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                                if (it_o2->second.node[x][y] == 0)
                                {
                                    operation++;
                                }
                                if (it_e1->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                                if (it_e2->second.node[x][y] == 1)
                                {
                                    operation++;
                                }
                            }
                        }
                    }
                }
                if (it_o1->first == 0 && it_o2->first == 1)
                {
                    operation_temp = operation;
                }
                else
                {
                    if (operation_temp > operation)
                    {
                        operation_temp = operation;
                    }
                }

            }
        }
    }
    operation = operation_temp;
    cout << operation << endl;
    return 0;
}