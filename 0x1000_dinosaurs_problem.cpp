#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <sstream>

using namespace std;

class dinosaurs {
    public:
        int read_file(fstream& filein1, fstream& filein2) {

            unordered_map <string, float> aMap;
            priority_queue <pair <float, string> > aQueue;
            stringstream ss;
            string aLine;
            string token;
            vector <string> each;

            while(getline(filein2, aLine)) {


                ss.clear();
                ss.str(aLine);
                while(getline(ss, token, ',')) {
                    //cout << token <<endl;
                    each.push_back(token);
                }
                if(each[2] == "bipedal"){
                    aMap[each[0]] = stof(each[1]);
                }
                each.clear();
            }

            filein2.close();


            while(getline(filein1, aLine)) {
                ss.clear();
                ss.str(aLine);
                while(getline(ss, token, ',')) {
                    each.push_back(token);
                }
                if(aMap.count(each[0])) {
                    aMap[each[0]] = speed(stof(each[1]), aMap[each[0]]);
                }
                each.clear();
            }

            filein1.close();

            for(auto &it:aMap) {
                aQueue.push({it.second, it.first});
            }

            while(aQueue.size()) {
                cout << aQueue.top().second <<endl;
                aQueue.pop();
            }
            return 1;
        }

        /***                                                                  *
         * calculate speed                                                    *
         * speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)  *
         *                                                                   ***/
        float speed(float leg_length, float stride_length) {
            return (stride_length / leg_length - 1) * sqrt(leg_length * 9.8);
        }


};

int main()
{
    fstream file1("C:\\OneDrive\\Jobs\\Problems&Solutions\\dinosaurs_dataset_1.csv", fstream::in);
    fstream file2("C:\\OneDrive\\Jobs\\Problems&Solutions\\dinosaurs_dataset_2.csv", fstream::in);
    dinosaurs d;
    d.read_file(file1, file2);
    return 0;
}