#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w, basic1, t, day, day_input, day_output;

    cin >> w >> basic1 >> t;
    cin >> day >> day_input >> day_output;

    int w1 = w;
    int w2 = w;

    int basic2 = basic1;

    for (int i=0; i<day; i++){
        w1 += day_input - (basic1 + day_output);
        w2 += day_input - (basic2 + day_output);
        if (abs(day_input - (basic2 + day_output)) > t)
            basic2 += floor((day_input - (basic2+day_output))/2.0);
    }

    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << basic1 << "\n";

    if (w2 <= 0 || basic2 <= 0)
        cout << "Danger Diet\n";
    else{
        cout << w2 << " " << basic2 << " ";
        if (basic1 - basic2 > 0) 
            cout << "YOYO";
        else
            cout << "NO";
    }
}