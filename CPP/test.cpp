#include "config.cpp"
#include "grid.cpp"
class gridTest : public Grid
{
public:
    gridTest(string filename) : Grid(filename)
    {
    }

    void gridCheckSetTest(string filename)
    {
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
        cout << "Successful Set Function on test " << filename << "!" << endl;
        my_file.close();
    }
    void gridCheckCountTest(string filename)
    {
        fstream my_file;
        my_file.open("./testCasesForCountCheck/" + filename, ios::in);
        if (!my_file)
        {
            cout << "Wrong File!!!";
            my_file.close();
            exit(0);
        }
        int n;
        my_file >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y, ans;
            my_file >> x >> y >> ans;
            x--, y--;
            assert(ans == count(x, y) - g[x][y].getCurState());
        }
        cout << "Successful Count Function on test " << filename << "!" << endl;
        my_file.close();
    }

    void gridCheckNextGenTest(string filename)
    {
        fstream my_file;
        my_file.open("./testCasesForNextGenCheck/" + filename, ios::in);
        if (!my_file)
        {
            cout << "Wrong File!!!";
            my_file.close();
            exit(0);
        }
        nextGen();
        int n;
        my_file >> n;
        set<pair<int,int>> st;
        for (int i = 0; i < n; i++)
        {
            int x,y;
            my_file >> x >> y;
            x--,y--;
            st.insert({x,y});
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                assert(g[i][j].getCurState() == st.count({i,j}));
            }
        }
        cout << "Successful NextGen Function on test " << filename << "!" << endl;
        my_file.close();
    }

    void  gridCheckStateChangeTest(string filename){
        Cell x = Cell();
        x.setState(true);
        assert(x.getCurState() == true);
        x.changeNewState(false);
        x.changeCurState();
        assert(x.getCurState() == false);
        cout << "Successful ChangeState Function on test " << filename << "!" << endl;
    }
};

void test()
{
    for (int i = 1; i <= 3; i++)
    {

        string filename = "case" + to_string(i) + ".txt";
        gridTest t = gridTest(filename);
        t.Set(filename);
        // Set Function Testing
        t.gridCheckSetTest(filename);

        // Count Function Testing
        t.gridCheckCountTest(filename);

        // NextGen Function Testing
        t.gridCheckNextGenTest(filename);

        // State Fucnction Testing
        t.gridCheckStateChangeTest(filename);

        cout << endl;
        t.close();
    }
}
