#include <iostream>
#include <getopt.h>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    if (argc==1) {
        cout << "Parametrs:\n a - среднее арифметическое\n m  - медиана\n у нас 9-11 операнд\n";
        exit(1);
    }

    int opt, i, d, st=0, k=1;
    float z, a=0, b, res;
    for (i=2; i<argc; i++){
        st+=1;
    }
    if ((st < 9) or (st > 11)){
        return 0;
    }
    while ((opt = getopt (argc, argv, "a:m:")) != -1) {
        switch (opt) {
        case 'a':
            for(i=3; i<argc; i++) {
                b = strtol(argv[i], NULL, 10);
                a = a + b;
                k+=1;
            }
            z = a / k;
            cout<< "RESULT: "<< z << endl;
            break;
        case 'm':
            vector< int > arr(argc-2);
            for(i=3; i<argc-2; i++) {
                b = strtol(argv[i+2], NULL, 10);
                arr[i] = b;
            }
            sort(arr.begin(), arr.end());
            if (argc-2 == 9 or argc-2 == 11) {
                int k = ceil((argc-2) / 2);
                res = arr[k];
            }
            else if (argc-2 == 10) {
                int k = ((argc-2) / 2);
                z = arr[k-1]+arr[k];
                res = z / 2;
            }
            cout<< "RESULT: "<< res << endl;
            break;
        }
    }
}
