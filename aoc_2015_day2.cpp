#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
    int result = 0;
    int ribbon = 0;
    char x = 'x';
    int l,w,h;
    string a;
    string filename = "input.txt";
    ifstream infile(filename);
    if (!infile) {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    } 
    string line;
    while (getline(infile, line)){
        stringstream ss(line);
        ss >> l >> x >> w >> x >> h;
        // area1, area2, area3
        int area1 = l*w;
        int area2 = l*h;
        int area3 = w*h;
        int temp_ribbon = 0;
        if(l>w){
            if(l>h){
                temp_ribbon = 2*(w+h);
            } else {
                temp_ribbon = 2*(l+w);
            }
        } else {
            if(w>h){
                temp_ribbon = 2*(l+h);
            } else {
                temp_ribbon = 2*(l+w);
            }
        }
        ribbon += temp_ribbon;
        int vol = l*h*w;
        ribbon += vol;
        result += 2*(area1 + area2 + area3);
        if(area1 > area2){
            if (area2 > area3){
                result += area3;
            } else {
                result += area2;
            }
        } else {
            if(area1 > area3){
                result += area3;
            } else {
                result += area1;
            }
        }
    }
    infile.close();
    cout << "Wrapping Paper :" << result << endl;
    cout << "Ribbon Paper :" << ribbon << endl;
    return 0;
}
