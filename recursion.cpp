#include<iostream>
#include<cassert>

int recursive_function(int factor_a, int factor_b) {
    // std::cout << factor_a << " | " << factor_b << std::endl;
    if(factor_a < 0 && factor_b < 0) {
        return recursive_function(-factor_a, -factor_b);
    }
    if(factor_a < 0 && factor_b > 0) {
        return -recursive_function(-factor_a, factor_b);
    }
    if(factor_a > 0 && factor_b < 0) {
        return -recursive_function(factor_a, -factor_b);
    }
    if(factor_a == 0 || factor_b == 0) {
        // std::cout << "nada";
        return 0;
    }
    if(factor_a == 1) {
        // std::cout << "returning ";
        return factor_b;
    }
    else {
        // std::cout << " * ";
        return factor_b + recursive_function(factor_a -1, factor_b);
    }
}

int recursion_helper (int factor_a, int factor_b) {
    int result = recursive_function(factor_a, factor_b);
    // std::cout << std::endl;
    return result;
}

bool test_recursive_function() {
    // setup
    int test_1_a = 5;
    int test_1_b = 4;
    int test_1_expected_result = 20;

    int test_2_a = -10;
    int test_2_b = 5;
    int test_2_expected_result = -50;

    int test_3_a = 5;
    int test_3_b = -5;
    int test_3_expected_result = -25;

    int test_4_a = -15;
    int test_4_b = -2;
    int test_4_expected_result = 30;

    int test_5_a = 0;
    int test_5_b = -2;
    int test_5_expected_result = 0;

    int test_6_a = 1;
    int test_6_b = 0;
    int test_6_expected_result = 0;

    // execution
    int test_1_result = recursion_helper(test_1_a, test_1_b);
    int test_2_result = recursion_helper(test_2_a, test_2_b);
    int test_3_result = recursion_helper(test_3_a, test_3_b);
    int test_4_result = recursion_helper(test_4_a, test_4_b);
    int test_5_result = recursion_helper(test_5_a, test_5_b);
    int test_6_result = recursion_helper(test_6_a, test_6_b);

    //validation
    // std::cout << "Test 1: " << test_1_result << " expected " << test_1_expected_result << std::endl; 
    assert(test_1_expected_result == test_1_result);
    // std::cout << "Test 2: " << test_2_result << " expected " << test_2_expected_result << std::endl;
    assert(test_2_expected_result == test_2_result);
    // std::cout << "Test 3: " << test_3_result << " expected " << test_3_expected_result << std::endl;
    assert(test_3_expected_result == test_3_result);
    // std::cout << "Test 4: " << test_4_result << " expected " << test_4_expected_result << std::endl;
    assert(test_4_expected_result == test_4_result);
    // std::cout << "Test 5: " << test_5_result << " expected " << test_5_expected_result << std::endl;
    assert(test_5_expected_result == test_5_result);
    // std::cout << "Test 6: " << test_6_result << " expected " << test_6_expected_result << std::endl;
    assert(test_6_expected_result == test_6_result);

    // clean up
    return true;
}

int calculate_power_recursive(int base, int exponent);
int caclulate_power_helper(int base, int exponent);
bool test_calculate_power();

int main() {
    test_recursive_function();
    return 0;
}