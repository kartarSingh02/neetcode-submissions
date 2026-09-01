class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        if(n==1)return true;
        int suma;
        int nCopy = n;
        while(n){
            suma = 0;
            while(nCopy >= 1){
                int module = nCopy % 10;
                suma += module * module;
                nCopy = nCopy/10;
            }
            if(suma == 1) return true;
            if(seen.count(suma)) return false;
            seen.insert(suma);
            nCopy = suma;
        }
        return false;
    }
};