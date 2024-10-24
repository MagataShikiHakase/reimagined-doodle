//Combination of sum
/*#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, x, count = 0;
    cin >> n >> k;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(vec[i] + vec[j] == k)
                count++;
        }
    }
    cout << count;
    return 0;
}*/

//Safety of password
/*#include <iostream>
#include <cmath>

using namespace std;  

int main(){
    string password;
    int counterOfDigit = 0, counterOfUpper = 0, counterOfLower = 0, letterOfPassword;
    long int score;
    cout << "enter the password: ";
    cin >> password;
    
    for(int i = 0; i < password.length(); i++){
        if(isupper(password[i]))
            counterOfUpper++;
        else if(islower(password[i]))
            counterOfLower++;
        else
            counterOfDigit++;
    }
    letterOfPassword = counterOfUpper + counterOfLower + counterOfDigit;
    //大文字または小文字のみで構成されている場合
    if(counterOfUpper == letterOfPassword || counterOfLower == letterOfPassword)
        score = pow(2, letterOfPassword);
    //数字のみで構成されている場合
    else if(counterOfDigit == letterOfPassword)
        score = 1;
    //小文字と数字または大文字と数字で構成されている場合
    else if(counterOfUpper == 0 || counterOfLower == 0)
        score = pow(4, letterOfPassword);
    //数字のみで構成されている場合
    else if(counterOfDigit == 0)
        score = pow(8, letterOfPassword);
    //大文字、小文字、数字全て含まれている場合
    else
        score = pow(32, letterOfPassword);
    
    cout << "score: " << score;
    return 0;
}*/

//The value of sum
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inputFile("receipt.txt");
    ofstream outputFile("sum.txt");

    int number, sum = 0;

    if(!inputFile){
        cerr << "Error opening receipt.txt" << endl;
        return 1;
    }

    while(inputFile >> number)
        sum += number;
    
    outputFile << "Sum: " << sum << endl;
    
    inputFile.close();
    outputFile.close();

    cout << "The sum has been written to sum.txt" << endl;

    return 0;
}