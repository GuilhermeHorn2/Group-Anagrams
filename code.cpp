#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

struct str{
    string s;//string
    int x;//ASCII value
};

int string_int(char *s,int l);
//void swapp(vector<str> v,int i,int j);
int part(str* v,int left,int right);
void quick_sort(str* v,int left,int right);

/*
    Make a struct that stores a string and its value in ascii table,then sort based on that value,sort the struct itself not only the integer
*/

int main()
{

    str v[100];

    for(int i = 0;i < 3;i++){
        printf("String %d :",i);
        char c[100];
        cin >> c;
        str tmp;
        tmp.s = c;
        tmp.x = string_int(c,strlen(c));
        v[i] = tmp;
    }


    quick_sort(v,0,2);

    /*for(int i = 0;i < v.size();i++){
        cout << v[i].s << endl;
    }*/


    for(int i = 0;i < 3;i++){
        cout << v[i].s << endl;
    }


    return 0;
}

int string_int(char *s,int l){

    int c = 0;
    for(int i = 0;i < l;i++){
        c += s[i];
    }
    return c;
}

/*void swapp(vector<str> v,int i,int j){
    str tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}*/


int part(str* v,int left,int right){

    int pivot = v[right].x;

    int i = left;

    for(int j = left;j < right;j++){
        if(v[j].x <= pivot){
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[right]);
    return i;


}

void quick_sort(str* v,int left,int right){

    if(left < right){
        int point = part(v,left,right);
        quick_sort(v,left,point-1);
        quick_sort(v,point+1,right);
    }


}

