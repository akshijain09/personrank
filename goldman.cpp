/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include <bits/stdc++.h>
#include<fstream>
#include<string.h>
#include<sstream>
#include<vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

vector<string> findmention(vector<string>&tweet){
    string arr[20];
    int i=0;
    vector<string>mentions;
    string mention;
    char c;
   int n=tweet.size();
   int p,o,b;
   char ch='@';
   string k;
   for(int i=0;i<n;i++){
        int p=0,o=0,b=0;
    k=tweet[i];
    mention.clear();
    p=k.find(ch);
    o=p;
    while(p<k.size()){
    if(((k[p]>='a'&&k[p]<='z') || (k[p]>='A' && k[p]<='Z')|| (k[p]==ch)|| k[p]=='_') && p<k.size()){
        mention+=k[p];
            p++;
    }
    else{

        break;
    }
    }
     //cout<<mention<<"\n";
      mentions.push_back(mention);
   }
  return mentions;
}




int findlikes(string str){
    vector<int>likes;
    int index = str.find_last_of('\t');
        index++;

        string li = "";
        while(index<str.size())
      {
           li+=str[index];

           index++;
      }

    int like;
    stringstream geek(li);
    geek>>like;
    return like;

}
string findtweet(string str,int pos){
    vector<string>tweet;
    int index,p;
    string tweets;
    //cout<<pos;
    pos++;
    while(str[pos]!='\t'){
       if(str[pos]!='\t'){
        p=pos;
        break;
       }
       else{
        pos++;
       }
    }
    index = str.find_last_of('\t');
    index--;





for(int i=p;i<=index;i++){
    tweets+=str[i];
}
return tweets;
}
bool sortByVal(const pair<string, int> &a, const pair<string, int> &b)
    {
       return (a.second > b.second);
    }
int main(){

    unordered_map<string,int>mp;
   //multimap<string, int, greater<int> > mp;
    vector<string>username;
    vector<string>tweet;
    vector<int>likes;
    vector<string>mentions;
    int i=0;
    ifstream file;
    file.open("personrank.txt");
    while(!file.eof()){
        string str,s,l;

        char c;
        getline(file,str);
        l=str;

        int pos=l.find('\t');
        s=l.substr(0,pos);
        username.push_back(s);
        int owl=findlikes(str);

        likes.push_back(owl);
       string tw= findtweet(str,pos);
       tweet.push_back(tw);





    }
    vector<string>me=findmention(tweet);

    for(int i=0;i<username.size();i++){
       //cout<<username[i]<<"\n";
    }
    for(int i=0;i<tweet.size();i++){
       //cout<<tweet[i]<<"\n";
    }
     for(int i=0;i<likes.size();i++){
       // cout<<likes[i]<<"\n";
     }
     //cout<<me.size();
     for(int i=0;i<me.size();i++){
        //cout<<me[i]<<"\n";
     }

     int n=username.size();
     for(int i=0;i<n;i++){
        mp.insert(make_pair(username[i],likes[i]));
     }
     for (auto& i: mp)
        {
            int p=i.second;
            p=p*10;
            i.second=p;
        }
        for (auto& i: mp)
        {
           //cout<<i.first<<":"<<mp[i.first]<<"\n";
        }

        for(int i=0;i<username.size()-1;i++){
            if(mp.find(me[i])==mp.end()){
                mp.insert(make_pair(me[i],50));

            }
            else{
                mp[me[i]]+=50;
            }
        }
        vector<pair<string, int>> vec;

	// copy key-value pairs from the map to the vector
  //map<string, int> m;
  for (auto& it2: mp)
  {
    vec.push_back(make_pair(it2.first, it2.second));
  }

	// // sort the vector by increasing order of its pair's second value
  sort(vec.begin(), vec.end(), sortByVal);

	// print the vector

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
	}







        //cout<<b;
        for (auto& i: mp)
        {
           //cout<<i.first<<":"<<mp[i.first]<<"\n";
        }
    file.close();

}
