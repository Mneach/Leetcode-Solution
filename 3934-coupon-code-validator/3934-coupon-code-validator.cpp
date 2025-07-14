class Solution {
public:
    vector<string> validateCoupons(vector<string>& codes, vector<string>& businessLines, vector<bool>& isActive) {
        vector<pair<string, string>> validCoupons;
        
        for (int i = 0; i < codes.size(); ++i) {
            if (isActive[i] && isValidCouponCode(codes[i]) && isValidBusinessLine(businessLines[i])) {
                validCoupons.emplace_back(businessLines[i], codes[i]);
            }
        }
        
        sort(validCoupons.begin(), validCoupons.end());
        
        vector<string> result;
        result.reserve(validCoupons.size());
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.second);
        }
        
        return result;
    }

private:
    bool isValidCouponCode(const string& code) const {
        if (code.empty()) return false;
        
        for (char c : code) {
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
    
    bool isValidBusinessLine(const string& businessLine) const {
        static const vector<string> validBusinessLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };
        return find(validBusinessLines.begin(), validBusinessLines.end(), businessLine) != validBusinessLines.end();
    }
};