#include <vector>
#include <climits>
#include <iostream>


class MaxSubArray {
public:
    int maxSubArray(std::vector<int> &nums) {
        int h = 0;
        int l = 0;
        int max_sum = INT_MIN;
        int max_l = 0;
        int max_h = 0;
        int curr_sum = 0;
        while (h < nums.size()) {
            curr_sum += nums[h];
            h++;
            if (max_sum < curr_sum) {
                max_sum = curr_sum;
            }
            if (curr_sum < 0) {
                l = h;
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};

bool test(std::vector<int> &input, int expected_res, MaxSubArray &sol);

int main(int argc, char *argv[]) {
    MaxSubArray sol;
    std::vector<std::vector<int>> inputs;
    std::vector<int> expected_results;
    
    inputs.push_back(std::vector<int>({-1}));
    expected_results.push_back(-1);

    inputs.push_back(std::vector<int>({-1, -1, 3}));
    expected_results.push_back(3);

    inputs.push_back({1, -1, -1, 3});
    expected_results.push_back(3);

    inputs.push_back({1, -1, -1, 3, 4});
    expected_results.push_back(7);

    inputs.push_back({-2,1,-3,4,-1,2,1,-5,4});
    expected_results.push_back(6);

    int failed = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (!test(inputs[i], expected_results[i], sol)) {
            failed++;
        }
    }
    std::cout << failed << " tests failed" << std::endl;
    return 0;
    
}

bool test(std::vector<int> &input, int expected_res, MaxSubArray &sol) {
    int res = sol.maxSubArray(input);
    if (res != expected_res) {
        std::cout << "test failed with input: " << std::endl << "[";
        for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); i++) {
            std::cout << *i << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << "output: " << res << std::endl;
        std::cout << "expected: " << expected_res << std::endl << std::endl;
        return false;
    }
    return true;
}


//      h
// [-1, 2, -4, 3, 3, 4, -10, 100]
//   l