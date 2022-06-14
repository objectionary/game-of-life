#include "config.cpp"
#include "grid.cpp"

class gridSetTest : public Grid
{
public:
    void gridCheckTest(string filename)
    {
        Set();
        set<pair<int, int>> a;
        fstream my_file;
        my_file.open("./testCasesForSetCheck/" + filename, ios::in);
        if (!my_file)
        {
            cout << "Wrong File!!!";
            my_file.close();
            exit(0);
        }
        int n;
        my_file >> n;
        int q;
        my_file >> q;
        for (int i = 0; i < q; i++)
        {
            int x, y;
            my_file >> x >> y;
            a.insert({x, y});
        }

        assert(n == size);
        assert(n == g.size());
        for (int i = 0; i < n; i++)
        {
            assert(n == g[i].size());
            for (int j = 0; j < n; j++)
            {
                if (a.count({i + 1, j + 1}))
                {
                    assert(g[i][j].getCurState() == true);
                }
                else
                {
                    assert(g[i][j].getCurState() == false);
                }
            }
        }
        cout << "Successful!" << endl;
    }
};

void test()
{
    gridSetTest t = gridSetTest();
    t.gridCheckTest("case3.txt"); // here you can check any one of 3 tests in testCases folder
}
