{
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

    using namespace rapidjson;
    using namespace std;

    ifstream ifs("G4simu.json");
    IStreamWrapper isw(ifs);

    Document d;
    d.ParseStream(isw);

    typedef pair<string, int> intpair;
    typedef pair<string, double> doublepair;
    vector<intpair> vint_branch;
    vector<doublepair> vdouble_branch;
    for (SizeType i = 0; i < d["branch"].Size(); i++)
    {
        if (string(d["branch"][2 * i + 1].GetString()) == "int")
        {
            intpair s;
            s.first = string(d["branch"][2 * i].GetString());
            s.second = d["init_value"]["int"].GetInt();
            vint_branch.push_back(s);
        }
        if (string(d["branch"][2 * i + 1].GetString()) == "double")
        {
            doublepair s;
            s.first = string(d["branch"][2 * i].GetString());
            s.second = d["init_value"]["double"].GetDouble();

            vdouble_branch.push_back(s);
        }
    }
    for (int i = 0; i < vint_branch.size(); i++)
    {
        //cout << vint_branch[i] << endl;
        cout << vint_branch[i].first << "\t" << vint_branch[i].second << endl;
    }
    for (size_t i = 0; i < vdouble_branch.size(); i++)
    {
        //cout << vdouble_branch[i] << endl;
        cout << vdouble_branch[i].first << "\t" << vdouble_branch[i].second << endl;
    }
    cout << d["maxhit"].IsInt() << endl;
}