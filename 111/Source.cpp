#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
template<class T>
void del(vector<T> &ch) {
    for (int i = 0; i < ch.size() - 1; ++i) {
        if (ch[i] == ch[i + 1]) {
           ch.erase(ch.begin() + i);
            i--;
        }
    }

}
class mnozhestvo {
public:
    mnozhestvo(){}
    virtual mnozhestvo mult (mnozhestvo &x) { return {}; };
virtual mnozhestvo add (mnozhestvo &x) { return {}; };
virtual mnozhestvo sim_sub(mnozhestvo &x) { return {}; };
vector<int> ch;
vector<string> str;
};
class chisla : public mnozhestvo {
public:
    explicit chisla(const vector<int> &get) {
           ch = get;
           sort(ch.begin(), ch.end());
         del(ch);
       }
	const mnozhestvo* x;
    mnozhestvo res;
    mnozhestvo mult(mnozhestvo& x) override {
        for (int &i: ch) {
                    res.ch.push_back(i);
                }
                for (int &i: x.ch) {
                    bool flag = 1;
                    for (int j: ch) {
                        if (i == j) flag = 0;
                    }
                    if (flag == 1) res.ch.push_back(i);
                }
                chisla eend(res.ch);
                sort(eend.ch.begin(), eend.ch.end());
                del(eend.ch);
                return eend;

	}
    mnozhestvo add(mnozhestvo& x) override {
        mnozhestvo res;
                   try {

                       for (int &i: x.ch) {
                           for (int j: ch) {
                               if (i == j) res.ch.push_back(i);
                           }
                       }
                       bool flag=0;
                       for (int &i: x.ch) {
                           for (int j: ch) {
                               if (i == j) flag=1;
                           }
                       }
                       if(flag==0) res.ch={0};
                   }

                   catch (std::out_of_range){
                       res.ch = {};
                   }
                   chisla eend(res.ch);
                   sort(eend.ch.begin(), eend.ch.end());
                   del(eend.ch);
                   return eend;

               }
    mnozhestvo sim_sub(mnozhestvo& x) override {
        mnozhestvo res;
        for (int &i: x.ch) {
            bool flag = 1;
            for (int j: ch) {
                if (i == j) flag = 0;
            }
            if (flag == 1) {
                res.ch.push_back(i);
            }
        }
        for (int &i: ch) {
            bool flag = 1;
            for (int j: x.ch) {
                if (i == j) flag = 0;
            }
            if (flag == 1) {
                res.ch.push_back(i);
            }
        }
        chisla eend(res.ch);
        sort(eend.ch.begin(), eend.ch.end());
        del(eend.ch);
        return eend;

    }

};
class stroki : public mnozhestvo {
public:
    stroki(const vector<string> &x) {
        str = x;
        sort(str.begin(), str.end());
        del(str);
    }

    mnozhestvo add(mnozhestvo &x) override {
        mnozhestvo res;
        for (string &i: str) {
            res.str.push_back(i);
        }
        for (string &i: x.str) {
            bool flag = true;
            for (string j: str) {
                if (i == j) flag = false;
            }
            if (flag == 1) res.str.push_back(i);
        }
        stroki eend(res.str);
        sort(eend.str.begin(), eend.str.end());
        del(eend.str);
        return eend;

    }

    mnozhestvo mult(mnozhestvo &x) override {
            mnozhestvo res;
            try {
                for (string &i: x.str) {
                    for (string j: str) {
                        if (i == j) res.str.push_back(i);
                    }
                }
                bool flag=0;
                for (string &i: x.str) {
                    for (string j: str) {
                        if (i == j) flag=1;
                    }
                }
                if(flag==0) res.str={""};
            }
            catch (out_of_range){
                res.str = {};
            }
            stroki eend(res.str);
            sort(eend.str.begin(), eend.str.end());
            del(eend.str);
            return eend;


        }

    mnozhestvo sim_sub(mnozhestvo &x) {
        mnozhestvo res;
        for (string &i: x.str) {
            bool flag = true;
            for (string j: str) {
                if (i == j) flag = false;
            }
            if (flag == 1) {
                res.str.push_back(i);
            }
        }
        for (string &i: str) {
            bool flag = true;
            for (string j: x.str) {
                if (i == j) flag = false;
            }
            if (flag == 1) {
                res.str.push_back(i);
            }
        }
        stroki eend(res.str);
        sort(eend.str.begin(), eend.str.end());
        del(eend.str);
        return eend;


    }


};
