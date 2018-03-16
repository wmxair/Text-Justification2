#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size()==1){
            int x;
            x=maxWidth-words[0].size();
            string s(x,' ');
            words[0]=words[0]+s;
            return words;
        }


        int lofw=words[0].size();//现有的单词+间隔的长度（每个单词间至少一个空格）从第一个单词开始
        int startindex=0,stopindex=0;//起始位置
        int lspace;//空格总长度
        vector<string> full;//最终结果
        string s="";//临时用的字符串

        int l,k,j;
        for(int i=1;i<=words.size();i++){
           if((i<words.size())&&(lofw+words[i].size()+stopindex-startindex+1<= maxWidth)){
               lofw+=words[i].size();
               stopindex++;
           }
           else{
                string s="";//临时用的字符串
                lspace=maxWidth-lofw;
                s=s+words[startindex];

                if(stopindex==startindex){
                    string temp(lspace,' ');
                    s=s+temp;
                }
                else{
                    k=lspace/(stopindex-startindex);//左边的空格
                    l=lspace%(stopindex-startindex);//右边的空格
                    cout<<startindex<<":"<<stopindex<<":"<<k<<":"<<l<<endl;
                    string temp(k,' ');
                    for(j=startindex+1;j<stopindex;j++){
                        s=s+temp;
                        s=s+words[j];
                    }

                    if(l==0)
                        s=s+temp;
                    else{
                        string temp2(l,' ');
                        s=s+temp2;
                    }

                    s=s+words[stopindex];
                }

                full.push_back(s);
                startindex=i;
                stopindex=i;

                if(i<words.size())
                    lofw=words[i].size();
            }
        }

        return full;

    }
};


int main()
{
        int l=12;
        vector<string> words;
        words.push_back("what");
        words.push_back("must");
        words.push_back("be");
        words.push_back("shall");
        words.push_back("be.");


        Solution S;
        vector<string> full;
        full=S.fullJustify(words,l);
    for(int i=0;i<full.size();i++){
        for(int j=0;j<full[i].size();j++)
                cout<<full[i][j];
        cout<<endl;
    }
    return 0;
}
