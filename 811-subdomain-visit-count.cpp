// Runtime: 40 ms, faster than 23.06% of C++ online submissions for Subdomain Visit Count.
// Memory Usage: 13.4 MB, less than 66.67% of C++ online submissions for Subdomain Visit Count.


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> out;
        unordered_map<string, int> counts;
        
        for (string& pair : cpdomains) {
            stringstream ss (pair);
            int count; 
            vector<string> domains;
            
            ss >> count;
            string temp;
            while(getline(ss, temp, '.')) { 
                for (string& s : domains) s += "." + temp;
                if (domains.size() > 0) temp = " " + temp;
                domains.push_back(temp); 
            }
            for (string&s : domains) {
                counts[s] += count;
            }
            
            // cout << count << " " << domains.size() << endl;
        }
        
        for ( const auto &p : counts ) {
           out.push_back(to_string(p.second) + p.first);
        } 
    
        return out;
    }
};
