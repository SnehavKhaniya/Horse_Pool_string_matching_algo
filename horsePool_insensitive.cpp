#include <bits/stdc++.h>
using namespace std;

int* shiftTable(string p){
    
    int m = p.size();

    static int shift[26];   /***/

    for(int i = 0; i < 26; ++i){
        shift[i] = m;
    }

    for(int i = 0; i <= m - 2; i++){
        shift[p[i] - 'a'] = m - i - 1;
    }

    return shift;
}

void horsePoolMatching(string t, string p){
    int n = t.size();
    int m = p.size();

    int *shift = shiftTable(p);

    cout << "Matched at:\n";
    int s = 0;

    while(s <= n - m){
        if(t[s + m - 1] == p[m - 1]){           //if last char of window matched

            int i = m - 2;
            while(i >= 0 && t[s + i] == p[i]){  //check matching of other chars
                i--;
            }

            if(i == -1){                        //if all chars are matched with pattern
                cout << s << " ";
            }
        }

        if(t[s + m - 1] == ' '){                //shift of ' '(space) is also m (length of pattern).
            s += m;
            continue;
        }

        s += shift[t[s + m - 1] - 'a'];         //shifted by last char(of current window)'s shift from shift table.
    }
}

int main(){

    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);

    //cout << text << endl << pattern << endl;
    horsePoolMatching(text, pattern);

    return 0;
}