#include <vector>
#include <string>
#include <cstring>

static constexpr int ALPHABET_SIZE = 26;
static constexpr int MOD = 1'000'000'007;

class TransformationMatrix {
public:
    TransformationMatrix() { reset(); }
    
    void reset() {
        std::memset(data_, 0, sizeof(data_));
    }
    
    void set_transformation(int from, int to, int value) {
        data_[to][from] = value;
    }
    
    int get_transformation(int from, int to) const {
        return data_[to][from];
    }
    
    TransformationMatrix operator*(const TransformationMatrix& other) const {
        TransformationMatrix result;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                long long sum = 0;
                for (int k = 0; k < ALPHABET_SIZE; ++k) {
                    sum += static_cast<long long>(data_[i][k]) * other.data_[k][j];
                    if (sum >= MOD) sum %= MOD;  // Prevent overflow
                }
                result.data_[i][j] = sum % MOD;
            }
        }
        return result;
    }
    
    static TransformationMatrix identity() {
        TransformationMatrix mat;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            mat.data_[i][i] = 1;
        }
        return mat;
    }
    
    static TransformationMatrix power(const TransformationMatrix& base, int exponent) {
        TransformationMatrix result = identity();
        TransformationMatrix current = base;
        
        while (exponent > 0) {
            if (exponent & 1) {
                result = result * current;
            }
            current = current * current;
            exponent >>= 1;
        }
        
        return result;
    }

private:
    int data_[ALPHABET_SIZE][ALPHABET_SIZE];
};

class Solution {
public:
    int lengthAfterTransformations(std::string s, int transformations, std::vector<int>& shifts) {
        TransformationMatrix transformationMatrix = buildTransformationMatrix(shifts);
        TransformationMatrix poweredMatrix = TransformationMatrix::power(transformationMatrix, transformations);
        
        std::vector<int> charCounts = countCharacters(s);
        return calculateResult(poweredMatrix, charCounts);
    }

private:
    TransformationMatrix buildTransformationMatrix(const std::vector<int>& shifts) {
        TransformationMatrix matrix;
        for (int from = 0; from < ALPHABET_SIZE; ++from) {
            for (int shift = 1; shift <= shifts[from]; ++shift) {
                int to = (from + shift) % ALPHABET_SIZE;
                matrix.set_transformation(from, to, 
                    (matrix.get_transformation(from, to) + 1) % MOD);
            }
        }
        return matrix;
    }
    
    std::vector<int> countCharacters(const std::string& s) {
        std::vector<int> counts(ALPHABET_SIZE, 0);
        for (char ch : s) {
            ++counts[ch - 'a'];
        }
        return counts;
    }
    
    int calculateResult(const TransformationMatrix& matrix, const std::vector<int>& charCounts) {
        long long result = 0;
        for (int from = 0; from < ALPHABET_SIZE; ++from) {
            if (charCounts[from] == 0) continue;
            for (int to = 0; to < ALPHABET_SIZE; ++to) {
                result += static_cast<long long>(matrix.get_transformation(from, to)) * charCounts[from];
                if (result >= MOD) result %= MOD;  // Prevent overflow
            }
        }
        return result % MOD;
    }
};