class Solution {
public:
    vector<string> Word_Calculate(string sentence){
        istringstream str(sentence);
        string word;
        vector<string>vp;
        while(str >> word){
            vp.push_back(word);
        }
        return vp;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        sentence1 +=" #";
        sentence2 +=" #";
        if(sentence1 == sentence2)return 1;
        vector<string>vp1(Word_Calculate(sentence1));
        vector<string>vp2(Word_Calculate(sentence2));
       
        for(auto u:vp1){
            cout << u <<endl;
        }
        cout <<endl;
        for(auto u:vp2){
            cout << u <<endl;
        }
        if(vp1.size() < vp2.size()){
            swap(vp1,vp2);
        }
        bool ok = 0,okk=0;
        int milenai1 = 0;
        int milenai2 = 0;
        int n = vp1.size(), m = vp2.size();
        for(int i = 0,j=0; i<n && j < m ; ){
            if(vp1[i] == vp2[j] && ok == 0){
                i++;j++;
                continue;
            }if(vp1[i] == vp2[j] && ok == 1){
                i++;j++;
                okk = 1;
                continue;
            }
            else{
                if(vp1[i]!=vp2[j] && ok == 0){
                    milenai1++;
                    ok = 1;
                }
                if(vp1[i]!=vp2[j] && okk == 1){
                    milenai2++;
                    //ok = 1;
                }
                i++;
            }
        }
        cout<<milenai1<<" "<<milenai2<<" "<<ok<<" "<<okk<<endl;
        if(milenai1>=1 && milenai2 == 0 && ok == 1 && okk == 1){
            return 1;
        }else{
            //return 0;
            sentence1.pop_back();
            sentence2.pop_back();
            sentence1 ="# "+sentence1;
            sentence2 ="# "+sentence2;
            cout<<sentence1 <<" "<<sentence2<<endl;
            //return 0;
            vector<string>vp11(Word_Calculate(sentence1));
            vector<string>vp22(Word_Calculate(sentence2));
            if(vp11.size()<vp22.size())swap(vp11,vp22);
            milenai1 = milenai2 = 0;
            ok = okk = 0;
            for(int i = n-1,j= m-1; i>=0 && j >=0 ; ){
            if(vp11[i] == vp22[j] && ok == 0){
                i--;j--;
                continue;
            }if(vp11[i] == vp22[j] && ok == 1){
                i--;j--;
                okk = 1;
                continue;
            }
            else{
                if(vp11[i]!=vp22[j] && ok == 0){
                    milenai1++;
                    ok = 1;
                }
                if(vp11[i]!=vp22[j] && okk == 1){
                    milenai2++;
                    
                }
                i--;
            }
        }
        cout<<milenai1<<" "<<milenai2 <<" "<<ok <<" "<<okk<<endl;
        if(milenai1>=1 && milenai2 == 0 && ok == 1 && okk == 1){
            return 1;
        }else{
            return 0;
        }
        }
        //return 0;
    }
};