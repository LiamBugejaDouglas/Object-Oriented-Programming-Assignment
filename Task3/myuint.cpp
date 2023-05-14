#include "myuint.hpp"
#include "string.h"

using namespace std;

//Returns 1 or 0 depending if the character is odd or even respectively.
std::string defineOdd(std::string num){

    char ch = num.back();

    if(ch == '1'){

        return "1";
    }
    else if(ch == '3'){

        return "1";
    }
    else if(ch == '5'){

        return "1";
    }
    else if(ch == '7'){

        return "1";
    }
    else if(ch == '9'){

        return "1";
    }
    else{

        return "0";
    } 
        
}

//Divides a string number by two, ("50"/"2" = "25");
std::string divideByTwo(std::string num){

    std::string ans="";
        
    size_t idx = 0;
    int temp = num[idx] - '0';

    while(temp<2){

        temp = temp*10 + (num[++idx]-'0');
    }

    while(num.size() > idx){

        ans+=(temp/2)+'0';

        temp = (temp%2) * 10 + num[++idx] - '0';
    }

    if(ans.length()==0){

        return "0";
    }

    return ans;
}

//Converts a decimal string number to binary by using the defineOdd and dividebyTwo methods.
std::string decimalStringToBinary(std::string num){

    std::string binary = "";

    while(num != "0"){

        binary = binary.insert(0,defineOdd(num));
        num = divideByTwo(num);
    }

    return binary;
}

//Convert binary string to a vector boolean
std::vector<bool> binaryStringToVectorBool(std::string num, int T){

    std::vector<bool> binary;
    std::string tempNum = decimalStringToBinary(num);

    int counter = (tempNum.length())-1;
    
     //std::cout<< tempNum << "\n";

    for(int i=0; i<T; i++){

        if(tempNum[counter]=='1'){

            binary.push_back(true);
            counter--;
    
        }else{

            binary.push_back(false);
            counter--;
        }
    }

    reverse(binary.begin(), binary.end());

    /*for(bool x : binary){

        std::cout << x;
    }*/

    return binary;
}

//Converts binary number in two's complement, used for - operator.
std::vector<bool> twosComplement(std::vector<bool> result){

    result.flip();

    int temp=1;

    for(int i=result.size()-1; i>=0; i--){

        if(result[i]==1 && temp==1){

            result[i]=0;
            temp=1;
        }
        else if(result[i]==0 && temp==1){

            result[i]=1;
            temp=0;
        }
        else{
            break;
        }
    }

    return result;
}

//Adds two binary numbers. Uses two boolean vectors.
std::vector<bool> addition(std::vector<bool> num1, std::vector<bool> num2){

    int size1 = std::max(num1.size(), num2.size());

    std::vector<bool> result(size1);

    int temp=0;

    for(int i=result.size()-1; i>0; i--){

        if(num1[i]==0 && num2[i]==0 && temp==0){

            result[i]=0;
        }
        else if(num1[i]==1 && num2[i]==0 && temp==0){

            result[i]=1;
        }
        else if(num1[i]==0 && num2[i]==1 && temp==0){

            result[i]=1;
        }
        else if(num1[i]==0 && num2[i]==0 && temp==1){

            result[i]=1;
            temp=0;
        }
        else if(num1[i]==1 && num2[i]==1 && temp==0){

            result[i]=0;
            temp=1;
        }
        else if(num1[i]==1 && num2[i]==0 && temp==1){

            result[i]=0;
            temp=1;
        }
        else if(num1[i]==0 && num2[i]==1 && temp==1){

            result[i]=0;
            temp=1;
        }
        else if(num1[i]==1 && num2[i]==1 && temp==1){

            result[i]=1;
            temp=1;
        }
    }

    if(num1.size()!=num2.size()){

        size_t flag = num1.size();

        if(flag<num2.size()){

            for(size_t i=num1.size(); i<num2.size(); i++){

                if(num2[i]==0 && temp==0){

                    result[i]=0;
                }
                else if(num2[i]==1 && temp==0){

                    result[i]=1;
                }
                else if(num2[i]==0 && temp==1){

                    result[i]=1;
                    temp=0;
                }
                else if(num2[i]==1 && temp==1){

                    result[i]=0;
                    temp=1;
                }
            }
        }else{

            for(size_t i=num2.size(); i<num1.size(); i++){

                if(num1[i]==0 && temp==0){

                    result[i]=0;
                }
                else if(num1[i]==1 && temp==0){

                    result[i]=1;
                }
                else if(num1[i]==0 && temp==1){

                    result[i]=1;
                    temp=0;
                }
                else if(num1[i]==1 && temp==1){

                    result[i]=0;
                    temp=1;
                }
            }
        }
    }
    return result;
}

//Default constructor
template <int T>
myuint<T>::myuint(){

    static_assert(floor(log2(T)) == log2(T), "myuint only accepts unsigned integers or strings, and must be 2^n bits");
    static_assert(T > 0, "myuint only accepts 2^n bits");
  
}

//Constructor accepts an intiger from the user.Checks if T is 2^n and converts the intiger number to a boolean vector.
template<int T>
myuint<T>::myuint(int num){

    this->bits = bits;

    static_assert(floor(log2(T)) == log2(T), "myuint only accepts unsigned integers or strings, and must be 2^n bits");
    static_assert(T > 0, "myuint only accepts 2^n bits");

    std::string str_num = std::to_string(num);
    
    while(bits>0){

        this->binaryNumVec.push_back(false);
        bits--;
    }

    binaryNumVec = binaryStringToVectorBool(str_num, T);

    /*for(int i=0; i<binaryNumVec.size(); i++){

        std::cout << binaryNumVec[i];
    }*/

}

//Constructor accepts an string from the user.Checks if T is 2^n and converts the string number to a boolean vector.
template<int T>
myuint<T>::myuint(std::string num){

    this->bits = bits;

    static_assert(floor(log2(T)) == log2(T), "myuint only accepts unsigned integers or strings, and must be 2^n bits");
    static_assert(T > 0, "myuint only accepts 2^n bits");

    while(bits>0){

        this->binaryNumVec.push_back(false);
        bits--;
    }

    binaryNumVec = binaryStringToVectorBool(num, T);

    /*for(size_t i=0; i<binaryNumVec.size(); i++){

        std::cout << binaryNumVec[i];
    }*/
}

//Setter
template <int T>
void myuint<T>::setNumber(std::vector<bool>binary){

    myuint<T>:: binaryNumVec = binary;
}

//Getter
template <int T>
std::vector<bool> myuint<T>::getVectorBool(){

    return myuint<T>::binaryNumVec;
}

//Right shift operator
template <int T>
myuint<T> myuint<T>::operator>>(int num){

    std::vector<bool> temp = myuint<T>::binaryNumVec;

    for(int i=0; i<num; i++){

        temp.erase(temp.end());
        temp.insert(temp.begin(),false);
    }

    myuint<T> result;

    result.setNumber(temp);

    /*for(size_t i=0; i<temp.size(); i++){

        std::cout << temp[i];
    }*/

    return result;
}

//Left shift operator
template <int T>
myuint<T> myuint<T>::operator<<(int num){

    std::vector<bool> temp = myuint<T>::binaryNumVec;

    for(int i=0; i<num; i++){

        temp.erase(temp.begin());
        temp.push_back(false);
    }

    myuint<T> result;

    result.setNumber(temp);

    /*for(size_t i=0; i<temp.size(); i++){

        std::cout << temp[i];
    }*/

    return result;
}

//Addition operator
template <int T>
myuint<T> myuint<T>::operator+(myuint<T> num){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;
    std::vector<bool> num2 = num.getVectorBool();

    //Using addition method, adds two boolean vectors
    std::vector<bool> result = addition(num1, num2);

    myuint<T> finalResult;

    finalResult.setNumber(result);

    /*for(int i=0; i<result.size(); i++){

        std::cout<< result[i];
    }*/

    return finalResult;
}

//Subtraction operator
template <int T>
myuint<T> myuint<T>::operator-(myuint<T> num){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;
    std::vector<bool> num2 = num.getVectorBool();

    //The RHS number is turned to negative
    num2=twosComplement(num2);

    //Using the addition method since the second binary number is negative, 5 + (-2) = 3.
    std::vector<bool> result = addition(num1, num2);

    myuint<T> finalResult;

    finalResult.setNumber(result);

    /*for(int i=0; i<result.size(); i++){

        std::cout<< result[i];
    }*/

    return finalResult;
}

//Multiplication operator
template <int T>
myuint<T> myuint<T>::operator*(myuint<T> num){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;
    std::vector<bool> num2 = num.getVectorBool();

    //Find the largest vector and use its size for result.
    size_t tempSize=num1.size();

    if(tempSize<num2.size()){

        tempSize=num2.size();
    }

    std::vector<bool> result(tempSize);
    std::vector<bool> temp(num1.size());

    int placeholder=0;

    //Loop through the multiplier, if i=1 than add the the multiplicant to result.
    for(int i=num2.size()-1; i>=0; i--){

        if(num2[i]!=0){

            temp=myuint<T>::binaryNumVec;

            for(int i=0; i<placeholder; i++){

                temp.push_back(0);
                temp.erase(temp.begin());
            }

            result = addition(temp, result);
        }
        //Used for adding the next higher order binary number.
        placeholder++;
    }

    myuint<T> finalResult;

    finalResult.setNumber(result);

    /*for(int i=0; i<result.size(); i++){

        std::cout<< result[i];
    }*/

    return finalResult;
}

//Equals operator
template <int T>
bool myuint<T>::operator==(myuint<T> num){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;
    std::vector<bool> num2 = num.getVectorBool();

    //Loops through both binary numbers and checks if each value is equal.
    for(int i=0; i<T; i++){

        if(num1[i]!=num2[i]){

            return false;
        }
    }

    return true;
}

//Greater than operator
template <int T>
bool myuint<T>::operator>(myuint<T> num){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;
    std::vector<bool> num2 = num.getVectorBool();

    //Loops through binary numbers and compaers each position
    for(int i=0; i<T; i++){

        //If the current positions are not equal, than one is larger.
        if(num1[i]!=num2[i]){

            if(num1[i]==1){

                return true;
            }
            else{

                return false;
            }
        }
    }

    //Numbers are equal.
    return false;
}

//Self subtraction operator
template <int T>
myuint<T> myuint<T>::operator-=(myuint<T> num){

    return *this = *this - num;
}

//Division operator
template<int T>
myuint<T> myuint<T>::operator/(myuint<T> num){

    myuint<T> temp = *this; 

    std::vector<bool> result(T, 0);
    std::vector<bool> tempVec(T-1, 0);

    tempVec.push_back(1);

    //While the numerator is greater or equal to denominator, subtract and increment result
    while(temp>num || temp==num){

        temp-=num;
        result = addition(result, tempVec);
    }

    myuint<T> finalResult;

    finalResult.setNumber(result);

    return finalResult;
}

//Modulud operator
template<int T>
myuint<T> myuint<T>::operator%(myuint<T> num){

    myuint<T> temp = *this;

    //While the numerator is greater or equal to denominator, subtract.
    while(temp>num || temp==num){

        temp-=num;
    }

    //Remainder will be returned.
    return temp;
}

//Method to convert myuint to specifed number type.
template<int T>
template<typename type>
type myuint<T>::convert(){

    std::vector<bool> num1 = myuint<T>::binaryNumVec;

    type result = 0;
    auto temp=0;

    for(int i=T-1; i>=0; i--){

        if(num1[i]==1){

            result += pow(2, temp);
        }

        temp++;
    }
    return result;
}

int main(){

    //Testing operators and different data types

    std::string num1 = "10";
    std::string num2 = "3";

    myuint<8> a (num1);
    myuint<8> b = a / (num2);
    std::cout << b.convert<int>() << std::endl; 

    myuint<16> c(50);
    myuint<16> d = c * (5) << (2);
    std::cout << d.convert<int>() << std::endl; 

    //Checking if static_assert works
    //myuint<17> e(30);

    return 0;
}

