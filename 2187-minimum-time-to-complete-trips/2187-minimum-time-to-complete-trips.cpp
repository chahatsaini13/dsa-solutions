class Solution {
public:
    using ll = long long;

    ll min_arr(vector<int>& a){
        ll min = INT_MAX;
        for(int i = 0; i < a.size(); i++){
            if( a[i] < min){
                min = a[i];
            }
        }
        return min;
    }

    ll best(vector<int>& time, ll guess){
        ll trips = 0;
        for(int t : time){
            trips += guess / t;
        }

        return trips;
    }

    ll minimumTime(vector<int>& time, int totalTrips) {
        ll low = min_arr(time);
        ll high = min_arr(time) * totalTrips;
        ll res = 0;

        while( low <= high){
            ll guess = (low + high) / 2;
            ll trips = best(time, guess);

            if(trips < totalTrips){
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess - 1;
            }
        }
        
        return res;
    }
};