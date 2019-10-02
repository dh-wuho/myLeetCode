// brute force

#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k;
    while(cin >> n >> k) {
        list<int> v;
        for(int i = 0; i < n; ++i) {
            v.push_back(i);   
        }
        auto pos = v.begin();
        while(v.size() > 1) {
            // start from first element, k - 1 jumps are required.
            for(int i = 0; i < k - 1; ++i) {
                ++pos;
                if(pos == v.end())
                    pos = v.begin();
            }
            pos = v.erase(pos);
            if(pos == v.end())
                pos = v.begin();
        }
        cout << v.front() << endl;
    }
    return 0;
}


// dp
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int last = 0;
    // array starts from 0, i the total number of current elements
    for(int i = 2; i < n + 1; i++) {
        last = (last + k) % i;
    }
    
    cout << last << endl;

    return 0;
}
