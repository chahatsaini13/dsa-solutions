class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while(i >= 0 || j >= 0){
            int sskip = 0;
            int tskip = 0;

            while(i >= 0){
                if(s[i] == '#'){
                    sskip++;
                    i--;
                }
                else if(sskip > 0){
                    sskip--;
                    i--;
                }
                else{
                    break;
                }
            }

            while(j >= 0){
                if(t[j] == '#'){
                    tskip++;
                    j--;
                }
                else if(tskip > 0){
                    tskip--;
                    j--;
                }
                else{
                    break;
                }
            }

            if(i >= 0 && j >= 0 && s[i] != t[j]){
                return false;
            }

            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            i--;
            j--;

        }

        return true;;
    }
};